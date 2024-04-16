#pragma once
#include "../GameLib/vector.h"

class BG
{
public:
    //------< �萔 >------------------------------------------------------------
    static const int CHIP_NUM_X = 12;       // �}�b�v�̉������̃`�b�v��
    static const int CHIP_NUM_Y = 10;       // �}�b�v�̏c�����̃`�b�v��
    static const int CHIP_SIZE = 64;       // %���Z�q���g�p���邽��int�^���g�p����
    static const int CHIP_NUM_PER_LINE = 8;        // �}�b�v�`�b�v��1��8��

    static constexpr float WIDTH = static_cast<float>(CHIP_NUM_X * CHIP_SIZE);   // �}�b�v�̕��i�h�b�g�j
    static constexpr float HEIGHT = static_cast<float>(CHIP_NUM_Y * CHIP_SIZE);   // �}�b�v�̍����i�h�b�g�j
    static constexpr float SCROLL_MERGIN_X = 240.0f;   // ���̐��l����ʒ[�ɋ߂Â�����X�N���[������i���j
    static constexpr float SCROLL_MERGIN_Y = 160.0f;   // ���̐��l����ʒ[�ɋ߂Â�����X�N���[������i�c�j

private:
    //------< �ϐ� >------------------------------------------------------------
    int terrain[BG::CHIP_NUM_X][BG::CHIP_NUM_Y]; //[X][Y]

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

private:
    DirectX::XMFLOAT2  cursorPos;
};