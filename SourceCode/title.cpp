//******************************************************************************
//
//
//      タイトル
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
#include "all.h"
#include "obj2d.h"

#include "scene.h"
#include "title.h"
#include "select.h"
#include "result.h"
#include "game.h"
#include "tutorial.h"
#include "Effect.h"
#include "collision.h"

//------< using >---------------------------------------------------------------
using namespace GameLib;
using namespace DirectX;

//------< 変数 >----------------------------------------------------------------
Title Title::instance_;

//Effect effects_fires[5];

Effect effects_bombs[5];

static GameLib::Sprite* title;

void Title::draw_init_status()
{
    //title
    title_draw.position = { 360.0f, 140.0f };
    title_draw.center = { 350.0f,90.0f };

    //game
    game_draw.position = { 885.0f, 585.0f };
    game_draw.center = { 185.0f,85.0f };

    //tutorial
    tutorial_draw.position = { 900.0f, 430.0f };
    tutorial_draw.center = { 330.0f, 85.0f };

    //scale&color
    title_draw.scale = game_draw.scale = tutorial_draw.scale = { 1,1 };
    title_draw.angle = game_draw.angle = tutorial_draw.angle = 0;
    title_draw.color = game_draw.color = tutorial_draw.color = { 1,1,1,1 };

    //flag
    isGame = false;
    isTutorial = false;
}

void Title::init()
{
    draw_init_status();
    A_timer = 0.0f;
    texture::load(1, L"./Data/Images/title.png", 256U);    //タイトル
    texture::load(2, L"./Data/Images/game.png", 256U);    //ゲーム
    texture::load(3, L"./Data/Images/tutorial.png", 256U);    //ﾁｭｰﾄﾘｱﾙ
}

void Title::deinit()
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
void Title::update()
{
    using namespace input;

    cursorPos = { static_cast<float>(GameLib::input::getCursorPosX()), static_cast<float>(GameLib::input::getCursorPosY()) };

    switch (state)
    {
    case 0:
        //////// 初期設定 ////////

        timer = 0;                                  // タイマーを初期化
        GameLib::setBlendMode(Blender::BS_ALPHA);   // 通常のアルファ処理
        state++;                                    // 初期化処理の終了

        /*fallthrough*/                             // 意図的にbreak;を記述していない

    case 1:
        //////// 通常時の処理 ////////

        timer++;                            // タイマーを足す

        game_draw.scale = tutorial_draw.scale = { 1,1 };
        //選択するとデカくなる
        //game
        if (collision_center(cursorPos, game_draw.position, game_draw.center))
        {
            game_draw.scale = { 1.3f,1.3f };

            if (TRG(0) & PAD_LC && !isTutorial)
            {
                A_timer += 0.1f;
                isGame = true;
            }
        }
        //tutorial
        else if (collision_center(cursorPos, tutorial_draw.position, tutorial_draw.center))
        {
            tutorial_draw.scale = { 1.2f,1.2f };
            if (TRG(0) & PAD_LC && !isGame)
            {
                A_timer += 0.1f;
                isTutorial = true;
            }
        }
        if (A_timer > 0.0f)
        {
            A_timer += 0.01f;
            if (A_timer > 1.0f)
            {
                // ゲームシーンに切り替え
                if (isGame)
                {
                    changeScene(Select::instance());
                }
                else if(isTutorial)
                {
                    changeScene(Result::instance());
                }
            }
        }


        //タイトル拡縮
        float timer_float = static_cast<float>(timer);
        if (timer % 60 >= 30)
        {
            title_timer += 0.005f;
            title_draw.scale = { 1.0f + title_timer,1.0f + title_timer };
        }
        if (timer % 60 < 31)
        {
            title_timer -= 0.005f;
            title_draw.scale = { 1.0f + title_timer,1.0f + title_timer };
        }

        //エフェクトの生成
        if (TRG(0) & PAD_RC) {
            for (auto& effect : effects_bombs) {
                if(!effect.exist)
                {
                    effect.exist = true;
                    //effect.pos = cursorPos;
                    effect.pos = VECTOR2(300.0f,300.0f);
                    break;
                }
            }
            angleflag = true;
        }
        //エフェクトの更新
        for (auto& effect : effects_bombs) {
            if (effect.exist)
            {
                XMVECTOR p = XMVectorSet(effect.pos.x, effect.pos.y, 0, 0);
                DirectX::XMVECTOR V2 = DirectX::XMVectorSet(
                    cursorPos.x + correctPos.x + circlePos.x,
                    cursorPos.y + correctPos.y + circlePos.y,
                    0,
                    0);
                float weight = 0.029f;
                DirectX::XMFLOAT2 pos;
                XMStoreFloat2(&pos, XMVectorLerp(p, V2, weight));
                effect.pos = VECTOR2(pos.x, pos.y);
            }
        }

        if (TRG(0) & PAD_START)             // PAD_TRG1が押されたら
            changeScene(Select::instance());  // ゲームシーンに切り替え

        circlePos = {
            0.0f + sinf(angle) * 100.0f,
            0.0f + cosf(angle) * 100.0f
        };

        if(angleflag)
        angle -= XMConvertToRadians(2);

        break;
    }
}

