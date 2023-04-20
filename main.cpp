#include "./src/chess/chess.hpp"
#include <iostream>


int main(void) {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Chess Game");

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second

  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    BeginDrawing();

    ClearBackground(Color{42, 47, 79});

    ChessGame::getGameInstance()->updateScreen();

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
