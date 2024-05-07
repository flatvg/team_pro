#include "result.h"
#include "all.h"
#include "title.h"
#include "collision.h"
#include "sprite_data.h"

using namespace GameLib;

//------< �ϐ� >----------------------------------------------------------------
Result Result::instance_;
static GameLib::Sprite* title;

Result::Result()
{

}

void Result::init()
{
    Scene::init();	    // ���N���X��init���Ă�
}

void Result::deinit()
{
    // �e�}�l�[�W���̉��
}

void Result::update()
{
    using namespace input;


    // �f�o�b�O������\��
    debug::setString("state:%d", state);
    debug::setString("timer:%d", timer);

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

        // �}�E�X�����N���b�N����ƃ^�C�g����ʂɖ߂�
        if (TRG(0) & PAD_LC) {

            // �}�E�X�̃N���b�N�ʒu���擾
            float mouseX = static_cast<float>(GameLib::input::getCursorPosX());
            float mouseY = static_cast<float>(GameLib::input::getCursorPosY());

            // �N���b�N�������W������̉~�`�̓����ɂ��邩�`�F�b�N
            if (mouseX >= 200.0f - 100.0f && mouseX <= 200.0f + 100.0f &&
                mouseY >= 500.0f - 100.0f && mouseY <= 500.0f + 100.0f) {

                // �^�C�g����ʂɖ߂鏈�������s
                changeScene(Title::instance());
                return;
            }
        }

        // �}�E�X�����N���b�N����ƃZ���N�g��ʂɖ߂�
        if (TRG(0) & PAD_LC) {

            // �}�E�X�̃N���b�N�ʒu���擾
            float mouseX = static_cast<float>(GameLib::input::getCursorPosX());
            float mouseY = static_cast<float>(GameLib::input::getCursorPosY());

            // �N���b�N�������W������̉~�`�̓����ɂ��邩�`�F�b�N
            if (mouseX >= 1000.0f - 100.0f && mouseX <= 1000.0f + 100.0f &&
                mouseY >= 500.0f - 100.0f && mouseY <= 500.0f + 100.0f) {

                // �Z���N�g��ʂɖ߂鏈�������s
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
    // ��ʃN���A
    GameLib::clear(VECTOR4(0, 0, 0, 1));

    title = sprite_load(L"./Data/Images/back.png");
    sprite_render(title, 0.0f, 0.0f, 2.0f, 1.5f, 0, 0, 640, 480, ToRadian(0));

    // �^�C�g����ʂ�
    GameLib::primitive::circle(200, 500, 100, 1, 1, ToRadian(0), 1, 0, 0);
    GameLib::text_out(4, "TITLE", 100, 480, 2, 2, 1, 1, 0);

    // �Z���N�g��ʂ�
    GameLib::primitive::circle(1000, 500, 100, 1, 1, ToRadian(0), 0, 0, 1);
    GameLib::text_out(4, "SERECT", 880, 480, 2, 2, 1, 1, 0);

    // ���̃X�R�A
    GameLib::primitive::rect(420, 180, 400, 200, 0, 0, ToRadian(0), 1, 1, 1, 1);

    delete title;
}