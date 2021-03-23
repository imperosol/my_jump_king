//
// Created by thgir on 17/03/2021.
//

#include "events.h"
void event_key_down(struct SDL_KeyboardEvent* key) {
    switch (key->keysym.scancode) {
        case SDL_SCANCODE_UP:
            myDirection.up = 1;
            break;
        case SDL_SCANCODE_RIGHT:
            myDirection.right = 1;
            break;
        case SDL_SCANCODE_LEFT:
            myDirection.left = 1;
            break;
        case SDL_SCANCODE_DOWN:
            myDirection.down = 1;
            break;
        default:
            break;
    }
}

void event_key_up(struct SDL_KeyboardEvent* key) {
    switch (key->keysym.scancode) {
        case SDL_SCANCODE_UP:
            myDirection.up = 0;
            break;
        case SDL_SCANCODE_RIGHT:
            myDirection.right = 0;
            break;
        case SDL_SCANCODE_LEFT:
            myDirection.left = 0;
            break;
        case SDL_SCANCODE_DOWN:
            myDirection.down = 0;
            break;
        default:
            break;
    }
}

void move_player(Entity* character) {
    if (myDirection.up) {
        character->position.y -= character->dy;
    }
    if (myDirection.left) {
        character->position.x -= character->dx;
    }
    if (myDirection.right) {
        character->position.x += character->dx;
    }
    if (myDirection.down) {
        character->position.y += character->dy;
    }
}
