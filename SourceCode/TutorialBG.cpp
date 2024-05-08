//------< �C���N���[�h >--------------------------------------------------------
#include "all.h"
#include "TutorialBG.h"
#include "common.h"
#include "collision.h"

//------< using >---------------------------------------------------------------
using namespace GameLib;
using namespace DirectX;

//------< �f�[�^ >---------------------------------------------------------------
int terrain_back_T[TutorialBG::STAGE_NUM][TutorialBG::CHIP_NUM_Y][TutorialBG::CHIP_NUM_X] =// �n�`�f�[�^[�X�e�[�W��][X][Y]
{
    //stage0
    {
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1, 1, 0, 1, 0, 1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1, 0, 1, 0, 1, 0,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1, 1, 0, 1, 0, 1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1, 0, 1, 0, 1, 0,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    },
    //stage1
    {
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1, 0, 1, 1,-1,-1,-1,-1,-1,-1,-1},
        {-1, 1, 1, 1, 1, 0, 0,-1,-1,-1,-1,-1,-1,-1},
        {-1, 1, 1, 2, 0, 1, 1,-1,-1,-1,-1,-1,-1,-1},
        {-1, 1, 1, 2, 2, 1, 0,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1, 0, 1, 0, 1, 0,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    },
    //stage2
    {
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1, 0, 1, 0, 1, 0, 1, 0, 1, 0,-1},
    {-1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1,-1},
    {-1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,-1},
    {-1, 1, 1, 0, 1, 0, 1,-1, 2, 2, 1, 0, 1,-1},
    {-1, 1, 0, 1, 0, 1, 0,-1, 2, 2, 0, 1, 0,-1},
    {-1, 1, 1, 0, 1, 0, 1,-1, 2, 2, 1, 0, 1,-1},
    {-1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,-1},
    {-1, 1, 1,-1,-1, 0, 1, 0, 1, 0, 1, 0, 1,-1},
    {-1, 1, 0,-1,-1, 1, 0, 1, 0, 1, 0, 1, 0,-1},
    {-1, 1, 1,-1,-1, 0, 1, 0, 1, 0, 1, 0, 1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    },
    //stage3
    {
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1, 0, 1, 0, 1, 0, 1, 0, 1, 0,-1},
    {-1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1,-1},
    {-1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,-1},
    {-1, 1, 1, 0, 1, 0, 1,-1, 1, 0,-1,-1,-1,-1},
    {-1, 1, 0, 1, 0, 1, 0,-1, 0, 1,-1,-1,-1,-1},
    {-1, 1, 1, 0, 1,-1,-1,-1, 1, 0,-1,-1,-1,-1},
    {-1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,-1},
    {-1, 1, 1,-1,-1,-1, 1, 0, 1, 0, 1, 0, 1,-1},
    {-1, 1, 0,-1,-1,-1, 0, 1, 0, 1, 0, 1, 0,-1},
    {-1, 1, 1,-1,-1,-1, 1, 0, 1, 0, 1, 0, 1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    },
    //stage4
    {   //�ݒu�s�}�X�̐����p
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1, 1, 0, 1, 0,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1, 0, 1, 0, 1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1, 1, 0, 1, 0,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1, 0, 1, 0, 1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1, 1, 0, 1, 0,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1, 0, 1, 0, 1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1, 1, 0, 1, 0,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    },
};

int bomb_pattern_T[8][4][3][3]//[���e�̎��][��]�̎��][y][x]
{
    //pattern0
    {
        //pattern0-0
        {
            {1,0,0},
            {1,0,0},
            {1,0,0},
        },
        //pattern0-1
        {
            {1,1,1},
            {0,0,0},
            {0,0,0},
        },
        //pattern0-2
        {
            {1,0,0},
            {1,0,0},
            {1,0,0},
        },
        //pattern0-3
        {
            {1,1,1},
            {0,0,0},
            {0,0,0},
        },
    },
    //pattern1
    {
        //pattern1-0
        {
            {1,1,0},
            {1,1,0},
            {0,0,0},
        },
        //pattern1-1
        {
            {1,1,0},
            {1,1,0},
            {0,0,0},
        },
        //pattern1-2
        {
            {1,1,0},
            {1,1,0},
            {0,0,0},
        },
        //pattern1-3
        {
            {1,1,0},
            {1,1,0},
            {0,0,0},
        },
    },
    //pattern2
    {
        //pattern2-0
        {
            {0,1,0},
            {1,1,1},
            {0,0,0},
        },
        //pattern2-1
        {
            {0,0,1},
            {0,1,1},
            {0,0,1},
        },
        //pattern2-2
        {
            {1,1,1},
            {0,1,0},
            {0,0,0},
        },
        //pattern2-3
        {
            {1,0,0},
            {1,1,0},
            {1,0,0},
        },
    },
    //pattern3
    {
        //pattern3-0
        {
            {1,0,0},
            {1,1,0},
            {0,1,0},
        },
        //pattern3-1
        {
            {0,1,1},
            {1,1,0},
            {0,0,0},
        },
        //pattern3-2
        {
            {1,0,0},
            {1,1,0},
            {0,1,0},
        },
        //pattern3-3
        {
            {0,1,1},
            {1,1,0},
            {0,0,0},
        },
    },
    //pattern4
    {
        //pattern4-0
        {
            {0,1,0},
            {1,1,0},
            {1,0,0},
        },
        //pattern4-1
        {
            {1,1,0},
            {0,1,1},
            {0,0,0},
        },
        //pattern4-2
        {
            {0,1,0},
            {1,1,0},
            {1,0,0},
        },
        //pattern4-3
        {
            {1,1,0},
            {0,1,1},
            {0,0,0},
        },
    },
    //pattern5
    {
        //pattern5-0
        {
            {1,1,0},
            {1,0,0},
            {0,0,0},
        },
        //pattern5-1
        {
            {1,0,0},
            {1,1,0},
            {0,0,0},
        },
        //pattern5-2
        {
            {0,1,0},
            {1,1,0},
            {0,0,0},
        },
        //pattern5-3
        {
            {1,1,0},
            {0,1,0},
            {0,0,0},
        },
    },
    //pattern6
    {
        //pattern6-0
        {
            {1,1,0},
            {1,0,0},
            {1,0,0},
        },
        //pattern6-1
        {
            {1,0,0},
            {1,1,1},
            {0,0,0},
        },
        //pattern6-2
        {
            {0,1,0},
            {0,1,0},
            {1,1,0},
        },
        //pattern6-3
        {
            {1,1,1},
            {0,0,1},
            {0,0,0},
        },
    },
    //pattern7
    {
        //pattern7-0
        {
            {1,1,0},
            {0,1,0},
            {0,1,0},
        },
        //pattern7-1
        {
            {0,0,1},
            {1,1,1},
            {0,0,0},
        },
        //pattern7-2
        {
            {1,0,0},
            {1,0,0},
            {1,1,0},
        },
        //pattern7-3
        {
            {1,1,1},
            {1,0,0},
            {0,0,0},
        },
    },

    //pattern-sample
    //{
    //    //pattern4-0
    //    {
    //        {0,0,0},
    //        {0,0,0},
    //        {0,0,0},
    //    },
    //    //pattern4-1
    //    {
    //        {0,0,0},
    //        {0,0,0},
    //        {0,0,0},
    //    },
    //    //pattern4-2
    //    {
    //        {0,0,0},
    //        {0,0,0},
    //        {0,0,0},
    //    },
    //    //pattern4-3
    //    {
    //        {0,0,0},
    //        {0,0,0},
    //        {0,0,0},
    //    },
    //},
};

//���e�̎�ނ�ς���
int bomb_numchanger_T(int now, int past)
{
    while (now == past)now = rand() % 8;
    return now;
}

//--------------------------------
//  �R���X�g���N�^
//--------------------------------
TutorialBG::TutorialBG()
{
}

//--------------------------------
//  �f�X�g���N�^
//--------------------------------
TutorialBG::~TutorialBG()
{
}

