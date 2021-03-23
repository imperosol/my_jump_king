//
// Created by thgir on 23/03/2021.
//

#include "collision.h"
#include <stdio.h>

void collision_management(Entity *character) {
    int tileX = TILE_SIZE, tileY = TILE_SIZE;
    const int posMinX = (character->position.x + 1) / TILE_SIZE;
    const int posMinY = (character->position.y + 1) / TILE_SIZE;
    const int posMaxX = (character->position.x - 1 + character->position.w) / TILE_SIZE;
    const int posMaxY = (character->position.y - 1 + character->position.h) / TILE_SIZE;
    if (myDirection.down || myDirection.up) {
        for (int i = posMinX; i <= posMaxX; ++i) {
            if (stage.map[i][posMaxY]) {
                myDirection.down = 0;
                character->position.y = (posMaxY) * TILE_SIZE - character->position.h;
                return;
            }
            if (stage.map[i][posMinY]) {
                myDirection.up = 0;
                character->position.y = (posMinY + 1) * TILE_SIZE;
                return;
            }
        }
    }
    if (myDirection.left || myDirection.right) {
        for (int i = posMinY; i <= posMaxY; ++i) {
            if (stage.map[posMaxX][i]) {
                myDirection.right = 0;
                character->position.x = (posMaxX) * TILE_SIZE - character->position.w;
                return;
            }
            if (stage.map[posMinX][i]) {
                myDirection.left = 0;
                character->position.x = (posMinX + 1) * TILE_SIZE;
                return;
            }
        }
    }
}

