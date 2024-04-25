#include "bg.h"
#include "all.h"
//******************************************************************************
//
//
//      BG�N���X
//
//
//******************************************************************************

//------< �C���N���[�h >--------------------------------------------------------
#include "all.h"

//------< using >---------------------------------------------------------------
using namespace GameLib;

//------< �f�[�^ >---------------------------------------------------------------
int terrain_back[4][BG::CHIP_NUM_Y][BG::CHIP_NUM_X] =// �n�`�f�[�^[�X�e�[�W��][X][Y]
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
//  �R���X�g���N�^
//--------------------------------
BG::BG()
{
}

//--------------------------------
//  �f�X�g���N�^
//--------------------------------
BG::~BG()
{
}

//--------------------------------
//  �����ݒ�
//--------------------------------
void BG::init(int stagenum)
{
    //�n�`�f�[�^terrain_back��bomb�n�`�f�[�^terrain�ɑ������
    for (int x = 0; x < CHIP_NUM_X; x++)
    {
        for (int y = 0; y < CHIP_NUM_Y; y++)
        {
            terrain[y][x] = terrain_back[stagenum][y][x];
            if (terrain[y][x] != UnBreakable)
            {
                terrain[y][x] = Normal;
            }
        }
    }

    //bomb�n�`�̏���������
    for (int x = 0; x < CHIP_NUM_X; x++)
    {
        for (int y = 0; y < CHIP_NUM_Y; y++)
        {
            terrainData[y][x].explosionTimer = explosionTime;
            terrainData[y][x].isAlredyChanged = false;
            terrainData[y][x].DelayTimer = delayTime;
        }
    }

    texture::load(0, L"./Data/Images/test_tile.png", 256U);    //�w�i
    texture::load(1, L"./Data/Images/test_tile02.png", 256U);    //�w�i

    //�^�C�}�[������
    timer = 0;
}

void BG::deinit()
{
    //�e�N�X�`�����
    texture::releaseAll();
}

//--------------------------------
//  �X�V����
//--------------------------------
void BG::update()
{
    //�J�[�\���̈ʒu���擾
    cursorPos = { static_cast<float>(GameLib::input::getCursorPosX()), static_cast<float>(GameLib::input::getCursorPosY()) };

    //�J�[�\���̈ʒu��w�i�ɑΉ�
    DirectX::XMINT2 Cpos = {
    static_cast<int>((cursorPos.x - Mapterrain_correction.x) / CHIP_SIZE),
    static_cast<int>((cursorPos.y - Mapterrain_correction.y) / CHIP_SIZE)
    };

    //�J�[�\����bomb�w�i���ɑ��݂��Ă��邩
    bool isInStage = cursorPos.x >  Mapterrain_correction.x
                  && cursorPos.x < (Mapterrain_correction.x + CHIP_SIZE * BG::CHIP_NUM_X)
                  && cursorPos.y >  Mapterrain_correction.y
                  && cursorPos.y < (Mapterrain_correction.y + CHIP_SIZE * BG::CHIP_NUM_Y);

    //�E�A���N���b�N�����Ă��邩�ۂ�
    bool isClickL = timer > operatbleCursorTime && GameLib::input::STATE(0) & GameLib::input::PAD_LC;
    bool isClickR = timer > operatbleCursorTime && GameLib::input::STATE(0) & GameLib::input::PAD_RC;

    //�J�[�\���������Ă���ӏ������e�łȂ����ۂ�
    bool isNotBomb = (terrain[Cpos.y][Cpos.x] == Normal || terrain[Cpos.y][Cpos.x] == InExplosion) && terrain[Cpos.y][Cpos.x] != UnBreakable;

    //�J�[�\���������Ă���ӏ������e���ۂ�
    bool isBomb = terrain[Cpos.y][Cpos.x] == Bomb;

    //�����̘A���̌W��
    int delayIndex = -1;

    //����������ӏ��̐ݒ�
    DirectX::XMINT2 ExplodePos[EXPLOSION_CHIP_NUM] = {
        CalcExplosionPoint(Cpos, ExplosionPoint::CENTER),
        CalcExplosionPoint(Cpos, ExplosionPoint::LEFT),
        CalcExplosionPoint(Cpos, ExplosionPoint::TOP),
        CalcExplosionPoint(Cpos, ExplosionPoint::RIGHT),
        CalcExplosionPoint(Cpos, ExplosionPoint::BOTTOM),
    };

    if (isInStage)
    {
        //���e�ݒu
        if (isNotBomb && isClickL)
        {
            terrain[Cpos.y][Cpos.x] = Bomb;
        }
        //���j
        if (isBomb && isClickR)
        {
            SetBomb(ExplodePos[ExplosionPoint::CENTER], ExplosionPoint::CENTER, delayIndex);
            SetBomb(ExplodePos[ExplosionPoint::LEFT], ExplosionPoint::LEFT, delayIndex);
            SetBomb(ExplodePos[ExplosionPoint::TOP], ExplosionPoint::TOP, delayIndex);
            SetBomb(ExplodePos[ExplosionPoint::RIGHT], ExplosionPoint::RIGHT, delayIndex);
            SetBomb(ExplodePos[ExplosionPoint::BOTTOM], ExplosionPoint::BOTTOM, delayIndex);
        }
    }

    timer++;
}

