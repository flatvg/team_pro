//******************************************************************************
//
//
//      BGクラス
//
//
//******************************************************************************

//TODO
//ボムを描画

//------< インクルード >--------------------------------------------------------
#include "all.h"
#include "common.h"
#include "bg.h"
#include "collision.h"

//------< using >---------------------------------------------------------------
using namespace GameLib;

//------< データ >---------------------------------------------------------------
int terrain_back[4][BG::CHIP_NUM_Y][BG::CHIP_NUM_X] =// 地形データ[ステージ数][X][Y]
{
    //stage0
    {
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1, 0, 1, 0, 1, 0, 1, 0, 1, 0,-1},
        {-1, 1, 2, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1,-1},
        {-1, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,-1},
        {-1, 2, 2, 0, 1, 0, 1,-1, 1, 0,-1,-1,-1,-1},
        {-1, 1, 0, 1, 0, 1, 0,-1, 0, 1,-1,-1,-1,-1},
        {-1, 1, 1, 0, 1,-1,-1,-1, 1, 0,-1,-1,-1,-1},
        {-1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,-1},
        {-1, 1, 1,-1,-1,-1, 1, 0, 1, 0, 1, 0, 1,-1},
        {-1, 1, 0,-1,-1,-1, 0, 1, 0, 1, 0, 1, 0,-1},
        {-1, 1, 1,-1,-1,-1, 1, 0, 1, 0, 1, 0, 1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    },
};

int bomb_pattern[8][4][3][3]//[爆弾の種類][回転の種類][y][x]
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
int bomb_numchanger(int now, int past)
{
    while (now == past)now = rand() % 8;
    return now;
}

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
    static GameLib::Sprite* effect_explosion = nullptr;
    static GameLib::Sprite* effect_bomb      = nullptr;
    effect_explosion = sprite_load(EXPLOSION);
    effect_bomb      = sprite_load(BOMB01);

    //地形データterrain_backをbomb地形データterrainに代入する
    for (int x = 0; x < CHIP_NUM_X; x++)
    {
        for (int y = 0; y < CHIP_NUM_Y; y++)
        {
            //地形データterrain_backをbomb地形データterrainに代入する
            terrainData[y][x].status = terrain_back[stagenum][y][x];

            //bomb地形の情報を初期化
            InitTerrain(TerrainStatus::Normal, x, y);

            terrainData[y][x].terrain_endurance = 10000;
            if (terrain_back[stagenum][y][x] == 2)
            {
                terrainData[y][x].terrain_endurance = 1;//1回爆破すると置けなくなる
            }

            //エフェクトの情報を初期化
            TerrainExplosion[y][x].pos = DirectX::XMFLOAT2(x * CHIP_SIZE_F, y * CHIP_SIZE_F);
            TerrainExplosion[y][x].timer = 0;
            TerrainExplosion[y][x].animeMax = 7;
            TerrainExplosion[y][x].animeNum = 0;
            TerrainExplosion[y][x].exist = false;
            TerrainExplosion[y][x].playSpeed = 1.0f;
            effect_explosion->getSize(TerrainExplosion[y][x].tx, TerrainExplosion[y][x].ty);
            TerrainExplosion[y][x].texSizeX = TerrainExplosion[y][x].tx / TerrainExplosion[y][x].animeMax;

            TerrainBomb[y][x].pos = DirectX::XMFLOAT2(x * CHIP_SIZE_F, y * CHIP_SIZE_F);
            TerrainBomb[y][x].timer = 0;
            TerrainBomb[y][x].animeMax = 4;
            TerrainBomb[y][x].animeNum = 0;
            TerrainBomb[y][x].exist = true;
            TerrainBomb[y][x].playSpeed = 0.4f;
            effect_bomb->getSize(TerrainBomb[y][x].tx, TerrainBomb[y][x].ty);
            TerrainBomb[y][x].texSizeX = static_cast<float>(TerrainBomb[y][x].tx - 122.0f) / TerrainBomb[y][x].animeMax;
        }
    }
    delete effect_bomb;
    delete effect_explosion;

    texture::load(Tile01, TILE01, 256U);           //背景
    texture::load(Tile02, TILE02, 256U);           //背景
    texture::load(Bomb01, BOMB01, 256U);           //爆弾
    texture::load(Explosion, EXPLOSION, 256U);     //爆発
    texture::load(Reset, RESET, 256U);             //リセット
    texture::load(BreakbleTile, BREAKETILE, 256U); //破壊可能ブロック

    //バクダンの種類を初期化
    for (int i = 0; i < BOMB_TYPE_MAX; i++)
    {
        //爆弾の種類決定
        int defnum = bomb_typenum[i];
        bomb_typenum[i] = bomb_numchanger(bomb_typenum[i], defnum);
        if (i > 1 && bomb_typenum[i] == bomb_typenum[i - 2])bomb_typenum[i] = bomb_numchanger(bomb_typenum[i], bomb_typenum[i - 2]);//1週目の爆弾と同じ種類なら変更
        if (i > 0 && bomb_typenum[i] == bomb_typenum[i - 1])bomb_typenum[i] = bomb_numchanger(bomb_typenum[i], bomb_typenum[i - 1]);//0週目の爆弾と同じ種類なら変更
        bomb_trun[i] = 0;
    }
    act = 0;
    bomb_movingtype = false;
    bomb_roopchecker = false;
    score = 0;
    finish_game = false;

    //タイマー初期化
    timer = 0;

    focusFactor = 1.0f;
    focusFlag = false;
    unFocusFlag = false;

    focus = std::make_unique<Focus>(VECTOR2(500.0f, 300.0f), 300.0f);
}

