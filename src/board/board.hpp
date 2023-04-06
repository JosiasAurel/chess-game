#include <array>
#include <type_traits>
#include <utility>

using std::array;
using std::pair;

using Piece = int;

extern array<array<Piece, 8>, 8> board;

typedef enum { DRAW, CHECKMAKE, UNFINISHED } GameState;

class Board {
public:
  Board();
  ~Board();

  // validates a move before taking action
  // returns false if the move attempt fails
  bool move(Piece, pair<int, int>);

private:
  array<array<Piece, 8>, 8> board;

  // a move is valid if the current instance of Piece
  // is able to move at the target position based on his current positon
  // if it is not beyond the bounds of the board
  bool ValidateMove(Piece, pair<int, int>);

  GameState EvaluateGame();
};
