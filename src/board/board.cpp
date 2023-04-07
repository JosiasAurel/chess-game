#include "./board.hpp"

Board::Board() {
  for(int row = 0; row < GRID_SIZE; row++)
    for(int col = 0; col < GRID_SIZE; col++)
      boardState[row][col] = nullptr;
}

Board::~Board(){
  //destroy all piece objects

}
bool Board::move(Piece* p, pair<int, int> target) { return false; }

bool Board::ValidateMove(Piece* p, pair<int, int> target) { return false; }

GameState Board::EvaluateGame() { return GameState::CHECKMAKE; }