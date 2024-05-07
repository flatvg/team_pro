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
#include "result.h"

//------< using >---------------------------------------------------------------
using namespace GameLib;

//------< �ϐ� >----------------------------------------------------------------
Game Game::instance_;

Effect effects_fire[5];
Effect effects_bomb[5];

//timer&score
static GameLib::Sprite* kanban = nullptr;

// nextmino
static GameLib::Sprite* box = nullptr;

// �Q�[���w�i
static GameLib::Sprite* back = nullptr;

int stageNum;

//--------------------------------
//  ����������
//--------------------------------
void Game::init()
{
    Scene::init();	    // ���N���X��init���Ă�

    stageNum = 0;
    bg.init(stageNum);  //BG�Œn�`�f�[�^�ǂݍ���
    A_timer = 1;
    isPaused = false;   // �|�[�Y�t���O�̏�����
}

//--------------------------------
//  �I������
//--------------------------------
void Game::deinit()
{
    for (int i = 0; i < 3; ++i)
    {
        bg.bomb_changepos[i] = bg.bomb_defpos[i];//�ʒu�������ʒu�ɖ߂�
    }
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
        {
            isPaused = !isPaused;       // 0�R���̃X�^�[�g�{�^���������ꂽ��|�[�Y��Ԃ����]
            music::pause();
        }

        if (isPaused) return;           // ���̎��_�Ń|�[�Y���Ȃ烊�^�[��

        if (!isPaused)
        {
            music::resume(0);
        }

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
            bg.update();
            //�G�t�F�N�g�̐���
            //if (TRG(0) & PAD_TRG1) {
            //    for (auto& effect : effects_fire) {
            //        if (!effect.exist) {
            //            effect.exist = true;
            //            effect.pos = { 300.0f, 200.0f };
            //            break;
            //        }
            //    }
            //}
            //if (TRG(0) & PAD_TRG4) {
            //    for (auto& effect : effects_bomb) {
            //        if (!effect.exist) {
            //            effect.exist = true;
            //            effect.pos = { 700.0f, 200.0f };
            //            break;
            //        }
            //    }
            //}
            timer++;

            break;
        }
    }
    if (bg.finish_game) // finish_game
    {
        A_timer += 0.04f;
        if (A_timer > 1.0f)
        {
            changeScene(Result::instance());  // �Q�[���V�[���ɐ؂�ւ�
        }
    }
}

//--------------------------------
//  �`�揈��
//--------------------------------
void Game::draw()
{
    // ��ʃN���A
    GameLib::clear(VECTOR4(0, 0, 0, 1));

    // �Q�[���w�i
    float txsX1 = 850;
    float txsY = 720;
    back = sprite_load(L"./Data/Images/back.png");
    sprite_render(back, 200.0f, 0.0f, txsX1 / 640, txsY / 480, 0, 0, 640, 480, ToRadian(0));

    //timer&score
    float txsX2 = 200;
    kanban = sprite_load(L"./Data/Images/kanban.png");
    sprite_render(kanban, 0, 0, txsX2 / 310, txsY / 1551, 0, 0, 310, 1551, ToRadian(0));

    //nextmino
    float txsX3 = 230;
    box = sprite_load(L"./Data/Images/box.png");
    sprite_render(box, GameLib::window::getWidth() - 34.0f - 200.0f, 0.0f,
        txsX3 / 600, txsY / 800, 0, 0, 600, 800, ToRadian(0));

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

    GameLib::primitive::rect(
        0.0f, 0.0f,
        GameLib::window::getWidth(), GameLib::window::getHeight(),
        0, 0,
        0,
        0, 0, 0, A_timer
    );

    // �f�o�b�O������\��
    debug::setString("state:%d", state);
    debug::setString("timer:%d", timer);

    delete kanban;
    delete box;
    delete back;
}

//******************************************************************************
