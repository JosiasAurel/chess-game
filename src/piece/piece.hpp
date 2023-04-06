#include <string>
#include <vector>

using std::string;
using std::pair;
using std::vector;

using Board = int; //defined in board class
typedef enum {WHITE, BLACK} Team;

class Piece{
  private:
    static unsigned counter;
    unsigned id;
    Team team;
    //board coordinates
    pair<int, int> coordinate;
    int x, y;
  public:
  Piece(int x, int y):id (counter++), coordinate({x,y}){}
  Piece(pair<int, int> position):id (counter++), coordinate(position){}
  ~Piece(){}

  int getId(){return id;}
  bool move(Board board, pair<int, int>);
  virtual vector<pair<int, int>> getPossibleMoves(Board) = 0;
    
};

class Pawn: private Piece{
  public:
  Pawn();
  ~Pawn(){};
  vector<pair<int, int>> getPossibleMoves(Board);
};
class Knight: private Piece{
  public:
  Knight();
  ~Knight(){};
  vector<pair<int, int>> getPossibleMoves(Board);
};
class Bishop: private Piece{
  public:
  Bishop();
  ~Bishop(){};
  vector<pair<int, int>> getPossibleMoves(Board);
};
class Rook: private Piece{
  public:
  Rook();
  ~Rook(){};
  vector<pair<int, int>> getPossibleMoves(Board);
};
class King: private Piece{
  public:
  King();
  ~King(){};
  vector<pair<int, int>> getPossibleMoves(Board);
};
class Queen: private Piece{
  public:
  Queen();
  ~Queen(){};
  vector<pair<int, int>> getPossibleMoves(Board);
};