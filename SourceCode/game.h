#ifndef INCLUDED_GAME
#define	INCLUDED_GAME

//******************************************************************************
//
//
//      �Q�[���V�[��
//
//
//******************************************************************************

//==============================================================================
//
//      Game�N���X
//
//==============================================================================

#include "bg.h"

class Game : public Scene
{
public:
    // �N���X���ł̒萔�̒�`�̎d��
    // int�^�ł����const�ŗǂ����A����ȊO��constexpr���g�p����
    static constexpr float GROUND_POS_Y = 640.0f;

public:
    static Game* instance() { return &instance_; }

    void init();
    void deinit();
    void update();
    void draw();

    void SetStageNum(int stageNum) { this->stageNum = stageNum; }

    int stageNum;
private:
    bool                isPaused;
    float A_timer;
    BG bg;

    VECTOR2 cursorPos;

    static Game instance_;
};

//******************************************************************************

#endif // !INCLUDED_GAME
