#pragma once
#include"all.h"

class Effect
{
public:
    void effectFire(GameLib::Sprite* sprite, int anime);
    void effectBomb(GameLib::Sprite* sprite, int anime);
    bool exist = false;
    int timer;
    VECTOR2 pos;
    int animeNum = 0;

private:
    int tx, ty;
};

