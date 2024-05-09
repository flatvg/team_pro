#include "all.h"
#include "select.h"
#include "game.h"
#include "audio.h"

using namespace DirectX;
using namespace GameLib;

Select Select::instance_;

extern int stageNum;

Sprite* back_img = nullptr;
Sprite* stage1_img = nullptr;
Sprite* stage2_img = nullptr;
Sprite* stage3_img = nullptr;

void Select::init()
{
    Scene::init();

    timer = 0;

    int index = 0;

    for (auto& stage : stages)
    {
        stage = setRectData(
            VECTOR2(25.0f + index++ * 425.0f, 250.0f),
            VECTOR2(1280.0f, 720.0f),
            VECTOR4(1, 1, 1, 1),
            VECTOR2(0.3f,0.3f)
        );
    }
}

void Select::deinit()
{
}

void Select::update()
{
    using namespace input;

    //カーソルの位置を取得
    cursorPos = { static_cast<float>(GameLib::input::getCursorPosX()), static_cast<float>(GameLib::input::getCursorPosY()) };

    int stageNumber = 0;
    for (auto& stage : stages)
    {
        if (isClickRect(cursorPos, stage))
        {
            stageNum = stageNumber;
            Game::instance()->SetStageNum(stageNum);
            changeScene(Game::instance());  // ゲームシーンに切り替え
        }
        stageNumber++;
    }

    if (TRG(0) & PAD_LC) {

        // マウスのクリック位置を取得
        float mouseX = static_cast<float>(GameLib::input::getCursorPosX());
        float mouseY = static_cast<float>(GameLib::input::getCursorPosY());

        Effect::addEffect(&effect_click, 100, { mouseX - 62,mouseY - 62 });
        sound::play(XWB_SOUNDS, BAKUHATU);
    }

    timer++;
}

void Select::draw()
{
    // 画面クリア
    GameLib::clear(VECTOR4(0, 0, 0, 1));

    back_img = sprite_load(BACK);
    sprite_render(back_img, 0.0f, 0.0f, 2.0f, 1.5f, 0, 0, 640, 480, ToRadian(0));

    stage1_img = sprite_load(STAGE1);
    stage2_img = sprite_load(STAGE2);
    stage3_img = sprite_load(STAGE3);
    sprite_render(
        stage1_img,
        stages[0].position.x, stages[0].position.y,
        stages[0].scale.x, stages[0].scale.y,
        0, 0,
        stages[0].size.x, stages[0].size.y,
        ToRadian(0)
    );
    sprite_render(
        stage2_img,
        stages[1].position.x, stages[1].position.y,
        stages[1].scale.x, stages[1].scale.y,
        0, 0,
        stages[1].size.x, stages[1].size.y,
        ToRadian(0)
    );
    sprite_render(
        stage3_img,
        stages[2].position.x, stages[2].position.y,
        stages[2].scale.x, stages[2].scale.y,
        0, 0,
        stages[2].size.x, stages[2].size.y,
        ToRadian(0)
    );

    static GameLib::Sprite* Click = nullptr;
    effect_click.isLoop = false;
    Click = sprite_load(CLICKEXPLODE);

    if (effect_click.exist)
    {
        effect_click.effectBakuhatu(Click, 6);
    }

    static GameLib::Sprite* cursor = nullptr;
    cursor = sprite_load(CURSOR);
    sprite_render(
        cursor,
        cursorPos.x, cursorPos.y,
        0.4f, 0.4f,
        0, 0,
        64, 64,
        32, 32,
        0);

    delete Click;
    delete cursor;
    delete stage1_img;
    delete back_img;
}

RectData Select::setRectData(VECTOR2 pos, VECTOR2 size, VECTOR4 color, VECTOR2 scale)
{
    RectData rectData;

    rectData.position = pos;
    rectData.size = size;
    rectData.color = color;
    rectData.center = VECTOR2(pos.x + size.x * 0.5f, pos.y + size.y * 0.5f);
    rectData.scale = scale;
    rectData.rect = makeRect(rectData.position, VECTOR2(rectData.size.x * rectData.scale.x, rectData.size.y * rectData.scale.y));

    return rectData;
}

bool Select::isClickRect(VECTOR2 cursorPos, RectData rectData)
{
    //カーソルが四角形の内部にあるか確認
    GameLib::fRECT rect = rectData.rect;

    if (cursorPos.x < rect.left)return false;
    if (cursorPos.x > rect.right)return false;
    if (cursorPos.y < rect.top)return false;
    if (cursorPos.y > rect.bottom)return false;

    //クリックされているか
    if (!(input::TRG(0) & input::PAD_LC))return false;

    return true;
}

void Select::renderRect(GameLib::fRECT rect, VECTOR4 color)
{
    GameLib::primitive::rect(
        rect.left, rect.top,
        rect.right - rect.left, rect.bottom - rect.top,
        0, 0,
        0,
        color.x, color.y, color.z, color.w);
}
