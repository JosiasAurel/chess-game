#pragma once

#ifndef _CHESS_H_
#define _CHESS_H_
#include "../../include/raylib.h"
#include "../board/board.hpp"
#include "../constants.hpp"
#include "../types.hpp"

extern Texture2D pathToTexture(string path);


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
