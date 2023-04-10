#pragma once

#ifndef _TYPES_H_
#define _TYPES_H_

#include <array>

using std::array;
using std::max;
using std::min;

// size of the chess
const int GRID_SIZE = 8;

// representing the internal state
class Piece;
using BoardState = array<array<Piece *, GRID_SIZE>, GRID_SIZE>;
using BoardRepr = array<array<int, GRID_SIZE>, GRID_SIZE>;

// categorising the pieces
enum class PieceType { PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING };

// represnting the team of a piece
enum class Team { CHESS_WHITE, CHESS_BLACK };

#endif
