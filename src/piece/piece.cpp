#include "./piece.hpp"

unsigned Piece::counter = 1;

bool Piece::move(BoardState boardState, pair<int, int>) {
  bool isValidMove = false;
  // validate move
  if (!isValidMove)
    ; // move

  return isValidMove;
};

vector<pair<int, int>> Pawn::getPossibleMoves(BoardState) {
  vector<pair<int, int>> possibleMoves;
  return possibleMoves;
}

vector<pair<int, int>> Knight::getPossibleMoves(BoardState) {
  vector<pair<int, int>> possibleMoves;
  return possibleMoves;
}

vector<pair<int, int>> Bishop::getPossibleMoves(BoardState) {
  vector<pair<int, int>> possibleMoves;
  return possibleMoves;
}

vector<pair<int, int>> Rook::getPossibleMoves(BoardState) {
  vector<pair<int, int>> possibleMoves;
  return possibleMoves;
}

vector<pair<int, int>> Queen::getPossibleMoves(BoardState) {
  vector<pair<int, int>> possibleMoves;
  return possibleMoves;
}

vector<pair<int, int>> King::getPossibleMoves(BoardState) {
  vector<pair<int, int>> possibleMoves;
  return possibleMoves;
}
