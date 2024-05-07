
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
#include "scene.h"

class Result : public Scene
{
public:
    // クラス内での定数の定義の仕方
    // int型であればconstで良いが、それ以外はconstexprを使用する
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

    static Result instance_;
};

//******************************************************************************