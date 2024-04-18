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

    for (int x = 0; x < CHIP_NUM_X; x++)
    {
        for (int y = 0; y < CHIP_NUM_Y; y++)
        {
            terrainTimer[y][x] = explosionTime;
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

    DirectX::XMINT2 Cpos = {
    static_cast<int>((cursorPos.x - Mapterrain_correction.x) / CHIP_SIZE),
    static_cast<int>((cursorPos.y - Mapterrain_correction.y) / CHIP_SIZE)
    };

    bool isInStage = cursorPos.x >  Mapterrain_correction.x
                  && cursorPos.x < (Mapterrain_correction.x + 64 * BG::CHIP_NUM_X)
                  && cursorPos.y >  Mapterrain_correction.y
                  && cursorPos.y < (Mapterrain_correction.y + 64 * BG::CHIP_NUM_Y);

    bool isClickL = timer > 5 && GameLib::input::STATE(0) & GameLib::input::PAD_LC;
    bool isClickR = timer > 5 && GameLib::input::STATE(0) & GameLib::input::PAD_RC;

    bool isNotBomb = terrain[Cpos.y][Cpos.x] == 0 || terrain[Cpos.y][Cpos.x] == 2;

    if (isInStage)
    {
        //爆破位置設定
        DirectX::XMINT2 ExplodePos[EXPLOSION_CHIP_NUM] = {
            CalcExplosionPoint(Cpos,ExplosionPoint::CENTER),
            CalcExplosionPoint(Cpos,ExplosionPoint::LEFT),
            CalcExplosionPoint(Cpos,ExplosionPoint::TOP),
            CalcExplosionPoint(Cpos,ExplosionPoint::RIGHT),
            CalcExplosionPoint(Cpos,ExplosionPoint::BOTTOM),
        };

        //爆弾設置
        if (isNotBomb && isClickL)
        {
            terrain[Cpos.y][Cpos.x] = 1;
        }
        //爆破
        if (!isNotBomb && isClickR)
        {
            terrain[ExplodePos[ExplosionPoint::CENTER].x][ExplodePos[ExplosionPoint::CENTER].y] = SetExplosionPoint(ExplodePos[ExplosionPoint::CENTER]);
            terrain[ExplodePos[ExplosionPoint::LEFT].x][ExplodePos[ExplosionPoint::LEFT].y]     = SetExplosionPoint(ExplodePos[ExplosionPoint::LEFT]);
            terrain[ExplodePos[ExplosionPoint::TOP].x][ExplodePos[ExplosionPoint::TOP].y]       = SetExplosionPoint(ExplodePos[ExplosionPoint::TOP]);
            terrain[ExplodePos[ExplosionPoint::RIGHT].x][ExplodePos[ExplosionPoint::RIGHT].y]   = SetExplosionPoint(ExplodePos[ExplosionPoint::RIGHT]);
            terrain[ExplodePos[ExplosionPoint::BOTTOM].x][ExplodePos[ExplosionPoint::BOTTOM].y] = SetExplosionPoint(ExplodePos[ExplosionPoint::BOTTOM]);
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
            if(terrain[y][x] == 2)
            {
                texture::draw(
                    1,
                    Mapterrain_correction.x + (x * 64.0f), Mapterrain_correction.y + (y * 64.0f),
                    1.0, 1.0,
                    0, 0,
                    CHIP_SIZE, CHIP_SIZE,
                    0, 0,
                    0,
                    0, 0, 1, 1
                );
                terrainTimer[y][x]--;
                if (terrainTimer[y][x] < 0) {
                    terrain[y][x] = 0;
                    terrainTimer[y][x] = explosionTime;
                }
            }
        }
    }
    texture::end(1);
}

DirectX::XMINT2 BG::CalcExplosionPoint(DirectX::XMINT2 BaseExplosionPoint, ExplosionPoint point)
{
    switch (point)
    {
    case ExplosionPoint::CENTER:
        return CalcCenterPoint(BaseExplosionPoint);
        break;
    case ExplosionPoint::LEFT:
        return CalcLeftPoint(BaseExplosionPoint);
        break;
    case ExplosionPoint::TOP:
        return CalcTopPoint(BaseExplosionPoint);
        break;
    case ExplosionPoint::RIGHT:
        return CalcRightPoint(BaseExplosionPoint);
        break;
    case ExplosionPoint::BOTTOM:
        return CalcBottomPoint(BaseExplosionPoint);
        break;
    default:
        return DirectX::XMINT2( -1, -1 );
        break;
    }
}

DirectX::XMINT2 BG::CalcCenterPoint(DirectX::XMINT2 BaseExplosionPoint)
{
    return DirectX::XMINT2{ BaseExplosionPoint.y,BaseExplosionPoint.x };
}

DirectX::XMINT2 BG::CalcLeftPoint(DirectX::XMINT2 BaseExplosionPoint)
{
    DirectX::XMINT2 leftPoint( BaseExplosionPoint.y, BaseExplosionPoint.x - 1);
    int planPointStatus = terrain[leftPoint.x][leftPoint.y];
    if (leftPoint.y < 0 || planPointStatus == -1)
    {
        leftPoint = { -1,-1 };
    }
    return leftPoint;
}

DirectX::XMINT2 BG::CalcTopPoint(DirectX::XMINT2 BaseExplosionPoint)
{
    DirectX::XMINT2 topPoint(BaseExplosionPoint.y - 1, BaseExplosionPoint.x);
    int planPointStatus = terrain[topPoint.x][topPoint.y];
    if (topPoint.x < 0 || planPointStatus == -1)
    {
        topPoint = { -1,-1 };
    }
    return topPoint;
}

DirectX::XMINT2 BG::CalcRightPoint(DirectX::XMINT2 BaseExplosionPoint)
{
    DirectX::XMINT2 rightPoint(BaseExplosionPoint.y, BaseExplosionPoint.x + 1);
    int planPointStatus = terrain[rightPoint.x][rightPoint.y];
    if (rightPoint.y >= CHIP_NUM_X || planPointStatus == -1)
    {
        rightPoint = { -1,-1 };
    }
    return rightPoint;
}

DirectX::XMINT2 BG::CalcBottomPoint(DirectX::XMINT2 BaseExplosionPoint)
{
    DirectX::XMINT2 bottomPoint(BaseExplosionPoint.y + 1, BaseExplosionPoint.x);
    int planPointStatus = terrain[bottomPoint.x][bottomPoint.y];
    if (bottomPoint.x >= CHIP_NUM_Y || planPointStatus == -1)
    {
        bottomPoint = { -1,-1 };
    }
    return bottomPoint;
}

int BG::SetExplosionPoint(DirectX::XMINT2 explosionPoint)
{
    if (explosionPoint.x == -1 && explosionPoint.y == -1)
    {
        return 0;
    }
    return 2;
}
