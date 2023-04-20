// #pragma once

#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_
#include <map>
#include "../include/raylib.h"


//measurements and dimensions
const int GRID_SIZE = 8;

const int WINDOW_WIDTH = 800, WINDOW_HEIGHT = 800;
const int CELL_SIZE = 60;
const int SPRITE_SIZE = CELL_SIZE * 0.8; //80% of cell size
const int BOARD_WIDTH = CELL_SIZE * GRID_SIZE, BOARD_HEIGHT = BOARD_WIDTH;

const int MARGIN_X = (WINDOW_WIDTH - BOARD_WIDTH) / 2, 
          MARGIN_Y = (WINDOW_HEIGHT - BOARD_HEIGHT) / 2;

//colors
const auto 
DEEP_BROWN     = Color{ 201, 137, 85, 255 },
LIGHT_BROWN    = Color{ 222, 202, 186, 255 },

LIGHT_GREEN    = Color{ 12, 200, 12, 60 },
LIGHT_YELLOW   = Color{ 201, 137, 85, 125 },
LIGHT_RED      = Color{ 201, 137, 85, 125 };


//Assets
//1. Sprites


//2. Audio



#endif
