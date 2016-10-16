#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include "Validation.h"
#include "GraphicEngine.h"


using namespace std;

bool goalFunction(int number_of_mines, int not_revealed_squares)
{
   //if number of mines == not revealed square count
   if(number_of_mines == not_revealed_squares)
   {
      // Graphic display YOU WIN
      return true;
   }
   return false;
}

bool goalFunctionMarkMine(int number_of_mines, int marked_squares)
{
   //if number of mines == not revealed square count
   if(number_of_mines == marked_squares)
   {
      // pre-condition is satisfied
      return true;
   }
   return false;
}

/*
 This function takes an integer as an input 
 then generates a random number and returns it
 -- should generate a number between 1 and 'limit'
*/
int randomNumber(int limit)
{
   srand(time(0));
   int rnd = 1 + rand() % limit;
   return rnd;
}

int main (int argc, char ** argv){

   if(argc !=4)
   {
      // width height number_of_mines
      cout << "usage: ./minesweeper width height number_of_mines" << endl;
      return 1;
   }

   Validation v; // Initialize our Validation Library!
   GraphicEngine gfx;

   gfx.printIntro(); // Display intro / program information
      
   // Validate -> width, height and number_of_mines are integer
   string str_width = argv[1];
   int width = v.isValidateParamINT(str_width);

   // validate width
   if(!v.isValidWidth(width))
   {
      return 1;
   }

   string str_height = argv[2];
   int height = v.isValidateParamINT(str_height);

   // validate height
   if(!v.isValidHeight(height))
   {
      return 1;
   }

   string str_number_of_mines = argv[3];
   int number_of_mines = v.isValidateParamINT(str_number_of_mines);

   // validate number_of_mines
   if(!v.isValidNumOfMines(width, height, number_of_mines))
   {
      return 1;
   }
   
   gfx.drawEmptyBoard(width, height);

   int board[height+1][width+1]; // {0:mine, -1: empty area, 1..9: adjacent mine numbers}
   int boardMarkings[height+1][width+1]; // {-1: not revealed squares, 0: revealed squares, 1: marked for mine}

   // initialize the board;
   for(int i = 1; i<=height; i++)
      for(int j = 1; j<=width; j++)
      {
         board[i][j] = -1; // empty squares
         boardMarkings[i][j] = -1; // 
      }
         
   // generate the random board with mines
   bool gameStatus = false;
   int mine_placement = 0;
   int mx_pos = 0;
   int my_pos = 0;
   while(mine_placement<number_of_mines)
   {
      mx_pos = randomNumber(height);
      my_pos = randomNumber(width);
      if(board[mx_pos][my_pos]!=0)
      {
          board[mx_pos][my_pos] = 0; // mine placement
          mine_placement++;
      }
   }

   // At this point the mines placed on the board!

   // Generate the numbers adjacent to mines
   int mineFree;
   for(int i = 1; i<=height; i++)
   {
      for(int j = 1; j<=width; j++)
      {
         mineFree = 0;
         // check i - 1 > 0, j - 1 > 0
         // check i + 1 < height, check j + 1 < width
         if(board[i][j]!=0)
         {
            // (1) i - 1, j - 1
            if(i - 1 > 0 && j - 1 > 0)
            {
               if(board[i-1][j-1]==0) mineFree++;
            }

            // (2) i + 1, j + 1
            if(i + 1 <= height && j + 1 <= width)
            {
               if(board[i+1][j+1]==0) mineFree++;
            }

            // (3) i - 1, j + 1
            if(i - 1 > 0 && j + 1 <= width)
            {
               if(board[i-1][j+1]==0) mineFree++;
            }

            // (4) i + 1, j - 1
            if(i + 1 <= height && j - 1 > 0)
            {
               if(board[i+1][j-1]==0) mineFree++;
            }

            // (5) i, j - 1
            if(j - 1 > 0)
            {
               if(board[i][j-1]==0) mineFree++;
            }
            

            // (6) i, j + 1
            if(j + 1 <= width)
            {
               if(board[i][j+1]==0) mineFree++;
            }
            

            // (7) i - 1, j
            if(i - 1 > 0)
            {
               if(board[i-1][j]==0) mineFree++;
            }

            // (8) i + 1, j
            if(i + 1 <= height)
            {
               if(board[i+1][j]==0) mineFree++;
            }

            // Assign value if greater than 0
            if(mineFree > 0)
            {
               board[i][j] = mineFree;
            }
          } // END OF IF
      } // END OF FOR - j
   } // END OF FOR - i

   // AT THIS POINT THE GAME BOARD IS READY FOR PLAY!
   map< int, int > sucessorMap; 


   // (leave as comment) to see the actual state of the game board - for debug puposes
   /*
   for(int i = 1; i<=height; i++)
   {
      for(int j = 1; j<=width; j++)
         cout << board[i][j] << " ";
      cout << "\n";
   }
   */
   
   // Game rules
   // IF revealed sucessfully, trigger cleanup empty spaces unless there is not any mine close by 1 square
   // IF revelaed is failed, display the mines and you lose message
   // Revealed should not open fields which is marked with 'M - mine'

   // Mark not revealed areas

   int not_revealed_squares;
   string cmd="y";
   string x_val = "";
   string y_val = "";
   int x_axs;
   int y_axs;
   int ilk;
   int iki;
   bool coords;
   int movements = 0;
   while(true)
   {
      cout << "What's your move? ";
      getline (cin, cmd);
      coords = true;

      if(cmd=="Q" || cmd=="q")
      {
         // Quit from program
         gfx.clearScreen();
         cout << "Thanks for playing Minesweeper!" << endl;
         return 1;
      }
      else if(cmd=="R" || cmd=="r")
      {
          // Reveal the coordinate
         while(coords)
         {
            cout << " X coordinate: (1 - "<< width<<")? ";
            getline (cin, x_val);

            cout << " Y coordinate: (1 - " << height<<")? ";
            getline (cin, y_val);

            coords = v.isCoordinatesValid(x_val, y_val, width, height);

            if(!coords)
            {
               movements++;
               x_axs = stoi(x_val);
               y_axs = stoi(y_val);
               // if the selected area is not marked for mine
               // if the selected area is not revealed
               if(boardMarkings[x_axs][y_axs]==-1)
               {
                  if(board[x_axs][y_axs] == 0)
                  {
                     cout << "ARGH... YOU BLOW UP!!!\n In your "<<movements<<" move!"<<endl;
                     for(int i = 1; i<=height; i++)
                     {
                        for(int j = 1; j<=width; j++)
                        {
                           if(board[i][j]==-1)
                              cout << "~";
                           else if(board[i][j]==0)
                              cout << "M";
                           else
                              cout << board[i][j];

                        }
                           
                        cout << "\n";
                     }
                     gfx.drawYouLost();
                     return 1;
                  }
                  else if(board[x_axs][y_axs] == -1)
                  {
                     // Trigger reveal effect! boardMarkings needs to be updated chain reaction!
                     sucessorMap.insert(pair<int,int>(x_axs,y_axs));
                     while(sucessorMap.size()>0)
                     {
                        for(map<int,int>::iterator i = sucessorMap.begin(); i!=sucessorMap.end();)
                        {
                           ilk = i->first;
                           iki = i->second;
                           sucessorMap.erase(i++);
                           if(board[ilk][iki] == -1)
                           {
                              boardMarkings[ilk][iki]=0; // Mark as revealed!
                           }
                           // (1) i - 1, j - 1
                           if(ilk - 1 > 0 && iki - 1 > 0)
                           {
                              if(board[ilk-1][iki-1]==-1 && boardMarkings[ilk-1][iki-1]==-1) sucessorMap.insert(pair<int,int>(ilk-1,iki-1));   
                           }

                           // (2) i + 1, j + 1
                           if(ilk + 1 <= height && iki + 1 <= width)
                           {
                              if(board[ilk+1][iki+1]==-1 && boardMarkings[ilk+1][iki+1]==-1) sucessorMap.insert(pair<int,int>(ilk+1,iki+1));
                           }

                           // (3) i - 1, j + 1
                           if(ilk - 1 > 0 && iki + 1 <= width)
                           {
                              if(board[ilk-1][iki+1]==-1 && boardMarkings[ilk-1][iki+1]==-1) sucessorMap.insert(pair<int,int>(ilk-1,iki+1));
                           }

                           // (4) i + 1, j - 1
                           if(ilk + 1 <= height && iki - 1 > 0)
                           {
                              if(board[ilk+1][iki-1]==-1 && boardMarkings[ilk+1][iki-1]==-1) sucessorMap.insert(pair<int,int>(ilk+1,iki-1));
                           }

                           // (5) i, j - 1
                           if(iki - 1 > 0)
                           {
                              if(board[ilk][iki-1]==-1 && boardMarkings[ilk][iki-1]==-1) sucessorMap.insert(pair<int,int>(ilk,iki-1));
                           }
                           

                           // (6) i, j + 1
                           if(iki + 1 <= width)
                           {
                              if(board[ilk][iki+1]==-1 && boardMarkings[ilk][iki+1]==-1) sucessorMap.insert(pair<int,int>(ilk,iki+1));
                           }
                           

                           // (7) i - 1, j
                           if(ilk - 1 > 0)
                           {
                              if(board[ilk-1][iki]==-1 && boardMarkings[ilk-1][iki]==-1) sucessorMap.insert(pair<int,int>(ilk-1,iki));
                           }

                           // (8) i + 1, j
                           if(ilk + 1 <= height)
                           {
                              if(board[ilk+1][iki]==-1 && boardMarkings[ilk+1][iki]==-1) sucessorMap.insert(pair<int,int>(ilk+1,iki));
                           }
                        } // END OF FOR
                     }  // END OF WHILE
                  }
                  else
                  {
                     // Reveal single square
                     boardMarkings[x_axs][y_axs]=0; // Mark as revealed!
                  }

                  // CHECK IF GOAL STATE IS TRUE
                  not_revealed_squares = 0;
                  for(int i = 1; i<=height; i++)
                  {
                     for(int j = 1; j<=width; j++)
                        if(boardMarkings[i][j]==-1 || boardMarkings[i][j]==1) not_revealed_squares++;
                  }
                  gameStatus = goalFunction(number_of_mines, not_revealed_squares);


                  // REDRAW the board
                  gfx.clearScreen();
                  for(int i = 1; i<=height; i++)
                  {
                     for(int j = 1; j<=width; j++)
                        gfx.drawBoard(boardMarkings[i][j], board[i][j]);
                     cout << "\n";
                  }
                  cout << "Keyboard settings:       R/r: (R)eveal       M/m: (M)ark the mine location       U/u: (U)nmark the mine location       Q/q: Quit" << endl;

                  if(gameStatus)
                  {
                     gfx.drawYouWon();
                     cout << "in " << movements << " move" << endl;
                     return 0;
                  }
               }
               else if (boardMarkings[x_axs][y_axs]==0)
               {

                  cout << "Invalid move! The area is already Revealed" << endl;
                  coords = true;

               }
               else if (boardMarkings[x_axs][y_axs]==1)
               {
                  cout << "Invalid move! The area is marked for mine!" << endl;
                  coords = true;
               }
               else
               {
                  // NOT RECOVARABLE ERROR
                  cout << "Memory is corrupted!" << endl;
                  return -1;
               }
            }
         } // END OF INNER WHILE
      }
      else if(cmd=="M" || cmd=="m")
      {
         // Mark the mine
         // check if the location is not revealed and not already marked!
         while(coords)
         {
            cout << " X coordinate: (1 - "<< width<<")? ";
            getline (cin, x_val);

            cout << " Y coordinate: (1 - " << height<<")? ";
            getline (cin, y_val);

            coords = v.isCoordinatesValid(x_val, y_val, width, height);

            if(!coords)
            {
               movements++;
               x_axs = stoi(x_val);
               y_axs = stoi(y_val);
               // if the selected area is marked for mine
               // if the selected area is not revealed
               if(boardMarkings[x_axs][y_axs]==-1)
               {
                  boardMarkings[x_axs][y_axs]=1; // Mark as revealed!
                  // REDRAW the board
                  gfx.clearScreen();
                  for(int i = 1; i<=height; i++)
                  {
                     for(int j = 1; j<=width; j++)
                        gfx.drawBoard(boardMarkings[i][j], board[i][j]);
                     cout << "\n";
                  }
                  cout << "Keyboard settings:       R/r: (R)eveal       M/m: (M)ark the mine location       U/u: (U)nmark the mine location       Q/q: Quit" << endl;
               }
               else if (boardMarkings[x_axs][y_axs]==0)
               {

                  cout << "Invalid move! The area is already Revealed" << endl;
                  coords = true;

               }
               else if (boardMarkings[x_axs][y_axs]==1)
               {
                  cout << "Invalid move! The area is marked for mine!" << endl;
                  coords = true;
               }
               else
               {
                  // NOT RECOVARABLE ERROR
                  cout << "Memory is corrupted!" << endl;
                  return -1;
               }
            }
         } // END OF INNER WHILE

      }
      else if(cmd=="U" || cmd=="u")
      {
         // Uumark the mine
         // check if the location is not revealed and not already marked!
         while(coords)
         {
            cout << " X coordinate: (1 - "<< width<<")? ";
            getline (cin, x_val);

            cout << " Y coordinate: (1 - " << height<<")? ";
            getline (cin, y_val);

            coords = v.isCoordinatesValid(x_val, y_val, width, height);

            if(!coords)
            {
               movements++;
               x_axs = stoi(x_val);
               y_axs = stoi(y_val);
               // if the selected area is marked for mine
               // if the selected area is not revealed
               if(boardMarkings[x_axs][y_axs]==1)
               {
                  boardMarkings[x_axs][y_axs]=-1; // Unmarked!
                  // REDRAW the board
                  gfx.clearScreen();
                  for(int i = 1; i<=height; i++)
                  {
                     for(int j = 1; j<=width; j++)
                        gfx.drawBoard(boardMarkings[i][j], board[i][j]);
                     cout << "\n";
                  }
                  cout << "Keyboard settings:       R/r: (R)eveal       M/m: (M)ark the mine location       U/u: (U)nmark the mine location       Q/q: Quit" << endl;     
               }
               else if (boardMarkings[x_axs][y_axs]==0)
               {

                  cout << "Invalid move! The area is already Revealed" << endl;
                  coords = true;

               }
               else if (boardMarkings[x_axs][y_axs]==-1)
               {
                  cout << "Invalid move! The area is not marked for mine yet!" << endl;
                  coords = true;
               }
               else
               {
                  // NOT RECOVARABLE ERROR
                  cout << "Memory is corrupted!" << endl;
                  return -1;
               }
            }
         } // END OF INNER WHILE
      }
      else
      {
         cout << "Invalid move!" << endl;
         gfx.clearScreen();
         // redraw the current board
         for(int i = 1; i<=height; i++)
         {
            for(int j = 1; j<=width; j++)
               gfx.drawBoard(boardMarkings[i][j], board[i][j]);
               cout << "\n";
         }
         cout << "Keyboard settings:       R/r: (R)eveal       M/m: (M)ark the mine location       U/u: (U)nmark the mine location       Q/q: Quit" << endl;

      }

      // (leave as comment) to see the actual state of the game board - for debug puposes
      /*
      for(int i = 1; i<=height; i++)
      {
         for(int j = 1; j<=width; j++)
            cout << board[i][j] << " ";
         cout << "\n";
      }
      */
   } // END OF WHILE
   
   
   
   


}
