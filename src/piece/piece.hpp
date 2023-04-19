#pragma once

#ifndef _PIECE_H_
#define _PIECE_H_
#include "../types.hpp"
#include <array>
#include <string>
#include <vector>

using std::pair, std::string, std::vector;

using Move = pair<int, int>;

// check if cell coordinates are valid coordinates on the board
extern bool (*cellWithinBounds)(int, int);

class Piece {
protected:
  static unsigned counter;
  unsigned id;

  // BoardState coordinates
  pair<int, int> coordinate;
  Team team;
  PieceType pieceType;

public:
  Piece(pair<int, int> position, Team team, PieceType piece)
      : id(counter++), coordinate(position), team(team), pieceType(piece) {}
  virtual ~Piece(){};

  int getId() { return id; }
  Team  getTeam(){return team; }
  PieceType getPieceType(){return pieceType;}
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
#endif
