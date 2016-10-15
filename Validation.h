#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>
class Validation {
   public:
   	  static int const MAX_WIDTH;
   	  static int const MAX_HEIGHT;
   	  bool isValidWidth(int width);
   	  bool isValidHeight(int height);
   	  bool isValidNumOfMines(int width, int height, int mines);
      void printIntro();
      int isValidateParamINT(std::string param);
      int isCoordParamINT(std::string param);
      bool isCoordinatesValid(std::string x, std::string y, int width, int height);
};

#endif // VALIDATION_H