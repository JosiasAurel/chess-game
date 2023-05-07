#include "./chess.hpp"
#include <iostream>

shared_ptr<ChessGame> ChessGame::gameInstance(nullptr);

ChessGame::ChessGame():chessBoard(Board()){
  // for (auto &[key, value] : WHITE_SPRITES){
  //   ImageResize(&value, SPRITE_SIZE, SPRITE_SIZE);
  // }
  // for (auto &[key, value] : BLACK_SPRITES){
  //   ImageResize(&value, SPRITE_SIZE, SPRITE_SIZE);
  // }
}

ChessGame::~ChessGame(){}

shared_ptr<ChessGame> ChessGame::getGameInstance(){
  if(ChessGame::gameInstance.get() == nullptr)
    ChessGame::gameInstance.reset(new ChessGame());
  return ChessGame::gameInstance;
}

Coord ChessGame::mapIndicesToCoord(Coord indices){
  auto [row, col] = indices;
  return pair(MARGIN_X + col * CELL_SIZE, MARGIN_Y + row * CELL_SIZE);
}
void ChessGame::drawBoard(){
  auto color = pair{0, DEEP_BROWN}; 
  for (int row = 0; row < GRID_SIZE; row++) {
    color = color.first  == 0  ? pair{1, LIGHT_BROWN} : pair{0, DEEP_BROWN};
    for (int col = 0; col < GRID_SIZE; col++) {
      if((col % 2) == 0)
        DrawRectangle(MARGIN_X + col * CELL_SIZE, MARGIN_Y + row * CELL_SIZE,
                      CELL_SIZE, CELL_SIZE, color.second);
      else
        DrawRectangle(MARGIN_X + col * CELL_SIZE, MARGIN_Y + row * CELL_SIZE,
                      CELL_SIZE, CELL_SIZE, color.second);
      color = color.first  == 0  ? pair{1, LIGHT_BROWN} : pair{0, DEEP_BROWN};
    }
  }
}


//TODO Pre-process and store the sprites to avoid wasting time
void ChessGame::drawSprites(){
  for (int row = 0; row < GRID_SIZE; row++) {
    for (int col = 0; col < GRID_SIZE; col++) {
      auto piecePtr = chessBoard.boardState[row][col].get(); 
      if (piecePtr == nullptr)
        continue;
      auto teamSprites = piecePtr->getTeam() == Team::CHESS_BLACK ?
                        BLACK_SPRITES : WHITE_SPRITES;
      // auto pieceSprite = teamSprites[piecePtr->getPieceType()];
      // ImageResize(&pieceSprite, SPRITE_SIZE, SPRITE_SIZE);

      //draw sprite at center of the cell
      DrawTexture(LoadTextureFromImage(teamSprites[piecePtr->getPieceType()]), 
                  MARGIN_X + col * CELL_SIZE + (CELL_SIZE - SPRITE_SIZE) / 2, 
                  MARGIN_Y + row * CELL_SIZE + (CELL_SIZE - SPRITE_SIZE) / 2, WHITE);
    }
  }
}

void ChessGame::highlightPiece(Coord coord, HighlightLevel highlightLevel, bool showMoves = false){
  auto [cellX, cellY] = mapIndicesToCoord(coord);
  auto [x, y] = coord;
  Color highlightColor;
  switch (highlightLevel)
  {
    case HighlightLevel::INFO:
    default:
      highlightColor = LIGHT_GREEN;
      break;
    case HighlightLevel::WARNING:
      highlightColor = LIGHT_YELLOW;
      break;
    case HighlightLevel::DANGER:
      highlightColor = LIGHT_RED;
      break;
  }
  DrawRectangle(cellX, cellY, CELL_SIZE, CELL_SIZE, highlightColor);
  if(!showMoves) return;
  //TODO implement later: hightlighting a piece's possibl moves
  // for(Coord coord: chessBoard.boardState[x][y]->getPossibleMoves()){
  //   //highlight with a different color
  // }
}

void ChessGame::updateScreen(){
  drawBoard();
  drawSprites();
}

void ChessGame::runGameLoop(){
  bool pieceSelected = false;
  int cellX = 0, cellY = 0;
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    BeginDrawing();

    ClearBackground(Color{42, 47, 79});

    //check if a piece has been selected and highlight it, and its moves
    if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
      auto [x, y] = currentMouseCoord = pair{GetMouseX(), GetMouseY()};

      //TODO find an easier way of resolving coord to board indices
      // int yi = (x - MARGIN_X)/CELL_SIZE;
      // int xi = (y - MARGIN_Y)/CELL_SIZE;
      
      for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
          auto cellRect = Rectangle{float(MARGIN_X + col * CELL_SIZE), 
                                    float(MARGIN_Y + row * CELL_SIZE),
                          CELL_SIZE, CELL_SIZE};
          pieceSelected = CheckCollisionPointRec(Vector2{float(x), float(y)}, cellRect);
          if(pieceSelected){
            lastMouseClickCoord = {x, y};
            cellX = row, cellY = col;
            break;
          } 
        }
        if(pieceSelected) break;
      }
    }

    drawBoard();
    if(pieceSelected)
      //CloseWindow();
      highlightPiece(pair{cellX, cellY}, HighlightLevel::INFO, false);
    drawSprites();

    EndDrawing();
  }

}