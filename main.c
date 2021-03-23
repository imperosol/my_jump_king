
#include <stdlib.h>
#include <stdio.h>

#include "src/struct.h"
#include "src/map_initialization.h"
#include "src/standard_functions.h"
#include "src/events.h"
#include "src/gravity.h"

short character_is_moving() {
    if (myDirection.up || myDirection.right || myDirection.left || myDirection.down) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char **argv) {

    const double frameTime = 1000.0f / FPS;
    int distance;
    Uint32 old = 0;
    Uint32 elapsed = 0;
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
    SDL_Texture* tile = IMG_LoadTexture(app.renderer, "img/tile.png");
    initialize_map(tile);
    SDL_RenderPresent(app.renderer);
    SDL_Rect position = {50,50,40,40};
    Entity hero = {position, 5, 5, 0,
                   IMG_LoadTexture(app.renderer, "img/hero.png"), 0};
    SDL_Event event;
    SDL_bool run = SDL_TRUE;
    while (run) {
        if (character_is_moving() || SDL_WaitEvent(&event)) {
            if (character_is_moving()){
                SDL_PollEvent(&event);
            }
            old = SDL_GetTicks();
            SDL_RenderClear(app.renderer);
            switch (event.type) {
                case SDL_WINDOWEVENT:
                    if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
                        run = SDL_FALSE;
                    }
                    break;
                case SDL_KEYDOWN:
                    event_key_down(&event.key);
                    break;
                case SDL_KEYUP:
                    event_key_up(&event.key);
                    break;
                default:
                    break;
            }
            //if (!hero.isOnGround) {
            //    distance = get_distance_from_down_platform(&hero);
            //}
            move_player(&hero);
            display_map_on_renderer(tile);
            SDL_RenderCopy(app.renderer, hero.texture, NULL, &hero.position);
            SDL_RenderPresent(app.renderer);

            elapsed = SDL_GetTicks() - old;
            if (elapsed < frameTime) {
                SDL_Delay(frameTime - elapsed);
            }
        }
    }
    SDL_DestroyTexture(tile);
    SDL_DestroyWindow(app.window);
    SDL_DestroyRenderer(app.renderer);
    SDL_Quit();

    return 0;
}
