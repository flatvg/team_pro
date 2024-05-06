#pragma once

#include <DirectXMath.h>

class Focus
{
public:
    Focus()
    {
        focusFactor = 1.0f;
        timer = 0;
        myInstance = instanceNum;
    }

    Focus(VECTOR2 pos, float radius ,bool OnFlag, bool OffFlag)
        :focusPos(pos),
        focusRadius(radius),
        focusOnFlag(OnFlag),
        unFocusFlag(OffFlag)
    {
        focusFactor = 1.0f;
        timer = 0;
        myInstance = instanceNum;
    }

    Focus(VECTOR2 pos, float radius)
        :focusPos(pos),
        focusRadius(radius)
    {
        focusFactor = 1.0f;
        timer = 0;
        myInstance = instanceNum;
    }

    ~Focus() {}

public:
    static int instanceNum;

    void update();

    void render();

    void SetFocusPos(const VECTOR2 &pos) { focusPos = pos; }

    void SetFocusSize(const VECTOR2& size) { focusSize = size; }

    void SetRadius(float radius) { focusRadius = radius; }

    void SetFocusFlag(bool flag) { if (flag)focusOnFlag = true; }

    void SetUnFocusFlag(bool flag) { if (flag)unFocusFlag = true;}

    float GetFactor() const { return focusFactor; }

    VECTOR2 GetPos() const { return focusPos; }

    bool IsDraw() { return isDraw; }

    void Reset();

private:
    VECTOR2 focusPos;
    VECTOR2 focusSize = { 1.0f,1.0f };
    float focusRadius;

    float focusFactorMax = 1.0f;
    float focusFactorMin = 0.6f;
    float focusFactor = 1.0f;

    float focusOnFactor = -0.015f;
    float UnFocusFactor = 0.025f;
    bool focusOnFlag = false;
    bool unFocusFlag = false;

    bool isDraw = true;

    int myInstance;

    int timer;
};