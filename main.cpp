#include "./include/raylib.h"
#include "./src/board/board.hpp"
#include "src/types.hpp"
#include <iostream>

#define SQ_SIZE 60

// using std::cout;
// using std::endl;

//Load assets

const map<PieceType, Image> blackPieces = {
  {PieceType::PAWN, LoadImage("../assets/sprites/pawn_black.png")},
  {PieceType::KNIGHT, LoadImage("../assets/sprites/knight_black.png")},
  {PieceType::BISHOP, LoadImage("../assets/sprites/bishop_black.png")},
  {PieceType::ROOK, LoadImage("../assets/sprites/rook_black.png")},
  {PieceType::QUEEN, LoadImage("../assets/sprites/queen_black.png")},
  {PieceType::KING, LoadImage("../assets/sprites/king_black.png")},
};

const map<PieceType, Image> whitePiece = {
  {PieceType::PAWN, LoadImage("../assets/sprites/pawn_black.png")},
  {PieceType::KNIGHT, LoadImage("../assets/sprites/knight_black.png")},
  {PieceType::BISHOP, LoadImage("../assets/sprites/bishop_black.png")},
  {PieceType::ROOK, LoadImage("../assets/sprites/rook_black.png")},
  {PieceType::QUEEN, LoadImage("../assets/sprites/queen_black.png")},
  {PieceType::KING, LoadImage("../assets/sprites/king_black.png")},
};



void DrawBoard(Board &board, int initW, int initH) {
  int xShift = initW;
  int yShift = initH;
  auto boardRepr = board.representBoard();
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      if (boardRepr[i][j]) {
        DrawRectangle(xShift, yShift, SQ_SIZE, SQ_SIZE, BOARD_BROWN);
      } else
        DrawRectangle(xShift, yShift, SQ_SIZE, SQ_SIZE, BOARD_LIGHT_BROWN);

      xShift += SQ_SIZE;
    }
    xShift = initW;
    yShift += SQ_SIZE;
  }
}

int main(void) {
  Board board = Board();
  auto boardRepr = board.representBoard();

  const int screenWidth = 800;
  const int screenHeight = 800;

  const int initWidth = screenWidth * 0.25;
  const int initHeight = screenHeight * 0.25;

  InitWindow(screenWidth, screenHeight, "Chess Game");

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second

  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    BeginDrawing();

    ClearBackground(PURPLE);

    DrawBoard(board, initWidth, initHeight);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
