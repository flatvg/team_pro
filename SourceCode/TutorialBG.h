#pragma once
#include <memory>
#include "../GameLib/vector.h"
#include "Effect.h"
#include "focus.h"

class TutorialBG
{
public:
    //enum class�o�Ȃ����̂�int�^�Ƃ��Ă��g�������̂�enum class���g��Ȃ�
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
        UnBreakble = -1,
        Normal,
        Bomb,
        InExplosion,
        BurningFuse,
        None
    };

    enum PatternStatus
    {
        IsNotBomb,
        IsBomb
    };

    enum TexNo
    {
        Tile01,
        Tile02,
        Bomb01,
        Explosion
    };

    enum class MoveType
    {
        StartToInGame,
        InGameToEnd
    };
public:
    //------< �萔 >------------------------------------------------------------
    static const int STAGE_NUM = 4;         // �X�e�[�W��
    static const int CHIP_NUM_X = 14;       // �}�b�v�̉������̃`�b�v��
    static const int CHIP_NUM_Y = 12;       // �}�b�v�̏c�����̃`�b�v��
    static const int CHIP_SIZE = 64;        // %���Z�q���g�p���邽��int�^���g�p����
    DirectX::XMFLOAT2 chip_size_xmfloat2 = { CHIP_SIZE * 0.5 ,CHIP_SIZE * 0.5 };
    static const int EXPLOSION_CHIP_NUM = 5;
    static const int BOMB_NUM = 3;
    static const int BOMB_ROTATE_MAX = 3;
    static const int BOMB_TYPE_MAX = 3;

    static constexpr float CHIP_SIZE_F = 64.0f;
    static constexpr float WIDTH = static_cast<float>(CHIP_NUM_X * CHIP_SIZE);   // �}�b�v�̕��i�h�b�g�j
    static constexpr float HEIGHT = static_cast<float>(CHIP_NUM_Y * CHIP_SIZE);   // �}�b�v�̍����i�h�b�g�j

    //�X�e�[�W�̗]��
    DirectX::XMFLOAT2 Mapterrain_correction{ 200.0f + 32.0f - 64.0f ,0.0f + 32.0f - 64.0f };
    //�o�N�_�������ʒu
    DirectX::XMFLOAT2 bomb_defpos[BOMB_NUM] =
    {
        {1096.0f,CHIP_SIZE_F + CHIP_SIZE * 0 + 10.0f},
        {1096.0f,CHIP_SIZE_F + CHIP_SIZE * 3 + 20.0f},
        {1096.0f,CHIP_SIZE_F + CHIP_SIZE * 6 + 30.0f},
    };
    DirectX::XMFLOAT2 bomb_changepos[BOMB_NUM] =
    {
        bomb_defpos[0],
        bomb_defpos[1],
        bomb_defpos[2],
    };

private:
    //------< �ϐ� >------------------------------------------------------------
    struct TerrainData
    {
        DirectX::XMFLOAT2 startPos;    //��ʉ��̈ʒu
        DirectX::XMFLOAT2 inGamePos;   //��ʒ����̈ʒu
        DirectX::XMFLOAT2 endPos;      //��ʏ�̈ʒu
        DirectX::XMFLOAT2 pos;         //���݂̈ʒu
        int status;                    //���
        int explosionTimer;            //���j����
        bool isAlredyChanged;          //���łɏ�񂪕ύX����Ă��邩
        bool isChained;                //���j���A���ɂ���Ĉ����N�����ꂽ���ۂ�
        bool isPutOn;                  //���̃u���b�N���o�N�_�����������Ԃ��ۂ�
        int DelayTimer;                //�����̘A�������炷����
        int terrain_endurance;         //�}�b�v�^�C���̑ϋv�l
        int terrain_enduranceC;        //�}�b�v�^�C���̑ϋv�l�̃`�F�b�N�p
    };
    //1�}�X�������
    TerrainData terrainData[TutorialBG::STAGE_NUM][TutorialBG::CHIP_NUM_Y][TutorialBG::CHIP_NUM_X];

    //�G�t�F�N�g�̏��
    struct TerrainEffect
    {
        DirectX::XMFLOAT2 pos;
        bool exist;
        int animeMax;
        int animeNum;
        float timer;
        int tx, ty;
        float texSizeX;
        float playSpeed;
    };
    TerrainEffect TerrainExplosion[TutorialBG::STAGE_NUM][TutorialBG::CHIP_NUM_Y][TutorialBG::CHIP_NUM_X];

    TerrainEffect TerrainBomb[TutorialBG::STAGE_NUM][TutorialBG::CHIP_NUM_Y][TutorialBG::CHIP_NUM_X];


