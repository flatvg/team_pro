#include "TextBox.h"

using namespace GameLib;

void TextBox::Update()
{
    if (popUpFlag)
    {
        scaleFactor += FLUCTAUTE_FACTOR;
    }
    if (scaleFactor > SCALE_MAX && popUpFlag)
    {
        scaleFactor = SCALE_MAX;
        popUpFlag = false;
    }

    if (popOutFlag)
    {
        scaleFactor -= FLUCTAUTE_FACTOR;
    }
    if (scaleFactor < SCALE_MIN && popOutFlag)
    {
        scaleFactor = SCALE_MIN;
        popOutFlag = false;
    }

    size = baseSize * scaleFactor;
    center = size * 0.5f;
    circlePos = position + center;
    circlePos.y += cosf(circleAngle) * AMPLITUDE_CORREC;
    circleAngle += DirectX::XMConvertToRadians(2);
}

void TextBox::Render()
{
    primitive::rect(
        position,
        size,
        center,
        0,
        color);

    if (scaleFactor > SCALE_MIN && isDrawClickHere)
    {
        primitive::circle(
            circlePos,
            radius,
            VECTOR2(scaleFactor, scaleFactor),
            0,
            color);
    }
}

void TextBox::SetPopUpFlag(bool flag)
{
    if (flag && !popOutFlag && !popUpFlag && !isAlreadyPopUp)
    {
        popUpFlag = true;
        isAlreadyPopUp = true;
    }
}

void TextBox::SetPopOutFlag(bool flag)
{
    if (flag && !popUpFlag && !popOutFlag && isAlreadyPopUp)
    {
        popOutFlag = true;
    }
}
