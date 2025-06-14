#pragma once

#ifndef _CHESS_H_
#define _CHESS_H_
#include "../../include/raylib.h"
#include "../board/board.hpp"
#include "../constants.hpp"
#include "../types.hpp"

extern Texture2D pathToTexture(string path);
extern void processTextures();

class ChessGame {
  private:
    static shared_ptr<ChessGame> gameInstance;

    Team teamTurn = Team::CHESS_WHITE;
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
    void loadAndPrepareAssets();
    void runGameLoop();
    ~ChessGame();
};


#endif
