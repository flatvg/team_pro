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

//------< using >---------------------------------------------------------------
using namespace GameLib;

//------< 変数 >----------------------------------------------------------------
Game Game::instance_;

int stageNum;

//--------------------------------
//  初期化処理
//--------------------------------
void Game::init()
{
    Scene::init();	    // 基底クラスのinitを呼ぶ

    stageNum = 0;
    bg.init(stageNum);  //BGで地形データ読み込み

    isPaused = false;   // ポーズフラグの初期化
}

//--------------------------------
//  終了処理
//--------------------------------
void Game::deinit()
{
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

    // ソフトリセット
    if ((STATE(0) & PAD_SELECT) &&  // 0コンのセレクトボタンが押されている状態で
        (TRG(0) & PAD_START))       // 0コンのスタートボタンが押された瞬間
    {
        changeScene(Title::instance());   // タイトルシーンに切り替える
        return;
    }

    // ポーズ処理
    if (TRG(0) & PAD_START)
        isPaused = !isPaused;       // 0コンのスタートボタンが押されたらポーズ状態が反転
    if (isPaused) return;           // この時点でポーズ中ならリターン

    switch (state)
    {
    case 0:
        //////// 初期設定 ////////

        timer = 0;
        GameLib::setBlendMode(Blender::BS_ALPHA);   // 通常のアルファ処理

        // テクスチャの読み込み

        state++;    // 初期化処理の終了

    case 1:
        //////// 通常時の処理 ////////
        bg.update();
        timer++;

        break;
    }
}

//--------------------------------
//  描画処理
//--------------------------------
void Game::draw()
{
    // 画面クリア
    GameLib::clear(VECTOR4(0, 0, 0, 1));

    ////map
    //GameLib::primitive::rect(
    //    200.0f, 0.0f,
    //    GameLib::window::getWidth() - 200.0f, GameLib::window::getHeight(),
    //    0,
    //    1, 0, 0, 1
    //);

    //timer&score
    GameLib::primitive::rect(
        0.0f, 0.0f,
        200.0f, GameLib::window::getHeight(),
        0, 0,
        0,
        0, 1, 0, 1
    );

    //nextmino
    GameLib::primitive::rect(
        GameLib::window::getWidth() - 34.0f - 200.0f, 0.0f,
        GameLib::window::getWidth() - 34.0f - 200.0f, GameLib::window::getHeight(),
        0, 0,
        0,
        0, 0, 1, 1
    );

    //map
    bg.drawTerrain();

    // デバッグ文字列表示
    debug::setString("state:%d", state);
    debug::setString("timer:%d", timer);
}

//******************************************************************************
