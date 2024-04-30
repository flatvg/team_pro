#pragma once
#include"all.h"
#include <DirectXMath.h>

class Effect
{
private:
    static constexpr float DEFAULT_SIZE_BOMB = 4.0f;
    static constexpr float DEFAULT_SIZE_FIRE = 1.0f;
    static constexpr float DEFAULT_SIZE_BAKUHATU = 4.0f;

public:
    // エフェクト
    void effectFire(GameLib::Sprite* sprite, int anime);
    void effectFire(GameLib::Sprite* sprite, int anime, DirectX::XMFLOAT2 size);
    void effectBomb(GameLib::Sprite* sprite, int anime);
    void effectBomb(GameLib::Sprite* sprite, int anime, DirectX::XMFLOAT2 size);
    void effectBakuhatu(GameLib::Sprite* sprite, int anime);
    void effectBakuhatu(GameLib::Sprite* sprite, int anime, DirectX::XMFLOAT2 size);

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

