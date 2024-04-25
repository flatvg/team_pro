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
#include "game.h"
#include "Effect.h"

//------< using >---------------------------------------------------------------
using namespace GameLib;
using namespace DirectX;

//------< 変数 >----------------------------------------------------------------
Title Title::instance_;

Effect effects_fires[5];

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

        //エフェクトの生成
        if (TRG(0) & PAD_RC) {
            for (auto& effect : effects_fires) {
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
        for (auto& effect : effects_fires) {
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

    // タイトル表示
    font::textOut(4, "ECC COMP", { 60, 60 }, { 4, 4 }, { 1, 1, 0, 1 });
    font::textOut(4, "Game Programming II", { 60, 160 }, { 2, 2 }, { 0, 1, 1, 1 });

    // "Push Start Button" 点滅
    if (timer / 40 % 2)
    {
        font::textOut(4, "Push Start Button", { 480, 540 }, { 2, 2 }, { 1, 0.5f, 0, 1 });
    }

    GameLib::primitive::circle(
        circlePos,
        25,
        VECTOR2(1, 1),
        0,
        VECTOR4(0, 1, 0, 1)
    );

    static GameLib::Sprite* fire_image = sprite_load(L"./Data/Images/fire03.png");
    for (auto& effect : effects_fires) {
        if (effect.exist) {
            effect.effectFire(fire_image, 6);
        }
    }

}

//******************************************************************************
