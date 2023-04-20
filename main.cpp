#include "./src/chess/chess.hpp"
#include <iostream>


int main(void) {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Chess Game");

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second

  ChessGame::getGameInstance()->runGameLoop();

  CloseWindow();

  return 0;
}