//--------------------------------
//  �����ݒ�
//--------------------------------
void TutorialBG::init(int stagenum)
{
    static GameLib::Sprite* effect_explosion = nullptr;
    static GameLib::Sprite* effect_bomb      = nullptr;
    effect_explosion = sprite_load(EXPLOSION);
    effect_bomb      = sprite_load(BOMB01);

    //�n�`�f�[�^terrain_back��bomb�n�`�f�[�^terrain�ɑ������
    for (int s = 0; s < STAGE_NUM; s++)
    {
        for (int x = 0; x < CHIP_NUM_X; x++)
        {
            for (int y = 0; y < CHIP_NUM_Y; y++)
            {
                //�n�`�f�[�^terrain_back��bomb�n�`�f�[�^terrain�ɑ������
                terrainData[s][y][x].status = terrain_back_T[s][y][x];

                //bomb�n�`�̏���������
                InitTerrain(TerrainStatus::Normal, s, x, y);
                SetTerrainPos(XMINT2(x, y), s);

                terrainData[s][y][x].terrain_endurance = 10000;
                if (terrain_back_T[s][y][x] == 2)
                {
                    terrainData[s][y][x].terrain_endurance = 1;//1�񔚔j����ƒu���Ȃ��Ȃ�
                }

                //�G�t�F�N�g�̏���������
                TerrainExplosion[s][y][x].pos = DirectX::XMFLOAT2(x * CHIP_SIZE_F, y * CHIP_SIZE_F);
                TerrainExplosion[s][y][x].timer = 0;
                TerrainExplosion[s][y][x].animeMax = 7;
                TerrainExplosion[s][y][x].animeNum = 0;
                TerrainExplosion[s][y][x].exist = false;
                TerrainExplosion[s][y][x].playSpeed = 1.0f;
                effect_explosion->getSize(TerrainExplosion[s][y][x].tx, TerrainExplosion[s][y][x].ty);
                TerrainExplosion[s][y][x].texSizeX = TerrainExplosion[s][y][x].tx / TerrainExplosion[s][y][x].animeMax;

                TerrainBomb[s][y][x].pos = DirectX::XMFLOAT2(x * CHIP_SIZE_F, y * CHIP_SIZE_F);
                TerrainBomb[s][y][x].timer = 0;
                TerrainBomb[s][y][x].animeMax = 4;
                TerrainBomb[s][y][x].animeNum = 0;
                TerrainBomb[s][y][x].exist = true;
                TerrainBomb[s][y][x].playSpeed = 0.4f;
                effect_bomb->getSize(TerrainBomb[s][y][x].tx, TerrainBomb[s][y][x].ty);
                TerrainBomb[s][y][x].texSizeX = static_cast<float>(TerrainBomb[s][y][x].tx - 122.0f) / TerrainBomb[s][y][x].animeMax;
            }
        }
        moveStageFlags[s] = false;
        stageMovers[s] = std::make_unique<StageMover>(s, s + 1);
        isTutorialClear[s] = false;
        stageAct[s] = 0;
        isDrawStage[s] = true;
    }
    delete effect_bomb;
    delete effect_explosion;

    texture::load(Tile01, TILE01, 1024U);          //�w�i
    texture::load(Tile02, TILE02, 1024U);          //�w�i
    texture::load(Bomb01, BOMB01, 1024U);          //���e
    texture::load(Explosion, EXPLOSION, 1024U);    //����
    texture::load(Reset, RESET, 124U);            //���Z�b�g
    texture::load(Shape, SHAPE, 1024U);            //�ݒu�s�\�}�X
    texture::load(TutorialText1,TEXT1,24U);

    //�o�N�_���̎�ނ�������
    for (int i = 0; i < BOMB_TYPE_MAX; i++)
    {
        //���e�̎�ތ���
        int defnum = bomb_typenum[i];
        bomb_typenum[i] = bomb_numchanger_T(bomb_typenum[i], defnum);
        if (i > 1 && bomb_typenum[i] == bomb_typenum[i - 2])bomb_typenum[i] = bomb_numchanger_T(bomb_typenum[i], bomb_typenum[i - 2]);//1�T�ڂ̔��e�Ɠ�����ނȂ�ύX
        if (i > 0 && bomb_typenum[i] == bomb_typenum[i - 1])bomb_typenum[i] = bomb_numchanger_T(bomb_typenum[i], bomb_typenum[i - 1]);//0�T�ڂ̔��e�Ɠ�����ނȂ�ύX
        bomb_trun[i] = 0;
    }
    act = 0;
    bomb_movingtype = false;
    bomb_roopchecker = false;
    score = 0;
    finish_game = false;

    //�^�C�}�[������
    timer = 0;

    for (auto& focus : focuses)
    {
        Focus::instanceNum++;
        focus = std::make_unique<Focus>(VECTOR2(0, 0), 300.0f);
    }

    for (auto& textBox : textBoxes)
    {
        textBox = std::make_unique<TextBox>(VECTOR2(200, 400), VECTOR2(446, 65), VECTOR4(WHITE));
    }

    tutorialNum = 0;

    isReset = false;

    //���`�ۊǂ̏d��
    weight = 0.041f;

    isPutOnFuse = true;

    isShowUnPutBle = false;
}

//--------------------------------
//  �I������
//--------------------------------
void TutorialBG::deinit()
{
    //�e�N�X�`�����
    texture::releaseAll();
}

//--------------------------------
//  �X�V����
//--------------------------------
void TutorialBG::update()
{
    //�J�[�\���̈ʒu���擾�A����
    cursorPos = { static_cast<float>(GameLib::input::getCursorPosX()), static_cast<float>(GameLib::input::getCursorPosY()) };
    if (cursorPos.x < 0)cursorPos.x = 0;
    if (cursorPos.x > GameLib::window::getWidth())cursorPos.x = GameLib::window::getWidth();
    if (cursorPos.y < 0)cursorPos.y = 0;
    if (cursorPos.y > GameLib::window::getHeight())cursorPos.y = GameLib::window::getHeight();

    //�J�[�\���̈ʒu��w�i�ɑΉ�
    DirectX::XMINT2 Cpos = {
    static_cast<int>((cursorPos.x - Mapterrain_correction.x) / CHIP_SIZE),
    static_cast<int>((cursorPos.y - Mapterrain_correction.y) / CHIP_SIZE)
    };

    //�J�[�\����bomb�w�i���ɑ��݂��Ă��邩
    bool isInStage = cursorPos.x > Mapterrain_correction.x
                  && cursorPos.x < (Mapterrain_correction.x + CHIP_SIZE * TutorialBG::CHIP_NUM_X)
                  && cursorPos.y >  Mapterrain_correction.y
                  && cursorPos.y < (Mapterrain_correction.y + CHIP_SIZE * TutorialBG::CHIP_NUM_Y);

    //�E�A���N���b�N�Ȃǂ����Ă��邩�ۂ�
    isClickL = timer > operatbleCursorTime && GameLib::input::STATE(0) & GameLib::input::PAD_LC;
    isClickR = timer > operatbleCursorTime && GameLib::input::STATE(0) & GameLib::input::PAD_RC;
    isZ = timer > operatbleCursorTime && GameLib::input::STATE(0) & GameLib::input::PAD_TRG1;
    isX = timer > operatbleCursorTime && GameLib::input::STATE(0) & GameLib::input::PAD_TRG2;
    isC = timer > operatbleCursorTime && GameLib::input::STATE(0) & GameLib::input::PAD_TRG3;

    //�X�e�[�W�̈ړ��t���O��ݒ�
    setMoveFlags();

    //���ΐ��}�X����o�N�_���}�X�ɕύX���ꂽ��
    bool isChangeedFuelToBomb = false;

    //�J�[�\���������Ă���}�X���ǂ��ۂ�
    bool isUnBreakble = terrainData[nowStage][Cpos.y][Cpos.x].status == TerrainStatus::UnBreakble;

    //�����̘A���̌W��
    //0�ȏ�ɂ���ƍŏ��̕��͘A��������C�ɔ�������悤�ɂȂ�
    int delayIndex = -1;

    //����������ӏ�
    DirectX::XMINT2 ExplodePos[EXPLOSION_CHIP_NUM] = {};

    //���e��u������̃��Z�b�g
    resetBombPostProcess();

    //���e�����Z�b�g
    resetButton();

    //IsPutOnFuse();

    if (burningFuse.exist || (tutorialNum == 1 && textBoxes[1]->GetPopOutFlag()))
    {
        //���e���h���b�O
        dragBomb();

        //���e����]
        rotateBomb();

        //���e���h���b�v
        dropBomb();

        //�J�[�\�����X�e�[�W���̎�
        if (isInStage)
        {
            //���e�ݒu
            for (int i = 0; i < 2; ++i)//0�T�ڂőS���̔��e�ǂݍ���Łu�ׂ���or���e�v&�u�J���Ă�}�X���Ȃ��ƒu���Ȃ��v���Ƃ𒲂ׂĔz�u�\�Ȃ�1�T�ڂŔz�u
            {
                for (int x = 0; x < 3; ++x)
                {
                    for (int y = 0; y < 3; ++y)
                    {
                        //���e�̎�ގ擾
                        int pt_bomb = bomb_pattern_T[bomb_typenum[bomb_waitingarea]][bomb_trun[bomb_waitingarea]][y][x];

                        //���e1�u���b�N���S���W(�X�N���[�����W�{�z��[y][x]�ڂ̃u���b�N)
                        DirectX::XMFLOAT2 bomb_pos_b = { bomb_changepos[bomb_waitingarea].x + CHIP_SIZE * x,bomb_changepos[bomb_waitingarea].y + CHIP_SIZE * y };
                        //�}�b�v�`�b�v�̔z��̏ꏊ
                        DirectX::XMINT2 Cpos = { static_cast<int>((bomb_pos_b.x - Mapterrain_correction.x) / CHIP_SIZE_F) , static_cast<int>((bomb_pos_b.y - Mapterrain_correction.y) / CHIP_SIZE_F) };

                        if (pt_bomb == PatternStatus::IsBomb)
                        {
                            if (
                                //�ׂ��ǂ�������
                                terrainData[nowStage][Cpos.y - 1][Cpos.x].status == TerrainStatus::UnBreakble ||//��
                                terrainData[nowStage][Cpos.y + 1][Cpos.x].status == TerrainStatus::UnBreakble ||//��
                                terrainData[nowStage][Cpos.y][Cpos.x + 1].status == TerrainStatus::UnBreakble ||//�E
                                terrainData[nowStage][Cpos.y][Cpos.x - 1].status == TerrainStatus::UnBreakble ||//��
                                //�ׂ����e��������
                                terrainData[nowStage][Cpos.y - 1][Cpos.x].status == TerrainStatus::Bomb ||//��
                                terrainData[nowStage][Cpos.y + 1][Cpos.x].status == TerrainStatus::Bomb ||//��
                                terrainData[nowStage][Cpos.y][Cpos.x + 1].status == TerrainStatus::Bomb ||//�E
                                terrainData[nowStage][Cpos.y][Cpos.x - 1].status == TerrainStatus::Bomb   //��
                                )
                            {
                                bomb_roopchecker = true;
                            }
                            if (bomb_roopchecker)
                            {
                                if (terrainData[nowStage][Cpos.y][Cpos.x].status != TerrainStatus::Normal && terrainData[nowStage][Cpos.y][Cpos.x].status != TerrainStatus::BurningFuse)bomb_release = true;
                                if (bomb_release)break;
                                if (i == 1 && GameLib::input::TRG_RELEASE(0) & GameLib::input::PAD_LC && (terrainData[nowStage][Cpos.y][Cpos.x].status == TerrainStatus::Normal || terrainData[nowStage][Cpos.y][Cpos.x].status == TerrainStatus::BurningFuse))
                                {
                                    //���e�ݒu
                                    if (terrainData[nowStage][Cpos.y][Cpos.x].status == TerrainStatus::BurningFuse && !isChangeedFuelToBomb)
                                    {
                                        isChangeedFuelToBomb = true;
                                        ExplodePos[ExplosionPoint::CENTER] = CalcExplosionPoint(Cpos, ExplosionPoint::CENTER);
                                        ExplodePos[ExplosionPoint::LEFT] = CalcExplosionPoint(Cpos, ExplosionPoint::LEFT);
                                        ExplodePos[ExplosionPoint::TOP] = CalcExplosionPoint(Cpos, ExplosionPoint::TOP);
                                        ExplodePos[ExplosionPoint::RIGHT] = CalcExplosionPoint(Cpos, ExplosionPoint::RIGHT);
                                        ExplodePos[ExplosionPoint::BOTTOM] = CalcExplosionPoint(Cpos, ExplosionPoint::BOTTOM);
                                    }
                                    terrainData[nowStage][Cpos.y][Cpos.x].status = TerrainStatus::Bomb;
                                    stageAct[nowStage]++;
                                    act++;
                                    //���e���Z�b�g
                                    bomb_reset = true;
                                }
                            }
                        }
                    }
                }
            }
            bomb_roopchecker = false;
            bomb_release = false;

            //���j
            if (isChangeedFuelToBomb)
            {
                for (int s = 0; s < STAGE_NUM; s++)
                {
                    for (int x = 0; x < CHIP_NUM_X; x++)
                    {
                        for (int y = 0; y < CHIP_NUM_Y; y++)
                        {
                            terrainData[s][y][x].terrain_enduranceC = terrainData[s][y][x].terrain_endurance;
                        }
                    }
                }
                SetBomb(nowStage, ExplodePos[ExplosionPoint::CENTER], ExplosionPoint::CENTER, delayIndex);
                SetBomb(nowStage, ExplodePos[ExplosionPoint::LEFT], ExplosionPoint::LEFT, delayIndex);
                SetBomb(nowStage, ExplodePos[ExplosionPoint::TOP], ExplosionPoint::TOP, delayIndex);
                SetBomb(nowStage, ExplodePos[ExplosionPoint::RIGHT], ExplosionPoint::RIGHT, delayIndex);
                SetBomb(nowStage, ExplodePos[ExplosionPoint::BOTTOM], ExplosionPoint::BOTTOM, delayIndex);
                //�X�R�A
                score += score_add * (score_counter * 1.05) * 0.01;
                //��ʂ��h���
                Mapterrain_correction = { Mapterrain_correction.x + rand() % 4 - 2,Mapterrain_correction.y + rand() % 4 - 2 };

                isChangeedFuelToBomb = false;
            }
            else
            {
                score_add = 0;
                score_counter = 0;
            }
        }
    }
    //�h�ꂽ��ʂ����ɖ߂�
    Mapterrain_correction = { 200.0f + 32.0f - 64.0f ,0.0f + 32.0f - 64.0f };

    if (!isUnBreakble && isX && !burningFuse.exist && IsPutOnFuse())
    {
        burningFuse.exist = true;
        burningFuse.pos = VECTOR2(
            Mapterrain_correction.x + Cpos.x * CHIP_SIZE_F - (CHIP_SIZE_F / 2),
            Mapterrain_correction.y + Cpos.y * CHIP_SIZE_F - (CHIP_SIZE_F / 2)
        );
        burningFuse.Cpos = Cpos;
        terrainData[nowStage][Cpos.y][Cpos.x].status = TerrainStatus::BurningFuse;
    }

    for (int s = 0; s < STAGE_NUM; s++)
    {
        for (int x = 0; x < CHIP_NUM_X; x++)
        {
            for (int y = 0; y < CHIP_NUM_Y; y++)
            {
                updateEffect(TerrainExplosion[s][y][x]);
                TerrainBomb[s][y][x].exist = true;
                updateEffect(TerrainBomb[s][y][x]);
            }
        }
    }

    bool isMoveStage = false;
    for (auto& stageMover : stageMovers)
    {
        //�X�e�[�W���[�o�[�X�V����
        stageMover->Update();
        //1�ł��X�e�[�W�������Ă��鎞�A���̃X�e�[�W�𓮂����Ȃ��悤�ɂ���
        isMoveStage = moveStages(stageMover) ? true : false;
    }

    SetIsPutOn();

    if (act > 200)finish_game = true;

    Tutorial();

    for (auto& textBox : textBoxes)
    {
        textBox->Update();
    }

    for (auto& focus : focuses)
    {
        focus->update();
    }

    timer++;
}

