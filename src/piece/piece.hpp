#pragma once

#include "../types.hpp"
#include <array>
#include <string>
#include <vector>

using std::pair;
using std::string;
using std::vector;

using std::max;
using std::min;

using Move = pair<int, int>;

class Piece {
protected:
  static unsigned counter;
  vector<Move> history;

  unsigned id;
  Team team;
  PieceType pieceType;
  // BoardState coordinates
  pair<int, int> coordinate;

  void registerMove(Move move) { history.push_back(move); }

public:
  Piece(pair<int, int> position, Team team, PieceType piece)
      : id(counter++), coordinate(position), team(team), pieceType(piece) {}
  ~Piece();

  int getId() { return id; }
  bool move(BoardState, pair<int, int>);
  virtual vector<pair<int, int>> getPossibleMoves(BoardState) = 0;
};

class Pawn : public Piece {
public:
  Pawn(pair<int, int> coord, Team team);
  ~Pawn(){};
  vector<pair<int, int>> getPossibleMoves(BoardState);
};

class Knight : public Piece {
public:
  Knight(pair<int, int> coord, Team team);
  ~Knight(){};
  vector<pair<int, int>> getPossibleMoves(BoardState);
};

class Bishop : public Piece {
public:
  Bishop(pair<int, int> coord, Team team);
  ~Bishop(){};
  vector<pair<int, int>> getPossibleMoves(BoardState);
};

class Rook : public Piece {
public:
  Rook(pair<int, int> coord, Team team);
  ~Rook(){};
  vector<pair<int, int>> getPossibleMoves(BoardState);
};

class King : public Piece {
public:
  King(pair<int, int> coord, Team team);
  ~King(){};
  vector<pair<int, int>> getPossibleMoves(BoardState);
};

class Queen : public Piece {
public:
  Queen(pair<int, int> coord, Team team);
  ~Queen(){};
  vector<pair<int, int>> getPossibleMoves(BoardState);
};
