#ifndef INCLUDED_GAME
#define	INCLUDED_GAME

//******************************************************************************
//
//
//      ゲームシーン
//
//
//******************************************************************************

//==============================================================================
//
//      Gameクラス
//
//==============================================================================

#include "bg.h"

class Game : public Scene
{
public:
    // クラス内での定数の定義の仕方
    // int型であればconstで良いが、それ以外はconstexprを使用する
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
