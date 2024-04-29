#pragma once
#include"all.h"
#include <DirectXMath.h>

class Effect
{
public:
    // �G�t�F�N�g
    void effectFire(GameLib::Sprite* sprite, int anime);
    void effectBomb(GameLib::Sprite* sprite, int anime);
    void effectBakuhatu(GameLib::Sprite* sprite, int anime);

    // �G�t�F�N�g����
    static void addEffect(Effect* effects, size_t size, const VECTOR2& pos);

    bool exist = false;
    int timer;
    VECTOR2 pos;
    DirectX::XMINT2 Cpos;
    int animeNum = 0;

private:
    int tx, ty;
};

