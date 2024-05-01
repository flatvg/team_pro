#pragma once

#include <memory>
#include "TutorialBG.h"
#include "scene.h"
#include "focus.h"

class Tutorial : public Scene
{
public:
    // クラス内での定数の定義の仕方
    // int型であればconstで良いが、それ以外はconstexprを使用する
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