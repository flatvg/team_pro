//------< インクルード >----------------------------------------------------------
#include "Effect.h"

//------< using >---------------------------------------------------------------
using namespace GameLib;

void Effect::effectFire(GameLib::Sprite* sprite, int anime)
{
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
    GameLib::sprite_render(sprite, pos.x, pos.y, 1.0f, 1.0f, texSizeX * animeNum, 0.0f, texSizeX, ty, 0.0f, 0.0f, ToRadian(0));
}

void Effect::effectBomb(GameLib::Sprite* sprite, int anime)
{
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
    GameLib::sprite_render(sprite, pos.x, pos.y, 4.0f, 4.0f, texSizeX * animeNum, 0.0f, texSizeX, ty, 0.0f, 0.0f, ToRadian(0));
}

void Effect::effectBakuhatu(GameLib::Sprite* sprite, int anime)
{
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
    GameLib::sprite_render(sprite, pos.x, pos.y, 4.0f, 4.0f, texSizeX * animeNum, 0.0f, texSizeX, ty, 0.0f, 0.0f, ToRadian(0));
}

void Effect::addEffect(Effect* effects, size_t size, const VECTOR2& pos)
{
    for (size_t i = 0; i < size; ++i) {
        if (!effects[i].exist) {
            effects[i].exist = true;
            effects[i].pos = pos;
            break;
        }
    }
}