//--------------------------------
//  �n�`�`��
//--------------------------------
void TutorialBG::drawTerrain()
{
    //�}�b�v
    texture::begin(Tile01);
    for (int s = 0; s < STAGE_NUM; s++)
    {
        if (!isDrawStage[s])break;
        for (int x = 0; x < CHIP_NUM_X; x++)
        {
            for (int y = 0; y < CHIP_NUM_Y; y++)
            {
                //CHANGED:float a = terrain_back_T[0][y][x];
                float a = terrain_back_T[s][y][x];
                texture::draw(
                    TexNo::Tile01,
                    terrainData[s][y][x].currentPos.x, terrainData[s][y][x].currentPos.y,
                    1.0, 1.0,
                    CHIP_SIZE_F * a, 0,
                    CHIP_SIZE_F * (a + 1), CHIP_SIZE_F
                );
                if (a == 2) //WARNIG: magic number
                {
                    texture::draw(
                        TexNo::Tile01,
                        terrainData[s][y][x].currentPos.x, terrainData[s][y][x].currentPos.y,
                        1.0, 1.0,
                        CHIP_SIZE_F * 1, 0,
                        CHIP_SIZE_F * (1 + 1), CHIP_SIZE_F,
                        0, 0,
                        0,
                        GREEN
                    );
                }
            }
        }
    }
    texture::end(Tile01);

    //�o�N�_��
    texture::begin(Tile02);
    for (int s = 0; s < STAGE_NUM; s++)
    {
        if (!isDrawStage[s])break;
        for (int x = 0; x < CHIP_NUM_X; x++)
        {
            for (int y = 0; y < CHIP_NUM_Y; y++)
            {
                //�ݒu�s�}�X�̕`��
                if (!terrainData[s][y][x].isPutOn && terrainData[s][y][x].status == TerrainStatus::Normal && drag_con)
                {
                    //texture::draw(
                    //    TexNo::Tile02,
                    //    terrainData[s][y][x].currentPos.x, terrainData[s][y][x].currentPos.y,
                    //    1.0f, 1.0f,
                    //    0, 0,
                    //    CHIP_SIZE_F, CHIP_SIZE_F,
                    //    0, 0,
                    //    0,
                    //    1, 0, 1, 0.6f
                    //);
                }
                if (terrainData[s][y][x].status == TerrainStatus::Bomb)
                {
                    //�o�N�_���̕`��
                    //texture::draw(
                    //    TexNo::Tile02,
                    //    Mapterrain_correction.x + (x * CHIP_SIZE_F), Mapterrain_correction.y + (y * CHIP_SIZE_F),
                    //    1.0f, 1.0f,
                    //    0, 0,
                    //    CHIP_SIZE_F, CHIP_SIZE_F,
                    //    0, 0,
                    //    0,
                    //    RED
                    //);
                }
                if (terrainData[s][y][x].status == TerrainStatus::InExplosion)
                {
                    if (terrainData[s][y][x].DelayTimer < 0)
                    {
                        TerrainExplosion[s][y][x].exist = true;
                        //�A�����邽�߂̎��Ԃ̂��炵�����������̂Ŕ�����`��
                        //texture::draw(
                        //    TexNo::Tile02,
                        //    Mapterrain_correction.x + (x * CHIP_SIZE_F), Mapterrain_correction.y + (y * CHIP_SIZE_F),
                        //    1.0f, 1.0f,
                        //    0, 0,
                        //    CHIP_SIZE_F, CHIP_SIZE_F,
                        //    0, 0,
                        //    0,
                        //    BLUE
                        //);
                        terrainData[s][y][x].explosionTimer--;
                    }
                    else if (!terrainData[s][y][x].isChained)
                    {
                        //�����̘A�����n�܂������A�܂��������Ă��Ȃ��o�N�_���̕`��
                        //texture::draw(
                        //    TexNo::Tile02,
                        //    Mapterrain_correction.x + (x * CHIP_SIZE_F), Mapterrain_correction.y + (y * CHIP_SIZE_F),
                        //    1.0f, 1.0f,
                        //    0, 0,
                        //    CHIP_SIZE_F, CHIP_SIZE_F,
                        //    0, 0,
                        //    0,
                        //    RED
                        //);
                    }
                    if (terrainData[s][y][x].isAlredyChanged)
                    {
                        //�o�N�_���̒x�����s���^�C�}�[�̌���
                        terrainData[s][y][x].DelayTimer--;
                    }
                }
                if (terrainData[s][y][x].status == TerrainStatus::BurningFuse)
                {
                    if (burningFuse.Cpos.x == x && burningFuse.Cpos.y == y)
                    {
                        //���ΐ��̕`��
                        //texture::draw(
                        //    TexNo::Tile02,
                        //    Mapterrain_correction.x + (x * CHIP_SIZE_F), Mapterrain_correction.y + (y * CHIP_SIZE_F),
                        //    1.0f, 1.0f,
                        //    0, 0,
                        //    CHIP_SIZE_F, CHIP_SIZE_F,
                        //    0, 0,
                        //    0,
                        //    GREEN
                        //);
                    }
                    else
                    {
                        //���ΐ��̈ʒu���ύX���ꂽ�̂�terrain�̏�Ԃ��ύX����
                        terrainData[s][y][x].status = TerrainStatus::Normal;
                    }
                }
                //�����I��
                if (terrainData[s][y][x].explosionTimer < 0) {
                    //�������I�������̂�terrain�̏�Ԃ�����������
                    InitTerrain(TerrainStatus::Normal, s, x, y);
                    //<HACK>
                    if (terrainData[s][y][x].terrain_endurance <= 0)
                    {
                        terrainData[s][y][x].status = TerrainStatus::UnBreakble;
                        terrain_back_T[s][y][x] = -1;
                    }

                    TerrainExplosion[s][y][x].exist = false;
                }
            }
        }
    }

    //���e�����邩�Ȃ���
    for (int bomb_array = 0; bomb_array < 3; bomb_array++)
    {
        for (int x = 0; x < 3; ++x)
        {
            for (int y = 0; y < 3; ++y)
            {
                int pt_bomb = bomb_pattern_T[bomb_typenum[bomb_array]][bomb_trun[bomb_array]][y][x];
                if (pt_bomb == PatternStatus::IsBomb)
                {
                    texture::draw(
                        TexNo::Tile02,
                        bomb_changepos[bomb_array].x + (x * CHIP_SIZE_F), bomb_changepos[bomb_array].y + (y * CHIP_SIZE_F),
                        1.0f, 1.0f,
                        0, 0,
                        CHIP_SIZE_F, CHIP_SIZE_F,
                        CHIP_SIZE_F * 0.5f, CHIP_SIZE_F * 0.5f,
                        0,
                        1, 1, 0, 1
                    );
                }
            }
        }
    }

    texture::end(Tile02);

    texture::begin(Reset);

    texture::draw(
        TexNo::Reset,
        static_cast<float>(reset_pos.x), static_cast<float>(reset_pos.y),
        static_cast<float>(reset_scale.x), static_cast<float>(reset_scale.y),
        0, 0,
        1000, 1000,
        static_cast<float>(reset_center.x), static_cast<float>(reset_center.y),
        0,
        1, 1, 1, 1
    );

    texture::end(Reset);

    texture::begin(Bomb01);

    for (int bomb_array = 0; bomb_array < 3; bomb_array++)
    {
        for (int x = 0; x < 3; ++x)
        {
            for (int y = 0; y < 3; ++y)
            {
                int pt_bomb = bomb_pattern_T[bomb_typenum[bomb_array]][bomb_trun[bomb_array]][y][x];
                if (pt_bomb == 1)
                {
                    texture::draw(
                        TexNo::Bomb01,
                        bomb_changepos[bomb_array].x + (x * CHIP_SIZE_F), bomb_changepos[bomb_array].y + (y * CHIP_SIZE_F),
                        1.0f, 1.0f,
                        0.0f, 0.0f,
                        CHIP_SIZE_F, CHIP_SIZE_F,
                        CHIP_SIZE_F * 0.5f, CHIP_SIZE_F * 0.5f,
                        0,
                        1, 1, 1, 1
                    );
                }
            }
        }
    }

    for (int s = 0; s < STAGE_NUM; s++)
    {
        if (!isDrawStage[s])break;
        for (int x = 0; x < CHIP_NUM_X; x++)
        {
            for (int y = 0; y < CHIP_NUM_Y; y++)
            {
                if ((terrainData[s][y][x].status == TerrainStatus::Bomb) || (terrainData[s][y][x].status == TerrainStatus::InExplosion && !terrainData[s][y][x].isChained) && terrainData[s][y][x].DelayTimer >= 25)
                {
                    texture::draw(
                        TexNo::Bomb01,
                        terrainData[s][y][x].currentPos.x + TerrainCenter_correction.x, terrainData[s][y][x].currentPos.y + TerrainCenter_correction.y,
                        1.0f, 1.0f,
                        0.0f, 0.0f,
                        CHIP_SIZE_F, CHIP_SIZE_F,
                        CHIP_SIZE_F * 0.5f, CHIP_SIZE_F * 0.5f,
                        0,
                        1, 1, 1, 1
                    );
                }
                if (terrainData[s][y][x].status == TerrainStatus::InExplosion && !terrainData[s][y][x].isChained)
                {
                    if (!terrainData[s][y][x].isChained && terrainData[s][y][x].DelayTimer < 25)
                    {
                        //�����̘A�����n�܂������A�܂��������Ă��Ȃ��o�N�_���̕`��
                        texture::draw(
                            TexNo::Bomb01,
                            terrainData[s][y][x].currentPos.x + TerrainCenter_correction.x, terrainData[s][y][x].currentPos.y + TerrainCenter_correction.y,
                            1.0f, 1.0f,
                            TerrainBomb[s][y][x].texSizeX * TerrainBomb[s][y][x].animeNum, 0.0f,
                            TerrainBomb[s][y][x].texSizeX, TerrainBomb[s][y][x].ty / 10,
                            CHIP_SIZE_F * 0.5f, CHIP_SIZE_F * 0.5f,
                            0,
                            1, 1, 1, 1
                        );
                    }
                }
            }
        }
    }

    texture::end(Bomb01);

    debug::setString("act:%d", act);
    debug::setString("score:%d", score);
    debug::setString("stage:%d", nowStage);

    texture::begin(Explosion);
    for (int s = 0; s < STAGE_NUM; s++)
    {
        if (!isDrawStage[s])break;
        for (int x = 0; x < CHIP_NUM_X; x++)
        {
            for (int y = 0; y < CHIP_NUM_Y; y++)
            {
                if (TerrainExplosion[s][y][x].exist)
                {
                    texture::draw(
                        TexNo::Explosion,
                        terrainData[s][y][x].currentPos.x + TerrainCenter_correction.x, terrainData[s][y][x].currentPos.y + TerrainCenter_correction.y,
                        0.8f, 0.8f,
                        TerrainExplosion[s][y][x].texSizeX * TerrainExplosion[s][y][x].animeNum, 0.0f,
                        TerrainExplosion[s][y][x].texSizeX, TerrainExplosion[s][y][x].ty,
                        120.0f / 2, 120.0f / 2,
                        0,
                        1, 1, 1, 1
                    );
                }
            }
        }
    }
    texture::end(Explosion);

    bool isBurningFuse = false;
    for (int s = 0; s < STAGE_NUM; s++)
    {
        if (!isDrawStage[s])break;
        for (int x = 0; x < CHIP_NUM_X; x++)
        {
            for (int y = 0; y < CHIP_NUM_Y; y++)
            {
                if (terrainData[s][y][x].status == TerrainStatus::BurningFuse)
                    isBurningFuse = true;
            }
        }
    }

    burningFuse.exist = isBurningFuse ? true : false;

    static GameLib::Sprite* fire_image = nullptr;
    fire_image = sprite_load(FIRE03);

    if (burningFuse.exist)
    {
        burningFuse.effectFire(fire_image, 6);
    }

    delete fire_image;

    texture::begin(Shape);

    //�ݒu�s�}�X�̕`��
    for (int s = 0; s < STAGE_NUM; s++)
    {
        if (!isDrawStage[s])break;
        for (int x = 0; x < CHIP_NUM_X; x++)
        {
            for (int y = 0; y < CHIP_NUM_Y; y++)
            {
                if (!terrainData[s][y][x].isPutOn && (drag_con || isShowUnPutBle) && (terrainData[s][y][x].status == TerrainStatus::Normal || terrainData[s][y][x].status == TerrainStatus::BurningFuse))
                {
                    texture::draw(
                        TexNo::Shape,
                        terrainData[s][y][x].currentPos.x, terrainData[s][y][x].currentPos.y,
                        4.0f, 4.0f,
                        48.0f, 16.0f,
                        16.0f, 16.0f,
                        0, 0,
                        0,
                        1, 1, 1, 0.75f
                    );
                }
                if (!terrainData[s][y][x].isPutOn && terrainData[s][y][x].status == TerrainStatus::Bomb && (drag_con || isShowUnPutBle))
                {
                    texture::draw(
                        TexNo::Shape,
                        terrainData[s][y][x].currentPos.x, terrainData[s][y][x].currentPos.y,
                        4.0f, 4.0f,
                        16.0f, 16.0f,
                        16.0f, 16.0f,
                        0, 0,
                        0,
                        1, 1, 1, 0.75f
                    );
                }
            }
        }
    }
    
    texture::end(Shape);

    for (auto& focus : focuses)
    {
        focus->render();
    }

    for (auto& textBox : textBoxes)
    {
        textBox->Render(/*TexNo::TutorialText1, TexNo::Reset*/);
    }
}


