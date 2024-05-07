#include "all.h"
#include "tutorial.h"
#include "title.h"

//------< using >---------------------------------------------------------------
using namespace GameLib;

//------< �ϐ� >----------------------------------------------------------------
Tutorial Tutorial::instance_;

//--------------------------------
//  ����������
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
//  �I������
//--------------------------------
void Tutorial::deinit()
{
    // �e�N�X�`���̉��
    texture::releaseAll();

    // ���y�̃N���A
    music::clear();
}

//--------------------------------
//  �X�V����
//--------------------------------
void Tutorial::update()
{
    using namespace input;
    if (A_timer > 0)A_timer -= 0.02f;
    if (A_timer <= 0)
    {
        // �\�t�g���Z�b�g
        if ((STATE(0) & PAD_SELECT) &&  // 0�R���̃Z���N�g�{�^����������Ă����Ԃ�
            (TRG(0) & PAD_START))       // 0�R���̃X�^�[�g�{�^���������ꂽ�u��
        {
            changeScene(Title::instance());   // �^�C�g���V�[���ɐ؂�ւ���
            return;
        }

        // �|�[�Y����
        if (TRG(0) & PAD_START)
            isPaused = !isPaused;       // 0�R���̃X�^�[�g�{�^���������ꂽ��|�[�Y��Ԃ����]
        if (isPaused) return;           // ���̎��_�Ń|�[�Y���Ȃ烊�^�[��

        switch (state)
        {
        case 0:
            //////// �����ݒ� ////////

            timer = 0;
            A_timer = 0;
            GameLib::setBlendMode(Blender::BS_ALPHA);   // �ʏ�̃A���t�@����

            state++;    // �����������̏I��

        case 1:
            //////// �ʏ펞�̏��� ////////
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
            changeScene(Title::instance());  // �Q�[���V�[���ɐ؂�ւ�
        }
    }
}

//--------------------------------
//  �`�揈��
//--------------------------------
void Tutorial::draw()
{
    // ��ʃN���A
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

    // �f�o�b�O������\��
    debug::setString("timer:%d", timer);

    delete back_img;
}

