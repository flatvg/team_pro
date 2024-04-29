#pragma once
#include"all.h"
#include <DirectXMath.h>

class Effect
{
public:
    // エフェクト
    void effectFire(GameLib::Sprite* sprite, int anime);
    void effectBomb(GameLib::Sprite* sprite, int anime);
    void effectBakuhatu(GameLib::Sprite* sprite, int anime);

    // エフェクト生成
    static void addEffect(Effect* effects, size_t size, const VECTOR2& pos);

    bool exist = false;
    int timer;
    VECTOR2 pos;
    DirectX::XMINT2 Cpos;
    int animeNum = 0;

private:
    int tx, ty;
};

