#include "./piece.hpp"

bool (*cellWithinBounds)(int, int) = [](int x, int y) {
  return (x >= 0 && x < GRID_SIZE) && (y >= 0 && y < GRID_SIZE);
};

unsigned Piece::counter = 1;

// bool Piece::move(, Coord) {
//   bool isValidMove = false;
//   // validate move
//   if (!isValidMove)
//     ; // move

//   return isValidMove;
// };

Pawn::Pawn(Coord coord, Team team)
    : Piece(coord, team, PieceType::PAWN) {}
vector<Coord> Pawn::getPossibleMoves() {
  vector<Coord> possibleMoves;
  // first determine default valid target cells
  // movement of pawn depends on its team
  // asummming here that white is up and black down: ui needs to be aware :-O
  auto [x, y] = this->coordinate;
  int direction = this->team == Team::CHESS_WHITE ? 1 : -1;
  // there are generally 3 directions to move(2 often stale )
  for (int walk : {-1, 0, 1})
    if (cellWithinBounds(x + walk, y + direction))
      possibleMoves.push_back({x + walk, y + direction});
  // and a pawn can move two cells on first move
  if (this->team == Team::CHESS_WHITE && y == 1) // white on first move
    possibleMoves.push_back({x, y + 1});
  if (this->team == Team::CHESS_BLACK &&
      y == GRID_SIZE - 2) // black on first move
    possibleMoves.push_back({x, y - 1});
  return possibleMoves;
}

Knight::Knight(Coord coord, Team team)
    : Piece(coord, team, PieceType::KNIGHT) {}
vector<Coord> Knight::getPossibleMoves() {
  vector<Coord> possibleMoves;
  auto [x, y] = this->coordinate;
  // first determine default valid target cells
  for (int walk : {-2, 2}) {
    for (int turn : {1, -1}) {
      auto [cellXLead, cellYLead] = pair{x + walk, y + turn};
      auto [cellXTrail, cellYTrail] = pair{x + turn, y + walk};

      if (cellWithinBounds(cellXLead, cellYLead))
        possibleMoves.push_back({cellXLead, cellYLead});
      ;
      if (cellWithinBounds(cellXTrail, cellYTrail))
        possibleMoves.push_back({cellXTrail, cellYTrail});
    }
  }
  // then eliminate cells that are stale
  return possibleMoves;
}

Bishop::Bishop(Coord coord, Team team)
    : Piece(coord, team, PieceType::BISHOP) {}
vector<Coord> Bishop::getPossibleMoves() {
  vector<Coord> possibleMoves;
  auto [x, y] = this->coordinate;
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
  return possibleMoves;
}

Rook::Rook(Coord coord, Team team)
    : Piece(coord, team, PieceType::ROOK) {}
vector<Coord> Rook::getPossibleMoves() {
  vector<Coord> possibleMoves;
  auto [x, y] = this->coordinate;
  for (int line = 0; line < GRID_SIZE; line++) {
    possibleMoves.push_back({x, line});
    possibleMoves.push_back({line, y});
  }
  return possibleMoves;
}

Queen::Queen(Coord coord, Team team)
    : Piece(coord, team, PieceType::QUEEN) {}
vector<Coord> Queen::getPossibleMoves() {
  vector<Coord> possibleMoves;
  auto [x, y] = this->coordinate;
  // queen has combineds moves of a rook and bishops
  // incporate moves of rook
  for (int line = 0; line < GRID_SIZE; line++) {
    possibleMoves.push_back({x, line});
    possibleMoves.push_back({line, y});
  }
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
  return possibleMoves;
}

King::King(Coord coord, Team team)
    : Piece(coord, team, PieceType::KING) {}
vector<Coord> King::getPossibleMoves() {
  vector<Coord> possibleMoves;
  auto [x, y] = this->coordinate;
  // first determine default valid target cells
  for (int walkX : {-1, 0, 1}) {
    for (int walkY : {1, 0, -1}) {
      auto [cellX, cellY] = pair{x + walkX, y + walkY};
      if (cellWithinBounds(cellX, cellY) && !(cellX == x && cellY == y))
        possibleMoves.push_back({cellX, cellY});
    }
  }
  // eliminate stale cells here
  return possibleMoves;
}
