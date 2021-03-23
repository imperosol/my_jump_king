//
// Created by thgir on 12/03/2021.
//

#ifndef MY_JUMP_KING_STRUCT_H
#define MY_JUMP_KING_STRUCT_H
#define MAX_TILES 7

#define MAP_WIDTH 27
#define MAP_HEIGHT 10

#define TILE_SIZE 25

#define MAP_RENDER_WIDTH    20
#define MAP_RENDER_HEIGHT   12

#define FPS 30

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


struct App {
    SDL_Renderer * renderer;
    SDL_Window * window;
};
struct App app;

typedef struct {
    int map[MAP_WIDTH][MAP_HEIGHT];
} Stage;
Stage stage;

typedef struct {
//    int x;
//    int y;
//    int w;
//    int h;
    SDL_Rect position;
    int dx;
    int dy;
    int isOnGround;
    SDL_Texture * texture;
    long flags;
} Entity;

typedef struct {
    unsigned short up;
    unsigned short right;
    unsigned short left;
    unsigned short down;
} Direction;
Direction myDirection;

#endif //MY_JUMP_KING_STRUCT_H
