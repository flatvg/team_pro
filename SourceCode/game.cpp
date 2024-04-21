//******************************************************************************
//
//
//      �Q�[��
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include "all.h"

#include "obj2d.h"

#include "scene.h"
#include "game.h"
#include "title.h"
#include "Effect.h"

//------< using >---------------------------------------------------------------
using namespace GameLib;

//------< �ϐ� >----------------------------------------------------------------
Game Game::instance_;

Effect effects_fire[5];
Effect effects_bomb[5];

int stageNum;

//--------------------------------
//  ����������
//--------------------------------
void Game::init()
{
    Scene::init();	    // ���N���X��init���Ă�

    stageNum = 0;
    bg.init(stageNum);  //BG�Œn�`�f�[�^�ǂݍ���

    isPaused = false;   // �|�[�Y�t���O�̏�����
}

//--------------------------------
//  �I������
//--------------------------------
void Game::deinit()
{
    // �e�}�l�[�W���̉��

    // �e�N�X�`���̉��
    texture::releaseAll();

    // ���y�̃N���A
    music::clear();
}

//--------------------------------
//  �X�V����
//--------------------------------
void Game::update()
{
    using namespace input;

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
        GameLib::setBlendMode(Blender::BS_ALPHA);   // �ʏ�̃A���t�@����

        // �e�N�X�`���̓ǂݍ���

        state++;    // �����������̏I��

    case 1:
        //////// �ʏ펞�̏��� ////////
        bg.update();

        //�G�t�F�N�g�̐���
        if (TRG(0) & PAD_TRG1) {
            for (auto& effect : effects_fire) {
                if (!effect.exist) {
                    effect.exist = true;
                    effect.pos = { 300.0f, 200.0f };
                    break;
                }
            }
        }
        if (TRG(0) & PAD_TRG4) {
            for (auto& effect : effects_bomb) {
                if (!effect.exist) {
                    effect.exist = true;
                    effect.pos = { 700.0f, 200.0f };
                    break;
                }
            }
        }

        timer++;

        break;
    }
}

//--------------------------------
//  �`�揈��
//--------------------------------
void Game::draw()
{
    // ��ʃN���A
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

    //�G�t�F�N�g
    static GameLib::Sprite* fire_img = sprite_load(L"./Data/Images/fire03.png");
    static GameLib::Sprite* bomb_img = sprite_load(L"./Data/Images/bomb01.png");

    for (auto& effect : effects_fire) {
        if (effect.exist) {
            effect.effectFire(fire_img, 6);
        }
    }
    for (auto& effect : effects_bomb) {
        if (effect.exist) {
            effect.effectBomb(bomb_img, 3);
        }
    }

    // �f�o�b�O������\��
    debug::setString("state:%d", state);
    debug::setString("timer:%d", timer);
}

//******************************************************************************
