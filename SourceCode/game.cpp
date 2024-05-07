//******************************************************************************
//
//
//      ゲーム
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
#include "all.h"

#include "obj2d.h"

#include "scene.h"
#include "game.h"
#include "title.h"
#include "Effect.h"
#include "result.h"

//------< using >---------------------------------------------------------------
using namespace GameLib;

//------< 変数 >----------------------------------------------------------------
Game Game::instance_;

Effect effects_fire[5];
Effect effects_bomb[5];

//timer&score
static GameLib::Sprite* kanban = nullptr;

// nextmino
static GameLib::Sprite* box = nullptr;

// ゲーム背景
static GameLib::Sprite* back = nullptr;

int stageNum;

//--------------------------------
//  初期化処理
//--------------------------------
void Game::init()
{
    Scene::init();	    // 基底クラスのinitを呼ぶ

    stageNum = 0;
    bg.init(stageNum);  //BGで地形データ読み込み
    A_timer = 1;
    isPaused = false;   // ポーズフラグの初期化
}

//--------------------------------
//  終了処理
//--------------------------------
void Game::deinit()
{
    for (int i = 0; i < 3; ++i)
    {
        bg.bomb_changepos[i] = bg.bomb_defpos[i];//位置を初期位置に戻す
    }
    // 各マネージャの解放

    // テクスチャの解放
    texture::releaseAll();

    // 音楽のクリア
    music::clear();
}

//--------------------------------
//  更新処理
//--------------------------------
void Game::update()
{
    using namespace input;
    if (A_timer > 0)A_timer -= 0.02f;
    if (A_timer <= 0)
    {

        // ソフトリセット
        if ((STATE(0) & PAD_SELECT) &&  // 0コンのセレクトボタンが押されている状態で
            (TRG(0) & PAD_START))       // 0コンのスタートボタンが押された瞬間
        {
            changeScene(Title::instance());   // タイトルシーンに切り替える
            return;
        }

        // ポーズ処理
        if (TRG(0) & PAD_START)
        {
            isPaused = !isPaused;       // 0コンのスタートボタンが押されたらポーズ状態が反転
            music::pause();
        }

        if (isPaused) return;           // この時点でポーズ中ならリターン

        if (!isPaused)
        {
            music::resume(0);
        }

        switch (state)
        {
        case 0:
            //////// 初期設定 ////////

            timer = 0;
            A_timer = 0;
            GameLib::setBlendMode(Blender::BS_ALPHA);   // 通常のアルファ処理

            state++;    // 初期化処理の終了

        case 1:
            //////// 通常時の処理 ////////
            bg.update();
            //エフェクトの生成
            //if (TRG(0) & PAD_TRG1) {
            //    for (auto& effect : effects_fire) {
            //        if (!effect.exist) {
            //            effect.exist = true;
            //            effect.pos = { 300.0f, 200.0f };
            //            break;
            //        }
            //    }
            //}
            //if (TRG(0) & PAD_TRG4) {
            //    for (auto& effect : effects_bomb) {
            //        if (!effect.exist) {
            //            effect.exist = true;
            //            effect.pos = { 700.0f, 200.0f };
            //            break;
            //        }
            //    }
            //}
            timer++;

            break;
        }
    }
    if (bg.finish_game) // finish_game
    {
        A_timer += 0.04f;
        if (A_timer > 1.0f)
        {
            changeScene(Result::instance());  // ゲームシーンに切り替え
        }
    }
}

//--------------------------------
//  描画処理
//--------------------------------
void Game::draw()
{
    // 画面クリア
    GameLib::clear(VECTOR4(0, 0, 0, 1));

    // ゲーム背景
    float txsX1 = 850;
    float txsY = 720;
    back = sprite_load(L"./Data/Images/back.png");
    sprite_render(back, 200.0f, 0.0f, txsX1 / 640, txsY / 480, 0, 0, 640, 480, ToRadian(0));

    //timer&score
    float txsX2 = 200;
    kanban = sprite_load(L"./Data/Images/kanban.png");
    sprite_render(kanban, 0, 0, txsX2 / 310, txsY / 1551, 0, 0, 310, 1551, ToRadian(0));

    //nextmino
    float txsX3 = 230;
    box = sprite_load(L"./Data/Images/box.png");
    sprite_render(box, GameLib::window::getWidth() - 34.0f - 200.0f, 0.0f,
        txsX3 / 600, txsY / 800, 0, 0, 600, 800, ToRadian(0));

    //map
    bg.drawTerrain();

    //エフェクト
    static GameLib::Sprite* fire_img = sprite_load(L"./Data/Images/fire03.png");
    static GameLib::Sprite* bomb_img = sprite_load(L"./Data/Images/bomb01.png");

    for (auto& effect : effects_fire) {
        if (effect.exist) {
            effect.effectFire(fire_img, 6);
        }
    }
    for (auto& effect : effects_bomb) {
        if (effect.exist) {
            effect.effectBomb(bomb_img, 3);
        }
    }

    GameLib::primitive::rect(
        0.0f, 0.0f,
        GameLib::window::getWidth(), GameLib::window::getHeight(),
        0, 0,
        0,
        0, 0, 0, A_timer
    );

    // デバッグ文字列表示
    debug::setString("state:%d", state);
    debug::setString("timer:%d", timer);

    delete kanban;
    delete box;
    delete back;
}

//******************************************************************************
