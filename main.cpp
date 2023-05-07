#include "./src/chess/chess.hpp"
#include <iostream>
#include <memory>


// Load assets

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

void DrawPieces(Board &board, TextureMap &tmap) {
  // auto boardState = board.boardState;
  for (int row = 0; row < GRID_SIZE; row++) {
    for (int col = 0; col < GRID_SIZE; col++) {
      auto piecePtr = board.boardState[row][col].get();

      if (piecePtr == nullptr)
        continue;

      // Draw the moves
      for (auto &result : board.movePath) {
        DrawCircle(MARGIN_X + result.second * CELL_SIZE + (CELL_SIZE / 2),
                   MARGIN_Y + result.first * CELL_SIZE + (CELL_SIZE / 2), 15,
                   PURPLE);
      }
      Texture2D pieceSprite = tmap[piecePtr->getId()];

      // think about layers in case there's a piece at that coordinate
      // draw sprite at center of the cell
      DrawTexture(pieceSprite,
                  MARGIN_X + col * CELL_SIZE + (CELL_SIZE - SPRITE_SIZE) / 2,
                  MARGIN_Y + row * CELL_SIZE + (CELL_SIZE - SPRITE_SIZE) / 2,
                  WHITE);
    }
  }
}

TextureMap BuildTextureMap(Board &board) {
  TextureMap tmap{};

  for (int row = 0; row < GRID_SIZE; row++) {
    for (int col = 0; col < GRID_SIZE; col++) {
      auto piecePtr = board.boardState[row][col].get();

      if (piecePtr == nullptr)
        continue;

      auto teamPieces =
          piecePtr->getTeam() == Team::CHESS_BLACK ? blackPieces : whitePieces;
      auto pieceSprite = ImageCopy(teamPieces[piecePtr->getPieceType()]);
      ImageResize(&pieceSprite, SPRITE_SIZE, SPRITE_SIZE);

      // insert the image texture
      tmap.insert({piecePtr->getId(), LoadTextureFromImage(pieceSprite)});
    }
  }
  return tmap;
}

int main(void) {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Chess Game");

  SetConfigFlags(FLAG_MSAA_4X_HINT);
  SetTargetFPS(60); // Set our game to run at 60 frames-per-second

  ChessGame::getGameInstance()->runGameLoop();

  TextureMap textureMap = BuildTextureMap(board);

  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    BeginDrawing();

    ClearBackground(PURPLE);

    board.DrawBoard();
    // DrawBoard(board);
    DrawPieces(board, textureMap);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
