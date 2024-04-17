#include "bg.h"
#include "all.h"
//******************************************************************************
//
//
//      BGクラス
//
//
//******************************************************************************

//------< インクルード >--------------------------------------------------------
#include "all.h"

//------< using >---------------------------------------------------------------
using namespace GameLib;

//------< データ >---------------------------------------------------------------
int terrain_back[4][BG::CHIP_NUM_Y][BG::CHIP_NUM_X] =// 地形データ[ステージ数][X][Y]
{
    //stage0
    {
        {-1,-1,-1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
        {-1,-1,-1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
        {-1,-1,-1, 0, 1, 0,-1, 0, 1, 0, 1, 0},
        { 1, 1, 0, 1, 0, 1,-1, 1, 0,-1,-1,-1},
        { 1, 0, 1, 0, 1, 0,-1, 0, 1,-1,-1,-1},
        { 1, 1, 0, 1,-1,-1,-1, 1, 0,-1,-1,-1},
        { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
        { 1, 1,-1,-1,-1, 1, 0, 1, 0, 1, 0, 1},
        { 1, 0,-1,-1,-1, 0, 1, 0, 1, 0, 1, 0},
        { 1, 1,-1,-1,-1, 1, 0, 1, 0, 1, 0, 1},
    },
};

//--------------------------------
//  コンストラクタ
//--------------------------------
BG::BG()
{
}

//--------------------------------
//  デストラクタ
//--------------------------------
BG::~BG()
{
}

//--------------------------------
//  初期設定
//--------------------------------
void BG::init(int stagenum)
{
    //地形データterrain_backをbomb地形データterrainに代入する
    for (int x = 0; x < CHIP_NUM_X; x++)
    {
        for (int y = 0; y < CHIP_NUM_Y; y++)
        {
            terrain[y][x] = terrain_back[stagenum][y][x];
            if (terrain[y][x] != -1)
            {
                terrain[y][x] = 0;
            }
        }
    }
    texture::load(0, L"./Data/Images/test_tile.png", 256U);    //背景
    texture::load(1, L"./Data/Images/test_tile02.png", 256U);    //背景

    timer = 0;
}

void BG::deinit()
{
    texture::releaseAll();
}

//--------------------------------
//  更新処理
//--------------------------------
void BG::update()
{
    cursorPos = { static_cast<float>(GameLib::input::getCursorPosX()), static_cast<float>(GameLib::input::getCursorPosY()) };


    bool isInStage = cursorPos.x > Mapterrain_correction.x && cursorPos.x<(Mapterrain_correction.x + 64 * BG::CHIP_NUM_X) && cursorPos.y>Mapterrain_correction.y && cursorPos.y < (Mapterrain_correction.y + 64 * BG::CHIP_NUM_Y);

    if (isInStage)
    {
        DirectX::XMINT2 Cpos = { static_cast<int>((cursorPos.x - Mapterrain_correction.x) / CHIP_SIZE) , static_cast<int>((cursorPos.y - Mapterrain_correction.y) / CHIP_SIZE) };

        DirectX::XMINT2 ExplodePos[] = {
            {Cpos.y,     Cpos.x}, //CENTER
            {Cpos.y - 1, Cpos.x}, //LEFT
            {Cpos.y, Cpos.x - 1}, //TOP
            {Cpos.y + 1, Cpos.x}, //RIGHT
            {Cpos.y, Cpos.x + 1}, //BOTTOM
        };

        if (terrain[Cpos.y][Cpos.x] == 0 && timer > 5 &&GameLib::input::STATE(0)& GameLib::input::PAD_START)
        {
            terrain[Cpos.y][Cpos.x] = 1;
        }

        if (terrain[Cpos.y][Cpos.x] == 0 && timer > 5 && GameLib::input::STATE(0) & GameLib::input::PAD_TRG4)
        {
            terrain[ExplodePos[0].x][ExplodePos[0].y] = 1;
            terrain[ExplodePos[1].x][ExplodePos[1].y] = 1;
            terrain[ExplodePos[2].x][ExplodePos[2].y] = 1;
            terrain[ExplodePos[3].x][ExplodePos[3].y] = 1;
            terrain[ExplodePos[4].x][ExplodePos[4].y] = 1;
        }
    }

    timer++;
}

//--------------------------------
//  地形描画
//--------------------------------
void BG::drawTerrain()
{
    //マップ
    texture::begin(0);
    for (int x = 0; x < CHIP_NUM_X; x++)
    {
        for (int y = 0; y < CHIP_NUM_Y; y++)
        {
            float a = terrain_back[0][y][x];
            texture::draw(
                0,
                Mapterrain_correction.x + (x * 64.0f), Mapterrain_correction.y + (y * 64.0f),
                1.0, 1.0,
                CHIP_SIZE * a, 0,
                CHIP_SIZE * (a + 1), CHIP_SIZE
            );
        }
    }
    texture::end(0);

    //バクダン
    texture::begin(1);
    for (int x = 0; x < CHIP_NUM_X; x++)
    {
        for (int y = 0; y < CHIP_NUM_Y; y++)
        {
            if (terrain[y][x] == 1)
            {
                texture::draw(
                    1,
                    Mapterrain_correction.x + (x * 64.0f), Mapterrain_correction.y + (y * 64.0f),
                    1.0, 1.0,
                    0, 0,
                    CHIP_SIZE, CHIP_SIZE,
                    0, 0,
                    0,
                    1, 0, 0, 1
                );
            }
        }
    }
    texture::end(1);
}

DirectX::XMFLOAT2 BG::SetExplosionPoint(DirectX::XMFLOAT2 BaseExplosionPoint, ExplosionPoint point)
{
    switch (point)
    {
    case ExplosionPoint::CENTER:
        return DirectX::XMFLOAT2{ BaseExplosionPoint.y,BaseExplosionPoint.x };
        break;
    case ExplosionPoint::LEFT:

    }

    return DirectX::XMFLOAT2();
}
