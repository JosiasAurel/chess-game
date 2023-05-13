#include "./src/chess/chess.hpp"
#include <iostream>
#include <memory>

int main(void) {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Chess Game");

  SetConfigFlags(FLAG_MSAA_4X_HINT);
  SetTargetFPS(60); // Set our game to run at 60 frames-per-second

  ChessGame::getGameInstance()->runGameLoop();
  
  return 0;
}
