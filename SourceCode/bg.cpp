//******************************************************************************
//
//
//      BG�N���X
//
//
//******************************************************************************

//TODO
//terrainData��Status�̃����o�ϐ�������
//�{����`��

//------< �C���N���[�h >--------------------------------------------------------
#include "all.h"
#include "common.h"
#include "bg.h"
#include "collision.h"

//------< using >---------------------------------------------------------------
using namespace GameLib;

//------< �f�[�^ >---------------------------------------------------------------
int terrain_back[4][BG::CHIP_NUM_Y][BG::CHIP_NUM_X] =// �n�`�f�[�^[�X�e�[�W��][X][Y]
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
};

int bomb_pattern[8][4][3][3]//[���e�̎��][��]�̎��][y][x]
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
int bomb_numchanger(int now, int past)
{
    while (now == past)now = rand() % 8;
    return now;
}

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
            //�n�`�f�[�^terrain_back��bomb�n�`�f�[�^terrain�ɑ������
            terrain[y][x] = terrain_back[stagenum][y][x];

            //bomb�n�`�̏���������
            InitTerrain(TerrainStatus::Normal, x, y);

            //�G�t�F�N�g�̏���������
            TerrainBomb[y][x].pos = VECTOR2(x * CHIP_SIZE_F, y * CHIP_SIZE_F);
            TerrainBomb[y][x].animeNum = 3;
            TerrainBomb[y][x].exist = false;
        }
    }

    texture::load(0, L"./Data/Images/test_tile.png", 256U);    //�w�i
    texture::load(1, L"./Data/Images/test_tile02.png", 256U);  //�w�i

    //�o�N�_���̎�ނ�������
    for (int i = 0; i < BOMB_TYPE_MAX; i++)
    {
        //���e�̎�ތ���
        int defnum = bomb_typenum[i];
        bomb_typenum[i] = bomb_numchanger(bomb_typenum[i], defnum);
        if (i > 1 && bomb_typenum[i] == bomb_typenum[i - 2])bomb_typenum[i] = bomb_numchanger(bomb_typenum[i], bomb_typenum[i - 2]);//1�T�ڂ̔��e�Ɠ�����ނȂ�ύX
        if (i > 0 && bomb_typenum[i] == bomb_typenum[i - 1])bomb_typenum[i] = bomb_numchanger(bomb_typenum[i], bomb_typenum[i - 1]);//0�T�ڂ̔��e�Ɠ�����ނȂ�ύX
        bomb_trun[i] = 0;
    }
    bomb_movingtype = false;
    bomb_roopchecker = false;

    //�^�C�}�[������
    timer = 0;
}