//--------------------------------
//  描画処理
//--------------------------------
void Title::draw()
{
    // 画面クリア
    GameLib::clear(VECTOR4(0.2f, 0.3f, 1.0f, 1));

    //背景画面表示
    title = sprite_load(BACK);
    sprite_render(title, 0.0f, 0.0f, 2.0f, 1.5f, 0, 0, 640, 480, ToRadian(0));

    // タイトル表示
    texture::begin(1);
    texture::draw(
        1,
        static_cast<float>(title_draw.position.x), static_cast<float>(title_draw.position.y),
        static_cast<float>(title_draw.scale.x), static_cast<float>(title_draw.scale.y),
        0.0f, 0.0f,
        1000.0f, 1000.0f,
        static_cast<float>(title_draw.center.x), static_cast<float>(title_draw.center.y),
        title_draw.angle,
        static_cast<float>(title_draw.color.w), static_cast<float>(title_draw.color.x), static_cast<float>(title_draw.color.y), static_cast<float>(title_draw.color.z)
    );
    texture::end(1);

    //ゲーム
    texture::begin(2);
    texture::draw(
        2,
        static_cast<float>(game_draw.position.x), static_cast<float>(game_draw.position.y),
        static_cast<float>(game_draw.scale.x), static_cast<float>(game_draw.scale.y),
        0.0f, 0.0f,
        1000.0f, 1000.0f,
        static_cast<float>(game_draw.center.x), static_cast<float>(game_draw.center.y),
        game_draw.angle,
        static_cast<float>(game_draw.color.w), static_cast<float>(game_draw.color.x), static_cast<float>(game_draw.color.y), static_cast<float>(game_draw.color.z)
    );
    texture::end(2);

    //ﾁｭｰﾄﾘｱﾙ
    texture::begin(3);
    texture::draw(
        3,
        static_cast<float>(tutorial_draw.position.x), static_cast<float>(tutorial_draw.position.y),
        static_cast<float>(tutorial_draw.scale.x), static_cast<float>(tutorial_draw.scale.y),
        0.0f, 0.0f,
        1000.0f, 1000.0f,
        static_cast<float>(tutorial_draw.center.x), static_cast<float>(tutorial_draw.center.y),
        tutorial_draw.angle,
        static_cast<float>(tutorial_draw.color.w), static_cast<float>(tutorial_draw.color.x), static_cast<float>(tutorial_draw.color.y), static_cast<float>(tutorial_draw.color.z)
    );
    texture::end(3);

    GameLib::primitive::rect(
        0.0f, 0.0f,
        GameLib::window::getWidth(), GameLib::window::getHeight(),
        0, 0,
        0,
        0, 0, 0, A_timer
    );

    GameLib::primitive::circle(
        circlePos,
        25,
        VECTOR2(1, 1),
        0,
        VECTOR4(0, 1, 0, 1)
    );

    //static GameLib::Sprite* fire_image = nullptr;
    static GameLib::Sprite* bomb_image = nullptr;
    //fire_image = sprite_load(FIRE03);
    bomb_image = sprite_load(BOMB01);
    for (auto& effect : effects_bombs) {
        if (effect.exist) {
            effect.effectBomb(bomb_image, 3, DirectX::XMFLOAT2(2.5f,2.5f));
        }
    }
    //delete fire_image;
    delete bomb_image;
    delete title;
}

//******************************************************************************