//�`���[�g���A��
void TutorialBG::Tutorial()
{
    switch (tutorialNum)
    {
    case 0:
        Tutorial_0();
        break;
    case 1:
        Tutorial_1();
        break;
    case 2:
        Tutorial_2();
        break;
    }
}

void TutorialBG::Tutorial_0()
{
    bool isActionTerrain = false;
    bool isSetFuse = false;
    for (int x = 0; x < CHIP_NUM_X && !isSetFuse && !isActionTerrain; x++)
    {
        for (int y = 0; y < CHIP_NUM_Y && !isSetFuse && !isActionTerrain; y++)
        {
            if (terrainData[nowStage][y][x].status == TerrainStatus::BurningFuse)
            {
                isSetFuse = true;
            }
            if (terrainData[nowStage][y][x].status == TerrainStatus::Bomb
                || terrainData[nowStage][y][x].status == TerrainStatus::InExplosion
                || terrainData[nowStage][y][x].status == TerrainStatus::BurningFuse)
            {
                isActionTerrain = true;
            }
        }
    }
    if (stageAct[nowStage] > 1 && !isActionTerrain)
    {
        isTutorialClear[nowStage] = true;
    }

    //stageMover
    {
        stageMovers[3]->SetInChangeStageIndex(false);
        stageMovers[3]->SetSrcIndex(4);
        stageMovers[3]->SetDstIndex(-1);

        stageMovers[3]->SetMoveFlag(textBoxes[3]->GetPopUpFlag());

        stageMovers[4]->SetInChangeStageIndex(false);
        stageMovers[4]->SetSrcIndex(-1);
        stageMovers[4]->SetDstIndex(4);

        stageMovers[4]->SetMoveFlag(textBoxes[2]->GetPopOutFlag());

        stageMovers[0]->SetMoveFlag(isTutorialClear[nowStage]);
    }

    //textBox
    {
        for (auto& textBox : textBoxes)
        {
            textBox->SetTextTexture(TEXT1);
            textBox->SetClickTexture(RESET);
        }

        textBoxes[4]->IsNotDrawClickHere();
        textBoxes[3]->IsNotDrawClickHere();
        textBoxes[2]->IsNotDrawClickHere();
        textBoxes[0]->SetPosition(VECTOR2(200, 400));

        //�`���[�g���A���ւ悤����
        textBoxes[0]->SetPopUpFlag(timer > 10);
        textBoxes[0]->SetPopOutFlag(isClickL && textBoxes[0]->WaitTime(30));

        //�΂����Ĕ��e�̔�����A�������A�n�C�X�R�A��_���܂��傤
        textBoxes[1]->SetPopUpFlag(textBoxes[0]->GetPopOutFlag());
        textBoxes[1]->SetPopOutFlag(isClickL && textBoxes[1]->WaitTime(30));

        //�܂��A�΂��������ꏊ�ɂ��L�[�ŉ΂�t���܂��傤
        textBoxes[2]->SetPopUpFlag(textBoxes[1]->GetPopOutFlag());
        textBoxes[2]->SetPopOutFlag(isSetFuse && textBoxes[2]->WaitTime(45));

        //���ɔ��e��ݒu���܂����A���������ӂ��ׂ����Ƃ�����܂��B

        if (textBoxes[5]->GetPopUpFlag())isShowUnPutBle = true;
        textBoxes[5]->SetPopUpFlag(textBoxes[2]->GetPopOutFlag());
        textBoxes[5]->SetPopOutFlag(isClickL && textBoxes[5]->WaitTime(45));

        //���e��ݒu����ꏊ�ɐԂ��o�c�󂪂���΂��̏ꏊ�ɔ��e��u�����Ƃ��ł��܂���

        textBoxes[6]->SetPopUpFlag(textBoxes[5]->GetPopOutFlag());
        textBoxes[6]->SetPopOutFlag(isClickL && textBoxes[6]->WaitTime(45));

        //�܂��A�ݒu�\��̏ꏊ���S�Ď��̎O�p�`�Ȃ�΂��̏ꍇ�ł��u�����Ƃ��ł��܂���

        textBoxes[7]->SetPopUpFlag(textBoxes[6]->GetPopOutFlag());
        textBoxes[7]->SetPopOutFlag(isClickL && textBoxes[7]->WaitTime(45));

        //�΂̃}�X�ɔ��e��u�����ƂŔ��e�𔚔��ł��܂�
        if (textBoxes[3]->GetPopUpFlag())isShowUnPutBle = false;
        textBoxes[3]->SetPopUpFlag(textBoxes[7]->GetPopOutFlag());
        textBoxes[3]->SetPopOutFlag(drag_con);

        //�����A�΂̃}�X�ɔ��e��u���Ȃ��󋵂Ɋׂ�����A���Z�b�g�{�^���������܂��傤
        textBoxes[4]->SetPopUpFlag(textBoxes[3]->GetPopOutFlag() && !focuses[0]->IsDraw());
        textBoxes[4]->SetPopOutFlag(isTutorialClear[nowStage]);
    }

    //focus
    {
        focuses[0]->SetFocusPos(VECTOR2(400, 175));
        focuses[0]->SetRadius(250.0f);
        focuses[1]->SetFocusPos(VECTOR2(1150, 360));
        focuses[1]->SetFocusSize(VECTOR2(1.1f, 1.9f));
        focuses[2]->SetFocusPos(VECTOR2(800, 175));
        focuses[3]->SetFocusPos(VECTOR2(800, 480));

        focuses[0]->SetFocusFlag(textBoxes[2]->GetPopUpFlag());
        focuses[0]->SetUnFocusFlag(textBoxes[2]->GetPopOutFlag());

        focuses[1]->SetFocusFlag(textBoxes[3]->GetPopUpFlag() && !focuses[0]->IsDraw());
        focuses[1]->SetUnFocusFlag(drag_con);   //�{���������Ă��鎞

        focuses[2]->SetFocusFlag(textBoxes[6]->GetPopUpFlag());
        focuses[2]->SetUnFocusFlag(textBoxes[6]->GetPopOutFlag());

        focuses[3]->SetFocusFlag(textBoxes[7]->GetPopUpFlag());
        focuses[3]->SetUnFocusFlag(textBoxes[7]->GetPopOutFlag());
    }
}