//--------------------------------
//  終了処理
//--------------------------------
void BG::deinit()
{
    //テクスチャ解放
    texture::releaseAll();
}

//--------------------------------
//  更新処理
//--------------------------------
void BG::update()
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
    bool isInStage = cursorPos.x >  Mapterrain_correction.x
                  && cursorPos.x < (Mapterrain_correction.x + CHIP_SIZE * BG::CHIP_NUM_X)
                  && cursorPos.y >  Mapterrain_correction.y
                  && cursorPos.y < (Mapterrain_correction.y + CHIP_SIZE * BG::CHIP_NUM_Y);

    //右、左クリックなどをしているか否か
    bool isClickL = timer > operatbleCursorTime && GameLib::input::STATE(0) & GameLib::input::PAD_LC;
    bool isClickR = timer > operatbleCursorTime && GameLib::input::STATE(0) & GameLib::input::PAD_RC;
    bool isZ      = timer > operatbleCursorTime && GameLib::input::STATE(0) & GameLib::input::PAD_TRG1;
    bool isX      = timer > operatbleCursorTime && GameLib::input::STATE(0) & GameLib::input::PAD_TRG2;
    bool isC      = timer > operatbleCursorTime && GameLib::input::STATE(0) & GameLib::input::PAD_TRG3;

    focus->SetFocusFlag(isC);
    focus->SetUnFocusFlag(isX);

    //導火線マスからバクダンマスに変更されたか
    bool isChangeedFuelToBomb = false;

    //カーソルをさしているマスが壁か否か
    bool isUnBreakble = terrainData[Cpos.y][Cpos.x].status == TerrainStatus::UnBreakble;

    //爆初の連鎖の係数
    //0以上にすると最初の方は連鎖せず一気に爆発するようになる
    int delayIndex = -1;

    //爆発させる箇所
    DirectX::XMINT2 ExplodePos[EXPLOSION_CHIP_NUM] = {};

    //爆弾を置いた後のリセット
    resetBombPostProcess();

    //爆弾をリセット
    resetButton();

    if (burningFuse.exist)
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
                        int pt_bomb = bomb_pattern[bomb_typenum[bomb_waitingarea]][bomb_trun[bomb_waitingarea]][y][x];

                        //爆弾1ブロック中心座標(スクリーン座標＋配列[y][x]目のブロック)
                        DirectX::XMFLOAT2 bomb_pos_b = { bomb_changepos[bomb_waitingarea].x + CHIP_SIZE * x,bomb_changepos[bomb_waitingarea].y + CHIP_SIZE * y };
                        //マップチップの配列の場所
                        DirectX::XMINT2 Cpos = { static_cast<int>((bomb_pos_b.x - Mapterrain_correction.x) / CHIP_SIZE_F) , static_cast<int>((bomb_pos_b.y - Mapterrain_correction.y) / CHIP_SIZE_F) };

                        if (pt_bomb == PatternStatus::IsBomb)
                        {
                            if (
                                //隣が壁だったら
                                terrainData[Cpos.y - 1][Cpos.x].status == TerrainStatus::UnBreakble ||//上
                                terrainData[Cpos.y + 1][Cpos.x].status == TerrainStatus::UnBreakble ||//下
                                terrainData[Cpos.y][Cpos.x + 1].status == TerrainStatus::UnBreakble ||//右
                                terrainData[Cpos.y][Cpos.x - 1].status == TerrainStatus::UnBreakble ||//左
                                //隣が爆弾だったら
                                terrainData[Cpos.y - 1][Cpos.x].status == TerrainStatus::Bomb ||//上
                                terrainData[Cpos.y + 1][Cpos.x].status == TerrainStatus::Bomb ||//下
                                terrainData[Cpos.y][Cpos.x + 1].status == TerrainStatus::Bomb ||//右
                                terrainData[Cpos.y][Cpos.x - 1].status == TerrainStatus::Bomb   //左
                                )
                            {
                                bomb_roopchecker = true;
                            }
                            if (bomb_roopchecker)
                            {
                                if (terrainData[Cpos.y][Cpos.x].status != TerrainStatus::Normal && terrainData[Cpos.y][Cpos.x].status != TerrainStatus::BurningFuse)bomb_release = true;
                                if (bomb_release)break;
                                if (i == 1 && GameLib::input::TRG_RELEASE(0) & GameLib::input::PAD_LC && (terrainData[Cpos.y][Cpos.x].status == TerrainStatus::Normal || terrainData[Cpos.y][Cpos.x].status == TerrainStatus::BurningFuse))
                                {
                                    //爆弾設置
                                    if (terrainData[Cpos.y][Cpos.x].status == TerrainStatus::BurningFuse && !isChangeedFuelToBomb)
                                    {
                                        isChangeedFuelToBomb = true;
                                        ExplodePos[ExplosionPoint::CENTER] = CalcExplosionPoint(Cpos, ExplosionPoint::CENTER);
                                        ExplodePos[ExplosionPoint::LEFT] = CalcExplosionPoint(Cpos, ExplosionPoint::LEFT);
                                        ExplodePos[ExplosionPoint::TOP] = CalcExplosionPoint(Cpos, ExplosionPoint::TOP);
                                        ExplodePos[ExplosionPoint::RIGHT] = CalcExplosionPoint(Cpos, ExplosionPoint::RIGHT);
                                        ExplodePos[ExplosionPoint::BOTTOM] = CalcExplosionPoint(Cpos, ExplosionPoint::BOTTOM);
                                    }
                                    terrainData[Cpos.y][Cpos.x].status = TerrainStatus::Bomb;
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
                for (int x = 0; x < CHIP_NUM_X; x++)
                {
                    for (int y = 0; y < CHIP_NUM_Y; y++)
                    {
                        terrainData[y][x].terrain_enduranceC = terrainData[y][x].terrain_endurance;
                    }
                }
                SetBomb(ExplodePos[ExplosionPoint::CENTER], ExplosionPoint::CENTER, delayIndex);
                SetBomb(ExplodePos[ExplosionPoint::LEFT], ExplosionPoint::LEFT, delayIndex);
                SetBomb(ExplodePos[ExplosionPoint::TOP], ExplosionPoint::TOP, delayIndex);
                SetBomb(ExplodePos[ExplosionPoint::RIGHT], ExplosionPoint::RIGHT, delayIndex);
                SetBomb(ExplodePos[ExplosionPoint::BOTTOM], ExplosionPoint::BOTTOM, delayIndex);
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

    if (!isUnBreakble && isX && !burningFuse.exist)
    {
        burningFuse.exist = true;
        burningFuse.pos = VECTOR2(
            Mapterrain_correction.x + Cpos.x * CHIP_SIZE_F - (CHIP_SIZE_F / 2),
            Mapterrain_correction.y + Cpos.y * CHIP_SIZE_F - (CHIP_SIZE_F / 2)
        );
        burningFuse.Cpos = Cpos;
        terrainData[Cpos.y][Cpos.x].status = TerrainStatus::BurningFuse;
    }

    for (int x = 0; x < CHIP_NUM_X; x++)
    {
        for (int y = 0; y < CHIP_NUM_Y; y++)
        {
            updateEffect(TerrainExplosion[y][x]);
            TerrainBomb[y][x].exist = true;
            updateEffect(TerrainBomb[y][x]);
        }
    }

    if (act > 20)finish_game = true;

    focus->update();

    timer++;
}

//--------------------------------
//  地形描画
//--------------------------------
void BG::drawTerrain()
{
    //マップ
    texture::begin(Tile01);
    for (int x = 0; x < CHIP_NUM_X; x++)
    {
        for (int y = 0; y < CHIP_NUM_Y; y++)
        {
            float a = terrain_back[0][y][x];
            texture::draw(
                TexNo::Tile01,
                Mapterrain_correction.x + (x * CHIP_SIZE_F), Mapterrain_correction.y + (y * CHIP_SIZE_F),
                1.0, 1.0,
                CHIP_SIZE_F * a, 0,
                CHIP_SIZE_F * (a + 1), CHIP_SIZE_F
            );
        }
    }
    texture::end(Tile01);

    texture::begin(BreakbleTile);
    for (int x = 0; x < CHIP_NUM_X; x++)
    {
        for (int y = 0; y < CHIP_NUM_Y; y++)
        {
            float a = terrain_back[0][y][x];
            if (a == 2)
            {
                texture::draw(
                    TexNo::BreakbleTile,
                    Mapterrain_correction.x + (x * CHIP_SIZE_F), Mapterrain_correction.y + (y * CHIP_SIZE_F),
                    1.0, 1.0,
                    CHIP_SIZE_F * 1, 0,
                    CHIP_SIZE_F * (1 + 1), CHIP_SIZE_F,
                    0, 0,
                    0,
                    WHITE
                );
            }

        }
    }
    texture::end(BreakbleTile);

    //バクダン
    texture::begin(Tile02);
    for (int x = 0; x < CHIP_NUM_X; x++)
    {
        for (int y = 0; y < CHIP_NUM_Y; y++)
        {
            if (terrainData[y][x].status == TerrainStatus::Bomb)
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
            if(terrainData[y][x].status == TerrainStatus::InExplosion)
            {
                if (terrainData[y][x].DelayTimer < 0)
                {
                    TerrainExplosion[y][x].exist = true;
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
                    terrainData[y][x].explosionTimer--;
                }
                else if(!terrainData[y][x].isChained)
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
                if (terrainData[y][x].isAlredyChanged)
                {
                    //バクダンの遅延を行うタイマーの減少
                    terrainData[y][x].DelayTimer--;
                }
            }
            if (terrainData[y][x].status == TerrainStatus::BurningFuse)
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
                    terrainData[y][x].status = TerrainStatus::Normal;
                }
            }
            //爆発終了
            if (terrainData[y][x].explosionTimer < 0) {
                //爆発が終了したのでterrainの状態を初期化する
                InitTerrain(TerrainStatus::Normal, x, y);
                //<HACK>
                if (terrainData[y][x].terrain_endurance <= 0)
                {
                    terrainData[y][x].status = TerrainStatus::UnBreakble;
                    terrain_back[stageNum][y][x] = -1;
                }

                TerrainExplosion[y][x].exist = false;
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
                int pt_bomb = bomb_pattern[bomb_typenum[bomb_array]][bomb_trun[bomb_array]][y][x];
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
        Reset,
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
                int pt_bomb = bomb_pattern[bomb_typenum[bomb_array]][bomb_trun[bomb_array]][y][x];
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
            if ((terrainData[y][x].status == TerrainStatus::Bomb) || (terrainData[y][x].status == TerrainStatus::InExplosion && !terrainData[y][x].isChained) && terrainData[y][x].DelayTimer >= 25)
            {
                texture::draw(
                    TexNo::Bomb01,
                    Mapterrain_correction.x + TerrainBomb[y][x].pos.x + CHIP_SIZE_F / 2, Mapterrain_correction.y + TerrainBomb[y][x].pos.y + CHIP_SIZE_F / 2,
                    1.0f, 1.0f,
                    0.0f, 0.0f,
                    CHIP_SIZE_F, CHIP_SIZE_F,
                    CHIP_SIZE_F * 0.5f, CHIP_SIZE_F * 0.5f,
                    0,
                    1, 1, 1, 1
                );
            }
            if (terrainData[y][x].status == TerrainStatus::InExplosion && !terrainData[y][x].isChained)
            {
                if (!terrainData[y][x].isChained && terrainData[y][x].DelayTimer < 20)
                {
                    //爆発の連鎖が始まったが、まだ爆発していないバクダンの描画
                    texture::draw(
                        TexNo::Bomb01,
                        Mapterrain_correction.x + TerrainBomb[y][x].pos.x + CHIP_SIZE_F / 2, Mapterrain_correction.y + TerrainBomb[y][x].pos.y + CHIP_SIZE_F / 2,
                        1.0f, 1.0f,
                        TerrainBomb[y][x].texSizeX * TerrainBomb[y][x].animeNum, 0.0f,
                        TerrainBomb[y][x].texSizeX, TerrainBomb[y][x].ty / 10,
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
            if (TerrainExplosion[y][x].exist)
            {
                texture::draw(
                    TexNo::Explosion,
                    Mapterrain_correction.x + TerrainExplosion[y][x].pos.x + CHIP_SIZE_F / 2, Mapterrain_correction.y + TerrainExplosion[y][x].pos.y + CHIP_SIZE_F / 2,
                    0.8f, 0.8f,
                    TerrainExplosion[y][x].texSizeX * TerrainExplosion[y][x].animeNum, 0.0f,
                    TerrainExplosion[y][x].texSizeX, TerrainExplosion[y][x].ty,
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
            if (terrainData[y][x].status == TerrainStatus::BurningFuse)
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
}

//爆弾をドラッグ
void BG::dragBomb()
{
    for (int bomb_array = 0; bomb_array < BOMB_ROTATE_MAX; bomb_array++)
    {
        for (int x = 0; x < 3; ++x)
        {
            for (int y = 0; y < 3; ++y)
            {
                //爆弾の種類取得
                int pt_bomb = bomb_pattern[bomb_typenum[bomb_array]][bomb_trun[bomb_array]][y][x];

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
void BG::rotateBomb()
{
    if (GameLib::input::TRG(0) & GameLib::input::PAD_RC)
    {
        bomb_trun[bomb_waitingarea]++;
        if (bomb_trun[bomb_waitingarea] > 3)bomb_trun[bomb_waitingarea] = 0;
    }
}

//爆弾をドロップ
void BG::dropBomb()
{
    if (GameLib::input::TRG_RELEASE(0) & GameLib::input::PAD_LC)
    {
        drag_con = false;
    }
}

//爆弾をリセット
void BG::resetButton()
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
                    InitTerrain(TerrainStatus::Normal, x, y);

                    if (terrainData[y][x].status == TerrainStatus::Bomb)
                    {
                        terrainData[y][x].status = TerrainStatus::Normal;
                    }

                    //エフェクトの情報を初期化
                    TerrainBomb[y][x].pos = VECTOR2(x * CHIP_SIZE_F, y * CHIP_SIZE_F);
                    TerrainBomb[y][x].animeNum = 3;
                    TerrainBomb[y][x].exist = false;
                }
            }

            //バクダンの種類を初期化
            for (int i = 0; i < BOMB_TYPE_MAX; i++)
            {
                //爆弾の種類決定
                int defnum = bomb_typenum[i];
                bomb_typenum[i] = bomb_numchanger(bomb_typenum[i], defnum);
                if (i > 1 && bomb_typenum[i] == bomb_typenum[i - 2])bomb_typenum[i] = bomb_numchanger(bomb_typenum[i], bomb_typenum[i - 2]);//1週目の爆弾と同じ種類なら変更
                if (i > 0 && bomb_typenum[i] == bomb_typenum[i - 1])bomb_typenum[i] = bomb_numchanger(bomb_typenum[i], bomb_typenum[i - 1]);//0週目の爆弾と同じ種類なら変更
                bomb_trun[i] = 0;
            }
        }
    }
}

//爆弾を置いた後のリセット
void BG::resetBombPostProcess()
{
    if (bomb_reset)
    {
        bomb_changepos[bomb_waitingarea] = bomb_defpos[bomb_waitingarea];//位置を初期位置に戻す

        //爆弾の種類を変える
        int  defnum = bomb_typenum[bomb_waitingarea];
        bomb_typenum[bomb_waitingarea] = bomb_numchanger(bomb_typenum[bomb_waitingarea], defnum);
        bomb_trun[bomb_waitingarea] = 0;//回転を初期角度に戻す
        bomb_movingtype = false;
        bomb_roopchecker = false;
        bomb_reset = false;//リセットを解除してドラッグできるようにする
    }
}

//--------------------------------
//  指定した箇所にすでに変更が加えられているか
//--------------------------------
bool BG::IsAlreadyChanged(DirectX::XMINT2 terrainPos)
{
    return terrainData[terrainPos.x][terrainPos.y].isAlredyChanged;
}

//--------------------------------
//  バクダンを設置
//--------------------------------
void BG::SetBomb(DirectX::XMINT2 terrainPos, ExplosionPoint point, int delayIndex)
{
    if (!IsAlreadyChanged(terrainPos)) {
        terrainData[terrainPos.x][terrainPos.y].status = SetExplosionPoint(terrainPos, point, delayIndex);
    }
    score_add += 10;
    score_counter++;
    if (terrainData[terrainPos.x][terrainPos.y].terrain_enduranceC == terrainData[terrainPos.x][terrainPos.y].terrain_endurance)terrainData[terrainPos.x][terrainPos.y].terrain_endurance--;
}

//--------------------------------
//  連鎖が終わる
//--------------------------------
void BG::finishChain(DirectX::XMINT2 terrainPos)
{
    terrainData[terrainPos.x][terrainPos.y].isChained = true;
}

//--------------------------------
//  terrainの初期化
//--------------------------------
void BG::InitTerrain(TerrainStatus terrainStatus, DirectX::XMINT2 terrainPos)
{
    //TerrainStatus::Noneの時、状態を変更しない
    if (terrainStatus != TerrainStatus::None)
    {
        if(terrainData[terrainPos.y][terrainPos.x].status != TerrainStatus::UnBreakble)
        terrainData[terrainPos.y][terrainPos.x].status = terrainStatus;
    }
    //terrainDataを初期化
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
//  指定した箇所の情報をセット
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
//  エフェクトを更新
//--------------------------------
void BG::updateEffect(TerrainEffect &effect)
{
    if (effect.exist)
    {
        effect.timer += effect.playSpeed;

        if (effect.timer > (effect.tx / effect.texSizeX))
        {
            effect.timer = 0;
            effect.animeNum++;
            if (effect.animeNum >= effect.animeMax)
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
//  初期設定
//--------------------------------
int BG::SetExplosionPoint(DirectX::XMINT2 explosionPoint, ExplosionPoint point, int delayIndex)
{
    switch (point)
    {
    case ExplosionPoint::CENTER:
    {
        int center = terrainData[explosionPoint.x][explosionPoint.y].status;
        return SetCenterPoint(center, explosionPoint, ++delayIndex);
        break;
    }
    case ExplosionPoint::LEFT:
    {
        DirectX::XMINT2 centerPos{ explosionPoint.x,explosionPoint.y + 1 };
        int center = terrainData[explosionPoint.x][explosionPoint.y + 1].status;
        int left   = terrainData[explosionPoint.x][explosionPoint.y].status;
        return SetLeftPoint(center, left, explosionPoint, centerPos, ++delayIndex);
        break;
    }
    case ExplosionPoint::TOP:
    {
        DirectX::XMINT2 centerPos{ explosionPoint.x + 1,explosionPoint.y};
        int center = terrainData[explosionPoint.x + 1][explosionPoint.y].status;
        int top    = terrainData[explosionPoint.x][explosionPoint.y].status;
        return SetTopPoint(center, top, explosionPoint, centerPos, ++delayIndex);
        break;
    }
    case ExplosionPoint::RIGHT:
    {
        DirectX::XMINT2 centerPos{ explosionPoint.x,explosionPoint.y - 1 };
        int center = terrainData[explosionPoint.x][explosionPoint.y - 1].status;
        int right  = terrainData[explosionPoint.x][explosionPoint.y].status;
        return SetRightPoint(center, right, explosionPoint, centerPos, ++delayIndex);
        break;
    }
    case ExplosionPoint::BOTTOM:
    {
        DirectX::XMINT2 centerPos{ explosionPoint.x - 1,explosionPoint.y };
        int center = terrainData[explosionPoint.x - 1][explosionPoint.y].status;
        int bottom = terrainData[explosionPoint.x][explosionPoint.y].status;
        return SetBottomPoint(center, bottom, explosionPoint, centerPos, ++delayIndex);
        break;
    }
    }
}

int BG::SetCenterPoint(int center, DirectX::XMINT2 centerPos, int delayIndex)
{
    //該当ブロックがステージの外に出ていないか
    bool isNotEdge = centerPos.x < 0 || centerPos.y < 0 || centerPos.x >= CHIP_NUM_Y || centerPos.y >= CHIP_NUM_X;

    if (isNotEdge && center == TerrainStatus::InExplosion)
    {
        return center;
    }

    //該当ブロックのデータ設定
    SetTerrainData(centerPos, delayIndex);

    return TerrainStatus::InExplosion;
}

int BG::SetLeftPoint(int center, int left, DirectX::XMINT2 leftPos, DirectX::XMINT2 centerPos, int delayIndex)
{
    //該当ブロックがステージの外に出ていないか
    bool isNotEdge = leftPos.x < 0 || leftPos.y < 0 || leftPos.x > CHIP_NUM_Y || leftPos.y > CHIP_NUM_X;

    if (isNotEdge || center == TerrainStatus::UnBreakble || left == TerrainStatus::UnBreakble || left == TerrainStatus::InExplosion)
    {
        return left;
    }

    //該当ブロックのデータ設定
    SetTerrainData(leftPos, delayIndex);

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
        SetBomb(explodePos[ExplosionPoint::LEFT], ExplosionPoint::LEFT, delayIndex);
        SetBomb(explodePos[ExplosionPoint::TOP], ExplosionPoint::TOP, delayIndex);
        SetBomb(explodePos[ExplosionPoint::BOTTOM], ExplosionPoint::BOTTOM, delayIndex);
    }
    //爆発の連鎖が起こらなかった場合
    else
    {
        finishChain(leftPos);
    }

    return TerrainStatus::InExplosion;
}

int BG::SetTopPoint(int center, int top, DirectX::XMINT2 topPos, DirectX::XMINT2 centerPos, int delayIndex)
{
    //該当ブロックがステージの外に出ていないか
    bool isNotEdge = topPos.x < 0 || topPos.y < 0 || topPos.x > CHIP_NUM_Y || topPos.y > CHIP_NUM_X;

    if (isNotEdge || center == TerrainStatus::UnBreakble || top == TerrainStatus::UnBreakble || top == TerrainStatus::InExplosion)
    {
        return top;
    }

    //該当ブロックのデータ設定
    SetTerrainData(topPos, delayIndex);

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
        SetBomb(explodePos[ExplosionPoint::LEFT], ExplosionPoint::LEFT, delayIndex);
        SetBomb(explodePos[ExplosionPoint::TOP], ExplosionPoint::TOP, delayIndex);
        SetBomb(explodePos[ExplosionPoint::RIGHT], ExplosionPoint::RIGHT, delayIndex);
    }
    //爆発の連鎖が起こらなかった場合
    else
    {
        finishChain(topPos);
    }

    return TerrainStatus::InExplosion;
}

int BG::SetRightPoint(int center, int right, DirectX::XMINT2 rightPos, DirectX::XMINT2 centerPos, int delayIndex)
{
    //該当ブロックがステージの外に出ていないか
    bool isNotEdge = rightPos.x < 0 || rightPos.y < 0 || rightPos.x >= CHIP_NUM_Y || rightPos.y >= CHIP_NUM_X;

    if (isNotEdge || center == TerrainStatus::UnBreakble || right == TerrainStatus::UnBreakble || right == TerrainStatus::InExplosion)
    {
        return right;
    }

    //該当ブロックのデータ設定
    SetTerrainData(rightPos, delayIndex);

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
        SetBomb(explodePos[ExplosionPoint::TOP], ExplosionPoint::TOP, delayIndex);
        SetBomb(explodePos[ExplosionPoint::RIGHT], ExplosionPoint::RIGHT, delayIndex);
        SetBomb(explodePos[ExplosionPoint::BOTTOM], ExplosionPoint::BOTTOM, delayIndex);
    }
    //爆発の連鎖が起こらなかった場合
    else
    {
        finishChain(rightPos);
    }

    return TerrainStatus::InExplosion;
}

int BG::SetBottomPoint(int center, int bottom, DirectX::XMINT2 bottomPos, DirectX::XMINT2 centerPos, int delayIndex)
{
    //該当ブロックがステージの外に出ていないか
    bool isNotEdge = bottomPos.x < 0 || bottomPos.y < 0 || bottomPos.x >= CHIP_NUM_Y || bottomPos.y >= CHIP_NUM_X;

    if (isNotEdge || center == TerrainStatus::UnBreakble || bottom == TerrainStatus::UnBreakble || bottom == TerrainStatus::InExplosion)
    {
        return bottom;
    }

    //該当ブロックのデータ設定
    SetTerrainData(bottomPos, delayIndex);

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
        SetBomb(explodePos[ExplosionPoint::LEFT], ExplosionPoint::LEFT, delayIndex);
        SetBomb(explodePos[ExplosionPoint::RIGHT], ExplosionPoint::RIGHT, delayIndex);
        SetBomb(explodePos[ExplosionPoint::BOTTOM], ExplosionPoint::BOTTOM, delayIndex);
    }
    //爆発の連鎖が起こらなかった場合
    else
    {
        finishChain(bottomPos);
    }

    return TerrainStatus::InExplosion;
}
