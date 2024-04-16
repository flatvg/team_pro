#pragma once
#include "scene.h"

class Select : public Scene
{
public:
    Select();
    ~Select();
public:
    static Select* instance() { return &instance_; }

    void init()override;
    void deinit()override;
    void update()override;
    void draw()override;
private:
    static Select instance_;
};