void TutorialBG::Tutorial_1()
{
    bool isActionTerrain = false;
    bool isSetFuse = false;
    bool isNotBrakbleTerrain = true;
    for (int x = 0; x < CHIP_NUM_X; x++)
    {
        for (int y = 0; y < CHIP_NUM_Y; y++)
        {
            if (terrainData[nowStage][y][x].status == TerrainStatus::BurningFuse)
            {
                isSetFuse = true;
            }
            if (terrainData[nowStage][y][x].status == TerrainStatus::Bomb
                || terrainData[nowStage][y][x].status == TerrainStatus::InExplosion
                || terrainData[nowStage][y][x].status == TerrainStatus::BurningFuse)
            {
                isActionTerrain = true;
            }
            if ((terrain_back_T[nowStage][y][x] == 2))
            {
                isNotBrakbleTerrain = false;
            }
        }
    }
    if (stageAct[nowStage] > 1 && !isActionTerrain)
    {
        isTutorialClear[nowStage] = true;
    }

    //stageMover
    {
        stageMovers[1]->SetMoveFlag(textBoxes[3]->GetPopOutFlag());
    }

    //textBox
    {
        for (auto& textBox : textBoxes)
        {
            textBox->SetTextTexture(TEXT1);
            textBox->SetClickTexture(RESET);
        }

        textBoxes[4]->IsNotDrawClickHere();

        textBoxes[1]->IsNotDrawClickHere();
        textBoxes[2]->IsNotDrawClickHere();

        //���̃u���b�N�ƌ����ڂ��Ⴄ�u���b�N������܂�
        //�󂵂Ă݂܂��傤
        textBoxes[0]->SetPopUpFlag(true);
        textBoxes[0]->SetPopOutFlag(isClickL);

        //�΂�u�������ꏊ�ɃJ�[�\���������Ăw
        textBoxes[1]->SetPopUpFlag(textBoxes[0]->GetPopOutFlag());
        textBoxes[1]->SetPopOutFlag(isSetFuse);

        //�c���c�Ŕ��e��ݒu
        textBoxes[2]->SetPopUpFlag(textBoxes[1]->GetPopOutFlag());
        textBoxes[2]->SetPopOutFlag(drag_con);

        //�q�r�������Ă���u���b�N��S�ĉ�
        textBoxes[4]->SetPopUpFlag(textBoxes[1]->GetPopOutFlag());
        textBoxes[4]->SetPopOutFlag(isNotBrakbleTerrain);

        //���̂悤�ɂЂт������Ă���u���b�N�͈�x�����𓖂Ă�Ɖ��Ă��܂��܂�
        textBoxes[3]->SetPopUpFlag(textBoxes[4]->GetPopOutFlag() && textBoxes[4]->WaitTime(40));
        textBoxes[3]->SetPopOutFlag(isClickL);
    }

    //focus
    {
        focuses[0]->SetFocusPos(VECTOR2(400, 175));
        focuses[0]->SetRadius(250.0f);
        focuses[1]->SetFocusPos(VECTOR2(1150, 360));
        focuses[1]->SetFocusSize(VECTOR2(1.1f, 1.9f));

        focuses[0]->SetFocusFlag(textBoxes[0]->GetPopUpFlag());
        focuses[0]->SetUnFocusFlag(textBoxes[1]->GetPopOutFlag());

        focuses[1]->SetFocusFlag(!focuses[0]->IsDraw() && textBoxes[2]->GetPopUpFlag());
        focuses[1]->SetUnFocusFlag(drag_con);   //�{���������Ă��鎞
    }
}

void TutorialBG::Tutorial_2()
{
    bool isActionTerrain = false;
    bool isSetFuse = false;
    bool isNotBrakbleTerrain = true;
    for (int x = 0; x < CHIP_NUM_X; x++)
    {
        for (int y = 0; y < CHIP_NUM_Y; y++)
        {
            if (terrainData[nowStage][y][x].status == TerrainStatus::BurningFuse)
            {
                isSetFuse = true;
            }
            if (terrainData[nowStage][y][x].status == TerrainStatus::Bomb
                || terrainData[nowStage][y][x].status == TerrainStatus::InExplosion
                || terrainData[nowStage][y][x].status == TerrainStatus::BurningFuse)
            {
                isActionTerrain = true;
            }
            if ((terrain_back_T[nowStage][y][x] == 2))
            {
                isNotBrakbleTerrain = false;
            }
        }
    }

    //stageMover
    {
        //stageMovers[2]->SetMoveFlag(isC);
    }

    //textBox
    {
        textBoxes[1]->IsNotDrawClickHere();
        textBoxes[2]->IsNotDrawClickHere();

        textBoxes[0]->SetPopUpFlag(true);
        textBoxes[0]->SetPopOutFlag(isClickL);

        //textBoxes[1]->SetPopUpFlag(textBoxes[0]->GetPopOutFlag());
        //textBoxes[1]->SetPopOutFlag(isSetFuse);

        //textBoxes[2]->SetPopUpFlag(textBoxes[1]->GetPopOutFlag());
        //textBoxes[2]->SetPopOutFlag(drag_con);

        //textBoxes[3]->SetPopUpFlag(isNotBrakbleTerrain);
        //textBoxes[3]->SetPopOutFlag(isClickL);
    }

    //focus
    {
    //    focuses[0]->SetFocusPos(VECTOR2(400, 175));
    //    focuses[0]->SetRadius(250.0f);

        //focuses[0]->SetFocusFlag(true);
        //focuses[0]->SetUnFocusFlag(textBoxes[1]->GetPopOutFlag());

        for (auto& focus : focuses)
        {
            focus->isDraw = false;
            //focus->Reset();
        }
    }
}

