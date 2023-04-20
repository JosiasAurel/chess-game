#pragma once

#ifndef _TYPES_H_
#define _TYPES_H_

#include <array>
#include <map>
#include <memory>
#include "./constants.hpp"

using std::map, std::pair, std::array, std::unique_ptr, std::shared_ptr;
using std::max, std::min;


// representing a chess piece
class Piece;

//reprsenting a 2-D coordinate
using Coord = pair<int, int>;

//represent internal state of the board
using BoardState = array<array<unique_ptr<Piece>, GRID_SIZE>, GRID_SIZE>;

// categorising the pieces
enum class PieceType { PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING };

// representing the team of a piece
enum class Team { CHESS_WHITE, CHESS_BLACK };

//  reprenting severity? of highlight
enum class HighlightLevel{
  INFO,
  WARNING,
  DANGER,
};

#endif
