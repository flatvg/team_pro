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

    bool isNotBomb = (terrain[Cpos.y][Cpos.x] == 0 || terrain[Cpos.y][Cpos.x] == 2) && terrain[Cpos.y][Cpos.x] != -1;

    bool isBomb = terrain[Cpos.y][Cpos.x] == 1;

    ExplodePos[CENTER] = CalcExplosionPoint(Cpos, ExplosionPoint::CENTER);
    ExplodePos[LEFT]   = CalcExplosionPoint(Cpos, ExplosionPoint::LEFT);
    ExplodePos[TOP]    = CalcExplosionPoint(Cpos, ExplosionPoint::TOP);
    ExplodePos[RIGHT]  = CalcExplosionPoint(Cpos, ExplosionPoint::RIGHT);
    ExplodePos[BOTTOM] = CalcExplosionPoint(Cpos, ExplosionPoint::BOTTOM);

    if (isInStage)
    {
        //爆弾設置
        if (isNotBomb && isClickL)
        {
            terrain[Cpos.y][Cpos.x] = 1;
        }
        //爆破
        if (isBomb && isClickR)
        {
            terrain[ExplodePos[ExplosionPoint::CENTER].x][ExplodePos[ExplosionPoint::CENTER].y] = SetExplosionPoint(Cpos,ExplosionPoint::CENTER);
            terrain[ExplodePos[ExplosionPoint::LEFT].x][ExplodePos[ExplosionPoint::LEFT].y]     = SetExplosionPoint(ExplodePos[ExplosionPoint::LEFT],ExplosionPoint::LEFT);
            terrain[ExplodePos[ExplosionPoint::TOP].x][ExplodePos[ExplosionPoint::TOP].y]       = SetExplosionPoint(ExplodePos[ExplosionPoint::TOP],ExplosionPoint::TOP);
            terrain[ExplodePos[ExplosionPoint::RIGHT].x][ExplodePos[ExplosionPoint::RIGHT].y]   = SetExplosionPoint(ExplodePos[ExplosionPoint::RIGHT],ExplosionPoint::RIGHT);
            terrain[ExplodePos[ExplosionPoint::BOTTOM].x][ExplodePos[ExplosionPoint::BOTTOM].y] = SetExplosionPoint(ExplodePos[ExplosionPoint::BOTTOM],ExplosionPoint::BOTTOM);
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
    }
}

DirectX::XMINT2 BG::CalcCenterPoint(DirectX::XMINT2 BaseExplosionPoint)
{
    DirectX::XMINT2 centerPoint(BaseExplosionPoint.y, BaseExplosionPoint.x);
    return centerPoint;
}

DirectX::XMINT2 BG::CalcLeftPoint(DirectX::XMINT2 BaseExplosionPoint)
{
    DirectX::XMINT2 leftPoint( BaseExplosionPoint.y, BaseExplosionPoint.x - 1);
    return leftPoint;
}

DirectX::XMINT2 BG::CalcTopPoint(DirectX::XMINT2 BaseExplosionPoint)
{
    DirectX::XMINT2 topPoint(BaseExplosionPoint.y - 1, BaseExplosionPoint.x);
    return topPoint;
}

DirectX::XMINT2 BG::CalcRightPoint(DirectX::XMINT2 BaseExplosionPoint)
{
    DirectX::XMINT2 rightPoint(BaseExplosionPoint.y, BaseExplosionPoint.x + 1);
    return rightPoint;
}

DirectX::XMINT2 BG::CalcBottomPoint(DirectX::XMINT2 BaseExplosionPoint)
{
    DirectX::XMINT2 bottomPoint(BaseExplosionPoint.y + 1, BaseExplosionPoint.x);
    return bottomPoint;
}

