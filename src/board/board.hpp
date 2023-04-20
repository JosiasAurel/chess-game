#pragma once

#ifndef _BOARD_H_
#define _BOARD_H_
#include "../piece/piece.hpp"
#include <array>
#include <utility>

using std::array, std::pair;

// STALEMATE -> when the game is a draw because one of the players can no longer move 
// CHECKMATE -> A player has CHECKMATEd their opponent 
// RESIGNED  -> A player resigns in the game
// ONGOING   -> The game is ongoing
typedef enum { STALEMATE, CHECKMATE, RESIGNED, ONGOING } GameState;

class Board {
public:
  BoardState boardState;

protected:
  vector<pair<Piece *, Coord>> history;

public:
  Board();
  ~Board();

  // validates a move before taking action
  // returns false if the move attempt fails
  bool movePiece(Coord, Coord);

public:
  // a move is valid if the current instance of Piece
  // is able to move at the target position based on his current positon
  // if it is not beyond the bounds of the board
  bool ValidateMove(Piece *, Coord);

  GameState EvaluateGame();
};

#endif
