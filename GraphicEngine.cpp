#include "GraphicEngine.h"
#include <iostream>
#include <cstdlib>


using namespace std;


void GraphicEngine::clearScreen()
{
	try{
       system("clear");
	}
	catch (exception& e)
	{
        cout << e.what() << endl;
        cout << "The game is not running on unix like machine!" << endl;
        	try{
		       system("cls");
			}
			catch (exception& e)
			{
		        cout << e.what() << endl;
		        cout << "The game is not running on windows like machine! Aborting screen cleaning!" << endl;
			}
	}
}

void GraphicEngine::printIntro()
{
   GraphicEngine::clearScreen();
   cout << "*******************************************************" << endl;
   cout << "* Secure System: Project 2: Minesweepers ver 0.1      *" << endl;
   cout << "*********************** Authors ***********************" << endl;
   cout << "* Alparslan Sari                                      *" << endl;
   cout << "* Kaoru (Teddy) Katayama                              *" << endl;
   cout << "* Pengcheng Zhou                                      *" << endl;
   cout << "*******************************************************" << endl;
}

void GraphicEngine::drawEmptyBoard(int width, int height)
{
   for(int i = 0; i < height; i++)
   {
      for(int j = 0; j < width; j++)
      {
         cout << "#";
      }
      cout << "\n";
   }
   cout << endl;
   cout << "Keyboard settings:       R/r: (R)eveal       M/m: (M)ark the mine location       U/u: (U)nmark the mine location       Q/q: Quit" << endl;
}

void GraphicEngine::drawBoard(int pos, int val)
{
   // -1: not revealed squares, 0: revealed squares, 1: marked for mine
   if(pos==-1)
   {
       cout << "#";
   }
   else if(pos==0)
   {
   	   if(val==-1)
   	   	  cout << "~";
   	   else
   	      cout << val;
   }
   else if(pos==1)
   {
   	   cout << "M";
   }
}

// http://patorjk.com/software/taag/#p=display&f=Doh&t=BYE%20!
void GraphicEngine::drawYouWon()
{
cout<<"YYYYYYY       YYYYYYY     OOOOOOOOO     UUUUUUUU     UUUUUUUU     WWWWWWWW                           WWWWWWWW     OOOOOOOOO     NNNNNNNN        NNNNNNNN"<<endl;
cout<<"Y:::::Y       Y:::::Y   OO:::::::::OO   U::::::U     U::::::U     W::::::W                           W::::::W   OO:::::::::OO   N:::::::N       N::::::N"<<endl;
cout<<"Y:::::Y       Y:::::Y OO:::::::::::::OO U::::::U     U::::::U     W::::::W                           W::::::W OO:::::::::::::OO N::::::::N      N::::::N"<<endl;
cout<<"Y::::::Y     Y::::::YO:::::::OOO:::::::OUU:::::U     U:::::UU     W::::::W                           W::::::WO:::::::OOO:::::::ON:::::::::N     N::::::N"<<endl;
cout<<"YYY:::::Y   Y:::::YYYO::::::O   O::::::O U:::::U     U:::::U       W:::::W           WWWWW           W:::::W O::::::O   O::::::ON::::::::::N    N::::::N"<<endl;
cout<<"   Y:::::Y Y:::::Y   O:::::O     O:::::O U:::::D     D:::::U        W:::::W         W:::::W         W:::::W  O:::::O     O:::::ON:::::::::::N   N::::::N"<<endl;
cout<<"    Y:::::Y:::::Y    O:::::O     O:::::O U:::::D     D:::::U         W:::::W       W:::::::W       W:::::W   O:::::O     O:::::ON:::::::N::::N  N::::::N"<<endl;
cout<<"     Y:::::::::Y     O:::::O     O:::::O U:::::D     D:::::U          W:::::W     W:::::::::W     W:::::W    O:::::O     O:::::ON::::::N N::::N N::::::N"<<endl;
cout<<"      Y:::::::Y      O:::::O     O:::::O U:::::D     D:::::U           W:::::W   W:::::W:::::W   W:::::W     O:::::O     O:::::ON::::::N  N::::N:::::::N"<<endl;
cout<<"       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U            W:::::W W:::::W W:::::W W:::::W      O:::::O     O:::::ON::::::N   N:::::::::::N"<<endl;
cout<<"       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U             W:::::W:::::W   W:::::W:::::W       O:::::O     O:::::ON::::::N    N::::::::::N"<<endl;
cout<<"       Y:::::Y       O::::::O   O::::::O U::::::U   U::::::U              W:::::::::W     W:::::::::W        O::::::O   O::::::ON::::::N     N:::::::::N"<<endl;
cout<<"       Y:::::Y       O:::::::OOO:::::::O U:::::::UUU:::::::U               W:::::::W       W:::::::W         O:::::::OOO:::::::ON::::::N      N::::::::N"<<endl;
cout<<"    YYYY:::::YYYY     OO:::::::::::::OO   UU:::::::::::::UU                 W:::::W         W:::::W           OO:::::::::::::OO N::::::N       N:::::::N"<<endl;
cout<<"    Y:::::::::::Y       OO:::::::::OO       UU:::::::::UU                    W:::W           W:::W              OO:::::::::OO   N::::::N        N::::::N"<<endl;
cout<<"    YYYYYYYYYYYYY         OOOOOOOOO           UUUUUUUUU                       WWW             WWW                 OOOOOOOOO     NNNNNNNN         NNNNNNN"<<endl;
}

