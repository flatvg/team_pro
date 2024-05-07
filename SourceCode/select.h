#pragma once
#include "scene.h"

struct RectData
{
    VECTOR2 position;
    VECTOR2 scale;
    VECTOR2 size;
    VECTOR2 center;
    VECTOR4 color;
    GameLib::fRECT rect;
};

class Select : public Scene
{
public:
    Select() {}
    ~Select() {}
public:
    static Select* instance() { return &instance_; }

    void init()override;
    void deinit()override;
    void update()override;
    void draw()override;

    bool isClickRect(VECTOR2 cursorPos, RectData rectData);

    void renderRect(GameLib::fRECT rect, VECTOR4 color);

    RectData setRectData(VECTOR2 pos, VECTOR2 size, VECTOR4 color, VECTOR2 scale);

private:
    static constexpr int STAGE_MAX = 3;

    VECTOR2  cursorPos;   //カーソルの位置

    RectData stages[STAGE_MAX];

    RectData stage1;

    static Select instance_;
};