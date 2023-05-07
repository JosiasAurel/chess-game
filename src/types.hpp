#pragma once

#ifndef _TYPES_H_
#define _TYPES_H_

#include "../include/raylib.h"
#include "./constants.hpp"
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

using std::map, std::pair, std::array, std::unique_ptr, std::shared_ptr;
using std::bitset;
using std::make_shared, std::shared_ptr;
using std::map, std::array, std::unique_ptr, std::make_unique;
using std::max, std::min;
using std::pair;
using std::set;
using std::string;
using std::vector;

// representing a chess piece
class Piece;

//reprsenting a 2-D coordinate
using Coord = pair<int, int>;

//represent internal state of the board
using BoardState = array<array<shared_ptr<Piece>, GRID_SIZE>, GRID_SIZE>;
using TextureMap = map<int, Texture2D>;
using Move = pair<int, int>;
using Position = pair<int, int>;
using Path = set<pair<int, int>>;

// categorising the pieces
enum class PieceType { PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING, NO_PIECE };

// representing the team of a piece
enum class Team { CHESS_WHITE, CHESS_BLACK };

//  reprenting severity? of highlight
enum class HighlightLevel{
  INFO,
  WARNING,
  DANGER,
};

// pardon me std::cout too long UwU
inline void logMsg(string msg) { std::cout << msg << std::endl; }

#endif
