#include "../types.hpp"
#include <string>
#include <vector>
#include <array>

using std::string;
using std::pair;
using std::vector;
using std::array;

class Piece{
  private:
    static unsigned counter;
    unsigned id;
    Team team;
    //BoardState coordinates
    pair<int, int> coordinate;
    
  public:
  Piece(pair<int, int> position, Team side):
    id (counter++), coordinate(position),team(side) {}
  ~Piece();

  int getId(){return id;}
  bool move(BoardState, pair<int, int>);
  virtual vector<pair<int, int>> getPossibleMoves(BoardState)=0;
    
};

class Pawn: private Piece{
  public:
  Pawn();
  ~Pawn(){};
  vector<pair<int, int>> getPossibleMoves(BoardState);
};
class Knight: private Piece{
  public:
  Knight();
  ~Knight(){};
  vector<pair<int, int>> getPossibleMoves(BoardState);
};
class Bishop: private Piece{
  public:
  Bishop();
  ~Bishop(){};
  vector<pair<int, int>> getPossibleMoves(BoardState);
};
class Rook: private Piece{
  public:
  Rook();
  ~Rook(){};
  vector<pair<int, int>> getPossibleMoves(BoardState);
};
class King: private Piece{
  public:
  King();
  ~King(){};
  vector<pair<int, int>> getPossibleMoves(BoardState);
};
class Queen: private Piece{
  public:
  Queen();
  ~Queen(){};
  vector<pair<int, int>> getPossibleMoves(BoardState);
};