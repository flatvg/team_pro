#include "all.h"
#include "tutorial.h"
#include "title.h"

//------< using >---------------------------------------------------------------
using namespace GameLib;

//------< 変数 >----------------------------------------------------------------
Tutorial Tutorial::instance_;

//--------------------------------
//  初期化処理
//--------------------------------
void Tutorial::init()
{
    Scene::init();

    stageNum = 0;
    T_bg.init(stageNum);
    A_timer = 1;
    isPaused = false;
}

//--------------------------------
//  終了処理
//--------------------------------
void Tutorial::deinit()
{
    // テクスチャの解放
    texture::releaseAll();

    // 音楽のクリア
    music::clear();
}

//--------------------------------
//  更新処理
//--------------------------------
void Tutorial::update()
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
            isPaused = !isPaused;       // 0コンのスタートボタンが押されたらポーズ状態が反転
        if (isPaused) return;           // この時点でポーズ中ならリターン

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
            T_bg.update();

            timer++;

            break;
        }
    }
    if (T_bg.finish_game) // finish_game
    {
        A_timer += 0.04f;
        if (A_timer > 1.0f)
        {
            changeScene(Title::instance());  // ゲームシーンに切り替え
        }
    }
}

//--------------------------------
//  描画処理
//--------------------------------
void Tutorial::draw()
{
    // 画面クリア
    GameLib::clear(VECTOR4(0, 0.5f, 0.5f, 1));

    Sprite* back_img = nullptr;

    back_img = sprite_load(BACK);
    sprite_render(back_img, 0.0f, 0.0f, 2.0f, 1.5f, 0, 0, 640, 480, ToRadian(0));

    //map
    T_bg.drawTerrain();

    GameLib::primitive::rect(
        0.0f, 0.0f,
        GameLib::window::getWidth(), GameLib::window::getHeight(),
        0, 0,
        0,
        0, 0, 0, A_timer
    );

    // デバッグ文字列表示
    debug::setString("timer:%d", timer);

    delete back_img;
}

