#include "./board.hpp"
#include <iostream>

// using std::cout;
// using std::endl;

Board::Board() {
  //place the the first line of black white pieces
  for(auto &[team, row]: {pair{Team::CHESS_BLACK, 0}, pair{Team::CHESS_WHITE, GRID_SIZE - 1}}){
    boardState[row][0].reset(new Rook({row, 0}, team));
    boardState[row][1].reset(new Knight({row, 1}, team));
    boardState[row][2].reset(new Bishop({row, 2}, team));
    boardState[row][3].reset(new Queen({row, 3}, team));
    boardState[row][4].reset(new King({row, 4}, team));
    boardState[row][5].reset(new Bishop({row, 5}, team));
    boardState[row][6].reset(new Knight({row, 6}, team));
    boardState[row][7].reset(new Rook({row, 7}, team));
  }
  //place the the second line of black white pieces(pawns)
  for(auto &[team, row]: {pair{Team::CHESS_BLACK, 1}, pair{Team::CHESS_WHITE, GRID_SIZE - 2}}){
    for(int column = 0; column < GRID_SIZE; column++)
      boardState[row][column].reset(new Pawn({row, column}, team));
  }
}

Board::~Board() {
  // destroy all piece objects
}
bool Board::movePiece(Coord from, Coord to) {
  // here should be called a piece's move method
  // pair<Piece *, Coord> action = {piece, target};
  // this->history.push_back(action);
  return false;
}

bool Board::ValidateMove(Piece *p, pair<int, int> target) { return false; }

GameState Board::EvaluateGame() { return GameState::CHECKMATE; }

