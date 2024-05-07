#include "result.h"
#include "all.h"
#include "title.h"
#include "collision.h"
#include "sprite_data.h"

using namespace GameLib;

//------< 変数 >----------------------------------------------------------------
Result Result::instance_;
static GameLib::Sprite* title;

Result::Result()
{

}

void Result::init()
{
    Scene::init();	    // 基底クラスのinitを呼ぶ
}

void Result::deinit()
{
    // 各マネージャの解放
}

void Result::update()
{
    using namespace input;


    // デバッグ文字列表示
    debug::setString("state:%d", state);
    debug::setString("timer:%d", timer);

    switch (state)
    {
    case 0:
        //////// 初期設定 ////////

        timer = 0;
        GameLib::setBlendMode(Blender::BS_ALPHA);   // 通常のアルファ処理

        // テクスチャの読み込み
        texture::load(loadTexture);


        state++;    // 初期化処理の終了

    case 1:
        //////// 通常時の処理 ////////

        // マウスを左クリックするとタイトル画面に戻る
        if (TRG(0) & PAD_LC) {

            // マウスのクリック位置を取得
            float mouseX = static_cast<float>(GameLib::input::getCursorPosX());
            float mouseY = static_cast<float>(GameLib::input::getCursorPosY());

            // クリックした座標が特定の円形の内側にあるかチェック
            if (mouseX >= 200.0f - 100.0f && mouseX <= 200.0f + 100.0f &&
                mouseY >= 500.0f - 100.0f && mouseY <= 500.0f + 100.0f) {

                // タイトル画面に戻る処理を実行
                changeScene(Title::instance());
                return;
            }
        }

        // マウスを左クリックするとセレクト画面に戻る
        if (TRG(0) & PAD_LC) {

            // マウスのクリック位置を取得
            float mouseX = static_cast<float>(GameLib::input::getCursorPosX());
            float mouseY = static_cast<float>(GameLib::input::getCursorPosY());

            // クリックした座標が特定の円形の内側にあるかチェック
            if (mouseX >= 1000.0f - 100.0f && mouseX <= 1000.0f + 100.0f &&
                mouseY >= 500.0f - 100.0f && mouseY <= 500.0f + 100.0f) {

                // セレクト画面に戻る処理を実行
                //changeScene(Title::instance());
                return;
            }
        }


        break;
    }

    timer++;
    draw();
}

void Result::draw()
{
    // 画面クリア
    GameLib::clear(VECTOR4(0, 0, 0, 1));

    title = sprite_load(L"./Data/Images/back.png");
    sprite_render(title, 0.0f, 0.0f, 2.0f, 1.5f, 0, 0, 640, 480, ToRadian(0));

    // タイトル画面へ
    GameLib::primitive::circle(200, 500, 100, 1, 1, ToRadian(0), 1, 0, 0);
    GameLib::text_out(4, "TITLE", 100, 480, 2, 2, 1, 1, 0);

    // セレクト画面へ
    GameLib::primitive::circle(1000, 500, 100, 1, 1, ToRadian(0), 0, 0, 1);
    GameLib::text_out(4, "SERECT", 880, 480, 2, 2, 1, 1, 0);

    // 仮のスコア
    GameLib::primitive::rect(420, 180, 400, 200, 0, 0, ToRadian(0), 1, 1, 1, 1);

    delete title;
}