//------< �C���N���[�h >--------------------------------------------------------
#include "all.h"
#include "TutorialBG.h"
#include "common.h"
#include "collision.h"

//------< using >---------------------------------------------------------------
using namespace GameLib;
using namespace DirectX;

//------< �f�[�^ >---------------------------------------------------------------
int terrain_back_T[4][TutorialBG::CHIP_NUM_Y][TutorialBG::CHIP_NUM_X] =// �n�`�f�[�^[�X�e�[�W��][X][Y]
{
    //stage0
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
    //stage1
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
    static GameLib::Sprite* effect_bomb = nullptr;
    effect_explosion = sprite_load(EXPLOSION);
    effect_bomb = sprite_load(BOMB01);

    //�n�`�f�[�^terrain_back��bomb�n�`�f�[�^terrain�ɑ������
    for (int s = 0; s < 2; s++)
    {
        for (int x = 0; x < CHIP_NUM_X; x++)
        {
            for (int y = 0; y < CHIP_NUM_Y; y++)
            {
                //�n�`�f�[�^terrain_back��bomb�n�`�f�[�^terrain�ɑ������
                terrainData[s][y][x].status = terrain_back_T[stagenum][y][x];

                //bomb�n�`�̏���������
                InitTerrain(TerrainStatus::Normal, x, y);
                SetTerrainPos(XMINT2(x, y), s);

                terrainData[s][y][x].terrain_endurance = 10000;
                if (terrain_back_T[stagenum][y][x] == 2)
                {
                    terrainData[s][y][x].terrain_endurance = 3;//3�񔚔j����ƒu���Ȃ��Ȃ�
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
    }
    delete effect_bomb;
    delete effect_explosion;

    texture::load(Tile01, TILE01, 256U);    //�w�i
    texture::load(Tile02, TILE02, 256U);    //�w�i
    texture::load(Bomb01, BOMB01, 256U);       //���e
    texture::load(Explosion, EXPLOSION, 256U);    //����

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

    focusFactor = 1.0f;
    focusFlag = false;
    unFocusFlag = false;

    focus = std::make_unique<Focus>(VECTOR2(500.0f, 300.0f), 300.0f);

    circlePos = { 1000,300 };
    circleAngle = 0.0f;

    moveTrg = false;
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
    //���݂̃X�e�[�W

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
    bool isClickL = timer > operatbleCursorTime && GameLib::input::STATE(0) & GameLib::input::PAD_LC;
    bool isClickR = timer > operatbleCursorTime && GameLib::input::STATE(0) & GameLib::input::PAD_RC;
    bool isZ = timer > operatbleCursorTime && GameLib::input::STATE(0) & GameLib::input::PAD_TRG1;
    bool isX = timer > operatbleCursorTime && GameLib::input::STATE(0) & GameLib::input::PAD_TRG2;
    bool isC = timer > operatbleCursorTime && GameLib::input::STATE(0) & GameLib::input::PAD_TRG3;

    focus->SetFocusFlag(isC);
    focus->SetUnFocusFlag(isX);

    //���ΐ��}�X����o�N�_���}�X�ɕύX���ꂽ��
    bool isChangeedFuelToBomb = false;

    //�J�[�\���������Ă���}�X���ǂ��ۂ�
    bool isUnBreakble = terrainData[nowStage][Cpos.y][Cpos.x].status == TerrainStatus::UnBreakble;

    //�����̘A���̌W��
    //0�ȏ�ɂ���ƍŏ��̕��͘A��������C�ɔ�������悤�ɂȂ�
    int delayIndex = -1;

    //����������ӏ�
    DirectX::XMINT2 ExplodePos[EXPLOSION_CHIP_NUM] = {};

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
            for (int x = 0; x < CHIP_NUM_X; x++)
            {
                for (int y = 0; y < CHIP_NUM_Y; y++)
                {
                    terrainData[nowStage][y][x].terrain_endurance = terrainData[nowStage][y][x].terrain_endurance;
                }
            }
            SetBomb(ExplodePos[ExplosionPoint::CENTER], ExplosionPoint::CENTER, delayIndex);
            SetBomb(ExplodePos[ExplosionPoint::LEFT], ExplosionPoint::LEFT, delayIndex);
            SetBomb(ExplodePos[ExplosionPoint::TOP], ExplosionPoint::TOP, delayIndex);
            SetBomb(ExplodePos[ExplosionPoint::RIGHT], ExplosionPoint::RIGHT, delayIndex);
            SetBomb(ExplodePos[ExplosionPoint::BOTTOM], ExplosionPoint::BOTTOM, delayIndex);
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
            //�h�ꂽ��ʂ����ɖ߂�
            Mapterrain_correction = { 200.0f + 32.0f - 64.0f ,0.0f + 32.0f - 64.0f };
        }

        if (!isUnBreakble && isX && !burningFuse.exist)
        {
            burningFuse.exist = true;
            burningFuse.pos = VECTOR2(
                Mapterrain_correction.x + Cpos.x * CHIP_SIZE_F - (CHIP_SIZE_F / 2),
                Mapterrain_correction.y + Cpos.y * CHIP_SIZE_F - (CHIP_SIZE_F / 2)
            );
            burningFuse.Cpos = Cpos;
            terrainData[nowStage][Cpos.y][Cpos.x].status = TerrainStatus::BurningFuse;
        }
    }

    for (int x = 0; x < CHIP_NUM_X; x++)
    {
        for (int y = 0; y < CHIP_NUM_Y; y++)
        {
            updateEffect(TerrainExplosion[nowStage][y][x]);
            TerrainBomb[nowStage][y][x].exist = true;
            updateEffect(TerrainBomb[nowStage][y][x]);
        }
    }

    if (isX)moveTrg = true;

    //���`�ۊǂ̏d��
    float weight = 0.031f;

    if (moveTrg)
    {
        moveStage(nowStage, MoveType::InGameToEnd);
    }

    SetIsPutOn();

    if (act > 40)finish_game = true;

    focus->update();

    circlePos.y += cosf(circleAngle);

    timer++;
    circleAngle += DirectX::XMConvertToRadians(2);
}

//--------------------------------
//  �n�`�`��
//--------------------------------
void TutorialBG::drawTerrain()
{
    //�}�b�v
    texture::begin(Tile01);
    for (int x = 0; x < CHIP_NUM_X; x++)
    {
        for (int y = 0; y < CHIP_NUM_Y; y++)
        {
            float a = terrain_back_T[0][y][x];
            texture::draw(
                TexNo::Tile01,
                terrainData[nowStage][y][x].currentPos.x, terrainData[nowStage][y][x].currentPos.y,
                1.0, 1.0,
                CHIP_SIZE_F * a, 0,
                CHIP_SIZE_F * (a + 1), CHIP_SIZE_F
            );
        }
    }
    texture::end(Tile01);

    //�o�N�_��
    texture::begin(Tile02);
    for (int x = 0; x < CHIP_NUM_X; x++)
    {
        for (int y = 0; y < CHIP_NUM_Y; y++)
        {
            if (!terrainData[nowStage][y][x].isPutOn && terrainData[nowStage][y][x].status == TerrainStatus::Normal)
            {
                texture::draw(
                    TexNo::Tile02,
                    terrainData[nowStage][y][x].currentPos.x, terrainData[nowStage][y][x].currentPos.y,
                    1.0f, 1.0f,
                    0, 0,
                    CHIP_SIZE_F, CHIP_SIZE_F,
                    0, 0,
                    0,
                    1,0,1,0.6f
                );
            }
            if (terrainData[nowStage][y][x].status == TerrainStatus::Bomb)
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
            if (terrainData[nowStage][y][x].status == TerrainStatus::InExplosion)
            {
                if (terrainData[nowStage][y][x].DelayTimer < 0)
                {
                    TerrainExplosion[nowStage][y][x].exist = true;
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
                    terrainData[nowStage][y][x].explosionTimer--;
                }
                else if (!terrainData[nowStage][y][x].isChained)
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
                if (terrainData[nowStage][y][x].isAlredyChanged)
                {
                    //�o�N�_���̒x�����s���^�C�}�[�̌���
                    terrainData[nowStage][y][x].DelayTimer--;
                }
            }
            if (terrainData[nowStage][y][x].status == TerrainStatus::BurningFuse)
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
                    terrainData[nowStage][y][x].status = TerrainStatus::Normal;
                }
            }
            //�����I��
            if (terrainData[nowStage][y][x].explosionTimer < 0) {
                //�������I�������̂�terrain�̏�Ԃ�����������
                InitTerrain(TerrainStatus::Normal, x, y);

                TerrainExplosion[nowStage][y][x].exist = false;
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

    for (int x = 0; x < CHIP_NUM_X; x++)
    {
        for (int y = 0; y < CHIP_NUM_Y; y++)
        {
            if ((terrainData[nowStage][y][x].status == TerrainStatus::Bomb) || (terrainData[nowStage][y][x].status == TerrainStatus::InExplosion && !terrainData[nowStage][y][x].isChained) && terrainData[nowStage][y][x].DelayTimer >= 25)
            {
                texture::draw(
                    TexNo::Bomb01,
                    /*Mapterrain_correction.x + TerrainBomb[y][x].pos.x + CHIP_SIZE_F / 2, Mapterrain_correction.y + TerrainBomb[y][x].pos.y + CHIP_SIZE_F / 2,*/
                    terrainData[nowStage][y][x].currentPos.x, terrainData[nowStage][y][x].currentPos.y,
                    1.0f, 1.0f,
                    0.0f, 0.0f,
                    CHIP_SIZE_F, CHIP_SIZE_F,
                    CHIP_SIZE_F * 0.5f, CHIP_SIZE_F * 0.5f,
                    0,
                    1, 1, 1, 1
                );
            }
            if (terrainData[nowStage][y][x].status == TerrainStatus::InExplosion && !terrainData[nowStage][y][x].isChained)
            {
                if (!terrainData[nowStage][y][x].isChained && terrainData[nowStage][y][x].DelayTimer < 25)
                {
                    //�����̘A�����n�܂������A�܂��������Ă��Ȃ��o�N�_���̕`��
                    texture::draw(
                        TexNo::Bomb01,
                        /*Mapterrain_correction.x + TerrainBomb[y][x].pos.x + CHIP_SIZE_F / 2, Mapterrain_correction.y + TerrainBomb[y][x].pos.y + CHIP_SIZE_F / 2,*/
                        terrainData[nowStage][y][x].currentPos.x, terrainData[nowStage][y][x].currentPos.y,
                        1.0f, 1.0f,
                        TerrainBomb[nowStage][y][x].texSizeX * TerrainBomb[nowStage][y][x].animeNum, 0.0f,
                        TerrainBomb[nowStage][y][x].texSizeX, TerrainBomb[nowStage][y][x].ty / 10,
                        CHIP_SIZE_F * 0.5f, CHIP_SIZE_F * 0.5f,
                        0,
                        1, 1, 1, 1
                    );
                }
            }
        }
    }

    texture::end(Bomb01);

    debug::setString("act:%d", act);
    debug::setString("score:%d", score);

    texture::begin(Explosion);
    for (int x = 0; x < CHIP_NUM_X; x++)
    {
        for (int y = 0; y < CHIP_NUM_Y; y++)
        {
            if (TerrainExplosion[nowStage][y][x].exist)
            {
                texture::draw(
                    TexNo::Explosion,
                    /*Mapterrain_correction.x + TerrainExplosion[y][x].pos.x + CHIP_SIZE_F / 2, Mapterrain_correction.y + TerrainExplosion[y][x].pos.y + CHIP_SIZE_F / 2,*/
                    terrainData[nowStage][y][x].currentPos.x, terrainData[nowStage][y][x].currentPos.y,
                    0.8f, 0.8f,
                    TerrainExplosion[nowStage][y][x].texSizeX * TerrainExplosion[nowStage][y][x].animeNum, 0.0f,
                    TerrainExplosion[nowStage][y][x].texSizeX, TerrainExplosion[nowStage][y][x].ty,
                    120.0f / 2, 120.0f / 2,
                    0,
                    1, 1, 1, 1
                );
            }
        }
    }
    texture::end(Explosion);

    bool isBurningFuse = false;
    for (int x = 0; x < CHIP_NUM_X; x++)
    {
        for (int y = 0; y < CHIP_NUM_Y; y++)
        {
            if (terrainData[nowStage][y][x].status == TerrainStatus::BurningFuse)
                isBurningFuse = true;
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

    focus->render();

    primitive::circle(
        circlePos,
        75.0f,
        VECTOR2(1, 1),
        0,
        VECTOR4(1, 0, 1, 1)
    );
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

        //���e��u������̃��Z�b�g
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
    }
}

//���̃u���b�N�Ƀo�N�_�����ݒu�\��
void TutorialBG::SetIsPutOn()
{
    for (int x = 0; x < CHIP_NUM_X; x++)
    {
        for (int y = 0; y < CHIP_NUM_Y; y++)
        {
            //�O���͔��e�}�X��u���Ȃ�
            if (x == 0 || y == 0)
            {
                terrainData[nowStage][y][x].isPutOn = false;
                continue;
            }

            //���ΐ��}�X�����ʂ̃}�X�ȊO�͒u���Ȃ�
            if (terrainData[nowStage][y][x].status != TerrainStatus::BurningFuse &&
                terrainData[nowStage][y][x].status != TerrainStatus::Normal)
            {
                terrainData[nowStage][y][x].isPutOn = false;
                continue;
            }

            //�ǁA�܂��͔��e�}�X�ɗאڂ��Ă��Ȃ��ƒu���Ȃ�
            if (!IsPutOn(y, x))
            {
                terrainData[nowStage][y][x].isPutOn = false;
                continue;
            }

            terrainData[nowStage][y][x].isPutOn = true;
        }
    }
}

bool TutorialBG::IsPutOn(int y, int x)
{
    int adjacentTerrainStatus[] = {
    0,                             //CENTER
    terrainData[nowStage][y][x - 1].status,  //LEFT
    terrainData[nowStage][y - 1][x].status,  //TOP
    terrainData[nowStage][y][x + 1].status,  //RIGHT
    terrainData[nowStage][y + 1][x].status,  //BOTTOM
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
void TutorialBG::moveStage(int stageNum, MoveType moveType)
{
    //���`�ۊǂ̏d��
    float weight = 0.031f;

    switch (moveType)
    {
    case MoveType::StartToInGame:
        for (int x = 0; x < CHIP_NUM_X; x++)
        {
            for (int y = 0; y < CHIP_NUM_Y; y++)
            {
                XMVECTOR NowPos = XMVectorSet(terrainData[stageNum][y][x].currentPos.x, terrainData[stageNum][y][x].currentPos.y, 0, 0);
                XMVECTOR EndPos = XMVectorSet(terrainData[stageNum][y][x].inGamePos.x, terrainData[stageNum][y][x].inGamePos.y, 0, 0);
                XMStoreFloat2(&terrainData[stageNum][y][x].currentPos, XMVectorLerp(NowPos, EndPos, weight));
            }
        }
        break;
    case MoveType::InGameToEnd:
        for (int x = 0; x < CHIP_NUM_X; x++)
        {
            for (int y = 0; y < CHIP_NUM_Y; y++)
            {
                XMVECTOR NowPos = XMVectorSet(terrainData[stageNum][y][x].currentPos.x, terrainData[stageNum][y][x].currentPos.y, 0, 0);
                XMVECTOR EndPos = XMVectorSet(terrainData[stageNum][y][x].endPos.x, terrainData[stageNum][y][x].endPos.y, 0, 0);
                XMStoreFloat2(&terrainData[stageNum][y][x].currentPos, XMVectorLerp(NowPos, EndPos, weight));
            }
        }
        break;
    }
}

//--------------------------------
//  �w�肵���ӏ��ɂ��łɕύX���������Ă��邩
//--------------------------------
bool TutorialBG::IsAlreadyChanged(DirectX::XMINT2 terrainPos)
{
    return terrainData[nowStage][terrainPos.x][terrainPos.y].isAlredyChanged;
}

//--------------------------------
//  �o�N�_����ݒu
//--------------------------------
void TutorialBG::SetBomb(DirectX::XMINT2 terrainPos, ExplosionPoint point, int delayIndex)
{
    if (!IsAlreadyChanged(terrainPos)) {
        terrainData[nowStage][terrainPos.x][terrainPos.y].status = SetExplosionPoint(terrainPos, point, delayIndex);
    }
    score_add += 10;
    score_counter++;
    if (terrainData[nowStage][terrainPos.x][terrainPos.y].terrain_enduranceC == terrainData[nowStage][terrainPos.x][terrainPos.y].terrain_endurance)terrainData[nowStage][terrainPos.x][terrainPos.y].terrain_endurance--;
}

//--------------------------------
//  �A�����I���
//--------------------------------
void TutorialBG::finishChain(DirectX::XMINT2 terrainPos)
{
    terrainData[nowStage][terrainPos.x][terrainPos.y].isChained = true;
}

//--------------------------------
//  terrain�̏�����
//--------------------------------
void TutorialBG::InitTerrain(TerrainStatus terrainStatus, DirectX::XMINT2 terrainPos)
{
    //TerrainStatus::None�̎��A��Ԃ�ύX���Ȃ�
    if (terrainStatus != TerrainStatus::None)
    {
        if (terrainData[nowStage][terrainPos.y][terrainPos.x].status != TerrainStatus::UnBreakble)
            terrainData[nowStage][terrainPos.y][terrainPos.x].status = terrainStatus;
    }
    //terrainData��������
    terrainData[nowStage][terrainPos.y][terrainPos.x].explosionTimer  = explosionTime;
    terrainData[nowStage][terrainPos.y][terrainPos.x].DelayTimer      = delayTime;
    terrainData[nowStage][terrainPos.y][terrainPos.x].isAlredyChanged = false;
    terrainData[nowStage][terrainPos.y][terrainPos.x].isChained       = false;
}

void TutorialBG::InitTerrain(TerrainStatus terrainStatus, int x, int y)
{
    InitTerrain(terrainStatus, DirectX::XMINT2(x, y));
}

void TutorialBG::SetTerrainPos(DirectX::XMINT2 terrainPos, int stageNum)
{
    DirectX::XMFLOAT2 startPos;
    DirectX::XMFLOAT2 inGamePos;
    DirectX::XMFLOAT2 endPos;

    inGamePos = XMFLOAT2(
        Mapterrain_correction.x + (terrainPos.x * CHIP_SIZE_F),
        Mapterrain_correction.y + (terrainPos.y * CHIP_SIZE_F));
    startPos = XMFLOAT2(
        inGamePos.x,
        inGamePos.y + static_cast<float>(window::getHeight()));
    endPos = XMFLOAT2(
        startPos.x,
        startPos.y - static_cast<float>(window::getHeight()));

    terrainData[nowStage][terrainPos.y][terrainPos.x].startPos = DirectX::XMFLOAT2(
        Mapterrain_correction.x + (terrainPos.x * CHIP_SIZE_F),
        Mapterrain_correction.y + (terrainPos.y * CHIP_SIZE_F)
    );
    terrainData[nowStage][terrainPos.y][terrainPos.x].endPos = DirectX::XMFLOAT2(
        terrainData[nowStage][terrainPos.y][terrainPos.x].startPos.x,
        terrainData[nowStage][terrainPos.y][terrainPos.x].startPos.y - static_cast<float>(window::getHeight())
    );
    terrainData[nowStage][terrainPos.y][terrainPos.x].currentPos = terrainData[nowStage][terrainPos.y][terrainPos.x].startPos;
}

//--------------------------------
//  �w�肵���ӏ��̏����Z�b�g
//--------------------------------
void TutorialBG::SetTerrainData(DirectX::XMINT2 terrainPos, int delayIndex)
{
    if (!terrainData[nowStage][terrainPos.x][terrainPos.y].isAlredyChanged)
    {
        terrainData[nowStage][terrainPos.x][terrainPos.y].DelayTimer = delayIndex * delayTime;
        terrainData[nowStage][terrainPos.x][terrainPos.y].isAlredyChanged = true;
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
int TutorialBG::SetExplosionPoint(DirectX::XMINT2 explosionPoint, ExplosionPoint point, int delayIndex)
{
    switch (point)
    {
    case ExplosionPoint::CENTER:
    {
        int center = terrainData[nowStage][explosionPoint.x][explosionPoint.y].status;
        return SetCenterPoint(center, explosionPoint, ++delayIndex);
        break;
    }
    case ExplosionPoint::LEFT:
    {
        DirectX::XMINT2 centerPos{ explosionPoint.x,explosionPoint.y + 1 };
        int center = terrainData[nowStage][explosionPoint.x][explosionPoint.y + 1].status;
        int left = terrainData[nowStage][explosionPoint.x][explosionPoint.y].status;
        return SetLeftPoint(center, left, explosionPoint, centerPos, ++delayIndex);
        break;
    }
    case ExplosionPoint::TOP:
    {
        DirectX::XMINT2 centerPos{ explosionPoint.x + 1,explosionPoint.y };
        int center = terrainData[nowStage][explosionPoint.x + 1][explosionPoint.y].status;
        int top = terrainData[nowStage][explosionPoint.x][explosionPoint.y].status;
        return SetTopPoint(center, top, explosionPoint, centerPos, ++delayIndex);
        break;
    }
    case ExplosionPoint::RIGHT:
    {
        DirectX::XMINT2 centerPos{ explosionPoint.x,explosionPoint.y - 1 };
        int center = terrainData[nowStage][explosionPoint.x][explosionPoint.y - 1].status;
        int right = terrainData[nowStage][explosionPoint.x][explosionPoint.y].status;
        return SetRightPoint(center, right, explosionPoint, centerPos, ++delayIndex);
        break;
    }
    case ExplosionPoint::BOTTOM:
    {
        DirectX::XMINT2 centerPos{ explosionPoint.x - 1,explosionPoint.y };
        int center = terrainData[nowStage][explosionPoint.x - 1][explosionPoint.y].status;
        int bottom = terrainData[nowStage][explosionPoint.x][explosionPoint.y].status;
        return SetBottomPoint(center, bottom, explosionPoint, centerPos, ++delayIndex);
        break;
    }
    }
}

int TutorialBG::SetCenterPoint(int center, DirectX::XMINT2 centerPos, int delayIndex)
{
    //�Y���u���b�N���X�e�[�W�̊O�ɏo�Ă��Ȃ���
    bool isNotEdge = centerPos.x < 0 || centerPos.y < 0 || centerPos.x >= CHIP_NUM_Y || centerPos.y >= CHIP_NUM_X;

    if (isNotEdge && center == TerrainStatus::InExplosion)
    {
        return center;
    }

    //�Y���u���b�N�̃f�[�^�ݒ�
    SetTerrainData(centerPos, delayIndex);

    return TerrainStatus::InExplosion;
}

int TutorialBG::SetLeftPoint(int center, int left, DirectX::XMINT2 leftPos, DirectX::XMINT2 centerPos, int delayIndex)
{
    //�Y���u���b�N���X�e�[�W�̊O�ɏo�Ă��Ȃ���
    bool isNotEdge = leftPos.x < 0 || leftPos.y < 0 || leftPos.x > CHIP_NUM_Y || leftPos.y > CHIP_NUM_X;

    if (isNotEdge || center == TerrainStatus::UnBreakble || left == TerrainStatus::UnBreakble || left == TerrainStatus::InExplosion)
    {
        return left;
    }

    //�Y���u���b�N�̃f�[�^�ݒ�
    SetTerrainData(leftPos, delayIndex);

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
        SetBomb(explodePos[ExplosionPoint::LEFT], ExplosionPoint::LEFT, delayIndex);
        SetBomb(explodePos[ExplosionPoint::TOP], ExplosionPoint::TOP, delayIndex);
        SetBomb(explodePos[ExplosionPoint::BOTTOM], ExplosionPoint::BOTTOM, delayIndex);
    }
    //�����̘A�����N����Ȃ������ꍇ
    else
    {
        finishChain(leftPos);
    }

    return TerrainStatus::InExplosion;
}

int TutorialBG::SetTopPoint(int center, int top, DirectX::XMINT2 topPos, DirectX::XMINT2 centerPos, int delayIndex)
{
    //�Y���u���b�N���X�e�[�W�̊O�ɏo�Ă��Ȃ���
    bool isNotEdge = topPos.x < 0 || topPos.y < 0 || topPos.x > CHIP_NUM_Y || topPos.y > CHIP_NUM_X;

    if (isNotEdge || center == TerrainStatus::UnBreakble || top == TerrainStatus::UnBreakble || top == TerrainStatus::InExplosion)
    {
        return top;
    }

    //�Y���u���b�N�̃f�[�^�ݒ�
    SetTerrainData(topPos, delayIndex);

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
        SetBomb(explodePos[ExplosionPoint::LEFT], ExplosionPoint::LEFT, delayIndex);
        SetBomb(explodePos[ExplosionPoint::TOP], ExplosionPoint::TOP, delayIndex);
        SetBomb(explodePos[ExplosionPoint::RIGHT], ExplosionPoint::RIGHT, delayIndex);
    }
    //�����̘A�����N����Ȃ������ꍇ
    else
    {
        finishChain(topPos);
    }

    return TerrainStatus::InExplosion;
}

int TutorialBG::SetRightPoint(int center, int right, DirectX::XMINT2 rightPos, DirectX::XMINT2 centerPos, int delayIndex)
{
    //�Y���u���b�N���X�e�[�W�̊O�ɏo�Ă��Ȃ���
    bool isNotEdge = rightPos.x < 0 || rightPos.y < 0 || rightPos.x >= CHIP_NUM_Y || rightPos.y >= CHIP_NUM_X;

    if (isNotEdge || center == TerrainStatus::UnBreakble || right == TerrainStatus::UnBreakble || right == TerrainStatus::InExplosion)
    {
        return right;
    }

    //�Y���u���b�N�̃f�[�^�ݒ�
    SetTerrainData(rightPos, delayIndex);

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
        SetBomb(explodePos[ExplosionPoint::TOP], ExplosionPoint::TOP, delayIndex);
        SetBomb(explodePos[ExplosionPoint::RIGHT], ExplosionPoint::RIGHT, delayIndex);
        SetBomb(explodePos[ExplosionPoint::BOTTOM], ExplosionPoint::BOTTOM, delayIndex);
    }
    //�����̘A�����N����Ȃ������ꍇ
    else
    {
        finishChain(rightPos);
    }

    return TerrainStatus::InExplosion;
}

int TutorialBG::SetBottomPoint(int center, int bottom, DirectX::XMINT2 bottomPos, DirectX::XMINT2 centerPos, int delayIndex)
{
    //�Y���u���b�N���X�e�[�W�̊O�ɏo�Ă��Ȃ���
    bool isNotEdge = bottomPos.x < 0 || bottomPos.y < 0 || bottomPos.x >= CHIP_NUM_Y || bottomPos.y >= CHIP_NUM_X;

    if (isNotEdge || center == TerrainStatus::UnBreakble || bottom == TerrainStatus::UnBreakble || bottom == TerrainStatus::InExplosion)
    {
        return bottom;
    }

    //�Y���u���b�N�̃f�[�^�ݒ�
    SetTerrainData(bottomPos, delayIndex);

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
        SetBomb(explodePos[ExplosionPoint::LEFT], ExplosionPoint::LEFT, delayIndex);
        SetBomb(explodePos[ExplosionPoint::RIGHT], ExplosionPoint::RIGHT, delayIndex);
        SetBomb(explodePos[ExplosionPoint::BOTTOM], ExplosionPoint::BOTTOM, delayIndex);
    }
    //�����̘A�����N����Ȃ������ꍇ
    else
    {
        finishChain(bottomPos);
    }

    return TerrainStatus::InExplosion;
}
