#include "./board.hpp"
#include <iostream>

// using std::cout;
// using std::endl;

Board::Board() {
  for (int row = 0; row < GRID_SIZE; row++)
    for (int col = 0; col < GRID_SIZE; col++)
      boardState[row][col] = nullptr;
}

Board::~Board() {
  // destroy all piece objects
}
bool Board::move(Piece *piece, pair<int, int> target) {
  pair<Piece *, Move> action = {piece, target};
  this->history.push_back(action);
  return false;
}

bool Board::ValidateMove(Piece *p, pair<int, int> target) { return false; }

GameState Board::EvaluateGame() { return GameState::CHECKMAKE; }

array<array<int, GRID_SIZE>, GRID_SIZE> Board::representBoard() {
  bool black = false;
  array<array<int, GRID_SIZE>, GRID_SIZE> boardRepr{};
  int squareCount = 1;
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      boardRepr[i][j] = black;
      black = black == true ? false : true;
      squareCount++;
    }
    black = !black;
  }

  return boardRepr;
}