int BG::SetExplosionPoint(DirectX::XMINT2 explosionPoint, ExplosionPoint point)
{
    switch (point)
    {
    case ExplosionPoint::CENTER:
    {
        int center = terrain[explosionPoint.x][explosionPoint.y];
        return SetCenterPoint(center, explosionPoint);
        break;
    }
    case ExplosionPoint::LEFT:
    {
        DirectX::XMINT2 centerPos{ explosionPoint.x,explosionPoint.y + 1 };
        int center = terrain[explosionPoint.x][explosionPoint.y + 1];
        int left = terrain[explosionPoint.x][explosionPoint.y];
        return SetLeftPoint(center, left, explosionPoint, centerPos);
        break;
    }
    case ExplosionPoint::TOP:
    {
        DirectX::XMINT2 centerPos{ explosionPoint.x + 1,explosionPoint.y};
        int center = terrain[explosionPoint.x + 1][explosionPoint.y];
        int top = terrain[explosionPoint.x][explosionPoint.y];
        return SetTopPoint(center, top, explosionPoint, centerPos);
        break;
    }
    case ExplosionPoint::RIGHT:
    {
        DirectX::XMINT2 centerPos{ explosionPoint.x,explosionPoint.y - 1 };
        int center = terrain[explosionPoint.x][explosionPoint.y - 1];
        int right = terrain[explosionPoint.x][explosionPoint.y];
        return SetRightPoint(center, right, explosionPoint, centerPos);
        break;
    }
    case ExplosionPoint::BOTTOM:
    {
        DirectX::XMINT2 centerPos{ explosionPoint.x - 1,explosionPoint.y };
        int center = terrain[explosionPoint.x - 1][explosionPoint.y];
        int bottom = terrain[explosionPoint.x][explosionPoint.y];
        return SetBottomPoint(center, bottom, explosionPoint, centerPos);
        break;
    }
    }
}

int BG::SetCenterPoint(int center, DirectX::XMINT2 centerPos)
{
    bool isNotEdge = centerPos.x < 0 || centerPos.y < 0 || centerPos.x >= CHIP_NUM_Y || centerPos.y >= CHIP_NUM_X;

    if (isNotEdge && center == -1)
    {
        return center;
    }

    return 2;
}

int BG::SetLeftPoint(int center, int left, DirectX::XMINT2 leftPos, DirectX::XMINT2 centerPos)
{
    bool isNotEdge = leftPos.x < 0 || leftPos.y < 0 || leftPos.x > CHIP_NUM_Y || leftPos.y > CHIP_NUM_X;

    if (isNotEdge || center == -1 || left == -1)
    {
        return left;
    }

    if (left == 1)
    {
        DirectX::XMINT2 inversePos{ leftPos.y, leftPos.x };

        //爆破箇所計算
        DirectX::XMINT2 explodePos[EXPLOSION_CHIP_NUM] = {
            DirectX::XMINT2(-1,-1),//CENTER
            CalcExplosionPoint(inversePos,ExplosionPoint::LEFT),
            CalcExplosionPoint(inversePos,ExplosionPoint::TOP),
            DirectX::XMINT2(-1,-1),//RIGHT
            CalcExplosionPoint(inversePos,ExplosionPoint::BOTTOM),
        };

        //爆弾設置
        terrain[explodePos[ExplosionPoint::LEFT].x][explodePos[ExplosionPoint::LEFT].y] = SetExplosionPoint(explodePos[LEFT], ExplosionPoint::LEFT);
        terrain[explodePos[ExplosionPoint::TOP].x][explodePos[ExplosionPoint::TOP].y] = SetExplosionPoint(explodePos[TOP], ExplosionPoint::TOP);
        terrain[explodePos[ExplosionPoint::BOTTOM].x][explodePos[ExplosionPoint::BOTTOM].y] = SetExplosionPoint(explodePos[BOTTOM], ExplosionPoint::BOTTOM);
    }

    return 2;
}

int BG::SetTopPoint(int center, int top, DirectX::XMINT2 topPos, DirectX::XMINT2 centerPos)
{
    bool isNotEdge = topPos.x < 0 || topPos.y < 0 || topPos.x > CHIP_NUM_Y || topPos.y > CHIP_NUM_X;

    if (isNotEdge || center == -1 || top == -1)
    {
        return top;
    }

    if (top == 1)
    {
        DirectX::XMINT2 inversePos{ topPos.y, topPos.x };

        //爆破箇所計算
        DirectX::XMINT2 explodePos[EXPLOSION_CHIP_NUM] = {
            DirectX::XMINT2(-1,-1),//CENTER
            CalcExplosionPoint(inversePos,ExplosionPoint::LEFT),
            CalcExplosionPoint(inversePos,ExplosionPoint::TOP),
            CalcExplosionPoint(inversePos,ExplosionPoint::RIGHT),
            DirectX::XMINT2(-1,-1),//BOTTOM
        };

        //爆弾設置
        terrain[explodePos[ExplosionPoint::LEFT].x][explodePos[ExplosionPoint::LEFT].y] = SetExplosionPoint(explodePos[ExplosionPoint::LEFT], ExplosionPoint::LEFT);
        terrain[explodePos[ExplosionPoint::TOP].x][explodePos[ExplosionPoint::TOP].y] = SetExplosionPoint(explodePos[ExplosionPoint::TOP], ExplosionPoint::TOP);
        terrain[explodePos[ExplosionPoint::RIGHT].x][explodePos[ExplosionPoint::RIGHT].y] = SetExplosionPoint(explodePos[ExplosionPoint::RIGHT], ExplosionPoint::RIGHT);
    }

    return 2;
}

