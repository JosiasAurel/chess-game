#include "./piece.hpp"

bool (*cellWithinBounds)(int, int) = [](int x, int y) {
  return (x >= 0 && x < GRID_SIZE) && (y >= 0 && y < GRID_SIZE);
};

unsigned Piece::counter = 1;

bool Piece::move(BoardState boardState, pair<int, int>) {
  bool isValidMove = false;
  // validate move
  if (!isValidMove)
    ; // move

  this->counter++;
  return isValidMove;
};

NoPiece::NoPiece(pair<int, int> coord, Team team)
    : Piece(coord, team, PieceType::NO_PIECE) {}

// No possible moves
Path NoPiece::getPossibleMoves(BoardState boardState) {
  Path possibleMoves;
  return possibleMoves;
}

Pawn::Pawn(pair<int, int> coord, Team team)
    : Piece(coord, team, PieceType::PAWN) {}

/*
In the case of the pawn, orientation matters very much
compared to any other piece.
Pawn moves one square ahead (or two squares if it's the first move)
It can move one square on the left or right diagonal
iff there is an opponent piece on there

Takes in BoardState and returns a Path

TODO: Validation
*/
Path Pawn::getPossibleMoves(BoardState boardState) {
  Path possibleMoves;

  // first determine default valid target cells
  // movement of pawn depends on its team
  // asummming here that white is up and black down: ui needs to be aware :-O
  auto [y, x] = this->coordinate;

  // direction
  // a value of 1 means the pawn is up (and Team Black)
  // otherwise the pawn is down (and Team White)
  int direction = this->team == Team::CHESS_BLACK ? 1 : -1;

  // there are generally 3 directions to move(2 often stale )
  for (int walk : {-1, 0, 1})
    if (cellWithinBounds(x + direction, y + walk)) {
      // logging point change
      possibleMoves.insert({x + direction, y + walk});
    }

  if (this->moveCount == 0) {
    int increment = this->team == Team::CHESS_BLACK ? 1 : -1;
    possibleMoves.insert({x + increment * 2, y});
  }

  this->moveCount++;
  return possibleMoves;
}

Knight::Knight(pair<int, int> coord, Team team)
    : Piece(coord, team, PieceType::KNIGHT) {}

/*
Knight moves in an L shape regardless of the direction
Moves in an L-shape
i.e
- two squares forward and one to the left
- two squares forward and one to the right
- two squares left and one forward
- two squares right and one forward
- *same for backward

TODO: Validation
*/
Path Knight::getPossibleMoves(BoardState boardState) {
  Path possibleMoves;

  auto [x, y] = this->coordinate;

  // first determine default valid target cells
  for (int walk : {-2, 2}) {
    for (int turn : {1, -1}) {

      // two squares left/right and one forward/backward
      auto [cellXLead, cellYLead] = pair{x + walk, y + turn};

      // one square left/right and two squares forward/backward
      auto [cellXTrail, cellYTrail] = pair{x + turn, y + walk};

      if (cellWithinBounds(cellXLead, cellYLead))
        possibleMoves.insert({cellXLead, cellYLead});

      if (cellWithinBounds(cellXTrail, cellYTrail))
        possibleMoves.insert({cellXTrail, cellYTrail});
    }
  }

  this->moveCount++;
  return possibleMoves;
}

Bishop::Bishop(pair<int, int> coord, Team team)
    : Piece(coord, team, PieceType::BISHOP) {}

