#pragma once
#include "../GameLib/vector.h"

enum ExplosionPoint
{
    CENTER,
    LEFT,
    TOP,
    RIGHT,
    BOTTOM,
};

enum TerrainStatus
{
    UnBreakable = -1,
    Normal,
    Bomb,
    InExplosion,
};

class BG
{
public:
    //------< 定数 >------------------------------------------------------------
    static const int CHIP_NUM_X = 12;       // マップの横方向のチップ数
    static const int CHIP_NUM_Y = 10;       // マップの縦方向のチップ数
    static const int CHIP_SIZE = 64;       // %演算子を使用するためint型を使用する
    static const int EXPLOSION_CHIP_NUM = 5;

    static constexpr float CHIP_SIZE_F = 64.0f;
    static constexpr float WIDTH = static_cast<float>(CHIP_NUM_X * CHIP_SIZE);   // マップの幅（ドット）
    static constexpr float HEIGHT = static_cast<float>(CHIP_NUM_Y * CHIP_SIZE);   // マップの高さ（ドット）

    //ステージの余白
    DirectX::XMFLOAT2 Mapterrain_correction{ 200.0f + 32.0f ,0.0f + 32.0f };

private:
    //------< 変数 >------------------------------------------------------------
    int terrain[BG::CHIP_NUM_Y][BG::CHIP_NUM_X];

    struct TerrainData
    {
        int explosionTimer;     //爆破時間
        bool isAlredyChanged;   //すでに情報が変更されているか
        int DelayTimer;         //爆発の連鎖をずらす時間
    };
    //1マスが持つ情報
    TerrainData terrainData[BG::CHIP_NUM_Y][BG::CHIP_NUM_X];

public:
    BG();
    ~BG();

    // 初期化
    void init(int stagenum);

    //終了化
    void deinit();

    // 更新
    void update();

    // 描画
    void drawTerrain();

    //爆発箇所計算
    DirectX::XMINT2 CalcExplosionPoint(DirectX::XMINT2 BaseExplosionPoint, ExplosionPoint point);
    DirectX::XMINT2 CalcCenterPoint(DirectX::XMINT2 BaseExplosionPoint);
    DirectX::XMINT2 CalcLeftPoint(DirectX::XMINT2 BaseExplosionPoint);
    DirectX::XMINT2 CalcTopPoint(DirectX::XMINT2 BaseExplosionPoint);
    DirectX::XMINT2 CalcRightPoint(DirectX::XMINT2 BaseExplosionPoint);
    DirectX::XMINT2 CalcBottomPoint(DirectX::XMINT2 BaseExplosionPoint);

    //爆発箇所を確定させる
    int SetExplosionPoint(DirectX::XMINT2 explosionPoint, ExplosionPoint point , int delayIndex);
    int SetCenterPoint(int center, DirectX::XMINT2 centerPos, int delayIndex);
    int SetLeftPoint(int center, int left, DirectX::XMINT2 leftPos, DirectX::XMINT2 centerPos, int delayIndex);
    int SetTopPoint(int center, int top, DirectX::XMINT2 topPos, DirectX::XMINT2 centerPos, int delayIndex);
    int SetRightPoint(int center, int right, DirectX::XMINT2 rightPos, DirectX::XMINT2 centerPos, int delayIndex);
    int SetBottomPoint(int center, int bottom, DirectX::XMINT2 bottomPos, DirectX::XMINT2 centerPos, int delayIndex);

    //bomb地形の設定
    void SetTerrainData(DirectX::XMINT2 terrainPos, int delayIndex);

    //すでに指定した箇所が変更されているか
    bool IsAlreadyChanged(DirectX::XMINT2 terrainPos);

    //バクダンを設置
    void SetBomb(DirectX::XMINT2 terrainPos, ExplosionPoint point, int delayIndex);

private:

    int timer;                      //全体の時間
    int explosionTime = 60;         //爆発が残留する時間
    int delayTime = 30;             //爆発の連鎖する間隔
    int operatbleCursorTime = 5;    //誤操作を防ぐための操作不能時間
    DirectX::XMFLOAT2  cursorPos;   //カーソルの位置
};