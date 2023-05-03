#pragma once

#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_
#include "../include/raylib.h"

// measurements and dimensions
constexpr int GRID_SIZE = 8;

constexpr int WINDOW_WIDTH = 800, WINDOW_HEIGHT = 800;
constexpr int CELL_SIZE = 60;
constexpr int SPRITE_SIZE = CELL_SIZE * 0.8; // 80% of cell size
constexpr int BOARD_WIDTH = CELL_SIZE * GRID_SIZE, BOARD_HEIGHT = BOARD_WIDTH;

constexpr int MARGIN_X = (WINDOW_WIDTH - BOARD_WIDTH) / 2,
              MARGIN_Y = (WINDOW_HEIGHT - BOARD_HEIGHT) / 2;

// colors
constexpr Color DEEP_BROWN = {201, 137, 85, 255};
constexpr Color LIGHT_BROWN = {222, 202, 186, 255};

// Assets
// 1. Sprites
// 2. Audio

#endif