/*
Bishop moves on left/right diagonal
until it reaches the end of the board/obstacle

TODO: Validation
*/
Path Bishop::getPossibleMoves(BoardState boardState) {
  Path possibleMoves;

  auto [x, y] = this->coordinate;
  Path pathDiffs{
      {1, 1},   // move diangonally downward to right
      {-1, 1},  // move diagonally downward to left
      {-1, -1}, // move diagonally upward to left
      {1, -1}   // move diagonally upward to right
  };

  for (auto &diff : pathDiffs) {
    Position position = {x, y};
    while (cellWithinBounds(position.first + diff.first,
                            position.second + diff.second)) {
      position.first += diff.first;
      position.second += diff.second;
      possibleMoves.insert(position);
    }
  }

  /*
  // first determine default valid target cells
  // start with leading diagonal
  for (int minIndex = min(x, y), cellX = x - minIndex, cellY = y - minIndex;
       cellX < GRID_SIZE && cellY < GRID_SIZE; cellX++, cellY++)
    possibleMoves.push_back({cellX, cellY});

  // then go to alternate diagonal
  for (int walk : {-1, 1}) {
    auto [cellX, cellY] = pair{x + walk, y - walk};
    while (cellWithinBounds(cellX, cellY)) {
      possibleMoves.push_back({cellX, cellY});
      cellX += walk;
      cellY -= walk;
    }
  }
  // then eliminate cells that are stale
  */
  return possibleMoves;
}

/*
Rook moves in a path so as to draw a + sign wherever it is found

TODO: Validation
*/
Rook::Rook(pair<int, int> coord, Team team)
    : Piece(coord, team, PieceType::ROOK) {}

Path Rook::getPossibleMoves(BoardState boardState) {
  Path possibleMoves;
  auto [x, y] = this->coordinate;

  for (int line = 0; line < GRID_SIZE; line++) {
    possibleMoves.insert({x, line});
    possibleMoves.insert({line, y});
  }

  return possibleMoves;
}

Queen::Queen(pair<int, int> coord, Team team)
    : Piece(coord, team, PieceType::QUEEN) {}

/*
Queen moves such that it forms a path in the form of a
+ sign
x -> two diagonals like a bishop
*/
Path Queen::getPossibleMoves(BoardState boardState) {
  Path possibleMoves;
  auto [x, y] = this->coordinate;

  Path pathDiffs{
      {1, 1},   // move diangonally downward to right
      {-1, 1},  // move diagonally downward to left
      {-1, -1}, // move diagonally upward to left
      {1, -1}   // move diagonally upward to right
  };

  for (auto &diff : pathDiffs) {
    Position position = {x, y};
    while (cellWithinBounds(position.first + diff.first,
                            position.second + diff.second)) {
      position.first += diff.first;
      position.second += diff.second;
      possibleMoves.insert(position);
    }
  }

  // queen has combineds moves of a rook and bishops
  // incporate moves of rook
  for (int line = 0; line < GRID_SIZE; line++) {
    possibleMoves.insert({x, line});
    possibleMoves.insert({line, y});
  }

  /*
  // incoporate movements of bishop
  // start with leading diagonal
  for (int minIndex = min(x, y), cellX = x - minIndex, cellY = y - minIndex;
       cellX < GRID_SIZE && cellY < GRID_SIZE; cellX++, cellY++)
    possibleMoves.push_back({cellX, cellY});

  // then go to alternate diagonal
  for (int walk : {-1, 1}) {
    auto [cellX, cellY] = pair{x + walk, y - walk};
    while (cellWithinBounds(cellX, cellY)) {
      possibleMoves.push_back({cellX, cellY});
      cellX += walk;
      cellY -= walk;
    }
  }
  */

  return possibleMoves;
}

King::King(pair<int, int> coord, Team team)
    : Piece(coord, team, PieceType::KING) {}

/*
Moves one square around itself

TODO: Validation
*/
Path King::getPossibleMoves(BoardState boardState) {
  Path possibleMoves;
  auto [x, y] = this->coordinate;

  // first determine default valid target cells
  for (int walkX : {-1, 0, 1}) {
    for (int walkY : {1, 0, -1}) {
      auto [cellX, cellY] = pair{x + walkX, y + walkY};

      if (cellWithinBounds(cellX, cellY) && !(cellX == x && cellY == y))
        possibleMoves.insert({cellX, cellY});
    }
  }

  // eliminate stale cells here
  return possibleMoves;
}