//--------------------------------
//  �I������
//--------------------------------
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
    bool isInStage = cursorPos.x >  Mapterrain_correction.x
                  && cursorPos.x < (Mapterrain_correction.x + CHIP_SIZE * BG::CHIP_NUM_X)
                  && cursorPos.y >  Mapterrain_correction.y
                  && cursorPos.y < (Mapterrain_correction.y + CHIP_SIZE * BG::CHIP_NUM_Y);

    //�E�A���N���b�N�Ȃǂ����Ă��邩�ۂ�
    bool isClickL = timer > operatbleCursorTime && GameLib::input::STATE(0) & GameLib::input::PAD_LC;
    bool isClickR = timer > operatbleCursorTime && GameLib::input::STATE(0) & GameLib::input::PAD_RC;
    bool isZ      = timer > operatbleCursorTime && GameLib::input::STATE(0) & GameLib::input::PAD_TRG1;
    bool isX      = timer > operatbleCursorTime && GameLib::input::STATE(0) & GameLib::input::PAD_TRG2;

    //���ΐ��}�X����o�N�_���}�X�ɕύX���ꂽ��
    bool isChangeedFuelToBomb = false;

    //�J�[�\���������Ă���}�X���ǂ��ۂ�
    bool isUnBreakble = terrain[Cpos.y][Cpos.x] == TerrainStatus::UnBreakble;

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
                    int pt_bomb = bomb_pattern[bomb_typenum[bomb_waitingarea]][bomb_trun[bomb_waitingarea]][y][x];

                    //���e1�u���b�N���S���W(�X�N���[�����W�{�z��[y][x]�ڂ̃u���b�N)
                    DirectX::XMFLOAT2 bomb_pos_b = { bomb_changepos[bomb_waitingarea].x + CHIP_SIZE * x,bomb_changepos[bomb_waitingarea].y + CHIP_SIZE * y };
                    //�}�b�v�`�b�v�̔z��̏ꏊ
                    DirectX::XMINT2 Cpos = { static_cast<int>((bomb_pos_b.x - Mapterrain_correction.x) / CHIP_SIZE_F) , static_cast<int>((bomb_pos_b.y - Mapterrain_correction.y) / CHIP_SIZE_F) };

                    if (pt_bomb == PatternStatus::IsBomb)
                    {
                        if (
                            //�ׂ��ǂ�������
                            terrain[Cpos.y - 1][Cpos.x] == TerrainStatus::UnBreakble ||//��
                            terrain[Cpos.y + 1][Cpos.x] == TerrainStatus::UnBreakble ||//��
                            terrain[Cpos.y][Cpos.x + 1] == TerrainStatus::UnBreakble ||//�E
                            terrain[Cpos.y][Cpos.x - 1] == TerrainStatus::UnBreakble ||//��
                            //�ׂ����e��������
                            terrain[Cpos.y - 1][Cpos.x] == TerrainStatus::Bomb ||//��
                            terrain[Cpos.y + 1][Cpos.x] == TerrainStatus::Bomb ||//��
                            terrain[Cpos.y][Cpos.x + 1] == TerrainStatus::Bomb ||//�E
                            terrain[Cpos.y][Cpos.x - 1] == TerrainStatus::Bomb   //��
                            )
                        {
                            bomb_roopchecker = true;
                        }
                        if (bomb_roopchecker)
                        {
                            if (terrain[Cpos.y][Cpos.x] != TerrainStatus::Normal && terrain[Cpos.y][Cpos.x] != TerrainStatus::BurningFuse)bomb_release = true;
                            if (bomb_release)break;
                            if (i == 1 && GameLib::input::TRG_RELEASE(0) & GameLib::input::PAD_LC && (terrain[Cpos.y][Cpos.x] == TerrainStatus::Normal || terrain[Cpos.y][Cpos.x] == TerrainStatus::BurningFuse))
                            {
                                //���e�ݒu
                                if (terrain[Cpos.y][Cpos.x] == TerrainStatus::BurningFuse && !isChangeedFuelToBomb)
                                {
                                    isChangeedFuelToBomb = true;
                                    ExplodePos[ExplosionPoint::CENTER] = CalcExplosionPoint(Cpos, ExplosionPoint::CENTER);
                                    ExplodePos[ExplosionPoint::LEFT] = CalcExplosionPoint(Cpos, ExplosionPoint::LEFT);
                                    ExplodePos[ExplosionPoint::TOP] = CalcExplosionPoint(Cpos, ExplosionPoint::TOP);
                                    ExplodePos[ExplosionPoint::RIGHT] = CalcExplosionPoint(Cpos, ExplosionPoint::RIGHT);
                                    ExplodePos[ExplosionPoint::BOTTOM] = CalcExplosionPoint(Cpos, ExplosionPoint::BOTTOM);
                                }
                                terrain[Cpos.y][Cpos.x] = TerrainStatus::Bomb;
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
            SetBomb(ExplodePos[ExplosionPoint::CENTER], ExplosionPoint::CENTER, delayIndex);
            SetBomb(ExplodePos[ExplosionPoint::LEFT], ExplosionPoint::LEFT, delayIndex);
            SetBomb(ExplodePos[ExplosionPoint::TOP], ExplosionPoint::TOP, delayIndex);
            SetBomb(ExplodePos[ExplosionPoint::RIGHT], ExplosionPoint::RIGHT, delayIndex);
            SetBomb(ExplodePos[ExplosionPoint::BOTTOM], ExplosionPoint::BOTTOM, delayIndex);

            //��ʂ��h���
            Mapterrain_correction = { Mapterrain_correction.x + rand() % 4 - 2,Mapterrain_correction.y + rand() % 4 - 2 };

            isChangeedFuelToBomb = false;
        }
        else
        {
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
            terrain[Cpos.y][Cpos.x] = TerrainStatus::BurningFuse;
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
            if (terrain[y][x] == TerrainStatus::Bomb)
            {
                //�o�N�_���̕`��
                texture::draw(
                    1,
                    Mapterrain_correction.x + (x * CHIP_SIZE_F), Mapterrain_correction.y + (y * CHIP_SIZE_F),
                    1.0f, 1.0f,
                    0, 0,
                    CHIP_SIZE_F, CHIP_SIZE_F,
                    0, 0,
                    0,
                    RED
                );
            }
            if(terrain[y][x] == TerrainStatus::InExplosion)
            {
                if (terrainData[y][x].DelayTimer < 0)
                {
                    //�A�����邽�߂̎��Ԃ̂��炵�����������̂Ŕ�����`��
                    texture::draw(
                        1,
                        Mapterrain_correction.x + (x * CHIP_SIZE_F), Mapterrain_correction.y + (y * CHIP_SIZE_F),
                        1.0f, 1.0f,
                        0, 0,
                        CHIP_SIZE_F, CHIP_SIZE_F,
                        0, 0,
                        0,
                        BLUE
                    );
                    terrainData[y][x].explosionTimer--;
                }
                else if(!terrainData[y][x].isChained)
                {
                    //�����̘A�����n�܂������A�܂��������Ă��Ȃ��o�N�_���̕`��
                    texture::draw(
                        1,
                        Mapterrain_correction.x + (x * CHIP_SIZE_F), Mapterrain_correction.y + (y * CHIP_SIZE_F),
                        1.0f, 1.0f,
                        0, 0,
                        CHIP_SIZE_F, CHIP_SIZE_F,
                        0, 0,
                        0,
                        RED
                    );
                }
                if (terrainData[y][x].isAlredyChanged)
                {
                    //�o�N�_���̒x�����s���^�C�}�[�̌���
                    terrainData[y][x].DelayTimer--;
                }
            }
            if (terrain[y][x] == TerrainStatus::BurningFuse)
            {
                if (burningFuse.Cpos.x == x && burningFuse.Cpos.y == y)
                {
                    //���ΐ��̕`��
                    texture::draw(
                        1,
                        Mapterrain_correction.x + (x * CHIP_SIZE_F), Mapterrain_correction.y + (y * CHIP_SIZE_F),
                        1.0f, 1.0f,
                        0, 0,
                        CHIP_SIZE_F, CHIP_SIZE_F,
                        0, 0,
                        0,
                        GREEN
                    );
                }
                else
                {
                    //���ΐ��̈ʒu���ύX���ꂽ�̂�terrain�̏�Ԃ��ύX����
                    terrain[y][x] = TerrainStatus::Normal;
                }
            }
            //�����I��
            if (terrainData[y][x].explosionTimer < 0) {
                //�������I�������̂�terrain�̏�Ԃ�����������
                InitTerrain(TerrainStatus::Normal, x, y);
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
                int pt_bomb = bomb_pattern[bomb_typenum[bomb_array]][bomb_trun[bomb_waitingarea]][y][x];
                if (pt_bomb == PatternStatus::IsBomb)
                {
                    texture::draw(
                        1,
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

    texture::end(1);

    bool isBurningFuse = false;
    for (int x = 0; x < CHIP_NUM_X; x++)
    {
        for (int y = 0; y < CHIP_NUM_Y; y++)
        {
            if (terrain[y][x] == TerrainStatus::BurningFuse)
                isBurningFuse = true;
        }
    }

    burningFuse.exist = isBurningFuse ? true : false;

    static GameLib::Sprite* fire_image = nullptr;
    fire_image = sprite_load(L"./Data/Images/fire03.png");

    if (burningFuse.exist)
    {
        burningFuse.effectFire(fire_image, 6);
    }

    delete fire_image;
}

//���e���h���b�O
void BG::dragBomb()
{
    for (int bomb_array = 0; bomb_array < BOMB_ROTATE_MAX; bomb_array++)
    {
        for (int x = 0; x < 3; ++x)
        {
            for (int y = 0; y < 3; ++y)
            {
                //���e�̎�ގ擾
                int pt_bomb = bomb_pattern[bomb_typenum[bomb_array]][bomb_trun[bomb_array]][y][x];

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
            bomb_typenum[bomb_waitingarea] = bomb_numchanger(bomb_typenum[bomb_waitingarea], defnum);
            bomb_trun[bomb_waitingarea] = 0;//��]�������p�x�ɖ߂�
            bomb_movingtype = false;
            bomb_roopchecker = false;
            bomb_reset = false;//���Z�b�g���������ăh���b�O�ł���悤�ɂ���
        }
    }
}

//���e����]
void BG::rotateBomb()
{
    if (GameLib::input::TRG(0) & GameLib::input::PAD_RC)
    {
        bomb_trun[bomb_waitingarea]++;
        if (bomb_trun[bomb_waitingarea] > 3)bomb_trun[bomb_waitingarea] = 0;
    }
}

//���e���h���b�v
void BG::dropBomb()
{
    if (GameLib::input::TRG_RELEASE(0) & GameLib::input::PAD_LC)
    {
        drag_con = false;
    }
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
//  �A�����I���
//--------------------------------
void BG::finishChain(DirectX::XMINT2 terrainPos)
{
    terrainData[terrainPos.x][terrainPos.y].isChained = true;
}

//--------------------------------
//  terrain�̏�����
//--------------------------------
void BG::InitTerrain(TerrainStatus terrainStatus, DirectX::XMINT2 terrainPos)
{
    //TerrainStatus::None�̎��A��Ԃ�ύX���Ȃ�
    if (terrainStatus != TerrainStatus::None)
    {
        if(terrain[terrainPos.y][terrainPos.x] != TerrainStatus::UnBreakble)
        terrain[terrainPos.y][terrainPos.x] = terrainStatus;
    }
    //terrainData��������
    terrainData[terrainPos.y][terrainPos.x].explosionTimer = explosionTime;
    terrainData[terrainPos.y][terrainPos.x].DelayTimer = delayTime;
    terrainData[terrainPos.y][terrainPos.x].isAlredyChanged = false;
    terrainData[terrainPos.y][terrainPos.x].isChained = false;
}

void BG::InitTerrain(TerrainStatus terrainStatus, int x, int y)
{
    InitTerrain(terrainStatus, DirectX::XMINT2(x, y));
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

    if (isNotEdge && center == TerrainStatus::InExplosion)
    {
        return center;
    }

    //�Y���u���b�N�̃f�[�^�ݒ�
    SetTerrainData(centerPos, delayIndex);

    return TerrainStatus::InExplosion;
}

int BG::SetLeftPoint(int center, int left, DirectX::XMINT2 leftPos, DirectX::XMINT2 centerPos, int delayIndex)
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

int BG::SetTopPoint(int center, int top, DirectX::XMINT2 topPos, DirectX::XMINT2 centerPos, int delayIndex)
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

int BG::SetRightPoint(int center, int right, DirectX::XMINT2 rightPos, DirectX::XMINT2 centerPos, int delayIndex)
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

int BG::SetBottomPoint(int center, int bottom, DirectX::XMINT2 bottomPos, DirectX::XMINT2 centerPos, int delayIndex)
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
