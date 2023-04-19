#include "./include/raylib.h"
#include "./src/board/board.hpp"
#include "./src/constants.hpp"
#include "src/types.hpp"
#include <iostream>

#define SQ_SIZE 60

// using std::cout;
// using std::endl;

//Load assets

const map<PieceType, Image> blackPieces = {
  {PieceType::PAWN, LoadImage("./assets/sprites/pawn_black.png")},
  {PieceType::KNIGHT, LoadImage("./assets/sprites/knight_black.png")},
  {PieceType::BISHOP, LoadImage("./assets/sprites/bishop_black.png")},
  {PieceType::ROOK, LoadImage("./assets/sprites/rook_black.png")},
  {PieceType::QUEEN, LoadImage("./assets/sprites/queen_black.png")},
  {PieceType::KING, LoadImage("./assets/sprites/king_black.png")},
};

const map<PieceType, Image> whitePieces = {
  {PieceType::PAWN, LoadImage("./assets/sprites/pawn_white.png")},
  {PieceType::KNIGHT, LoadImage("./assets/sprites/knight_white.png")},
  {PieceType::BISHOP, LoadImage("./assets/sprites/bishop_white.png")},
  {PieceType::ROOK, LoadImage("./assets/sprites/rook_white.png")},
  {PieceType::QUEEN, LoadImage("./assets/sprites/queen_white.png")},
  {PieceType::KING, LoadImage("./assets/sprites/king_white.png")},
};



void DrawBoard(Board &board) {
  auto boardRepr = board.representBoard();
  //since objects of `Color` don't have a == operator
  //use 0 for DEEP_BROWN and 1 for light BROWN
  auto color = pair{0, DEEP_BROWN}; 
  for (int row = 0; row < GRID_SIZE; row++) {
    color = color.first  == 0  ? pair{1, LIGHT_BROWN} : pair{0, DEEP_BROWN};
    for (int col = 0; col < GRID_SIZE; col++) {
      if((col % 2) == 0)
        DrawRectangle(MARGIN_X + col * CELL_SIZE, MARGIN_Y + row * CELL_SIZE,
                      CELL_SIZE, CELL_SIZE, color.second);
      else
        DrawRectangle(MARGIN_X + col * CELL_SIZE, MARGIN_Y + row * CELL_SIZE,
                      CELL_SIZE, CELL_SIZE, color.second);
      color = color.first  == 0  ? pair{1, LIGHT_BROWN} : pair{0, DEEP_BROWN};
    }
  }
}

void DrawPieces(Board &board) {
  // auto boardState = board.boardState;
  for (int row = 0; row < GRID_SIZE; row++) {
    for (int col = 0; col < GRID_SIZE; col++) {
      auto piecePtr = board.boardState[row][col].get(); 
      if (piecePtr == nullptr)
        continue;
      auto teamPieces = piecePtr->getTeam() == Team::CHESS_BLACK ?
                        blackPieces : whitePieces;
      auto pieceSprite = ImageCopy(teamPieces[piecePtr->getPieceType()]);
      ImageResize(&pieceSprite, SPRITE_SIZE, SPRITE_SIZE);

      //draw sprite at center of the cell
      DrawTexture(LoadTextureFromImage(pieceSprite), 
                  MARGIN_X + col * CELL_SIZE + (CELL_SIZE - SPRITE_SIZE) / 2, 
                  MARGIN_Y + row * CELL_SIZE + (CELL_SIZE - SPRITE_SIZE) / 2, WHITE);
    }
  }
}


int main(void) {
  Board board = Board();
  auto boardRepr = board.representBoard();

  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Chess Game");

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second

  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    BeginDrawing();

    ClearBackground(PURPLE);

    DrawBoard(board);
    DrawPieces(board);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
