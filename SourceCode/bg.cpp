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
            terrain[x][y] = terrain_back[stagenum][x][y];
            if (terrain[x][y] == -1)
            {
                terrain[x][y] = 0;
            }
        }
    }
    texture::load(0, L"./Data/Images/test_tile.png", 256U);    //�w�i
    texture::load(1, L"./Data/Images/test_tile02.png",256U);    //�w�i
}

void BG::deinit()
{
    texture::releaseAll();
}

//--------------------------------
//  �X�V����
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
//  �n�`�`��
//--------------------------------
void BG::drawTerrain()
{
    //�}�b�v
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

    //�o�N�_��
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