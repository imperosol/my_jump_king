
#include <stdlib.h>
#include <stdio.h>

#include "struct.h"
//#include "map_initialization.h"
#include "standard_functions.h"
#include "events.h"

void display_map_on_renderer(SDL_Texture* tile) {
    SDL_Rect rect = {1, 1, TILE_SIZE, TILE_SIZE};
    for (int i = 0; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            if (stage.map[j][i]) {
                SDL_RenderCopy(app.renderer, tile, NULL, &rect);
            }
            rect.x += TILE_SIZE;
        }
        rect.x = 1;
        rect.y += TILE_SIZE;
    }
}
void initialize_map(SDL_Texture* tile) {
    memset(stage.map, 0, sizeof(int) * MAP_WIDTH * MAP_HEIGHT);
    FILE * mapFile = open_file("map/map.txt", "r");
    char mapLine[MAP_WIDTH + 1] = "";
    for (int i = 0; !feof(mapFile); ++i){
        fscanf(mapFile, "%s", mapLine);
        for (int j = 0; j < MAP_WIDTH; ++j) {
            stage.map[j][i] = (mapLine[j] == '#');
        }
    }
    fclose(mapFile);
    display_map_on_renderer(tile);
}


int main(int argc, char **argv) {

//    const double frameTime = 1000.0f / FPS;
//    Uint32 old = 0;
//    Uint32 elapsed = 0;
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        printf("window initialization failure due to : %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    if (IMG_Init(IMG_INIT_PNG) == -1) {
        printf("window initialization failure due to");
        exit(EXIT_FAILURE);
    }
    app.window = SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                  800, 400, SDL_WINDOW_SHOWN);
    app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(app.renderer, 200, 200, 200, 250);
    SDL_RenderClear(app.renderer);
    SDL_Texture* hero_img = IMG_LoadTexture(app.renderer, "img/tile.png");
    initialize_map(hero_img);
    SDL_RenderPresent(app.renderer);
      SDL_Rect position = {50,50,40,40};
    Entity hero = {position, 10, 10, 0,IMG_LoadTexture(app.renderer, "img/hero.png"), 0};

    SDL_Event event;
    SDL_bool run = SDL_TRUE;
    while (run) {
        if (SDL_WaitEvent(&event)) {
            //old = SDL_GetTicks();
            SDL_RenderClear(app.renderer);
            switch (event.type) {
                case SDL_WINDOWEVENT:
                    if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
                        run = SDL_FALSE;
                    }
                    break;
//                case SDL_KEYDOWN:
//                    event_key_down(event.key.keysym.sym);
//                    break;
//                case SDL_KEYUP:
//                    event_key_up(event.key.keysym.sym);
//                    break;
//                default:
//                    break;
            }
//            move_player(&hero);
            display_map_on_renderer(hero_img);
            SDL_RenderCopy(app.renderer, hero.texture, NULL, &hero.position);
            SDL_RenderPresent(app.renderer);

//            elapsed = SDL_GetTicks() - old;
//            if (elapsed < frameTime) {
//                SDL_Delay(frameTime - elapsed);
//            }
        }
    }
    //SDL_DestroyTexture(tile);
    SDL_Delay(2000);
    SDL_DestroyWindow(app.window);
    SDL_DestroyRenderer(app.renderer);
    SDL_Quit();

    return 0;
}
