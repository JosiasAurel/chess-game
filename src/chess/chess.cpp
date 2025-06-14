#include "./chess.hpp"

// generate the 2D textures for game sprites
map<PieceType, Texture2D> BLACK_SPRITES;
map<PieceType, Texture2D> WHITE_SPRITES;

Texture2D pathToTexture(string path){
  Image img = LoadImage(path.c_str());
  ImageResize(&img, SPRITE_SIZE, SPRITE_SIZE);
  return LoadTextureFromImage(img);
}

void processTextures(){
  BLACK_SPRITES.insert({PieceType::PAWN, pathToTexture("./assets/sprites/pawn_black.png")});
  BLACK_SPRITES.insert({PieceType::KNIGHT, pathToTexture("./assets/sprites/knight_black.png")});
  BLACK_SPRITES.insert({PieceType::BISHOP, pathToTexture("./assets/sprites/bishop_black.png")});
  BLACK_SPRITES.insert({PieceType::ROOK, pathToTexture("./assets/sprites/rook_black.png")});
  BLACK_SPRITES.insert({PieceType::QUEEN, pathToTexture("./assets/sprites/queen_black.png")});
  BLACK_SPRITES.insert({PieceType::KING, pathToTexture("./assets/sprites/king_black.png")});

  WHITE_SPRITES.insert({PieceType::PAWN, pathToTexture("./assets/sprites/pawn_white.png")});
  WHITE_SPRITES.insert({PieceType::KNIGHT, pathToTexture("./assets/sprites/knight_white.png")});
  WHITE_SPRITES.insert({PieceType::BISHOP, pathToTexture("./assets/sprites/bishop_white.png")});
  WHITE_SPRITES.insert({PieceType::ROOK, pathToTexture("./assets/sprites/rook_white.png")});
  WHITE_SPRITES.insert({PieceType::QUEEN, pathToTexture("./assets/sprites/queen_white.png")});
  WHITE_SPRITES.insert({PieceType::KING, pathToTexture("./assets/sprites/king_white.png")});
}

shared_ptr<ChessGame> ChessGame::gameInstance(nullptr);

ChessGame::ChessGame():chessBoard(Board()) {}

ChessGame::~ChessGame() {}

shared_ptr<ChessGame> ChessGame::getGameInstance() {
  if (ChessGame::gameInstance.get() == nullptr)
    ChessGame::gameInstance.reset(new ChessGame());
  return ChessGame::gameInstance;
}

Coord ChessGame::mapIndicesToCoord(Coord indices){
  auto [row, col] = indices;
  return pair(MARGIN_X + col * CELL_SIZE, MARGIN_Y + row * CELL_SIZE);
}

void ChessGame::drawBoard(){
  // since objects of `Color` don't have a == operator
  // use 0 for DEEP_BROWN and 1 for LIGHT_BROWN
  auto color = pair{0, DEEP_BROWN};
  for (int row = 0; row < GRID_SIZE; row++) {
    color = color.first == 0 ? pair{1, LIGHT_BROWN} : pair{0, DEEP_BROWN};
    for (int col = 0; col < GRID_SIZE; col++) {
      Rectangle rect = {.x = static_cast<float>(MARGIN_X + col * CELL_SIZE),
                        .y = static_cast<float>(MARGIN_Y + row * CELL_SIZE),
                        .width = CELL_SIZE,
                        .height = CELL_SIZE};

      DrawRectangleRec(rect, color.second);
      color = color.first == 0 ? pair{1, LIGHT_BROWN} : pair{0, DEEP_BROWN};
    }
  }
}


//TODO Pre-process and store the sprites to avoid waisting time
void ChessGame::drawSprites(){
  for (int row = 0; row < GRID_SIZE; row++) {
    for (int col = 0; col < GRID_SIZE; col++) {
      // auto pieceSharedPtr = chessBoard.boardState[row][col];
      auto piecePtr = chessBoard.boardState[row][col].get();
      if (piecePtr == nullptr)
        continue;
      /*
       auto cellX = static_cast<int>((pieceRect.x - MARGIN_X) / CELL_SIZE);
      auto cellY = static_cast<int>((pieceRect.y - MARGIN_Y) / CELL_SIZE);

      // std::cout << "cellX " << cellX << " when it ought to be " << row << std::endl;
      // std::cout << "cellY " << cellY << " when it ought to be " << col << std::endl;
      
      pieceSharedPtr->_setRect(pieceRect);
      piecesRef[typeid(*piecePtr).name()] = pieceSharedPtr;
  */
      auto teamSprites = piecePtr->getTeam() == Team::CHESS_BLACK ?
                        BLACK_SPRITES : WHITE_SPRITES;
      auto pieceSprite = teamSprites[piecePtr->getPieceType()];
     //draw sprite at center of the cell
      DrawTexture(pieceSprite,
                  MARGIN_X + col * CELL_SIZE + (CELL_SIZE - SPRITE_SIZE) / 2,
                  MARGIN_Y + row * CELL_SIZE + (CELL_SIZE - SPRITE_SIZE) / 2, WHITE);
    }
  }
}

void ChessGame::highlightPiece(int x, int y, HighlightLevel highlightLevel, bool showMoves = false){
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
  DrawRectangle(x, y, CELL_SIZE, CELL_SIZE, highlightColor);
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

void ChessGame::loadAndPrepareAssets(){
  processTextures();
}

void ChessGame::runGameLoop(){
  loadAndPrepareAssets();

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

      // this is slow... gotta optimize this shit
      // it is much faster to look through the position of individual pieces to
      // check which one intersects with the current mouse coordinates
    
      auto mousePosition = Vector2{float(x), float(y)};
      for (const std::pair<std::string, shared_ptr<Piece>>& pieceRef : chessBoard.piecesRef) {
        auto chessPiece = pieceRef.second.get();
        auto pieceRect = chessPiece->_rect();
        // auto pieceRect = pieceRef.get()->_rect();
        pieceSelected = CheckCollisionPointRec(mousePosition, pieceRect);
       
        if (pieceSelected) {

          std::cout << "mx " << mousePosition.x << " my " << mousePosition.y << std::endl;
          std::cout << "Rectangle(x=" << pieceRect.x << ", y=" << pieceRect.y << ", width=" << pieceRect.width << ", height=" << pieceRect.height << ")" << std::endl;
          std::cout << "collision? " << pieceSelected << std::endl;

          lastMouseClickCoord = {x, y};

          // cellX = (pieceRect.x - MARGIN_X) / CELL_SIZE;
          // cellY = (pieceRect.y - MARGIN_Y) / CELL_SIZE;

          cellX = pieceRect.x;
          cellY = pieceRect.y;

          break;
        }
        if (pieceSelected) break;
      }
      /*

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
        */
    }

    drawBoard();
    if(pieceSelected)
      highlightPiece(cellX, cellY, HighlightLevel::INFO, false);
    drawSprites();

    EndDrawing();
  }

}
