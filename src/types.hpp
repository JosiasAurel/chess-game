#pragma once

#include <array>

using std::array;

// size of the chess
const int GRID_SIZE = 8;

// representing the internal state
class Piece;
using BoardState = array<array<Piece *, GRID_SIZE>, GRID_SIZE>;

// represnting the team of a piece
typedef enum { WHITE, BLACK } Team;
