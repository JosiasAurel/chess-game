#include "./board.hpp"

array<array<Piece, 8>, 8> board;

Board::Board() {}
bool Board::move(Piece p, pair<int, int> target) { return false; }

bool Board::ValidateMove(Piece p, pair<int, int> target) { return false; }

GameState Board::EvaluateGame() { return GameState::CHECKMAKE; }