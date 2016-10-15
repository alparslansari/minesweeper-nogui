#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "Validation.h"

using namespace std;

int main (int argc, char ** argv){
   if(argc !=4)
   {
      // width height number_of_mines
      cout << "usage: ./minesweeper width height number_of_mines" << endl;
      return 1;
   }
   else
   {
      Validation v; // Initialize our Validation Library!
      v.printIntro(); // Display intro / program information
      
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




      // Validate -> width is even
      // Validate -> height is even
      // Validate -> number_of_mines < width * height
   }

   
   
   
   


}
