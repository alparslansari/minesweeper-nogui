#include <fstream>
#include <iostream>
#include <sstream>
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
      // Validate -> width, height and number_of_mines are integer
      // Validate -> width is even
      // Validate -> height is even
      // Validate -> number_of_mines < width * height
   }

//cout << "OK" << endl;
   Validation v;
   v.printIntro();
}
