
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
#include "scene.h"
#include "Effect.h"

class Result : public Scene
{
public:
    // �N���X���ł̒萔�̒�`�̎d��
    // int�^�ł����const�ŗǂ����A����ȊO��constexpr���g�p����
    static constexpr float GROUND_POS_Y = 640.0f;

public:
    static Result* instance() { return &instance_; }

    Result();
    void init();
    void deinit();
    void update();
    void draw();
private:
    int score;
    int act;
    bool isPaused;
    DirectX::XMFLOAT2 title_scale;
    DirectX::XMFLOAT2 select_scale;

    VECTOR2 cursorPos;

    Effect effect_click;

    static Result instance_;
};

//******************************************************************************