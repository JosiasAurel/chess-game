#include "./board.hpp"
#include "../types.hpp"
#include <cstdio>
#include <iostream>

// using std::cout;
// using std::endl;

Board::Board() {

  // place the the first line of black white pieces
  for (auto &[team, row] :
       {pair{Team::CHESS_BLACK, 0}, pair{Team::CHESS_WHITE, GRID_SIZE - 1}}) {

    boardState[row][0].reset(new Rook({row, 0}, team));
    boardState[row][1].reset(new Knight({row, 1}, team));
    boardState[row][2].reset(new Bishop({row, 2}, team));
    boardState[row][3].reset(new Queen({row, 3}, team));
    boardState[row][4].reset(new King({row, 4}, team));
    boardState[row][5].reset(new Bishop({row, 5}, team));
    boardState[row][6].reset(new Knight({row, 6}, team));
    boardState[row][7].reset(new Rook({row, 7}, team));
  }

  // place the the second line of black white pieces(pawns)
  for (auto &[team, row] :
       {pair{Team::CHESS_BLACK, 1}, pair{Team::CHESS_WHITE, GRID_SIZE - 2}}) {
    for (int column = 0; column < GRID_SIZE; column++)
      boardState[row][column].reset(new Pawn({row, column}, team));
  }
}

Board::~Board() {
  // TODO: destroy all piece objects
}
bool Board::move(Piece *piece, pair<int, int> target) {
  // here should be called a piece's move method
  pair<Piece *, Move> action = {piece, target};
  this->history.push_back(action);
  return false;
}

bool Board::ValidateMove(Piece *p, pair<int, int> target) { return false; }

GameState Board::EvaluateGame() { return GameState::CHECKMATE; }

void Board::DrawBoard() {

  // since objects of `Color` don't have a == operator
  // use 0 for DEEP_BROWN and 1 for light BROWN
  auto color = pair{0, DEEP_BROWN};
  for (int row = 0; row < GRID_SIZE; row++) {

    color = color.first == 0 ? pair{1, LIGHT_BROWN} : pair{0, DEEP_BROWN};

    for (int col = 0; col < GRID_SIZE; col++) {
      Rectangle rect = {.x = static_cast<float>(MARGIN_X + col * CELL_SIZE),
                        .y = static_cast<float>(MARGIN_Y + row * CELL_SIZE),
                        .width = CELL_SIZE,
                        .height = CELL_SIZE};
      if ((col % 2) == 0)
        DrawRectangleRec(rect, color.second);
      else
        DrawRectangleRec(rect, color.second);
      color = color.first == 0 ? pair{1, LIGHT_BROWN} : pair{0, DEEP_BROWN};

      // find out if there's a piece at this point
      // this block is temporary
      // should be well organised later to make navigating the code clearer
      auto piecePtr = this->boardState[row][col].get();
      if (piecePtr != nullptr) {
        if (CheckCollisionPointRec(GetMousePosition(), rect) &&
            IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
          Position p{row, col};
          this->BuildPiecePath(*piecePtr, p);
        }
      }
    }
  }
}

void Board::BuildPiecePath(Piece &piece, Position &position) {

  switch (piece.getPieceType()) {
  case PieceType::PAWN: {
    logMsg("pawn here");
    break;
  }
  case PieceType::ROOK: {
    logMsg("rook here");
    break;
  }
  case PieceType::KNIGHT: {
    logMsg("knight here");
    break;
  }
  case PieceType::BISHOP: {
    logMsg("bishop here");
    break;
  }
  case PieceType::KING: {
    logMsg("king here");
    break;
  }
  case PieceType::QUEEN: {
    logMsg("queen here");
    break;
  }
  }
  // nothing here
  // to talk about
}