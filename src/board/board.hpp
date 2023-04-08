#pragma once

#include "../piece/piece.hpp"
#include "../types.hpp"
#include <array>
#include <type_traits>
#include <utility>

using std::array;
using std::pair;

// STALEMATE -> when the game is a draw because one of the players can no longer
// move CHECKMAKE -> A player has CHECKMAKEd their opponent RESIGNED -> when a
// A player resigns in the game
// ONGOING -> The game is ongoing
typedef enum { STALEMATE, CHECKMAKE, RESIGNED, ONGOING } GameState;

class Board {
public:
  BoardState boardState;

public:
  Board();
  ~Board();

  // validates a move before taking action
  // returns false if the move attempt fails
  bool move(Piece *, pair<int, int>);
  void printBoard();

public:
  // a move is valid if the current instance of Piece
  // is able to move at the target position based on his current positon
  // if it is not beyond the bounds of the board
  bool ValidateMove(Piece *, pair<int, int>);

  GameState EvaluateGame();
};