//���e���h���b�O
void TutorialBG::dragBomb()
{
    for (int bomb_array = 0; bomb_array < BOMB_ROTATE_MAX; bomb_array++)
    {
        for (int x = 0; x < 3; ++x)
        {
            for (int y = 0; y < 3; ++y)
            {
                //���e�̎�ގ擾
                int pt_bomb = bomb_pattern_T[bomb_typenum[bomb_array]][bomb_trun[bomb_array]][y][x];

                if (pt_bomb == PatternStatus::IsBomb)
                {
                    int bomb_array_vaut = bomb_array;
                    if (bomb_movingtype)bomb_array = bomb_waitingarea;
                    DirectX::XMFLOAT2 bomb_pos;
                    //���e1�u���b�N���S���W(�X�N���[�����W�{�z��[y][x]�ڂ̃u���b�N)
                    bomb_pos = { bomb_changepos[bomb_array].x + CHIP_SIZE * x,bomb_changepos[bomb_array].y + CHIP_SIZE * y };
                    //�����蔻��||�J�[�\�����x���������邱�Ƃ̑Ή�
                    if (collision_center(cursorPos, bomb_pos, chip_size_xmfloat2) || drag_con)
                    {
                        if (GameLib::input::STATE(0) & GameLib::input::PAD_LC)
                        {
                            //���e�̈ʒu���J�[�\���̈ʒu�ɒǏ]
                            bomb_changepos[bomb_array] = cursorPos;
                            bomb_waitingarea = bomb_array;
                            bomb_movingtype = true;
                            drag_con = true;
                        }
                    }
                    bomb_array = bomb_array_vaut;
                }
            }
        }
        if (drag_con)break;//�h���b�O���Ă���ꍇ1�̔��e�ɌŒ�
    }
}

//���e����]
void TutorialBG::rotateBomb()
{
    if (GameLib::input::TRG(0) & GameLib::input::PAD_RC)
    {
        bomb_trun[bomb_waitingarea]++;
        if (bomb_trun[bomb_waitingarea] > 3)bomb_trun[bomb_waitingarea] = 0;
    }
}

//���e���h���b�v
void TutorialBG::dropBomb()
{
    if (GameLib::input::TRG_RELEASE(0) & GameLib::input::PAD_LC)
    {
        drag_con = false;
        isReset = false;
    }
}

//���e�����Z�b�g
void TutorialBG::resetButton()
{
    //���Z�b�g
    reset_scale = { 0.45f,0.45f };
    reset_pos = { 90,650 };
    reset_center = { 200, 100 };
    if (collision_center(cursorPos, reset_pos, reset_center))
    {
        reset_scale = { 0.5f,0.5f };
        if (GameLib::input::TRG(0) & GameLib::input::PAD_LC && drag_con == false)
        {
            isReset = true;

            bomb_changepos[bomb_waitingarea] = bomb_defpos[bomb_waitingarea];//�ʒu�������ʒu�ɖ߂�

            //���e�̎�ނ�ς���
            int  defnum = bomb_typenum[bomb_waitingarea];
            bomb_trun[bomb_waitingarea] = 0;//��]�������p�x�ɖ߂�
            bomb_movingtype = false;
            bomb_roopchecker = false;

            //�n�`�f�[�^terrain_back��bomb�n�`�f�[�^terrain�ɑ������
            for (int x = 0; x < CHIP_NUM_X; x++)
            {
                for (int y = 0; y < CHIP_NUM_Y; y++)
                {
                    //bomb�n�`�̏���������
                    InitTerrain(TerrainStatus::Normal, nowStage, x, y);

                    if (terrainData[nowStage][y][x].status == TerrainStatus::Bomb)
                    {
                        terrainData[nowStage][y][x].status = TerrainStatus::Normal;
                    }

                    //�G�t�F�N�g�̏���������
                    TerrainBomb[nowStage][y][x].pos = VECTOR2(x * CHIP_SIZE_F, y * CHIP_SIZE_F);
                    TerrainBomb[nowStage][y][x].animeNum = 3;
                    TerrainBomb[nowStage][y][x].exist = false;
                }
            }

            //�o�N�_���̎�ނ�������
            for (int i = 0; i < BOMB_TYPE_MAX; i++)
            {
                //���e�̎�ތ���
                int defnum = bomb_typenum[i];
                bomb_typenum[i] = bomb_numchanger_T(bomb_typenum[i], defnum);
                if (i > 1 && bomb_typenum[i] == bomb_typenum[i - 2])bomb_typenum[i] = bomb_numchanger_T(bomb_typenum[i], bomb_typenum[i - 2]);//1�T�ڂ̔��e�Ɠ�����ނȂ�ύX
                if (i > 0 && bomb_typenum[i] == bomb_typenum[i - 1])bomb_typenum[i] = bomb_numchanger_T(bomb_typenum[i], bomb_typenum[i - 1]);//0�T�ڂ̔��e�Ɠ�����ނȂ�ύX
                bomb_trun[i] = 0;
            }
        }
    }
}

//���e��u������̃��Z�b�g
void TutorialBG::resetBombPostProcess()
{
    if (bomb_reset)
    {
        bomb_changepos[bomb_waitingarea] = bomb_defpos[bomb_waitingarea];//�ʒu�������ʒu�ɖ߂�

        //���e�̎�ނ�ς���
        int  defnum = bomb_typenum[bomb_waitingarea];
        bomb_typenum[bomb_waitingarea] = bomb_numchanger_T(bomb_typenum[bomb_waitingarea], defnum);
        bomb_trun[bomb_waitingarea] = 0;//��]�������p�x�ɖ߂�
        bomb_movingtype = false;
        bomb_roopchecker = false;
        bomb_reset = false;//���Z�b�g���������ăh���b�O�ł���悤�ɂ���
    }
}

//���̃u���b�N�Ƀo�N�_�����ݒu�\��
void TutorialBG::SetIsPutOn()
{
    for (int s = 0; s < STAGE_NUM; s++)
    {
        for (int x = 0; x < CHIP_NUM_X; x++)
        {
            for (int y = 0; y < CHIP_NUM_Y; y++)
            {
                //�O���͔��e�}�X��u���Ȃ�
                if (x == 0 || y == 0)
                {
                    terrainData[s][y][x].isPutOn = false;
                    continue;
                }

                //���ΐ��}�X�����ʂ̃}�X�ȊO�͒u���Ȃ�
                if (terrainData[s][y][x].status != TerrainStatus::BurningFuse &&
                    terrainData[s][y][x].status != TerrainStatus::Normal)
                {
                    terrainData[s][y][x].isPutOn = false;
                    continue;
                }

                //�ǁA�܂��͔��e�}�X�ɗאڂ��Ă��Ȃ��ƒu���Ȃ�
                if (!IsPutOn(s, y, x))
                {
                    terrainData[s][y][x].isPutOn = false;
                    continue;
                }

                terrainData[s][y][x].isPutOn = true;
            }
        }
    }
}

bool TutorialBG::IsPutOn(int s, int y, int x)
{
    int adjacentTerrainStatus[] = {
    0,                             //CENTER
    terrainData[s][y][x - 1].status,  //LEFT
    terrainData[s][y - 1][x].status,  //TOP
    terrainData[s][y][x + 1].status,  //RIGHT
    terrainData[s][y + 1][x].status,  //BOTTOM
    };

    if (SearchAdjacentTerrain(adjacentTerrainStatus[LEFT])  ||
        SearchAdjacentTerrain(adjacentTerrainStatus[TOP])   ||
        SearchAdjacentTerrain(adjacentTerrainStatus[RIGHT]) ||
        SearchAdjacentTerrain(adjacentTerrainStatus[BOTTOM])) return true;

    return false;
}

bool TutorialBG::SearchAdjacentTerrain(int status)
{
    return (status == TerrainStatus::UnBreakble || status == TerrainStatus::Bomb) ? true : false;
}

//--------------------------------
//  �X�e�[�W���ړ�������
//--------------------------------
bool TutorialBG::moveStages(std::unique_ptr<StageMover> &stageMover)
{
    if (stageMover->IsMove())
    {
        bool isFinishMove[2] = {
            moveStage(stageMover->GetSrcIndex(),MoveType::InGameToEnd),
            moveStage(stageMover->GetDstIndex(),MoveType::StartToInGame)
        };

        if (!isFinishMove[0] && !isFinishMove[1])
        {
            if (stageMover->IsChangeStageIndex())
            {
                nowStage++;
                tutorialNum++;
                isDrawStage[nowStage - 1];
                for (auto& textBox : textBoxes)textBox->Reset();;
                for (auto& focus : focuses)focus->Reset();
            }
            stageMover->FinishMove();
        }

        return true;
    }

    return false;
}
bool TutorialBG::moveStage(int stageNum, MoveType moveType)
{
    switch (moveType)
    {
    case MoveType::StartToInGame:
        if (stageNum >= 0)
        {
            for (int x = 0; x < CHIP_NUM_X; x++)
            {
                for (int y = 0; y < CHIP_NUM_Y; y++)
                {
                    XMVECTOR CurrentPos = XMVectorSet(terrainData[stageNum][y][x].currentPos.x, terrainData[stageNum][y][x].currentPos.y, 0, 0);
                    XMVECTOR EndPos = XMVectorSet(terrainData[stageNum][y][x].inGamePos.x, terrainData[stageNum][y][x].inGamePos.y, 0, 0);
                    XMStoreFloat2(&terrainData[stageNum][y][x].currentPos, XMVectorLerp(CurrentPos, EndPos, weight));

                    //�X�e�[�W�̍Ō�̃}�b�v�`�b�v�̎��̂ݎ��s
                    if (y == CHIP_NUM_Y - 1 && x == CHIP_NUM_X - 1)
                    {
                        XMVECTOR LengthSq = XMVector2Length(XMVectorSubtract(EndPos, CurrentPos));
                        float lengthSq;
                        XMStoreFloat(&lengthSq, LengthSq);
                        if (lengthSq < 10.0f)
                        {
                            weight = 0.082f;
                            if (lengthSq < 2.0f)
                            {
                                //���̊֐����I��点��
                                for (int x = 0; x < CHIP_NUM_X; x++)
                                {
                                    for (int y = 0; y < CHIP_NUM_Y; y++)
                                    {
                                        weight = 0.041f;
                                        terrainData[stageNum][y][x].currentPos = terrainData[stageNum][y][x].inGamePos;
                                    }
                                }
                                return false;
                            }
                        }
                    }
                }
            }
        }
        else return false;
        break;
    case MoveType::InGameToEnd:
        if (stageNum >= 0)
        {
            for (int x = 0; x < CHIP_NUM_X; x++)
            {
                for (int y = 0; y < CHIP_NUM_Y; y++)
                {
                    XMVECTOR CurrentPos = XMVectorSet(terrainData[stageNum][y][x].currentPos.x, terrainData[stageNum][y][x].currentPos.y, 0, 0);
                    XMVECTOR EndPos = XMVectorSet(terrainData[stageNum][y][x].endPos.x, terrainData[stageNum][y][x].endPos.y, 0, 0);
                    XMStoreFloat2(&terrainData[stageNum][y][x].currentPos, XMVectorLerp(CurrentPos, EndPos, weight));

                    //�X�e�[�W�̍Ō�̃}�b�v�`�b�v�̎��̂ݎ��s
                    if (y == CHIP_NUM_Y - 1 && x == CHIP_NUM_X - 1)
                    {
                        XMVECTOR LengthSq = XMVector2Length(XMVectorSubtract(EndPos, CurrentPos));
                        float lengthSq;
                        XMStoreFloat(&lengthSq, LengthSq);
                        if (lengthSq < 1.0f)
                        {
                            //���̊֐����I��点��
                            for (int x = 0; x < CHIP_NUM_X; x++)
                            {
                                for (int y = 0; y < CHIP_NUM_Y; y++)
                                {
                                    terrainData[stageNum][y][x].currentPos = terrainData[stageNum][y][x].endPos;
                                }
                            }
                            return false;
                        }
                    }
                }
            }
        }
        else return false;
        break;
    }

    return true;
}

