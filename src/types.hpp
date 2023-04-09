#pragma once

#include <array>

using std::array;

// size of the chess
const int GRID_SIZE = 8;

// representing the internal state
class Piece;
using BoardState = array<array<Piece *, GRID_SIZE>, GRID_SIZE>;

//categorising the pieces
enum class PieceType{PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING};

// represnting the team of a piece
enum class Team { WHITE, BLACK };


//check if cell coordinates are valid coordinates on the board
auto isValidCell = [](int x, int y) {
  return (x >= 0 && x < GRID_SIZE) && (y >= 0 && y < GRID_SIZE);
};