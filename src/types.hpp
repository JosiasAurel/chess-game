#pragma once

#ifndef _TYPES_H_
#define _TYPES_H_

#include <array>
#include <map>
#include <memory>
#include "./constants.hpp"

using std::map, std::array, std::unique_ptr;
using std::max, std::min;


// representing the internal state
class Piece;
using BoardState = array<array<unique_ptr<Piece>, GRID_SIZE>, GRID_SIZE>;

// categorising the pieces
enum class PieceType { PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING };

// represnting the team of a piece
enum class Team { CHESS_WHITE, CHESS_BLACK };

#endif
