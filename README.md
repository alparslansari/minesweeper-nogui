# minesweeper-nogui
minesweeper without gui

The game is implementation is now done. The game is fully functional. Player needs to use keyboard to play the game. Game instructions is displayed on the screen and very straight forward.
In order to win the game all squares needs to be revealed / Marking a filed as mine does not necessary.

# Example to run the game
./minesweeper 4 4 4


# To modify Libraries
vi Validation.h 

vi Validation.cpp

vi GraphicEngine.h

vi GraphicEngine.cpp

# To modify main application
vi minesweeper.cpp

# To compile the project
g++ minesweeper.cpp Validation.cpp GraphicEngine.cpp -o minesweeper