void GraphicEngine::drawYouLost()
{
cout<<"KKKKKKKKK    KKKKKKK               AAA               BBBBBBBBBBBBBBBBB        OOOOOOOOO          OOOOOOOOO          OOOOOOOOO     MMMMMMMM               MMMMMMMM  !!! "<<endl;
cout<<"K:::::::K    K:::::K              A:::A              B::::::::::::::::B     OO:::::::::OO      OO:::::::::OO      OO:::::::::OO   M:::::::M             M:::::::M !!:!!"<<endl;
cout<<"K:::::::K    K:::::K             A:::::A             B::::::BBBBBB:::::B  OO:::::::::::::OO  OO:::::::::::::OO  OO:::::::::::::OO M::::::::M           M::::::::M !:::!"<<endl;
cout<<"K:::::::K   K::::::K            A:::::::A            BB:::::B     B:::::BO:::::::OOO:::::::OO:::::::OOO:::::::OO:::::::OOO:::::::OM:::::::::M         M:::::::::M !:::!"<<endl;
cout<<"KK::::::K  K:::::KKK           A:::::::::A             B::::B     B:::::BO::::::O   O::::::OO::::::O   O::::::OO::::::O   O::::::OM::::::::::M       M::::::::::M !:::!"<<endl;
cout<<"  K:::::K K:::::K             A:::::A:::::A            B::::B     B:::::BO:::::O     O:::::OO:::::O     O:::::OO:::::O     O:::::OM:::::::::::M     M:::::::::::M !:::!"<<endl;
cout<<"  K::::::K:::::K             A:::::A A:::::A           B::::BBBBBB:::::B O:::::O     O:::::OO:::::O     O:::::OO:::::O     O:::::OM:::::::M::::M   M::::M:::::::M !:::!"<<endl;
cout<<"  K:::::::::::K             A:::::A   A:::::A          B:::::::::::::BB  O:::::O     O:::::OO:::::O     O:::::OO:::::O     O:::::OM::::::M M::::M M::::M M::::::M !:::!"<<endl;
cout<<"  K:::::::::::K            A:::::A     A:::::A         B::::BBBBBB:::::B O:::::O     O:::::OO:::::O     O:::::OO:::::O     O:::::OM::::::M  M::::M::::M  M::::::M !:::!"<<endl;
cout<<"  K::::::K:::::K          A:::::AAAAAAAAA:::::A        B::::B     B:::::BO:::::O     O:::::OO:::::O     O:::::OO:::::O     O:::::OM::::::M   M:::::::M   M::::::M !:::!"<<endl;
cout<<"  K:::::K K:::::K        A:::::::::::::::::::::A       B::::B     B:::::BO:::::O     O:::::OO:::::O     O:::::OO:::::O     O:::::OM::::::M    M:::::M    M::::::M !!:!!"<<endl;
cout<<"KK::::::K  K:::::KKK    A:::::AAAAAAAAAAAAA:::::A      B::::B     B:::::BO::::::O   O::::::OO::::::O   O::::::OO::::::O   O::::::OM::::::M     MMMMM     M::::::M  !!! "<<endl;
cout<<"K:::::::K   K::::::K   A:::::A             A:::::A   BB:::::BBBBBB::::::BO:::::::OOO:::::::OO:::::::OOO:::::::OO:::::::OOO:::::::OM::::::M               M::::::M      "<<endl;
cout<<"K:::::::K    K:::::K  A:::::A               A:::::A  B:::::::::::::::::B  OO:::::::::::::OO  OO:::::::::::::OO  OO:::::::::::::OO M::::::M               M::::::M  !!! "<<endl;
cout<<"K:::::::K    K:::::K A:::::A                 A:::::A B::::::::::::::::B     OO:::::::::OO      OO:::::::::OO      OO:::::::::OO   M::::::M               M::::::M !!:!!"<<endl;
cout<<"KKKKKKKKK    KKKKKKKAAAAAAA                   AAAAAAABBBBBBBBBBBBBBBBB        OOOOOOOOO          OOOOOOOOO          OOOOOOOOO     MMMMMMMM               MMMMMMMM  !!! "<<endl;
cout<<"                                                                                                                                                                      "<<endl;
cout<<"                                                                                                                                                                     "<<endl;
cout<<"                                                                                                                                                                      "<<endl;
cout<<"                                                                                                                                                                      "<<endl;
cout<<"                                                                                                                                                                      "<<endl;
cout<<"                                                                                                                                                                      "<<endl;
cout<<"                                                                                                                                                                      "<<endl;
cout<<"                                                                                                                                                                      "<<endl;
cout<<"                                                                                                                                                                      "<<endl;
cout<<"YYYYYYY       YYYYYYY     OOOOOOOOO     UUUUUUUU     UUUUUUUU     LLLLLLLLLLL                  OOOOOOOOO        SSSSSSSSSSSSSSS TTTTTTTTTTTTTTTTTTTTTTT               "<<endl;
cout<<"Y:::::Y       Y:::::Y   OO:::::::::OO   U::::::U     U::::::U     L:::::::::L                OO:::::::::OO    SS:::::::::::::::ST:::::::::::::::::::::T               "<<endl;
cout<<"Y:::::Y       Y:::::Y OO:::::::::::::OO U::::::U     U::::::U     L:::::::::L              OO:::::::::::::OO S:::::SSSSSS::::::ST:::::::::::::::::::::T               "<<endl;
cout<<"Y::::::Y     Y::::::YO:::::::OOO:::::::OUU:::::U     U:::::UU     LL:::::::LL             O:::::::OOO:::::::OS:::::S     SSSSSSST:::::TT:::::::TT:::::T               "<<endl;
cout<<"YYY:::::Y   Y:::::YYYO::::::O   O::::::O U:::::U     U:::::U        L:::::L               O::::::O   O::::::OS:::::S            TTTTTT  T:::::T  TTTTTT               "<<endl;
cout<<"   Y:::::Y Y:::::Y   O:::::O     O:::::O U:::::D     D:::::U        L:::::L               O:::::O     O:::::OS:::::S                    T:::::T                       "<<endl;
cout<<"    Y:::::Y:::::Y    O:::::O     O:::::O U:::::D     D:::::U        L:::::L               O:::::O     O:::::O S::::SSSS                 T:::::T                       "<<endl;
cout<<"     Y:::::::::Y     O:::::O     O:::::O U:::::D     D:::::U        L:::::L               O:::::O     O:::::O  SS::::::SSSSS            T:::::T                       "<<endl;
cout<<"      Y:::::::Y      O:::::O     O:::::O U:::::D     D:::::U        L:::::L               O:::::O     O:::::O    SSS::::::::SS          T:::::T                       "<<endl;
cout<<"       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U        L:::::L               O:::::O     O:::::O       SSSSSS::::S         T:::::T                       "<<endl;
cout<<"       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U        L:::::L               O:::::O     O:::::O            S:::::S        T:::::T                       "<<endl;
cout<<"       Y:::::Y       O::::::O   O::::::O U::::::U   U::::::U        L:::::L         LLLLLLO::::::O   O::::::O            S:::::S        T:::::T                       "<<endl;
cout<<"       Y:::::Y       O:::::::OOO:::::::O U:::::::UUU:::::::U      LL:::::::LLLLLLLLL:::::LO:::::::OOO:::::::OSSSSSSS     S:::::S      TT:::::::TT                     "<<endl;
cout<<"    YYYY:::::YYYY     OO:::::::::::::OO   UU:::::::::::::UU       L::::::::::::::::::::::L OO:::::::::::::OO S::::::SSSSSS:::::S      T:::::::::T                     "<<endl;
cout<<"    Y:::::::::::Y       OO:::::::::OO       UU:::::::::UU         L::::::::::::::::::::::L   OO:::::::::OO   S:::::::::::::::SS       T:::::::::T                     "<<endl;
cout<<"    YYYYYYYYYYYYY         OOOOOOOOO           UUUUUUUUU           LLLLLLLLLLLLLLLLLLLLLLLL     OOOOOOOOO      SSSSSSSSSSSSSSS         TTTTTTTTTTT  "<<endl;
}