//--------------------------------
//  �X�e�[�W�̈ړ��t���O��ݒ�
//--------------------------------
void TutorialBG::setMoveFlags()
{

}

//--------------------------------
//  �w�肵���ӏ��ɂ��łɕύX���������Ă��邩
//--------------------------------
bool TutorialBG::IsAlreadyChanged(int stageNum, DirectX::XMINT2 terrainPos)
{
    return terrainData[stageNum][terrainPos.x][terrainPos.y].isAlredyChanged;
}

//--------------------------------
//  �o�N�_����ݒu
//--------------------------------
void TutorialBG::SetBomb(int stageNum, DirectX::XMINT2 terrainPos, ExplosionPoint point, int delayIndex)
{
    if (!IsAlreadyChanged(stageNum, terrainPos)) {
        terrainData[stageNum][terrainPos.x][terrainPos.y].status = SetExplosionPoint(stageNum, terrainPos, point, delayIndex);
    }
    score_add += 10;
    score_counter++;
    if (terrainData[stageNum][terrainPos.x][terrainPos.y].terrain_enduranceC == terrainData[stageNum][terrainPos.x][terrainPos.y].terrain_endurance)terrainData[stageNum][terrainPos.x][terrainPos.y].terrain_endurance--;
}

//--------------------------------
//  �A�����I���
//--------------------------------
void TutorialBG::finishChain(int stageNum, DirectX::XMINT2 terrainPos)
{
    terrainData[stageNum][terrainPos.x][terrainPos.y].isChained = true;
}

//--------------------------------
//  terrain�̏�����
//--------------------------------
void TutorialBG::InitTerrain(TerrainStatus terrainStatus, int stageNum, DirectX::XMINT2 terrainPos)
{
    //TerrainStatus::None�̎��A��Ԃ�ύX���Ȃ�
    if (terrainStatus != TerrainStatus::None)
    {
        if (terrainData[stageNum][terrainPos.y][terrainPos.x].status != TerrainStatus::UnBreakble)
            terrainData[stageNum][terrainPos.y][terrainPos.x].status = terrainStatus;
    }
    //terrainData��������
    terrainData[stageNum][terrainPos.y][terrainPos.x].explosionTimer  = explosionTime;
    terrainData[stageNum][terrainPos.y][terrainPos.x].DelayTimer      = delayTime;
    terrainData[stageNum][terrainPos.y][terrainPos.x].isAlredyChanged = false;
    terrainData[stageNum][terrainPos.y][terrainPos.x].isChained       = false;
}

void TutorialBG::InitTerrain(TerrainStatus terrainStatus, int s, int x, int y)
{
    InitTerrain(terrainStatus, s, DirectX::XMINT2(x, y));
}

void TutorialBG::SetTerrainPos(DirectX::XMINT2 terrainPos, int stageNum)
{
    DirectX::XMFLOAT2 startPos;
    DirectX::XMFLOAT2 inGamePos;
    DirectX::XMFLOAT2 endPos;

    switch (stageNum)
    {
    case 2:
        inGamePos = XMFLOAT2(
            Mapterrain_correction.x + (terrainPos.x * CHIP_SIZE_F),
            Mapterrain_correction.y + (terrainPos.y * CHIP_SIZE_F));
        startPos = XMFLOAT2(
            inGamePos.x - static_cast<float>(window::getWidth()) * 1.77f,
            inGamePos.y);
        endPos = XMFLOAT2(
            inGamePos.x + static_cast<float>(window::getWidth()) * 1.77f,
            inGamePos.y);
        break;
    default:
        inGamePos = XMFLOAT2(
            Mapterrain_correction.x + (terrainPos.x * CHIP_SIZE_F),
            Mapterrain_correction.y + (terrainPos.y * CHIP_SIZE_F));
        startPos = XMFLOAT2(
            inGamePos.x,
            inGamePos.y + static_cast<float>(window::getHeight()));
        endPos = XMFLOAT2(
            inGamePos.x,
            inGamePos.y - static_cast<float>(window::getHeight()));
        break;
    }

    terrainData[stageNum][terrainPos.y][terrainPos.x].startPos = startPos;
    terrainData[stageNum][terrainPos.y][terrainPos.x].inGamePos = inGamePos;
    terrainData[stageNum][terrainPos.y][terrainPos.x].endPos = endPos;

    //�ŏ��̃X�e�[�W�͏����l��imGamePos(��ʒ���)�A����ȊO�͏����l��startPos�ɂ���
    DirectX::XMFLOAT2 defaultPos = stageNum == 0 ? inGamePos : startPos;
    terrainData[stageNum][terrainPos.y][terrainPos.x].currentPos = defaultPos;
}

//--------------------------------
//  ���ΐ���u���邩
//--------------------------------
bool TutorialBG::IsPutOnFuse()
{
    for (int x = 0; x < CHIP_NUM_X; x++)
    {
        for (int y = 0; y < CHIP_NUM_Y; y++)
        {
            if (terrainData[nowStage][y][x].status == TerrainStatus::InExplosion)
            {
                isPutOnFuse = false;
                return false;
            }
        }
    }

    isPutOnFuse = true;
    return true;
}

//--------------------------------
//  �w�肵���ӏ��̏����Z�b�g
//--------------------------------
void TutorialBG::SetTerrainData(int stageNum, DirectX::XMINT2 terrainPos, int delayIndex)
{
    if (!terrainData[stageNum][terrainPos.x][terrainPos.y].isAlredyChanged)
    {
        terrainData[stageNum][terrainPos.x][terrainPos.y].DelayTimer = delayIndex * delayTime;
        terrainData[stageNum][terrainPos.x][terrainPos.y].isAlredyChanged = true;
    }
}

//--------------------------------
//  �G�t�F�N�g���X�V
//--------------------------------
void TutorialBG::updateEffect(TerrainEffect& effect)
{
    if (effect.exist)
    {
        effect.timer += effect.playSpeed;

        if (effect.timer > (effect.tx / effect.texSizeX))
        {
            effect.timer = 0;
            effect.animeNum++;
            if (effect.animeNum > effect.animeMax)
            {
                effect.timer = 0;
                effect.animeNum = 0;
                effect.exist = false;
            }
        }
    }
}

//--------------------------------
//  �����ӏ��̌v�Z
//--------------------------------
DirectX::XMINT2 TutorialBG::CalcExplosionPoint(DirectX::XMINT2 BaseExplosionPoint, ExplosionPoint point)
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

DirectX::XMINT2 TutorialBG::CalcCenterPoint(DirectX::XMINT2 BaseExplosionPoint)
{
    DirectX::XMINT2 centerPoint(BaseExplosionPoint.y, BaseExplosionPoint.x);
    return centerPoint;
}

DirectX::XMINT2 TutorialBG::CalcLeftPoint(DirectX::XMINT2 BaseExplosionPoint)
{
    DirectX::XMINT2 leftPoint(BaseExplosionPoint.y, BaseExplosionPoint.x - 1);
    return leftPoint;
}

DirectX::XMINT2 TutorialBG::CalcTopPoint(DirectX::XMINT2 BaseExplosionPoint)
{
    DirectX::XMINT2 topPoint(BaseExplosionPoint.y - 1, BaseExplosionPoint.x);
    return topPoint;
}

DirectX::XMINT2 TutorialBG::CalcRightPoint(DirectX::XMINT2 BaseExplosionPoint)
{
    DirectX::XMINT2 rightPoint(BaseExplosionPoint.y, BaseExplosionPoint.x + 1);
    return rightPoint;
}

DirectX::XMINT2 TutorialBG::CalcBottomPoint(DirectX::XMINT2 BaseExplosionPoint)
{
    DirectX::XMINT2 bottomPoint(BaseExplosionPoint.y + 1, BaseExplosionPoint.x);
    return bottomPoint;
}

