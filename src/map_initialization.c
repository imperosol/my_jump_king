//
// Created by thgir on 12/03/2021.
//

#include "map_initialization.h"
#include <stdio.h>

/*static void display_map_on_shell(int map[MAP_WIDTH][MAP_HEIGHT]) {
    for (int i = 0; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            printf("%d ; ", map[j][i]);
        }
        printf("\n");
    }
}*/

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
