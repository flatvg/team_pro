#pragma once

#include <DirectXMath.h>

class Focus
{
public:
    Focus()
    {
        focusFactor = 1.0f;
        timer = 0;
    }

    Focus(VECTOR2 pos, float radius ,bool OnFlag, bool OffFlag)
        :focusPos(pos),
        focusRadius(radius),
        focusOnFlag(OnFlag),
        unFocusFlag(OffFlag)
    {
        focusFactor = 1.0f;
        timer = 0;
    }

    Focus(VECTOR2 pos, float radius)
        :focusPos(pos),
        focusRadius(radius)
    {
        focusFactor = 1.0f;
        timer = 0;
    }

    ~Focus() {}

public:
    void update();

    void render();

    VECTOR2 SetFocusPos(VECTOR2 pos) { focusPos = pos; }

    float SetRadius(float radius) { focusRadius = radius; }

    void SetFocusFlag(bool flag) { if (flag)focusOnFlag = true; }

    void SetUnFocusFlag(bool flag) { if (flag)unFocusFlag = true;}

    float GetFactor() const { return focusFactor; }

    VECTOR2 GetPos() const { return focusPos; }

private:
    VECTOR2 focusPos;
    float focusRadius;

    float focusFactorMax = 1.0f;
    float focusFactorMin = 0.6f;
    float focusFactor = 1.0f;

    float focusOnFactor = -0.015f;
    float UnFocusFactor = 0.025f;
    bool focusOnFlag = false;
    bool unFocusFlag = false;

    int timer;
};