//--------------------------------
//  �n�`�`��
//--------------------------------
void BG::drawTerrain()
{
    //�}�b�v
    texture::begin(0);
    for (int x = 0; x < CHIP_NUM_X; x++)
    {
        for (int y = 0; y < CHIP_NUM_Y; y++)
        {
            float a = terrain_back[0][y][x];
            texture::draw(
                0,
                Mapterrain_correction.x + (x * CHIP_SIZE_F), Mapterrain_correction.y + (y * CHIP_SIZE_F),
                1.0, 1.0,
                CHIP_SIZE_F * a, 0,
                CHIP_SIZE_F * (a + 1), CHIP_SIZE_F
            );
        }
    }
    texture::end(0);

    //�o�N�_��
    texture::begin(1);
    for (int x = 0; x < CHIP_NUM_X; x++)
    {
        for (int y = 0; y < CHIP_NUM_Y; y++)
        {
            if (terrain[y][x] == Bomb)
            {
                texture::draw(
                    1,
                    Mapterrain_correction.x + (x * CHIP_SIZE_F), Mapterrain_correction.y + (y * CHIP_SIZE_F),
                    1.0f, 1.0f,
                    0, 0,
                    CHIP_SIZE_F, CHIP_SIZE_F,
                    0, 0,
                    0,
                    1, 0, 0, 1
                );
            }
            if(terrain[y][x] == InExplosion)
            {
                if (terrainData[y][x].DelayTimer < 0)
                {
                    //�A�����邽�߂̎��Ԃ̂��炵�����������̂Ńo�N�_����`��
                    texture::draw(
                        1,
                        Mapterrain_correction.x + (x * CHIP_SIZE_F), Mapterrain_correction.y + (y * CHIP_SIZE_F),
                        1.0f, 1.0f,
                        0, 0,
                        CHIP_SIZE_F, CHIP_SIZE_F,
                        0, 0,
                        0,
                        0, 0, 1, 1
                    );
                    terrainData[y][x].explosionTimer--;
                }
                if (terrainData[y][x].isAlredyChanged)
                {
                    terrainData[y][x].DelayTimer--;
                }
            }
            //�����I��
            if (terrainData[y][x].explosionTimer < 0) {
                terrain[y][x] = Normal;
                terrainData[y][x].explosionTimer = explosionTime;
                terrainData[y][x].DelayTimer = delayTime;
                terrainData[y][x].isAlredyChanged = false;
            }
        }
    }
    texture::end(1);
}

//--------------------------------
//  �w�肵���ӏ��ɂ��łɕύX���������Ă��邩
//--------------------------------
bool BG::IsAlreadyChanged(DirectX::XMINT2 terrainPos)
{
    return terrainData[terrainPos.x][terrainPos.y].isAlredyChanged;
}

//--------------------------------
//  �o�N�_����ݒu
//--------------------------------
void BG::SetBomb(DirectX::XMINT2 terrainPos, ExplosionPoint point, int delayIndex)
{
    if (!IsAlreadyChanged(terrainPos)) {
        terrain[terrainPos.x][terrainPos.y] = SetExplosionPoint(terrainPos, point, delayIndex);
    }
}

//--------------------------------
//  �w�肵���ӏ��̏����Z�b�g
//--------------------------------
void BG::SetTerrainData(DirectX::XMINT2 terrainPos, int delayIndex)
{
    if (!terrainData[terrainPos.x][terrainPos.y].isAlredyChanged)
    {
        terrainData[terrainPos.x][terrainPos.y].DelayTimer = delayIndex * delayTime;
        terrainData[terrainPos.x][terrainPos.y].isAlredyChanged = true;
    }
}

//--------------------------------
//  �����ӏ��̌v�Z
//--------------------------------
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

