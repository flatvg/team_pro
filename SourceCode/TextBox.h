#pragma once

#include "all.h"
#include "../GameLib/vector.h"

class TextBox
{
private:
    static constexpr float SCALE_MAX = 1.0f;
    static constexpr float SCALE_MIN = 0.0f;
    static constexpr float FLUCTAUTE_FACTOR = 0.045f; //scaleÇ™ïœìÆÇ≥ÇπÇÈç€Ç…ópÇ¢ÇÈåWêî
    static constexpr float AMPLITUDE_CORREC = 7.5f;

public:
    TextBox()
    {
        position = VECTOR2(0, 0);
        baseSize = VECTOR2(100, 100);
        color = VECTOR4(1, 1, 1, 1);
        scaleFactor = 0.0f;
        size = baseSize * scaleFactor;
        center = size * 0.5f;
        popUpFlag = false;
        popOutFlag = false;
        circlePos = position + center;
        radius = 20.0f;
        circleAngle = 0.0f;
        isAlreadyPopUp = false;
    }

    TextBox(VECTOR2 pos, VECTOR2 Bsize, VECTOR4 color)
        :position(pos),baseSize(Bsize),color(color)
    {
        scaleFactor = 0.0f;
        size = baseSize * scaleFactor;
        center = size * 0.5f;
        popUpFlag = false;
        popOutFlag = false;
        circlePos = pos + center;
        radius = 20.0f;
        circleAngle = 0.0f;
        isAlreadyPopUp = false;
        isDrawClickHere = true;
    }
    ~TextBox() {}

public:
    void Update();

    void Render(int boxTexNo, int clickTexNo);

    void IsNotDrawClickHere() { isDrawClickHere = false; }

    void SetPosition(VECTOR2 pos) { position = pos; }

    bool GetPopUpFlag() { return popUpFlag; }

    bool GetPopOutFlag() { return popOutFlag; }

    void SetPopUpFlag(bool flag);

    void SetPopOutFlag(bool flag);

    void Reset();

    const VECTOR2& getPosition() const { return position; }

private:
    GameLib::Sprite* textTexture = nullptr;
    GameLib::Sprite* clickTexture = nullptr;

    VECTOR2 position;
    VECTOR2 baseSize;
    VECTOR2 size;
    VECTOR2 center;
    VECTOR4 color;
    VECTOR2 circlePos;
    float radius;
    float circleAngle;
    float scaleFactor;
    bool popUpFlag;
    bool popOutFlag;
    bool isAlreadyPopUp;
    bool isDrawClickHere;
};