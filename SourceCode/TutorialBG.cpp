//------< インクルード >--------------------------------------------------------
#include "all.h"
#include "TutorialBG.h"
#include "common.h"
#include "collision.h"

//------< using >---------------------------------------------------------------
using namespace GameLib;
using namespace DirectX;

//------< データ >---------------------------------------------------------------
int terrain_back_T[TutorialBG::STAGE_NUM][TutorialBG::CHIP_NUM_Y][TutorialBG::CHIP_NUM_X] =// 地形データ[ステージ数][X][Y]
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
    {   //設置不可マスの説明用
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

int bomb_pattern_T[8][4][3][3]//[爆弾の種類][回転の種類][y][x]
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

//爆弾の種類を変える
int bomb_numchanger_T(int now, int past)
{
    while (now == past)now = rand() % 8;
    return now;
}

//--------------------------------
//  コンストラクタ
//--------------------------------
TutorialBG::TutorialBG()
{
}

//--------------------------------
//  デストラクタ
//--------------------------------
TutorialBG::~TutorialBG()
{
}

//--------------------------------
//  初期設定
//--------------------------------
void TutorialBG::init(int stagenum)
{
    static GameLib::Sprite* effect_explosion = nullptr;
    static GameLib::Sprite* effect_bomb      = nullptr;
    effect_explosion = sprite_load(EXPLOSION);
    effect_bomb      = sprite_load(BOMB01);

    //地形データterrain_backをbomb地形データterrainに代入する
    for (int s = 0; s < STAGE_NUM; s++)
    {
        for (int x = 0; x < CHIP_NUM_X; x++)
        {
            for (int y = 0; y < CHIP_NUM_Y; y++)
            {
                //地形データterrain_backをbomb地形データterrainに代入する
                terrainData[s][y][x].status = terrain_back_T[s][y][x];

                //bomb地形の情報を初期化
                InitTerrain(TerrainStatus::Normal, s, x, y);
                SetTerrainPos(XMINT2(x, y), s);

                terrainData[s][y][x].terrain_endurance = 10000;
                if (terrain_back_T[s][y][x] == 2)
                {
                    terrainData[s][y][x].terrain_endurance = 1;//1回爆破すると置けなくなる
                }

                //エフェクトの情報を初期化
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

    texture::load(Tile01, TILE01, 1024U);          //背景
    texture::load(Tile02, TILE02, 1024U);          //背景
    texture::load(Bomb01, BOMB01, 1024U);          //爆弾
    texture::load(Explosion, EXPLOSION, 1024U);    //爆発
    texture::load(Reset, RESET, 124U);            //リセット
    texture::load(Shape, SHAPE, 1024U);            //設置不可能マス
    texture::load(TutorialText1,TEXT1,24U);

    //バクダンの種類を初期化
    for (int i = 0; i < BOMB_TYPE_MAX; i++)
    {
        //爆弾の種類決定
        int defnum = bomb_typenum[i];
        bomb_typenum[i] = bomb_numchanger_T(bomb_typenum[i], defnum);
        if (i > 1 && bomb_typenum[i] == bomb_typenum[i - 2])bomb_typenum[i] = bomb_numchanger_T(bomb_typenum[i], bomb_typenum[i - 2]);//1週目の爆弾と同じ種類なら変更
        if (i > 0 && bomb_typenum[i] == bomb_typenum[i - 1])bomb_typenum[i] = bomb_numchanger_T(bomb_typenum[i], bomb_typenum[i - 1]);//0週目の爆弾と同じ種類なら変更
        bomb_trun[i] = 0;
    }
    act = 0;
    bomb_movingtype = false;
    bomb_roopchecker = false;
    score = 0;
    finish_game = false;

    //タイマー初期化
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

    //線形保管の重み
    weight = 0.041f;

    isPutOnFuse = true;

    isShowUnPutBle = false;
}

//--------------------------------
//  終了処理
//--------------------------------
void TutorialBG::deinit()
{
    //テクスチャ解放
    texture::releaseAll();
}

//--------------------------------
//  更新処理
//--------------------------------
void TutorialBG::update()
{
    //カーソルの位置を取得、制限
    cursorPos = { static_cast<float>(GameLib::input::getCursorPosX()), static_cast<float>(GameLib::input::getCursorPosY()) };
    if (cursorPos.x < 0)cursorPos.x = 0;
    if (cursorPos.x > GameLib::window::getWidth())cursorPos.x = GameLib::window::getWidth();
    if (cursorPos.y < 0)cursorPos.y = 0;
    if (cursorPos.y > GameLib::window::getHeight())cursorPos.y = GameLib::window::getHeight();

    //カーソルの位置を背景に対応
    DirectX::XMINT2 Cpos = {
    static_cast<int>((cursorPos.x - Mapterrain_correction.x) / CHIP_SIZE),
    static_cast<int>((cursorPos.y - Mapterrain_correction.y) / CHIP_SIZE)
    };

    //カーソルがbomb背景内に存在しているか
    bool isInStage = cursorPos.x > Mapterrain_correction.x
                  && cursorPos.x < (Mapterrain_correction.x + CHIP_SIZE * TutorialBG::CHIP_NUM_X)
                  && cursorPos.y >  Mapterrain_correction.y
                  && cursorPos.y < (Mapterrain_correction.y + CHIP_SIZE * TutorialBG::CHIP_NUM_Y);

    //右、左クリックなどをしているか否か
    isClickL = timer > operatbleCursorTime && GameLib::input::STATE(0) & GameLib::input::PAD_LC;
    isClickR = timer > operatbleCursorTime && GameLib::input::STATE(0) & GameLib::input::PAD_RC;
    isZ = timer > operatbleCursorTime && GameLib::input::STATE(0) & GameLib::input::PAD_TRG1;
    isX = timer > operatbleCursorTime && GameLib::input::STATE(0) & GameLib::input::PAD_TRG2;
    isC = timer > operatbleCursorTime && GameLib::input::STATE(0) & GameLib::input::PAD_TRG3;

    //ステージの移動フラグを設定
    setMoveFlags();

    //導火線マスからバクダンマスに変更されたか
    bool isChangeedFuelToBomb = false;

    //カーソルをさしているマスが壁か否か
    bool isUnBreakble = terrainData[nowStage][Cpos.y][Cpos.x].status == TerrainStatus::UnBreakble;

    //爆初の連鎖の係数
    //0以上にすると最初の方は連鎖せず一気に爆発するようになる
    int delayIndex = -1;

    //爆発させる箇所
    DirectX::XMINT2 ExplodePos[EXPLOSION_CHIP_NUM] = {};

    //爆弾を置いた後のリセット
    resetBombPostProcess();

    //爆弾をリセット
    resetButton();

    //IsPutOnFuse();

    if (burningFuse.exist || (tutorialNum == 1 && textBoxes[1]->GetPopOutFlag()))
    {
        //爆弾をドラッグ
        dragBomb();

        //爆弾を回転
        rotateBomb();

        //爆弾をドロップ
        dropBomb();

        //カーソルがステージ内の時
        if (isInStage)
        {
            //爆弾設置
            for (int i = 0; i < 2; ++i)//0週目で全部の爆弾読み込んで「隣が壁or爆弾」&「開いてるマスがないと置けない」ことを調べて配置可能なら1週目で配置
            {
                for (int x = 0; x < 3; ++x)
                {
                    for (int y = 0; y < 3; ++y)
                    {
                        //爆弾の種類取得
                        int pt_bomb = bomb_pattern_T[bomb_typenum[bomb_waitingarea]][bomb_trun[bomb_waitingarea]][y][x];

                        //爆弾1ブロック中心座標(スクリーン座標＋配列[y][x]目のブロック)
                        DirectX::XMFLOAT2 bomb_pos_b = { bomb_changepos[bomb_waitingarea].x + CHIP_SIZE * x,bomb_changepos[bomb_waitingarea].y + CHIP_SIZE * y };
                        //マップチップの配列の場所
                        DirectX::XMINT2 Cpos = { static_cast<int>((bomb_pos_b.x - Mapterrain_correction.x) / CHIP_SIZE_F) , static_cast<int>((bomb_pos_b.y - Mapterrain_correction.y) / CHIP_SIZE_F) };

                        if (pt_bomb == PatternStatus::IsBomb)
                        {
                            if (
                                //隣が壁だったら
                                terrainData[nowStage][Cpos.y - 1][Cpos.x].status == TerrainStatus::UnBreakble ||//上
                                terrainData[nowStage][Cpos.y + 1][Cpos.x].status == TerrainStatus::UnBreakble ||//下
                                terrainData[nowStage][Cpos.y][Cpos.x + 1].status == TerrainStatus::UnBreakble ||//右
                                terrainData[nowStage][Cpos.y][Cpos.x - 1].status == TerrainStatus::UnBreakble ||//左
                                //隣が爆弾だったら
                                terrainData[nowStage][Cpos.y - 1][Cpos.x].status == TerrainStatus::Bomb ||//上
                                terrainData[nowStage][Cpos.y + 1][Cpos.x].status == TerrainStatus::Bomb ||//下
                                terrainData[nowStage][Cpos.y][Cpos.x + 1].status == TerrainStatus::Bomb ||//右
                                terrainData[nowStage][Cpos.y][Cpos.x - 1].status == TerrainStatus::Bomb   //左
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
                                    //爆弾設置
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
                                    //爆弾リセット
                                    bomb_reset = true;
                                }
                            }
                        }
                    }
                }
            }
            bomb_roopchecker = false;
            bomb_release = false;

            //爆破
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
                //スコア
                score += score_add * (score_counter * 1.05) * 0.01;
                //画面が揺れる
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
    //揺れた画面を元に戻す
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
        //ステージムーバー更新処理
        stageMover->Update();
        //1つでもステージが動いている時、他のステージを動かさないようにする
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
//  地形描画
//--------------------------------
void TutorialBG::drawTerrain()
{
    //マップ
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

    //バクダン
    texture::begin(Tile02);
    for (int s = 0; s < STAGE_NUM; s++)
    {
        if (!isDrawStage[s])break;
        for (int x = 0; x < CHIP_NUM_X; x++)
        {
            for (int y = 0; y < CHIP_NUM_Y; y++)
            {
                //設置不可マスの描画
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
                    //バクダンの描画
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
                        //連鎖するための時間のずらしが完了したので爆発を描画
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
                        //爆発の連鎖が始まったが、まだ爆発していないバクダンの描画
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
                        //バクダンの遅延を行うタイマーの減少
                        terrainData[s][y][x].DelayTimer--;
                    }
                }
                if (terrainData[s][y][x].status == TerrainStatus::BurningFuse)
                {
                    if (burningFuse.Cpos.x == x && burningFuse.Cpos.y == y)
                    {
                        //導火線の描画
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
                        //導火線の位置が変更されたのでterrainの状態も変更する
                        terrainData[s][y][x].status = TerrainStatus::Normal;
                    }
                }
                //爆発終了
                if (terrainData[s][y][x].explosionTimer < 0) {
                    //爆発が終了したのでterrainの状態を初期化する
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

    //爆弾があるかないか
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
                        //爆発の連鎖が始まったが、まだ爆発していないバクダンの描画
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

    //設置不可マスの描画
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


//チュートリアル
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

        //チュートリアルへようこそ
        textBoxes[0]->SetPopUpFlag(timer > 10);
        textBoxes[0]->SetPopOutFlag(isClickL && textBoxes[0]->WaitTime(30));

        //火をつけて爆弾の爆発を連鎖させ、ハイスコアを狙いましょう
        textBoxes[1]->SetPopUpFlag(textBoxes[0]->GetPopOutFlag());
        textBoxes[1]->SetPopOutFlag(isClickL && textBoxes[1]->WaitTime(30));

        //まず、火をつけたい場所にｘキーで火を付けましょう
        textBoxes[2]->SetPopUpFlag(textBoxes[1]->GetPopOutFlag());
        textBoxes[2]->SetPopOutFlag(isSetFuse && textBoxes[2]->WaitTime(45));

        //次に爆弾を設置しますが、いくつか注意すべきことがあります。

        if (textBoxes[5]->GetPopUpFlag())isShowUnPutBle = true;
        textBoxes[5]->SetPopUpFlag(textBoxes[2]->GetPopOutFlag());
        textBoxes[5]->SetPopOutFlag(isClickL && textBoxes[5]->WaitTime(45));

        //爆弾を設置する場所に赤いバツ印があればその場所に爆弾を置くことができません

        textBoxes[6]->SetPopUpFlag(textBoxes[5]->GetPopOutFlag());
        textBoxes[6]->SetPopOutFlag(isClickL && textBoxes[6]->WaitTime(45));

        //また、設置予定の場所が全て紫の三角形ならばこの場合でも置くことができません

        textBoxes[7]->SetPopUpFlag(textBoxes[6]->GetPopOutFlag());
        textBoxes[7]->SetPopOutFlag(isClickL && textBoxes[7]->WaitTime(45));

        //火のマスに爆弾を置くことで爆弾を爆発できます
        if (textBoxes[3]->GetPopUpFlag())isShowUnPutBle = false;
        textBoxes[3]->SetPopUpFlag(textBoxes[7]->GetPopOutFlag());
        textBoxes[3]->SetPopOutFlag(drag_con);

        //もし、火のマスに爆弾を置けない状況に陥ったら、リセットボタンを押しましょう
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
        focuses[1]->SetUnFocusFlag(drag_con);   //ボムを持っている時

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

        //他のブロックと見た目が違うブロックがあります
        //壊してみましょう
        textBoxes[0]->SetPopUpFlag(true);
        textBoxes[0]->SetPopOutFlag(isClickL);

        //火を置きたい場所にカーソルを向けてＸ
        textBoxes[1]->SetPopUpFlag(textBoxes[0]->GetPopOutFlag());
        textBoxes[1]->SetPopOutFlag(isSetFuse);

        //Ｄ＆Ｄで爆弾を設置
        textBoxes[2]->SetPopUpFlag(textBoxes[1]->GetPopOutFlag());
        textBoxes[2]->SetPopOutFlag(drag_con);

        //ヒビが入っているブロックを全て壊す
        textBoxes[4]->SetPopUpFlag(textBoxes[1]->GetPopOutFlag());
        textBoxes[4]->SetPopOutFlag(isNotBrakbleTerrain);

        //このようにひびが入っているブロックは一度爆風を当てると壊れてしまいます
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
        focuses[1]->SetUnFocusFlag(drag_con);   //ボムを持っている時
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

//爆弾をドラッグ
void TutorialBG::dragBomb()
{
    for (int bomb_array = 0; bomb_array < BOMB_ROTATE_MAX; bomb_array++)
    {
        for (int x = 0; x < 3; ++x)
        {
            for (int y = 0; y < 3; ++y)
            {
                //爆弾の種類取得
                int pt_bomb = bomb_pattern_T[bomb_typenum[bomb_array]][bomb_trun[bomb_array]][y][x];

                if (pt_bomb == PatternStatus::IsBomb)
                {
                    int bomb_array_vaut = bomb_array;
                    if (bomb_movingtype)bomb_array = bomb_waitingarea;
                    DirectX::XMFLOAT2 bomb_pos;
                    //爆弾1ブロック中心座標(スクリーン座標＋配列[y][x]目のブロック)
                    bomb_pos = { bomb_changepos[bomb_array].x + CHIP_SIZE * x,bomb_changepos[bomb_array].y + CHIP_SIZE * y };
                    //あたり判定||カーソル速度が速すぎることの対応
                    if (collision_center(cursorPos, bomb_pos, chip_size_xmfloat2) || drag_con)
                    {
                        if (GameLib::input::STATE(0) & GameLib::input::PAD_LC)
                        {
                            //爆弾の位置をカーソルの位置に追従
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
        if (drag_con)break;//ドラッグしている場合1つの爆弾に固定
    }
}

//爆弾を回転
void TutorialBG::rotateBomb()
{
    if (GameLib::input::TRG(0) & GameLib::input::PAD_RC)
    {
        bomb_trun[bomb_waitingarea]++;
        if (bomb_trun[bomb_waitingarea] > 3)bomb_trun[bomb_waitingarea] = 0;
    }
}

//爆弾をドロップ
void TutorialBG::dropBomb()
{
    if (GameLib::input::TRG_RELEASE(0) & GameLib::input::PAD_LC)
    {
        drag_con = false;
        isReset = false;
    }
}

//爆弾をリセット
void TutorialBG::resetButton()
{
    //リセット
    reset_scale = { 0.45f,0.45f };
    reset_pos = { 90,650 };
    reset_center = { 200, 100 };
    if (collision_center(cursorPos, reset_pos, reset_center))
    {
        reset_scale = { 0.5f,0.5f };
        if (GameLib::input::TRG(0) & GameLib::input::PAD_LC && drag_con == false)
        {
            isReset = true;

            bomb_changepos[bomb_waitingarea] = bomb_defpos[bomb_waitingarea];//位置を初期位置に戻す

            //爆弾の種類を変える
            int  defnum = bomb_typenum[bomb_waitingarea];
            bomb_trun[bomb_waitingarea] = 0;//回転を初期角度に戻す
            bomb_movingtype = false;
            bomb_roopchecker = false;

            //地形データterrain_backをbomb地形データterrainに代入する
            for (int x = 0; x < CHIP_NUM_X; x++)
            {
                for (int y = 0; y < CHIP_NUM_Y; y++)
                {
                    //bomb地形の情報を初期化
                    InitTerrain(TerrainStatus::Normal, nowStage, x, y);

                    if (terrainData[nowStage][y][x].status == TerrainStatus::Bomb)
                    {
                        terrainData[nowStage][y][x].status = TerrainStatus::Normal;
                    }

                    //エフェクトの情報を初期化
                    TerrainBomb[nowStage][y][x].pos = VECTOR2(x * CHIP_SIZE_F, y * CHIP_SIZE_F);
                    TerrainBomb[nowStage][y][x].animeNum = 3;
                    TerrainBomb[nowStage][y][x].exist = false;
                }
            }

            //バクダンの種類を初期化
            for (int i = 0; i < BOMB_TYPE_MAX; i++)
            {
                //爆弾の種類決定
                int defnum = bomb_typenum[i];
                bomb_typenum[i] = bomb_numchanger_T(bomb_typenum[i], defnum);
                if (i > 1 && bomb_typenum[i] == bomb_typenum[i - 2])bomb_typenum[i] = bomb_numchanger_T(bomb_typenum[i], bomb_typenum[i - 2]);//1週目の爆弾と同じ種類なら変更
                if (i > 0 && bomb_typenum[i] == bomb_typenum[i - 1])bomb_typenum[i] = bomb_numchanger_T(bomb_typenum[i], bomb_typenum[i - 1]);//0週目の爆弾と同じ種類なら変更
                bomb_trun[i] = 0;
            }
        }
    }
}

//爆弾を置いた後のリセット
void TutorialBG::resetBombPostProcess()
{
    if (bomb_reset)
    {
        bomb_changepos[bomb_waitingarea] = bomb_defpos[bomb_waitingarea];//位置を初期位置に戻す

        //爆弾の種類を変える
        int  defnum = bomb_typenum[bomb_waitingarea];
        bomb_typenum[bomb_waitingarea] = bomb_numchanger_T(bomb_typenum[bomb_waitingarea], defnum);
        bomb_trun[bomb_waitingarea] = 0;//回転を初期角度に戻す
        bomb_movingtype = false;
        bomb_roopchecker = false;
        bomb_reset = false;//リセットを解除してドラッグできるようにする
    }
}

//そのブロックにバクダンが設置可能か
void TutorialBG::SetIsPutOn()
{
    for (int s = 0; s < STAGE_NUM; s++)
    {
        for (int x = 0; x < CHIP_NUM_X; x++)
        {
            for (int y = 0; y < CHIP_NUM_Y; y++)
            {
                //外周は爆弾マスを置けない
                if (x == 0 || y == 0)
                {
                    terrainData[s][y][x].isPutOn = false;
                    continue;
                }

                //導火線マスか普通のマス以外は置けない
                if (terrainData[s][y][x].status != TerrainStatus::BurningFuse &&
                    terrainData[s][y][x].status != TerrainStatus::Normal)
                {
                    terrainData[s][y][x].isPutOn = false;
                    continue;
                }

                //壁、または爆弾マスに隣接していないと置けない
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
//  ステージを移動させる
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

                    //ステージの最後のマップチップの時のみ実行
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
                                //この関数を終わらせる
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

                    //ステージの最後のマップチップの時のみ実行
                    if (y == CHIP_NUM_Y - 1 && x == CHIP_NUM_X - 1)
                    {
                        XMVECTOR LengthSq = XMVector2Length(XMVectorSubtract(EndPos, CurrentPos));
                        float lengthSq;
                        XMStoreFloat(&lengthSq, LengthSq);
                        if (lengthSq < 1.0f)
                        {
                            //この関数を終わらせる
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
//  ステージの移動フラグを設定
//--------------------------------
void TutorialBG::setMoveFlags()
{

}

//--------------------------------
//  指定した箇所にすでに変更が加えられているか
//--------------------------------
bool TutorialBG::IsAlreadyChanged(int stageNum, DirectX::XMINT2 terrainPos)
{
    return terrainData[stageNum][terrainPos.x][terrainPos.y].isAlredyChanged;
}

//--------------------------------
//  バクダンを設置
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
//  連鎖が終わる
//--------------------------------
void TutorialBG::finishChain(int stageNum, DirectX::XMINT2 terrainPos)
{
    terrainData[stageNum][terrainPos.x][terrainPos.y].isChained = true;
}

//--------------------------------
//  terrainの初期化
//--------------------------------
void TutorialBG::InitTerrain(TerrainStatus terrainStatus, int stageNum, DirectX::XMINT2 terrainPos)
{
    //TerrainStatus::Noneの時、状態を変更しない
    if (terrainStatus != TerrainStatus::None)
    {
        if (terrainData[stageNum][terrainPos.y][terrainPos.x].status != TerrainStatus::UnBreakble)
            terrainData[stageNum][terrainPos.y][terrainPos.x].status = terrainStatus;
    }
    //terrainDataを初期化
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

    //最初のステージは初期値をimGamePos(画面中央)、それ以外は初期値をstartPosにする
    DirectX::XMFLOAT2 defaultPos = stageNum == 0 ? inGamePos : startPos;
    terrainData[stageNum][terrainPos.y][terrainPos.x].currentPos = defaultPos;
}

//--------------------------------
//  導火線を置けるか
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
//  指定した箇所の情報をセット
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
//  エフェクトを更新
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
//  爆発箇所の計算
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
//  初期設定
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
    //該当ブロックがステージの外に出ていないか
    bool isNotEdge = centerPos.x < 0 || centerPos.y < 0 || centerPos.x >= CHIP_NUM_Y || centerPos.y >= CHIP_NUM_X;

    if (isNotEdge && center == TerrainStatus::InExplosion)
    {
        return center;
    }

    //該当ブロックのデータ設定
    SetTerrainData(stageNum, centerPos, delayIndex);

    return TerrainStatus::InExplosion;
}

int TutorialBG::SetLeftPoint(int stageNum, int center, int left, DirectX::XMINT2 leftPos, DirectX::XMINT2 centerPos, int delayIndex)
{
    //該当ブロックがステージの外に出ていないか
    bool isNotEdge = leftPos.x < 0 || leftPos.y < 0 || leftPos.x > CHIP_NUM_Y || leftPos.y > CHIP_NUM_X;

    if (isNotEdge || center == TerrainStatus::UnBreakble || left == TerrainStatus::UnBreakble || left == TerrainStatus::InExplosion)
    {
        return left;
    }

    //該当ブロックのデータ設定
    SetTerrainData(stageNum, leftPos, delayIndex);

    //連鎖爆破処理
    DirectX::XMINT2 inversePos{ leftPos.y, leftPos.x };
    if (left == TerrainStatus::Bomb)
    {
        //連鎖爆破箇所計算
        DirectX::XMINT2 explodePos[EXPLOSION_CHIP_NUM] = {
            DirectX::XMINT2(-1,-1),//CENTER
            CalcExplosionPoint(inversePos,ExplosionPoint::LEFT),
            CalcExplosionPoint(inversePos,ExplosionPoint::TOP),
            DirectX::XMINT2(-1,-1),//RIGHT
            CalcExplosionPoint(inversePos,ExplosionPoint::BOTTOM),
        };

        //爆弾設置
        SetBomb(stageNum, explodePos[ExplosionPoint::LEFT], ExplosionPoint::LEFT, delayIndex);
        SetBomb(stageNum, explodePos[ExplosionPoint::TOP], ExplosionPoint::TOP, delayIndex);
        SetBomb(stageNum, explodePos[ExplosionPoint::BOTTOM], ExplosionPoint::BOTTOM, delayIndex);
    }
    //爆発の連鎖が起こらなかった場合
    else
    {
        finishChain(stageNum, leftPos);
    }

    return TerrainStatus::InExplosion;
}

int TutorialBG::SetTopPoint(int stageNum, int center, int top, DirectX::XMINT2 topPos, DirectX::XMINT2 centerPos, int delayIndex)
{
    //該当ブロックがステージの外に出ていないか
    bool isNotEdge = topPos.x < 0 || topPos.y < 0 || topPos.x > CHIP_NUM_Y || topPos.y > CHIP_NUM_X;

    if (isNotEdge || center == TerrainStatus::UnBreakble || top == TerrainStatus::UnBreakble || top == TerrainStatus::InExplosion)
    {
        return top;
    }

    //該当ブロックのデータ設定
    SetTerrainData(stageNum, topPos, delayIndex);

    //連鎖爆破処理
    DirectX::XMINT2 inversePos{ topPos.y, topPos.x };
    if (top == TerrainStatus::Bomb)
    {
        //連鎖爆破箇所計算
        DirectX::XMINT2 explodePos[EXPLOSION_CHIP_NUM] = {
            DirectX::XMINT2(-1,-1),//CENTER
            CalcExplosionPoint(inversePos,ExplosionPoint::LEFT),
            CalcExplosionPoint(inversePos,ExplosionPoint::TOP),
            CalcExplosionPoint(inversePos,ExplosionPoint::RIGHT),
            DirectX::XMINT2(-1,-1),//BOTTOM
        };

        //爆弾設置
        SetBomb(stageNum, explodePos[ExplosionPoint::LEFT], ExplosionPoint::LEFT, delayIndex);
        SetBomb(stageNum, explodePos[ExplosionPoint::TOP], ExplosionPoint::TOP, delayIndex);
        SetBomb(stageNum, explodePos[ExplosionPoint::RIGHT], ExplosionPoint::RIGHT, delayIndex);
    }
    //爆発の連鎖が起こらなかった場合
    else
    {
        finishChain(stageNum, topPos);
    }

    return TerrainStatus::InExplosion;
}

int TutorialBG::SetRightPoint(int stageNum, int center, int right, DirectX::XMINT2 rightPos, DirectX::XMINT2 centerPos, int delayIndex)
{
    //該当ブロックがステージの外に出ていないか
    bool isNotEdge = rightPos.x < 0 || rightPos.y < 0 || rightPos.x >= CHIP_NUM_Y || rightPos.y >= CHIP_NUM_X;

    if (isNotEdge || center == TerrainStatus::UnBreakble || right == TerrainStatus::UnBreakble || right == TerrainStatus::InExplosion)
    {
        return right;
    }

    //該当ブロックのデータ設定
    SetTerrainData(stageNum, rightPos, delayIndex);

    //連鎖爆破処理
    DirectX::XMINT2 inversePos{ rightPos.y, rightPos.x };
    if (right == TerrainStatus::Bomb)
    {
        //連鎖爆破箇所計算
        DirectX::XMINT2 explodePos[EXPLOSION_CHIP_NUM] = {
            DirectX::XMINT2(-1,-1),//CENTER
            DirectX::XMINT2(-1,-1),//LEFT
            CalcExplosionPoint(inversePos,ExplosionPoint::TOP),
            CalcExplosionPoint(inversePos,ExplosionPoint::RIGHT),
            CalcExplosionPoint(inversePos,ExplosionPoint::BOTTOM),
        };

        //爆弾設置
        SetBomb(stageNum, explodePos[ExplosionPoint::TOP], ExplosionPoint::TOP, delayIndex);
        SetBomb(stageNum, explodePos[ExplosionPoint::RIGHT], ExplosionPoint::RIGHT, delayIndex);
        SetBomb(stageNum, explodePos[ExplosionPoint::BOTTOM], ExplosionPoint::BOTTOM, delayIndex);
    }
    //爆発の連鎖が起こらなかった場合
    else
    {
        finishChain(stageNum, rightPos);
    }

    return TerrainStatus::InExplosion;
}

int TutorialBG::SetBottomPoint(int stageNum, int center, int bottom, DirectX::XMINT2 bottomPos, DirectX::XMINT2 centerPos, int delayIndex)
{
    //該当ブロックがステージの外に出ていないか
    bool isNotEdge = bottomPos.x < 0 || bottomPos.y < 0 || bottomPos.x >= CHIP_NUM_Y || bottomPos.y >= CHIP_NUM_X;

    if (isNotEdge || center == TerrainStatus::UnBreakble || bottom == TerrainStatus::UnBreakble || bottom == TerrainStatus::InExplosion)
    {
        return bottom;
    }

    //該当ブロックのデータ設定
    SetTerrainData(stageNum, bottomPos, delayIndex);

    //連鎖爆破処理
    DirectX::XMINT2 inversePos{ bottomPos.y, bottomPos.x };
    if (bottom == TerrainStatus::Bomb)
    {
        //連鎖爆破箇所計算
        DirectX::XMINT2 explodePos[EXPLOSION_CHIP_NUM] = {
            DirectX::XMINT2(-1,-1),//CENTER
            CalcExplosionPoint(inversePos,ExplosionPoint::LEFT),
            DirectX::XMINT2(-1,-1),//TOP
            CalcExplosionPoint(inversePos,ExplosionPoint::RIGHT),
            CalcExplosionPoint(inversePos,ExplosionPoint::BOTTOM),
        };

        //爆弾設置
        SetBomb(stageNum, explodePos[ExplosionPoint::LEFT], ExplosionPoint::LEFT, delayIndex);
        SetBomb(stageNum, explodePos[ExplosionPoint::RIGHT], ExplosionPoint::RIGHT, delayIndex);
        SetBomb(stageNum, explodePos[ExplosionPoint::BOTTOM], ExplosionPoint::BOTTOM, delayIndex);
    }
    //爆発の連鎖が起こらなかった場合
    else
    {
        finishChain(stageNum, bottomPos);
    }

    return TerrainStatus::InExplosion;
}
