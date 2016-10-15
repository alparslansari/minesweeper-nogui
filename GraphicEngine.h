#ifndef GRAPHICENGINE_H
#define GRAPHICENGINE_H

class GraphicEngine {
   public:
      void clearScreen();
      void printIntro();
      void drawEmptyBoard(int width, int height);
      void drawBoard(int pos, int val);
      void drawYouWon();
      void drawYouLost();
};

#endif // GRAPHICENGINE_H