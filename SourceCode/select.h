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

    bool isClickRect(DirectX::XMFLOAT2 cursorPos, GameLib::fRECT rect) override;

    void renderRect(GameLib::fRECT rect, DirectX::XMFLOAT4 color);

    RectData setRectData(DirectX::XMFLOAT2 pos, DirectX::XMFLOAT2 size, DirectX::XMFLOAT4 color);

private:

    DirectX::XMFLOAT2  cursorPos;   //カーソルの位置

    RectData stage1;

    static Select instance_;
};