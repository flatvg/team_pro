#include "Effect.h"

using namespace GameLib;

void Effect::effectFire(Sprite* sprite, int anime)
{
    if (this->exist) {
        timer++;

        if (timer > 5) {
            timer = 0;
            animeNum++;
            if (animeNum > anime - 1) {
                animeNum = 0;
            }
        }

        sprite->getSize(tx, ty);
        float texSizeX = tx / anime;
        sprite_render(sprite, pos.x, pos.y, 1.0f, 1.0f, texSizeX * animeNum, 0.0f, texSizeX, ty, 0.0f, 0.0f, ToRadian(0));
    }
}

void Effect::effectBomb(Sprite* sprite, int anime)
{
    if (this->exist) {
        timer++;

        if (timer > 5) {
            timer = 0;
            animeNum++;
            if (animeNum > anime - 1) {
                animeNum = 0;
            }
        }

        sprite->getSize(tx, ty);
        float texSizeX = tx / anime;
        sprite_render(sprite, pos.x, pos.y, 4.0f, 4.0f, texSizeX * animeNum, 0.0f, texSizeX, ty, 0.0f, 0.0f, ToRadian(0));
    }
}