#include "result.h"
#include "all.h"
#include "title.h"
#include "select.h"
#include "collision.h"
#include "sprite_data.h"
#include "audio.h"

using namespace GameLib;

//------< �ϐ� >----------------------------------------------------------------
Result Result::instance_;
static GameLib::Sprite* title;
int act_ext;
int score_ext;
bool winlose;

Result::Result()
{

}

void Result::init()
{
    Scene::init();	    // ���N���X��init���Ă�
    texture::load(20, L"./Data/Images/num.png", 256U); //����
}

void Result::deinit()
{
    // �e�}�l�[�W���̉��
    texture::releaseAll();
}

void Result::update()
{
    using namespace input;

    cursorPos = VECTOR2(GameLib::input::getCursorPosX(), GameLib::input::getCursorPosY());

    // �f�o�b�O������\��
    debug::setString("state:%d", state);
    debug::setString("timer:%d", timer);

    // �|�[�Y����
    if (TRG(0) & PAD_START)
    {
        isPaused = !isPaused;       // 0�R���̃X�^�[�g�{�^���������ꂽ��|�[�Y��Ԃ����]
        music::pause();
    }

    if (isPaused)return;            // ���̎��_�Ń|�[�Y���Ȃ烊�^�[��

    if (!isPaused)
    {
        music::resume(0);
    }

    switch (state)
    {
    case 0:
        //////// �����ݒ� ////////

        timer = 0;
        GameLib::setBlendMode(Blender::BS_ALPHA);   // �ʏ�̃A���t�@����

        // �e�N�X�`���̓ǂݍ���
        texture::load(loadTexture);


        state++;    // �����������̏I��

    case 1:
        //////// �ʏ펞�̏��� ////////
        title_scale = { 1.0f, 1.0f };
        select_scale = { 1.0f, 1.0f };

        if (TRG(0) & PAD_LC) {

            // �}�E�X�̃N���b�N�ʒu���擾
            float mouseX = static_cast<float>(GameLib::input::getCursorPosX());
            float mouseY = static_cast<float>(GameLib::input::getCursorPosY());

            Effect::addEffect(&effect_click, 100, { mouseX - 62,mouseY - 62 });
            sound::play(XWB_SOUNDS, BAKUHATU);
        }

        float mouseX = static_cast<float>(GameLib::input::getCursorPosX());
        float mouseY = static_cast<float>(GameLib::input::getCursorPosY());
        // �N���b�N�������W������̉~�`�̓����ɂ��邩�`�F�b�N
        if (mouseX >= 200.0f - 100.0f && mouseX <= 200.0f + 100.0f &&
            mouseY >= 500.0f - 100.0f && mouseY <= 500.0f + 100.0f) {
            title_scale = { 1.5f,1.5f };
            // �}�E�X�����N���b�N����ƃ^�C�g����ʂɖ߂�
            if (TRG(0) & PAD_LC) {

                // �^�C�g����ʂɖ߂鏈�������s
                changeScene(Title::instance());
                return;
            }
        }

        // �N���b�N�������W������̉~�`�̓����ɂ��邩�`�F�b�N
        if (mouseX >= 1000.0f - 100.0f && mouseX <= 1000.0f + 100.0f &&
            mouseY >= 500.0f - 100.0f && mouseY <= 500.0f + 100.0f) {

            select_scale = { 1.5f,1.5f };
            // �}�E�X�����N���b�N����ƃZ���N�g��ʂɖ߂�
            if (TRG(0) & PAD_LC) {

                // �Z���N�g��ʂɖ߂鏈�������s
                changeScene(Title::instance());
                return;
            }
        }
        break;
    }

    timer++;
}

void Result::draw()
{
    // ��ʃN���A
    GameLib::clear(VECTOR4(0, 0, 0, 1));

    title = sprite_load(L"./Data/Images/back.png");
    sprite_render(title, 0.0f, 0.0f, 2.0f, 1.5f, 0, 0, 640, 480, ToRadian(0));

    // �^�C�g����ʂ�
    GameLib::primitive::circle(200, 500, 100, static_cast<float>(title_scale.x), static_cast<float>(title_scale.y), ToRadian(0), 1, 0, 0);
    GameLib::text_out(4, "TITLE", 100, 480, 2, 2, 1, 1, 0);

    // �Z���N�g��ʂ�
    GameLib::primitive::circle(1000, 500, 100, static_cast<float>(select_scale.x), static_cast<float>(select_scale.y), ToRadian(0), 0, 0, 1);
    GameLib::text_out(4, "SERECT", 880, 480, 2, 2, 1, 1, 0);

    // ���̃X�R�A
    //GameLib::primitive::rect(420, 180, 400, 200, 0, 0, ToRadian(0), 1, 1, 1, 1);
    GameLib::text_out(4, "SCORE:", 320, 480, 2, 2, 1, 1, 0);
    GameLib::text_out(4, "ACT:", 400, 580, 2, 2, 1, 1, 0);
    texture::begin(20);
    for (int i = 0; i < 5; ++i)
    {
        int n = 10;
        int score_re;
        int act_re;
        for (int m = 0; m < i; ++m)
        {
            n *= 10;
        }
        score_re = (score_ext % n) / (n / 10);
        if (score_re == 0)score_re = 10;
        texture::draw(
            20,
            800 - (50 * i), 440,
            0.5f, 0.5f,
            50 * ((score_re - 1) * 2), 0,
            50 * 2, 1000,
            0, 0,
            0,
            1, 1, 1, 1);
        act_re = (act_ext % n) / (n / 10);
        if (act_re == 0)act_re = 10;
        texture::draw(
            20,
            800 - (50 * i), 540,
            0.5f, 0.5f,
            50 * ((act_re - 1) * 2), 0,
            50 * 2, 1000,
            0, 0,
            0,
            1, 1, 1, 1);
    }
    texture::end(20);

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
    delete title;
}