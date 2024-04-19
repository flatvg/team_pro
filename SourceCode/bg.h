#pragma once
#include "../GameLib/vector.h"

enum ExplosionPoint
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
    static const int EXPLOSION_CHIP_NUM = 5;

    static constexpr float WIDTH = static_cast<float>(CHIP_NUM_X * CHIP_SIZE);   // �}�b�v�̕��i�h�b�g�j
    static constexpr float HEIGHT = static_cast<float>(CHIP_NUM_Y * CHIP_SIZE);   // �}�b�v�̍����i�h�b�g�j

    //�X�e�[�W�̗]��
    DirectX::XMFLOAT2 Mapterrain_correction{ 200.0f + 32.0f ,0.0f + 32.0f };

private:
    //------< �ϐ� >------------------------------------------------------------
    int terrain[BG::CHIP_NUM_Y][BG::CHIP_NUM_X]; //

    int terrainTimer[BG::CHIP_NUM_Y][BG::CHIP_NUM_X];

    int terrainFlag[BG::CHIP_NUM_Y][BG::CHIP_NUM_X];
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

    //�����ӏ��v�Z
    DirectX::XMINT2 CalcExplosionPoint(DirectX::XMINT2 BaseExplosionPoint, ExplosionPoint point);
    DirectX::XMINT2 CalcCenterPoint(DirectX::XMINT2 BaseExplosionPoint);
    DirectX::XMINT2 CalcLeftPoint(DirectX::XMINT2 BaseExplosionPoint);
    DirectX::XMINT2 CalcTopPoint(DirectX::XMINT2 BaseExplosionPoint);
    DirectX::XMINT2 CalcRightPoint(DirectX::XMINT2 BaseExplosionPoint);
    DirectX::XMINT2 CalcBottomPoint(DirectX::XMINT2 BaseExplosionPoint);

    //����
    int SetExplosionPoint(DirectX::XMINT2 explosionPoint, ExplosionPoint point);
    int SetCenterPoint(int center, DirectX::XMINT2 centerPos);
    int SetLeftPoint(int center, int left, DirectX::XMINT2 leftPos, DirectX::XMINT2 centerPos);
    int SetTopPoint(int center, int top, DirectX::XMINT2 topPos, DirectX::XMINT2 centerPos);
    int SetRightPoint(int center, int right, DirectX::XMINT2 rightPos, DirectX::XMINT2 centerPos);
    int SetBottomPoint(int center, int bottom, DirectX::XMINT2 bottomPos, DirectX::XMINT2 centerPos);


private:

    int timer;
    int explosionTime = 60;
    DirectX::XMFLOAT2  cursorPos;
};