#include "all.h"
#include "select.h"
#include "game.h"

using namespace GameLib;

Select Select::instance_;

void Select::init()
{
    Scene::init();

    timer = 0;

    int index = 0;
    for (auto& stage : stages)
    {
        stage = setRectData(
            DirectX::XMFLOAT2(index++ * 400.0f, 0.0f),
            DirectX::XMFLOAT2(300.0f, 600.0f),
            DirectX::XMFLOAT4(0, 1, 0, 1)
        );
    }
}

void Select::deinit()
{

}

void Select::update()
{
    using namespace input;

    //�J�[�\���̈ʒu���擾
    cursorPos = { static_cast<float>(GameLib::input::getCursorPosX()), static_cast<float>(GameLib::input::getCursorPosY()) };

    int stageNum = 0;
    for (auto& stage : stages)
    {
        if (isClickRect(cursorPos, stage))
        {
            Game::instance()->SetStageNum(stageNum);
            changeScene(Game::instance());  // �Q�[���V�[���ɐ؂�ւ�
        }
        stageNum++;
    }

    timer++;
}

void Select::draw()
{
    // ��ʃN���A
    GameLib::clear(VECTOR4(0, 0, 0, 1));

    for (auto& stage : stages)
    {
        renderRect(stage.rect, stage.color);
    }
}

RectData Select::setRectData(DirectX::XMFLOAT2 pos, DirectX::XMFLOAT2 size, DirectX::XMFLOAT4 color)
{
    RectData rectData;

    rectData.position = pos;
    rectData.size = size;
    rectData.color = color;
    rectData.rect = makeRect(rectData.position, rectData.size);

    return rectData;
}

bool Select::isClickRect(DirectX::XMFLOAT2 cursorPos, RectData rectData)
{
    //�J�[�\�����l�p�`�̓����ɂ��邩�m�F
    GameLib::fRECT rect = rectData.rect;

    if (cursorPos.x < rect.left)return false;
    if (cursorPos.x > rect.right)return false;
    if (cursorPos.y < rect.top)return false;
    if (cursorPos.y > rect.bottom)return false;

    //�N���b�N����Ă��邩
    if (!(input::TRG(0) & input::PAD_LC))return false;

    return true;
}

void Select::renderRect(GameLib::fRECT rect, DirectX::XMFLOAT4 color)
{
    GameLib::primitive::rect(
        rect.left, rect.top,
        rect.right - rect.left, rect.bottom - rect.top,
        0, 0,
        0,
        color.x, color.y, color.z, color.w);
}
