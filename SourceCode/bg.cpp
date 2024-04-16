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
        {-1,-1,-1,0,1,0,1,0,1,0,1,0},
        {-1,-1,-1,1,0,1,0,1,0,1,0,1},
        {-1,-1,-1,0,1,0,1,0,1,0,1,0},
        {1,1,0,1,0,1,0,1,0,1,-1,-1},
        {1,0,1,0,1,0,1,0,1,0,-1,-1},
        {1,1,0,1,0,1,0,1,0,-1,-1,-1},
        {1,0,1,0,1,0,1,0,1,0,1,0},
        {1,1,-1,-1,-1,1,0,1,0,1,0,1},
        {1,0,-1,-1,-1,0,1,0,1,0,1,0},
        {1,1,-1,-1,-1,1,0,1,0,1,0,1},
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
            terrain[x][y] = terrain_back[stagenum][x][y];
            if (terrain[x][y] == -1)
            {
                terrain[x][y] = 0;
            }
        }
    }
    texture::load(0, L"./Data/Images/test_tile.png", 256U);    //背景
    texture::load(1, L"./Data/Images/test_tile02.png",256U);    //背景
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
    DirectX::XMINT2 Cpos = { static_cast<int>(cursorPos.x / 64.0f),static_cast<int>(cursorPos.y / 64.0f) };
    if (terrain[Cpos.x][Cpos.y]==0&&GameLib::input::TRG(0)& GameLib::input::PAD_START)
    {
        terrain[Cpos.x][Cpos.y] = 1;
    }
}

//--------------------------------
//  地形描画
//--------------------------------
void BG::drawTerrain()
{
    //マップ
    texture::begin(1);
    for (int x = 0; x < CHIP_NUM_X; x++)
    {
        for (int y = 0; y < CHIP_NUM_Y; y++)
        {
            float a = terrain_back[0][y][x];
            texture::draw(
                1,
                200.0f+32.0f+(x*64.0f), 0.0f+32.0f+(y * 64.0f),
                1.0, 1.0,
                CHIP_SIZE*a, 0,
                CHIP_SIZE*(a+1), CHIP_SIZE
            );
        }
    }
    texture::end(1);

    //バクダン
    //texture::begin(0);
    //for (int x = 0; x < CHIP_NUM_X; x++)
    //{
    //    for (int y = 0; y < CHIP_NUM_Y; y++)
    //    {
    //        if (terrain[y][x] == 1)
    //        {
    //            texture::draw(
    //                0,
    //                200.0f + 32.0f + (x * 64.0f), 0.0f + 32.0f + (y * 64.0f),
    //                1.0, 1.0,
    //                0, 0,
    //                CHIP_SIZE, CHIP_SIZE,
    //                0, 0,
    //                0,
    //                1, 0, 0, 1
    //            );
    //        }
    //    }
    //}
    //texture::end(0);
}