int BG::SetRightPoint(int center, int right, DirectX::XMINT2 rightPos, DirectX::XMINT2 centerPos)
{
    bool isNotEdge = rightPos.x < 0 || rightPos.y < 0 || rightPos.x >= CHIP_NUM_Y || rightPos.y >= CHIP_NUM_X;

    if (isNotEdge || center == -1 || right == -1)
    {
        return right;
    }

    if (right == 1)
    {
        DirectX::XMINT2 inversePos{ rightPos.y, rightPos.x };

        //爆破箇所計算
        DirectX::XMINT2 explodePos[EXPLOSION_CHIP_NUM] = {
            DirectX::XMINT2(-1,-1),//CENTER
            DirectX::XMINT2(-1,-1),//LEFT
            CalcExplosionPoint(inversePos,ExplosionPoint::TOP),
            CalcExplosionPoint(inversePos,ExplosionPoint::RIGHT),
            CalcExplosionPoint(inversePos,ExplosionPoint::BOTTOM),
        };

        //爆弾設置
        terrain[explodePos[ExplosionPoint::TOP].x][explodePos[ExplosionPoint::TOP].y] = SetExplosionPoint(explodePos[ExplosionPoint::TOP], ExplosionPoint::TOP);
        terrain[explodePos[ExplosionPoint::RIGHT].x][explodePos[ExplosionPoint::RIGHT].y] = SetExplosionPoint(explodePos[ExplosionPoint::RIGHT], ExplosionPoint::RIGHT);
        terrain[explodePos[ExplosionPoint::BOTTOM].x][explodePos[ExplosionPoint::BOTTOM].y] = SetExplosionPoint(explodePos[ExplosionPoint::BOTTOM], ExplosionPoint::BOTTOM);
    }

    return 2;
}

int BG::SetBottomPoint(int center, int bottom, DirectX::XMINT2 bottomPos, DirectX::XMINT2 centerPos)
{
    bool isNotEdge = bottomPos.x < 0 || bottomPos.y < 0 || bottomPos.x >= CHIP_NUM_Y || bottomPos.y >= CHIP_NUM_X;

    if (isNotEdge || center == -1 || bottom == -1)
    {
        return bottom;
    }

    if (bottom == 1)
    {
        DirectX::XMINT2 inversePos{ bottomPos.y, bottomPos.x };

        //爆破箇所計算
        DirectX::XMINT2 explodePos[EXPLOSION_CHIP_NUM] = {
            DirectX::XMINT2(-1,-1),//CENTER
            CalcExplosionPoint(inversePos,ExplosionPoint::LEFT),
            DirectX::XMINT2(-1,-1),//TOP
            CalcExplosionPoint(inversePos,ExplosionPoint::RIGHT),
            CalcExplosionPoint(inversePos,ExplosionPoint::BOTTOM),
        };

        //爆弾設置
        terrain[explodePos[ExplosionPoint::LEFT].x][explodePos[ExplosionPoint::LEFT].y] = SetExplosionPoint(explodePos[ExplosionPoint::LEFT], ExplosionPoint::LEFT);
        terrain[explodePos[ExplosionPoint::RIGHT].x][explodePos[ExplosionPoint::RIGHT].y] = SetExplosionPoint(explodePos[ExplosionPoint::RIGHT], ExplosionPoint::RIGHT);
        terrain[explodePos[ExplosionPoint::BOTTOM].x][explodePos[ExplosionPoint::BOTTOM].y] = SetExplosionPoint(explodePos[ExplosionPoint::BOTTOM], ExplosionPoint::BOTTOM);
    }

    return 2;
}
