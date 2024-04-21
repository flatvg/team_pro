#pragma once
#include "../GameLib/vector.h"

enum ExplosionPoint
{
    CENTER,
    LEFT,
    TOP,
    RIGHT,
    BOTTOM,
};

enum TerrainStatus
{
    UnBreakable = -1,
    Normal,
    Bomb,
    InExplosion,
};

class BG
{
public:
    //------< �萔 >------------------------------------------------------------
    static const int CHIP_NUM_X = 12;       // �}�b�v�̉������̃`�b�v��
    static const int CHIP_NUM_Y = 10;       // �}�b�v�̏c�����̃`�b�v��
    static const int CHIP_SIZE = 64;       // %���Z�q���g�p���邽��int�^���g�p����
    static const int EXPLOSION_CHIP_NUM = 5;

    static constexpr float CHIP_SIZE_F = 64.0f;
    static constexpr float WIDTH = static_cast<float>(CHIP_NUM_X * CHIP_SIZE);   // �}�b�v�̕��i�h�b�g�j
    static constexpr float HEIGHT = static_cast<float>(CHIP_NUM_Y * CHIP_SIZE);   // �}�b�v�̍����i�h�b�g�j

    //�X�e�[�W�̗]��
    DirectX::XMFLOAT2 Mapterrain_correction{ 200.0f + 32.0f ,0.0f + 32.0f };

private:
    //------< �ϐ� >------------------------------------------------------------
    int terrain[BG::CHIP_NUM_Y][BG::CHIP_NUM_X];

    struct TerrainData
    {
        int explosionTimer;     //���j����
        bool isAlredyChanged;   //���łɏ�񂪕ύX����Ă��邩
        int DelayTimer;         //�����̘A�������炷����
    };
    //1�}�X�������
    TerrainData terrainData[BG::CHIP_NUM_Y][BG::CHIP_NUM_X];

public:
    BG();
    ~BG();

    // ������
    void init(int stagenum);

    //�I����
    void deinit();

    // �X�V
    void update();

    // �`��
    void drawTerrain();

    //�����ӏ��v�Z
    DirectX::XMINT2 CalcExplosionPoint(DirectX::XMINT2 BaseExplosionPoint, ExplosionPoint point);
    DirectX::XMINT2 CalcCenterPoint(DirectX::XMINT2 BaseExplosionPoint);
    DirectX::XMINT2 CalcLeftPoint(DirectX::XMINT2 BaseExplosionPoint);
    DirectX::XMINT2 CalcTopPoint(DirectX::XMINT2 BaseExplosionPoint);
    DirectX::XMINT2 CalcRightPoint(DirectX::XMINT2 BaseExplosionPoint);
    DirectX::XMINT2 CalcBottomPoint(DirectX::XMINT2 BaseExplosionPoint);

    //�����ӏ����m�肳����
    int SetExplosionPoint(DirectX::XMINT2 explosionPoint, ExplosionPoint point , int delayIndex);
    int SetCenterPoint(int center, DirectX::XMINT2 centerPos, int delayIndex);
    int SetLeftPoint(int center, int left, DirectX::XMINT2 leftPos, DirectX::XMINT2 centerPos, int delayIndex);
    int SetTopPoint(int center, int top, DirectX::XMINT2 topPos, DirectX::XMINT2 centerPos, int delayIndex);
    int SetRightPoint(int center, int right, DirectX::XMINT2 rightPos, DirectX::XMINT2 centerPos, int delayIndex);
    int SetBottomPoint(int center, int bottom, DirectX::XMINT2 bottomPos, DirectX::XMINT2 centerPos, int delayIndex);

    //bomb�n�`�̐ݒ�
    void SetTerrainData(DirectX::XMINT2 terrainPos, int delayIndex);

    //���łɎw�肵���ӏ����ύX����Ă��邩
    bool IsAlreadyChanged(DirectX::XMINT2 terrainPos);

    //�o�N�_����ݒu
    void SetBomb(DirectX::XMINT2 terrainPos, ExplosionPoint point, int delayIndex);

private:

    int timer;                      //�S�̂̎���
    int explosionTime = 60;         //�������c�����鎞��
    int delayTime = 30;             //�����̘A������Ԋu
    int operatbleCursorTime = 5;    //�둀���h�����߂̑���s�\����
    DirectX::XMFLOAT2  cursorPos;   //�J�[�\���̈ʒu
};