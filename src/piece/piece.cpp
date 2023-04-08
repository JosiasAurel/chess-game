#include "./piece.hpp"

unsigned Piece::counter = 1;

bool Piece::move(BoardState boardState, pair<int, int>) {
  bool isValidMove = false;
  // validate move
  if (!isValidMove)
    ; // move

  return isValidMove;
};

Pawn::Pawn(pair<int, int> coord, Team team) : Piece(coord, team) {}
vector<pair<int, int>> Pawn::getPossibleMoves(BoardState) {
  vector<pair<int, int>> possibleMoves;
  return possibleMoves;
}

Knight::Knight(pair<int, int> coord, Team team) : Piece(coord, team) {}
vector<pair<int, int>> Knight::getPossibleMoves(BoardState) {
  vector<pair<int, int>> possibleMoves;
  return possibleMoves;
}

Bishop::Bishop(pair<int, int> coord, Team team) : Piece(coord, team) {}
vector<pair<int, int>> Bishop::getPossibleMoves(BoardState) {
  vector<pair<int, int>> possibleMoves;
  return possibleMoves;
}

Rook::Rook(pair<int, int> coord, Team team) : Piece(coord, team) {}
vector<pair<int, int>> Rook::getPossibleMoves(BoardState) {
  vector<pair<int, int>> possibleMoves;
  return possibleMoves;
}

Queen::Queen(pair<int, int> coord, Team team) : Piece(coord, team) {}
vector<pair<int, int>> Queen::getPossibleMoves(BoardState) {
  vector<pair<int, int>> possibleMoves;
  auto [x, y] = this->coordinate;

  return possibleMoves;
}

King::King(pair<int, int> coord, Team team) : Piece(coord, team) {}
vector<pair<int, int>> King::getPossibleMoves(BoardState state) {
  vector<pair<int, int>> possibleMoves;
  return possibleMoves;
}