//--------------------------------
//  �����ݒ�
//--------------------------------
int TutorialBG::SetExplosionPoint(int stageNum, DirectX::XMINT2 explosionPoint, ExplosionPoint point, int delayIndex)
{
    switch (point)
    {
    case ExplosionPoint::CENTER:
    {
        int center = terrainData[stageNum][explosionPoint.x][explosionPoint.y].status;
        return SetCenterPoint(stageNum, center, explosionPoint, ++delayIndex);
        break;
    }
    case ExplosionPoint::LEFT:
    {
        DirectX::XMINT2 centerPos{ explosionPoint.x,explosionPoint.y + 1 };
        int center = terrainData[stageNum][explosionPoint.x][explosionPoint.y + 1].status;
        int left = terrainData[stageNum][explosionPoint.x][explosionPoint.y].status;
        return SetLeftPoint(stageNum, center, left, explosionPoint, centerPos, ++delayIndex);
        break;
    }
    case ExplosionPoint::TOP:
    {
        DirectX::XMINT2 centerPos{ explosionPoint.x + 1,explosionPoint.y };
        int center = terrainData[stageNum][explosionPoint.x + 1][explosionPoint.y].status;
        int top = terrainData[stageNum][explosionPoint.x][explosionPoint.y].status;
        return SetTopPoint(stageNum, center, top, explosionPoint, centerPos, ++delayIndex);
        break;
    }
    case ExplosionPoint::RIGHT:
    {
        DirectX::XMINT2 centerPos{ explosionPoint.x,explosionPoint.y - 1 };
        int center = terrainData[stageNum][explosionPoint.x][explosionPoint.y - 1].status;
        int right = terrainData[stageNum][explosionPoint.x][explosionPoint.y].status;
        return SetRightPoint(stageNum, center, right, explosionPoint, centerPos, ++delayIndex);
        break;
    }
    case ExplosionPoint::BOTTOM:
    {
        DirectX::XMINT2 centerPos{ explosionPoint.x - 1,explosionPoint.y };
        int center = terrainData[stageNum][explosionPoint.x - 1][explosionPoint.y].status;
        int bottom = terrainData[stageNum][explosionPoint.x][explosionPoint.y].status;
        return SetBottomPoint(stageNum, center, bottom, explosionPoint, centerPos, ++delayIndex);
        break;
    }
    }
}

int TutorialBG::SetCenterPoint(int stageNum, int center, DirectX::XMINT2 centerPos, int delayIndex)
{
    //�Y���u���b�N���X�e�[�W�̊O�ɏo�Ă��Ȃ���
    bool isNotEdge = centerPos.x < 0 || centerPos.y < 0 || centerPos.x >= CHIP_NUM_Y || centerPos.y >= CHIP_NUM_X;

    if (isNotEdge && center == TerrainStatus::InExplosion)
    {
        return center;
    }

    //�Y���u���b�N�̃f�[�^�ݒ�
    SetTerrainData(stageNum, centerPos, delayIndex);

    return TerrainStatus::InExplosion;
}

int TutorialBG::SetLeftPoint(int stageNum, int center, int left, DirectX::XMINT2 leftPos, DirectX::XMINT2 centerPos, int delayIndex)
{
    //�Y���u���b�N���X�e�[�W�̊O�ɏo�Ă��Ȃ���
    bool isNotEdge = leftPos.x < 0 || leftPos.y < 0 || leftPos.x > CHIP_NUM_Y || leftPos.y > CHIP_NUM_X;

    if (isNotEdge || center == TerrainStatus::UnBreakble || left == TerrainStatus::UnBreakble || left == TerrainStatus::InExplosion)
    {
        return left;
    }

    //�Y���u���b�N�̃f�[�^�ݒ�
    SetTerrainData(stageNum, leftPos, delayIndex);

    //�A�����j����
    DirectX::XMINT2 inversePos{ leftPos.y, leftPos.x };
    if (left == TerrainStatus::Bomb)
    {
        //�A�����j�ӏ��v�Z
        DirectX::XMINT2 explodePos[EXPLOSION_CHIP_NUM] = {
            DirectX::XMINT2(-1,-1),//CENTER
            CalcExplosionPoint(inversePos,ExplosionPoint::LEFT),
            CalcExplosionPoint(inversePos,ExplosionPoint::TOP),
            DirectX::XMINT2(-1,-1),//RIGHT
            CalcExplosionPoint(inversePos,ExplosionPoint::BOTTOM),
        };

        //���e�ݒu
        SetBomb(stageNum, explodePos[ExplosionPoint::LEFT], ExplosionPoint::LEFT, delayIndex);
        SetBomb(stageNum, explodePos[ExplosionPoint::TOP], ExplosionPoint::TOP, delayIndex);
        SetBomb(stageNum, explodePos[ExplosionPoint::BOTTOM], ExplosionPoint::BOTTOM, delayIndex);
    }
    //�����̘A�����N����Ȃ������ꍇ
    else
    {
        finishChain(stageNum, leftPos);
    }

    return TerrainStatus::InExplosion;
}

int TutorialBG::SetTopPoint(int stageNum, int center, int top, DirectX::XMINT2 topPos, DirectX::XMINT2 centerPos, int delayIndex)
{
    //�Y���u���b�N���X�e�[�W�̊O�ɏo�Ă��Ȃ���
    bool isNotEdge = topPos.x < 0 || topPos.y < 0 || topPos.x > CHIP_NUM_Y || topPos.y > CHIP_NUM_X;

    if (isNotEdge || center == TerrainStatus::UnBreakble || top == TerrainStatus::UnBreakble || top == TerrainStatus::InExplosion)
    {
        return top;
    }

    //�Y���u���b�N�̃f�[�^�ݒ�
    SetTerrainData(stageNum, topPos, delayIndex);

    //�A�����j����
    DirectX::XMINT2 inversePos{ topPos.y, topPos.x };
    if (top == TerrainStatus::Bomb)
    {
        //�A�����j�ӏ��v�Z
        DirectX::XMINT2 explodePos[EXPLOSION_CHIP_NUM] = {
            DirectX::XMINT2(-1,-1),//CENTER
            CalcExplosionPoint(inversePos,ExplosionPoint::LEFT),
            CalcExplosionPoint(inversePos,ExplosionPoint::TOP),
            CalcExplosionPoint(inversePos,ExplosionPoint::RIGHT),
            DirectX::XMINT2(-1,-1),//BOTTOM
        };

        //���e�ݒu
        SetBomb(stageNum, explodePos[ExplosionPoint::LEFT], ExplosionPoint::LEFT, delayIndex);
        SetBomb(stageNum, explodePos[ExplosionPoint::TOP], ExplosionPoint::TOP, delayIndex);
        SetBomb(stageNum, explodePos[ExplosionPoint::RIGHT], ExplosionPoint::RIGHT, delayIndex);
    }
    //�����̘A�����N����Ȃ������ꍇ
    else
    {
        finishChain(stageNum, topPos);
    }

    return TerrainStatus::InExplosion;
}

int TutorialBG::SetRightPoint(int stageNum, int center, int right, DirectX::XMINT2 rightPos, DirectX::XMINT2 centerPos, int delayIndex)
{
    //�Y���u���b�N���X�e�[�W�̊O�ɏo�Ă��Ȃ���
    bool isNotEdge = rightPos.x < 0 || rightPos.y < 0 || rightPos.x >= CHIP_NUM_Y || rightPos.y >= CHIP_NUM_X;

    if (isNotEdge || center == TerrainStatus::UnBreakble || right == TerrainStatus::UnBreakble || right == TerrainStatus::InExplosion)
    {
        return right;
    }

    //�Y���u���b�N�̃f�[�^�ݒ�
    SetTerrainData(stageNum, rightPos, delayIndex);

    //�A�����j����
    DirectX::XMINT2 inversePos{ rightPos.y, rightPos.x };
    if (right == TerrainStatus::Bomb)
    {
        //�A�����j�ӏ��v�Z
        DirectX::XMINT2 explodePos[EXPLOSION_CHIP_NUM] = {
            DirectX::XMINT2(-1,-1),//CENTER
            DirectX::XMINT2(-1,-1),//LEFT
            CalcExplosionPoint(inversePos,ExplosionPoint::TOP),
            CalcExplosionPoint(inversePos,ExplosionPoint::RIGHT),
            CalcExplosionPoint(inversePos,ExplosionPoint::BOTTOM),
        };

        //���e�ݒu
        SetBomb(stageNum, explodePos[ExplosionPoint::TOP], ExplosionPoint::TOP, delayIndex);
        SetBomb(stageNum, explodePos[ExplosionPoint::RIGHT], ExplosionPoint::RIGHT, delayIndex);
        SetBomb(stageNum, explodePos[ExplosionPoint::BOTTOM], ExplosionPoint::BOTTOM, delayIndex);
    }
    //�����̘A�����N����Ȃ������ꍇ
    else
    {
        finishChain(stageNum, rightPos);
    }

    return TerrainStatus::InExplosion;
}

int TutorialBG::SetBottomPoint(int stageNum, int center, int bottom, DirectX::XMINT2 bottomPos, DirectX::XMINT2 centerPos, int delayIndex)
{
    //�Y���u���b�N���X�e�[�W�̊O�ɏo�Ă��Ȃ���
    bool isNotEdge = bottomPos.x < 0 || bottomPos.y < 0 || bottomPos.x >= CHIP_NUM_Y || bottomPos.y >= CHIP_NUM_X;

    if (isNotEdge || center == TerrainStatus::UnBreakble || bottom == TerrainStatus::UnBreakble || bottom == TerrainStatus::InExplosion)
    {
        return bottom;
    }

    //�Y���u���b�N�̃f�[�^�ݒ�
    SetTerrainData(stageNum, bottomPos, delayIndex);

    //�A�����j����
    DirectX::XMINT2 inversePos{ bottomPos.y, bottomPos.x };
    if (bottom == TerrainStatus::Bomb)
    {
        //�A�����j�ӏ��v�Z
        DirectX::XMINT2 explodePos[EXPLOSION_CHIP_NUM] = {
            DirectX::XMINT2(-1,-1),//CENTER
            CalcExplosionPoint(inversePos,ExplosionPoint::LEFT),
            DirectX::XMINT2(-1,-1),//TOP
            CalcExplosionPoint(inversePos,ExplosionPoint::RIGHT),
            CalcExplosionPoint(inversePos,ExplosionPoint::BOTTOM),
        };

        //���e�ݒu
        SetBomb(stageNum, explodePos[ExplosionPoint::LEFT], ExplosionPoint::LEFT, delayIndex);
        SetBomb(stageNum, explodePos[ExplosionPoint::RIGHT], ExplosionPoint::RIGHT, delayIndex);
        SetBomb(stageNum, explodePos[ExplosionPoint::BOTTOM], ExplosionPoint::BOTTOM, delayIndex);
    }
    //�����̘A�����N����Ȃ������ꍇ
    else
    {
        finishChain(stageNum, bottomPos);
    }

    return TerrainStatus::InExplosion;
}
