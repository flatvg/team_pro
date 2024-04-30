#pragma once
#include "scene.h"

struct RectData
{
    DirectX::XMFLOAT2 position;
    DirectX::XMFLOAT2 size;
    DirectX::XMFLOAT4 color;
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

    bool isClickRect(DirectX::XMFLOAT2 cursorPos, RectData rectData);

    void renderRect(GameLib::fRECT rect, DirectX::XMFLOAT4 color);

    RectData setRectData(DirectX::XMFLOAT2 pos, DirectX::XMFLOAT2 size, DirectX::XMFLOAT4 color);

private:
    static constexpr int STAGE_MAX = 3;

    DirectX::XMFLOAT2  cursorPos;   //カーソルの位置

    RectData stages[STAGE_MAX];

    RectData stage1;

    static Select instance_;
};