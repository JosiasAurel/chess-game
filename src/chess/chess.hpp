#pragma once

#ifndef _CHESS_H_
#define _CHESS_H_
#include "../../include/raylib.h"
#include "../board/board.hpp"
#include "../constants.hpp"
#include "../types.hpp"

const map<PieceType, Image> BLACK_SPRITES = {
  {PieceType::PAWN, LoadImage("./assets/sprites/pawn_black.png")},
  {PieceType::KNIGHT, LoadImage("./assets/sprites/knight_black.png")},
  {PieceType::BISHOP, LoadImage("./assets/sprites/bishop_black.png")},
  {PieceType::ROOK, LoadImage("./assets/sprites/rook_black.png")},
  {PieceType::QUEEN, LoadImage("./assets/sprites/queen_black.png")},
  {PieceType::KING, LoadImage("./assets/sprites/king_black.png")},
};

const map<PieceType, Image> WHITE_SPRITES = {
  {PieceType::PAWN, LoadImage("./assets/sprites/pawn_white.png")},
  {PieceType::KNIGHT, LoadImage("./assets/sprites/knight_white.png")},
  {PieceType::BISHOP, LoadImage("./assets/sprites/bishop_white.png")},
  {PieceType::ROOK, LoadImage("./assets/sprites/rook_white.png")},
  {PieceType::QUEEN, LoadImage("./assets/sprites/queen_white.png")},
  {PieceType::KING, LoadImage("./assets/sprites/king_white.png")},
};

class ChessGame {
  private:
    static shared_ptr<ChessGame> gameInstance;

    Board chessBoard;
    Coord lastMouseClickCoord, currentMouseCoord;
    ChessGame();
    Coord mapIndicesToCoord(int x, int y){return mapIndicesToCoord(pair{x, y});}
    Coord mapIndicesToCoord(Coord );
  public:
    ChessGame(const ChessGame& )= delete; //delete copy constructor
    static shared_ptr<ChessGame> getGameInstance();
    void highlightPiece(Coord, HighlightLevel , bool);
    void drawBoard();
    void drawSprites();
    void updateScreen();
    void runGameLoop();
    ~ChessGame();
};


#endif
