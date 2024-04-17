#pragma once
#include "../GameLib/vector.h"

enum class ExplosionPoint
{
    CENTER,
    LEFT,
    TOP,
    RIGHT,
    BOTTOM
};

class BG
{
public:
    //------< �萔 >------------------------------------------------------------
    static const int CHIP_NUM_X = 12;       // �}�b�v�̉������̃`�b�v��
    static const int CHIP_NUM_Y = 10;       // �}�b�v�̏c�����̃`�b�v��
    static const int CHIP_SIZE = 64;       // %���Z�q���g�p���邽��int�^���g�p����

    static constexpr float WIDTH = static_cast<float>(CHIP_NUM_X * CHIP_SIZE);   // �}�b�v�̕��i�h�b�g�j
    static constexpr float HEIGHT = static_cast<float>(CHIP_NUM_Y * CHIP_SIZE);   // �}�b�v�̍����i�h�b�g�j

    //�X�e�[�W�̗]��
    DirectX::XMFLOAT2 Mapterrain_correction{ 200.0f + 32.0f ,0.0f + 32.0f };

private:
    //------< �ϐ� >------------------------------------------------------------
    int terrain[BG::CHIP_NUM_Y][BG::CHIP_NUM_X]; //

public:
    BG();
    ~BG();

    // ������
    void init(int stagenum);

    void deinit();

    // �X�V
    void update();

    // �`��
    void drawTerrain();                                     // �n�`�`��

    //�����ӏ��ڒn
    DirectX::XMFLOAT2 SetExplosionPoint(DirectX::XMFLOAT2 BaseExplosionPoint, ExplosionPoint point);

private:

    int timer;
    DirectX::XMFLOAT2  cursorPos;
};