//--------------------------------
//  �����ݒ�
//--------------------------------
int BG::SetExplosionPoint(DirectX::XMINT2 explosionPoint, ExplosionPoint point, int delayIndex)
{
    switch (point)
    {
    case ExplosionPoint::CENTER:
    {
        int center = terrain[explosionPoint.x][explosionPoint.y];
        return SetCenterPoint(center, explosionPoint, ++delayIndex);
        break;
    }
    case ExplosionPoint::LEFT:
    {
        DirectX::XMINT2 centerPos{ explosionPoint.x,explosionPoint.y + 1 };
        int center = terrain[explosionPoint.x][explosionPoint.y + 1];
        int left   = terrain[explosionPoint.x][explosionPoint.y];
        return SetLeftPoint(center, left, explosionPoint, centerPos, ++delayIndex);
        break;
    }
    case ExplosionPoint::TOP:
    {
        DirectX::XMINT2 centerPos{ explosionPoint.x + 1,explosionPoint.y};
        int center = terrain[explosionPoint.x + 1][explosionPoint.y];
        int top    = terrain[explosionPoint.x][explosionPoint.y];
        return SetTopPoint(center, top, explosionPoint, centerPos, ++delayIndex);
        break;
    }
    case ExplosionPoint::RIGHT:
    {
        DirectX::XMINT2 centerPos{ explosionPoint.x,explosionPoint.y - 1 };
        int center = terrain[explosionPoint.x][explosionPoint.y - 1];
        int right  = terrain[explosionPoint.x][explosionPoint.y];
        return SetRightPoint(center, right, explosionPoint, centerPos, ++delayIndex);
        break;
    }
    case ExplosionPoint::BOTTOM:
    {
        DirectX::XMINT2 centerPos{ explosionPoint.x - 1,explosionPoint.y };
        int center = terrain[explosionPoint.x - 1][explosionPoint.y];
        int bottom = terrain[explosionPoint.x][explosionPoint.y];
        return SetBottomPoint(center, bottom, explosionPoint, centerPos, ++delayIndex);
        break;
    }
    }
}

int BG::SetCenterPoint(int center, DirectX::XMINT2 centerPos, int delayIndex)
{
    //�Y���u���b�N���X�e�[�W�̊O�ɏo�Ă��Ȃ���
    bool isNotEdge = centerPos.x < 0 || centerPos.y < 0 || centerPos.x >= CHIP_NUM_Y || centerPos.y >= CHIP_NUM_X;

    if (isNotEdge && center == InExplosion)
    {
        return center;
    }

    //�Y���u���b�N�̃f�[�^�ݒ�
    SetTerrainData(centerPos, delayIndex);

    return InExplosion;
}

int BG::SetLeftPoint(int center, int left, DirectX::XMINT2 leftPos, DirectX::XMINT2 centerPos, int delayIndex)
{
    //�Y���u���b�N���X�e�[�W�̊O�ɏo�Ă��Ȃ���
    bool isNotEdge = leftPos.x < 0 || leftPos.y < 0 || leftPos.x > CHIP_NUM_Y || leftPos.y > CHIP_NUM_X;

    if (isNotEdge || center == UnBreakable || left == UnBreakable || left == InExplosion)
    {
        return left;
    }

    //�Y���u���b�N�̃f�[�^�ݒ�
    SetTerrainData(leftPos, delayIndex);

    //�A�����j����
    if (left == Bomb)
    {
        DirectX::XMINT2 inversePos{ leftPos.y, leftPos.x };

        //���j�ӏ��v�Z
        DirectX::XMINT2 explodePos[EXPLOSION_CHIP_NUM] = {
            DirectX::XMINT2(-1,-1),//CENTER
            CalcExplosionPoint(inversePos,ExplosionPoint::LEFT),
            CalcExplosionPoint(inversePos,ExplosionPoint::TOP),
            DirectX::XMINT2(-1,-1),//RIGHT
            CalcExplosionPoint(inversePos,ExplosionPoint::BOTTOM),
        };

        //���e�ݒu
        SetBomb(explodePos[ExplosionPoint::LEFT], ExplosionPoint::LEFT, delayIndex);
        SetBomb(explodePos[ExplosionPoint::TOP], ExplosionPoint::TOP, delayIndex);
        SetBomb(explodePos[ExplosionPoint::BOTTOM], ExplosionPoint::BOTTOM, delayIndex);
    }

    return InExplosion;
}

