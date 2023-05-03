#pragma once

#ifndef _PIECE_H_
#define _PIECE_H_
#include "../types.hpp"
#include <array>
#include <string>
#include <vector>

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
  unsigned moveCount = 0;

public:
  Piece(pair<int, int> position, Team team, PieceType piece)
      : id(counter++), coordinate(position), team(team), pieceType(piece) {}
  virtual ~Piece(){};

  int getId() { return id; }
  Team getTeam() { return team; }
  PieceType getPieceType() { return pieceType; }
  bool move(BoardState, pair<int, int>);
  virtual Path getPossibleMoves(BoardState) = 0;
};

/*
Moves one square ahead all the time
May move two squares on the first move
Can move one unit on left or right diagonal if there's an enemy piece
*/
class Pawn : public Piece {
public:
  Pawn(pair<int, int> coord, Team team);
  ~Pawn(){};
  Path getPossibleMoves(BoardState);
};

/*
Moves such that it forms an L-shape
Must land on the last square that contitutes the L
Cannot move in a certain L-shape if there is a piece on one the path
*/
class Knight : public Piece {
public:
  Knight(pair<int, int> coord, Team team);
  ~Knight(){};
  Path getPossibleMoves(BoardState);
};

/*
Moves along the path of a cross
Diagonal left extending forward and backward
Diagonal right extending forward and backward
*/
class Bishop : public Piece {
public:
  Bishop(pair<int, int> coord, Team team);
  ~Bishop(){};
  Path getPossibleMoves(BoardState);
  Path getMoves();
};

/*
Moves so as to form a plus sign (both forward and backward)
*/
class Rook : public Piece {
public:
  Rook(pair<int, int> coord, Team team);
  ~Rook(){};
  Path getPossibleMoves(BoardState);
};

/*
Moves at most one square in all directions
*/
class King : public Piece {
public:
  King(pair<int, int> coord, Team team);
  ~King(){};
  Path getPossibleMoves(BoardState);
};

/*
Moves along a path that is a combination of a plus and an X sign
i.e like a Rook and bishop combined
*/
class Queen : public Piece {
public:
  Queen(pair<int, int> coord, Team team);
  ~Queen(){};
  Path getPossibleMoves(BoardState);
};
#endif
