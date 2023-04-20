#pragma once

#ifndef _PIECE_H_
#define _PIECE_H_
#include "../types.hpp"
#include <array>
#include <string>
#include <vector>

using std::pair, std::string, std::vector;

// check if cell coordinates are valid coordinates on the board
extern bool (*cellWithinBounds)(int, int);

class Piece {
protected:
  static unsigned counter;
  unsigned id;

  //  coordinates
  Coord coordinate;
  Team team;
  PieceType pieceType;

public:
  Piece(Coord position, Team team, PieceType piece)
      : id(counter++), coordinate(position), team(team), pieceType(piece) {}
  virtual ~Piece(){};

  int getId() { return id; }
  Team  getTeam(){return team; }
  PieceType getPieceType(){return pieceType;}
  // bool move(, Coord);
  virtual vector<Coord> getPossibleMoves() = 0;
};

class Pawn : public Piece {
public:
  Pawn(Coord coord, Team team);
  ~Pawn(){};
  vector<Coord> getPossibleMoves();
};

class Knight : public Piece {
public:
  Knight(Coord coord, Team team);
  ~Knight(){};
  vector<Coord> getPossibleMoves();
};

class Bishop : public Piece {
public:
  Bishop(Coord coord, Team team);
  ~Bishop(){};
  vector<Coord> getPossibleMoves();
};

class Rook : public Piece {
public:
  Rook(Coord coord, Team team);
  ~Rook(){};
  vector<Coord> getPossibleMoves();
};

class King : public Piece {
public:
  King(Coord coord, Team team);
  ~King(){};
  vector<Coord> getPossibleMoves();
};

class Queen : public Piece {
public:
  Queen(Coord coord, Team team);
  ~Queen(){};
  vector<Coord> getPossibleMoves();
};
#endif
