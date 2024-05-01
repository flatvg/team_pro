#pragma once

#include <memory>
#include "TutorialBG.h"
#include "scene.h"
#include "focus.h"

class Tutorial : public Scene
{
public:
    // �N���X���ł̒萔�̒�`�̎d��
    // int�^�ł����const�ŗǂ����A����ȊO��constexpr���g�p����
    static constexpr float GROUND_POS_Y = 640.0f;

public:
    static Tutorial* instance() { return &instance_; }

    void init();
    void deinit();
    void update();
    void draw();

    void SetStageNum(int stageNum) { this->stageNum = stageNum; }

    int stageNum;
private:
    bool                isPaused;
    float A_timer;
    TutorialBG T_bg;
    std::unique_ptr<Focus> focus;

    static Tutorial instance_;
};