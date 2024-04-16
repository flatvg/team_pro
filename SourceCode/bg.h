#pragma once
#include "../GameLib/vector.h"

class BG
{
public:
    //------< 定数 >------------------------------------------------------------
    static const int CHIP_NUM_X = 12;       // マップの横方向のチップ数
    static const int CHIP_NUM_Y = 10;       // マップの縦方向のチップ数
    static const int CHIP_SIZE = 64;       // %演算子を使用するためint型を使用する
    static const int CHIP_NUM_PER_LINE = 8;        // マップチップの1列が8個

    static constexpr float WIDTH = static_cast<float>(CHIP_NUM_X * CHIP_SIZE);   // マップの幅（ドット）
    static constexpr float HEIGHT = static_cast<float>(CHIP_NUM_Y * CHIP_SIZE);   // マップの高さ（ドット）
    static constexpr float SCROLL_MERGIN_X = 240.0f;   // この数値より画面端に近づいたらスクロールする（横）
    static constexpr float SCROLL_MERGIN_Y = 160.0f;   // この数値より画面端に近づいたらスクロールする（縦）

private:
    //------< 変数 >------------------------------------------------------------
    int terrain[BG::CHIP_NUM_X][BG::CHIP_NUM_Y]; //[X][Y]

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

private:
    DirectX::XMFLOAT2  cursorPos;
};