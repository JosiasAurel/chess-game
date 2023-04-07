#pragma once

#include "../types.hpp"
#include <array>
#include <string>
#include <vector>

using std::pair;
using std::string;
using std::vector;

class Piece {
protected:
  static unsigned counter;
  unsigned id;
  Team team;
  // BoardState coordinates
  pair<int, int> coordinate;

public:
  Piece(pair<int, int> position, Team side)
      : id(counter++), coordinate(position), team(side) {}
  ~Piece();

  int getId() { return id; }
  bool move(BoardState, pair<int, int>);
  virtual vector<pair<int, int>> getPossibleMoves(BoardState) = 0;
};

class Pawn : public Piece {
public:
  Pawn();
  ~Pawn(){};
  vector<pair<int, int>> getPossibleMoves(BoardState);
};

class Knight : public Piece {
public:
  Knight();
  ~Knight(){};
  vector<pair<int, int>> getPossibleMoves(BoardState);
};

class Bishop : public Piece {
public:
  Bishop();
  ~Bishop(){};
  vector<pair<int, int>> getPossibleMoves(BoardState);
};

class Rook : public Piece {
public:
  Rook();
  ~Rook(){};
  vector<pair<int, int>> getPossibleMoves(BoardState);
};

class King : public Piece {
public:
  King();
  ~King(){};
  vector<pair<int, int>> getPossibleMoves(BoardState);
};

class Queen : public Piece {
public:
  Queen();
  ~Queen(){};
  vector<pair<int, int>> getPossibleMoves(BoardState);
};