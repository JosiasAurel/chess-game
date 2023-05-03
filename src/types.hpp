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

using std::bitset;
using std::make_shared, std::shared_ptr;
using std::map, std::array, std::unique_ptr, std::make_unique;
using std::max, std::min;
using std::pair;
using std::set;
using std::string;
using std::vector;

// representing the internal state
class Piece;
using BoardState = array<array<shared_ptr<Piece>, GRID_SIZE>, GRID_SIZE>;
using TextureMap = map<int, Texture2D>;
using Move = pair<int, int>;
using Position = pair<int, int>;
using Path = set<pair<int, int>>;

// categorising the pieces
enum class PieceType { PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING, NO_PIECE };

// represnting the team of a piece
enum class Team { CHESS_WHITE, CHESS_BLACK };

// pardon me std::cout too long UwU
inline void logMsg(string msg) { std::cout << msg << std::endl; }

#endif