int BG::SetTopPoint(int center, int top, DirectX::XMINT2 topPos, DirectX::XMINT2 centerPos, int delayIndex)
{
    //�Y���u���b�N���X�e�[�W�̊O�ɏo�Ă��Ȃ���
    bool isNotEdge = topPos.x < 0 || topPos.y < 0 || topPos.x > CHIP_NUM_Y || topPos.y > CHIP_NUM_X;

    if (isNotEdge || center == UnBreakable || top == UnBreakable || top == InExplosion)
    {
        return top;
    }

    //�Y���u���b�N�̃f�[�^�ݒ�
    SetTerrainData(topPos, delayIndex);

    //�A�����j����
    if (top == Bomb)
    {
        DirectX::XMINT2 inversePos{ topPos.y, topPos.x };

        //���j�ӏ��v�Z
        DirectX::XMINT2 explodePos[EXPLOSION_CHIP_NUM] = {
            DirectX::XMINT2(-1,-1),//CENTER
            CalcExplosionPoint(inversePos,ExplosionPoint::LEFT),
            CalcExplosionPoint(inversePos,ExplosionPoint::TOP),
            CalcExplosionPoint(inversePos,ExplosionPoint::RIGHT),
            DirectX::XMINT2(-1,-1),//BOTTOM
        };

        //���e�ݒu
        SetBomb(explodePos[ExplosionPoint::LEFT], ExplosionPoint::LEFT, delayIndex);
        SetBomb(explodePos[ExplosionPoint::TOP], ExplosionPoint::TOP, delayIndex);
        SetBomb(explodePos[ExplosionPoint::RIGHT], ExplosionPoint::RIGHT, delayIndex);
    }

    return InExplosion;
}

int BG::SetRightPoint(int center, int right, DirectX::XMINT2 rightPos, DirectX::XMINT2 centerPos, int delayIndex)
{
    //�Y���u���b�N���X�e�[�W�̊O�ɏo�Ă��Ȃ���
    bool isNotEdge = rightPos.x < 0 || rightPos.y < 0 || rightPos.x >= CHIP_NUM_Y || rightPos.y >= CHIP_NUM_X;

    if (isNotEdge || center == UnBreakable || right == UnBreakable || right == InExplosion)
    {
        return right;
    }

    //�Y���u���b�N�̃f�[�^�ݒ�
    SetTerrainData(rightPos, delayIndex);

    //�A�����j����
    if (right == Bomb)
    {
        DirectX::XMINT2 inversePos{ rightPos.y, rightPos.x };

        //���j�ӏ��v�Z
        DirectX::XMINT2 explodePos[EXPLOSION_CHIP_NUM] = {
            DirectX::XMINT2(-1,-1),//CENTER
            DirectX::XMINT2(-1,-1),//LEFT
            CalcExplosionPoint(inversePos,ExplosionPoint::TOP),
            CalcExplosionPoint(inversePos,ExplosionPoint::RIGHT),
            CalcExplosionPoint(inversePos,ExplosionPoint::BOTTOM),
        };

        //���e�ݒu
        SetBomb(explodePos[ExplosionPoint::TOP], ExplosionPoint::TOP, delayIndex);
        SetBomb(explodePos[ExplosionPoint::RIGHT], ExplosionPoint::RIGHT, delayIndex);
        SetBomb(explodePos[ExplosionPoint::BOTTOM], ExplosionPoint::BOTTOM, delayIndex);
    }

    return InExplosion;
}

int BG::SetBottomPoint(int center, int bottom, DirectX::XMINT2 bottomPos, DirectX::XMINT2 centerPos, int delayIndex)
{
    //�Y���u���b�N���X�e�[�W�̊O�ɏo�Ă��Ȃ���
    bool isNotEdge = bottomPos.x < 0 || bottomPos.y < 0 || bottomPos.x >= CHIP_NUM_Y || bottomPos.y >= CHIP_NUM_X;

    if (isNotEdge || center == UnBreakable || bottom == UnBreakable || bottom == InExplosion)
    {
        return bottom;
    }

    //�Y���u���b�N�̃f�[�^�ݒ�
    SetTerrainData(bottomPos, delayIndex);

    //�A�����j����
    if (bottom == Bomb)
    {
        DirectX::XMINT2 inversePos{ bottomPos.y, bottomPos.x };

        //���j�ӏ��v�Z
        DirectX::XMINT2 explodePos[EXPLOSION_CHIP_NUM] = {
            DirectX::XMINT2(-1,-1),//CENTER
            CalcExplosionPoint(inversePos,ExplosionPoint::LEFT),
            DirectX::XMINT2(-1,-1),//TOP
            CalcExplosionPoint(inversePos,ExplosionPoint::RIGHT),
            CalcExplosionPoint(inversePos,ExplosionPoint::BOTTOM),
        };

        //���e�ݒu
        SetBomb(explodePos[ExplosionPoint::LEFT], ExplosionPoint::LEFT, delayIndex);
        SetBomb(explodePos[ExplosionPoint::RIGHT], ExplosionPoint::RIGHT, delayIndex);
        SetBomb(explodePos[ExplosionPoint::BOTTOM], ExplosionPoint::BOTTOM, delayIndex);
    }

    return InExplosion;
}
