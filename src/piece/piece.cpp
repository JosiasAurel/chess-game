#include "./piece.hpp"

unsigned Piece::counter = 1;

bool Piece::move(Board board, pair<int, int>){
    bool isValidMove = false;
    //validate move
    if(!isValidMove) ;//move

    return isValidMove;
  };


vector<pair<int, int>> Pawn::getPossibleMoves(Board){
  vector<pair<int, int>> possibleMoves;
  return possibleMoves;
}


vector<pair<int, int>> Knight::getPossibleMoves(Board){
  vector<pair<int, int>> possibleMoves;
  return possibleMoves;
}


vector<pair<int, int>> Bishop::getPossibleMoves(Board){
  vector<pair<int, int>> possibleMoves;
  return possibleMoves;
}

vector<pair<int, int>> Rook::getPossibleMoves(Board){
  vector<pair<int, int>> possibleMoves;
  return possibleMoves;
}


vector<pair<int, int>> Queen::getPossibleMoves(Board){
  vector<pair<int, int>> possibleMoves;
  return possibleMoves;
}


vector<pair<int, int>> King::getPossibleMoves(Board){
  vector<pair<int, int>> possibleMoves;
  return possibleMoves;
}

