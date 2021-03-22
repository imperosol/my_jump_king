//
// Created by thgir on 12/03/2021.
//

#ifndef MY_JUMP_KING_MAP_INITIALIZATION_H
#define MY_JUMP_KING_MAP_INITIALIZATION_H

#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "standard_functions.h"

//static void display_map_on_shell(int map[MAP_WIDTH][MAP_HEIGHT]);
void initialize_map(SDL_Texture* tile);
//void load_tiles(int* tiles);
void display_map_on_renderer(SDL_Texture* tile);

#endif //MY_JUMP_KING_MAP_INITIALIZATION_H