public:
    TutorialBG();
    ~TutorialBG();

    // ������
    void init(int stagenum);

    //�I����
    void deinit();

    // �X�V
    void update();

    // �`��
    void drawTerrain();

    //���e���h���b�O
    void dragBomb();

    //���e����]
    void rotateBomb();

    //���e���h���b�v
    void dropBomb();

    //���̃u���b�N�Ƀo�N�_�����ݒu�\��
    void SetIsPutOn();

    bool IsPutOn(int y, int x);

    bool SearchAdjacentTerrain(int status);

    //�X�e�[�W���ړ�
    void moveStage(int stageNum, MoveType moveType);

    //�G�t�F�N�g���X�V
    void updateEffect(TerrainEffect& effect);

    //�����ӏ��v�Z
    DirectX::XMINT2 CalcExplosionPoint(DirectX::XMINT2 BaseExplosionPoint, ExplosionPoint point);
    DirectX::XMINT2 CalcCenterPoint(DirectX::XMINT2 BaseExplosionPoint);
    DirectX::XMINT2 CalcLeftPoint(DirectX::XMINT2 BaseExplosionPoint);
    DirectX::XMINT2 CalcTopPoint(DirectX::XMINT2 BaseExplosionPoint);
    DirectX::XMINT2 CalcRightPoint(DirectX::XMINT2 BaseExplosionPoint);
    DirectX::XMINT2 CalcBottomPoint(DirectX::XMINT2 BaseExplosionPoint);

    //�����ӏ����m�肳����
    int SetExplosionPoint(DirectX::XMINT2 explosionPoint, ExplosionPoint point, int delayIndex);
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

    //�A�����I���
    void finishChain(DirectX::XMINT2 terrainPos);

    //terrain�̏�����
    void InitTerrain(TerrainStatus terrainStatus, DirectX::XMINT2 terrainPos);
    void InitTerrain(TerrainStatus terrainStatus, int x, int y);

    //terrain��position�̐ݒ�
    void SetTerrainPos(DirectX::XMINT2 terrainPos, int stageNum);

    bool finish_game;

private:

    int stageNum;
    int timer;                      //�S�̂̎���
    int explosionTime = 50;         //�������c�����鎞��
    int delayTime = 20;             //�����̘A������Ԋu
    int operatbleCursorTime = 5;    //�둀���h�����߂̑���s�\����
    DirectX::XMFLOAT2  cursorPos;   //�J�[�\���̈ʒu
    bool drag_con = false;

    //�X�R�A�֘A
    int act;
    int score;
    int score_add;
    int score_counter;

    //�{���֘A
    int bomb_typenum[BOMB_TYPE_MAX];
    int bomb_trun[BOMB_ROTATE_MAX];
    int bomb_waitingarea;
    bool bomb_notset = false;
    bool bomb_release = false;
    bool bomb_reset = false;
    bool bomb_movingtype = false;
    bool bomb_roopchecker = false;

    Effect burningFuse;

    float focusFactor;
    bool focusFlag;
    bool unFocusFlag;

    std::unique_ptr<Focus> focus;

    VECTOR2 circlePos;
    float circleAngle;

    bool moveTrg;

    int nowStage = 0;
};