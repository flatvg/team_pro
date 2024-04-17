#pragma once
#include "../GameLib/vector.h"

enum class ExplosionPoint
{
    CENTER,
    LEFT,
    TOP,
    RIGHT,
    BOTTOM
};

class BG
{
public:
    //------< 定数 >------------------------------------------------------------
    static const int CHIP_NUM_X = 12;       // マップの横方向のチップ数
    static const int CHIP_NUM_Y = 10;       // マップの縦方向のチップ数
    static const int CHIP_SIZE = 64;       // %演算子を使用するためint型を使用する

    static constexpr float WIDTH = static_cast<float>(CHIP_NUM_X * CHIP_SIZE);   // マップの幅（ドット）
    static constexpr float HEIGHT = static_cast<float>(CHIP_NUM_Y * CHIP_SIZE);   // マップの高さ（ドット）

    //ステージの余白
    DirectX::XMFLOAT2 Mapterrain_correction{ 200.0f + 32.0f ,0.0f + 32.0f };

private:
    //------< 変数 >------------------------------------------------------------
    int terrain[BG::CHIP_NUM_Y][BG::CHIP_NUM_X]; //

public:
    BG();
    ~BG();

    // 初期化
    void init(int stagenum);

    void deinit();

    // 更新
    void update();

    // 描画
    void drawTerrain();                                     // 地形描画

    //爆発箇所接地
    DirectX::XMFLOAT2 SetExplosionPoint(DirectX::XMFLOAT2 BaseExplosionPoint, ExplosionPoint point);

private:

    int timer;
    DirectX::XMFLOAT2  cursorPos;
};