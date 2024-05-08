#include "TextBox.h"

using namespace GameLib;

void TextBox::Update()
{
    if (popUpFlag)
    {
        isStartTimer = true;
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

    if(isStartTimer)timer++;
}

void TextBox::Render(/*int boxTexNo, int clickTexNo*/)
{
//    texture::begin(boxTexNo);
//
//    texture::draw(
//        boxTexNo,
//        position,
//        VECTOR2(1,1),
//        VECTOR2(0, 0),
//        size,
//        center,
//        0,
//        VECTOR4(1,1,1,1)
//    );
//
//    texture::end(boxTexNo);

    if (textTextureFileName)
    {
        textTexture = sprite_load(textTextureFileName);

        sprite_render(
            textTexture,
            position.x, position.y,
            1.0f, 1.0f,
            0.0f, 0.0f,
            size.x, size.y,
            center.x, center.y,
            0,
            1, 1, 1, 1);

        delete textTexture;
    }

    //primitive::rect(
    //    position,
    //    size,
    //    center,
    //    0,
    //    color);

    if (scaleFactor > SCALE_MIN && isDrawClickHere)
    {
        //primitive::circle(
        //    circlePos,
        //    radius,
        //    VECTOR2(scaleFactor, scaleFactor),
        //    0,
        //    color);

        //texture::begin(clickTexNo);

        //texture::draw(
        //    clickTexNo,
        //    circlePos,
        //    VECTOR2(1, 1),
        //    VECTOR2(0, 0),
        //    size,
        //    VECTOR2(0,0),
        //    0,
        //    VECTOR4(1, 1, 1, 1)
        //);

        //texture::end(clickTexNo);

        if (clickTextureFileName)
        {
            clickTexture = sprite_load(clickTextureFileName);

            sprite_render(
                clickTexture,
                circlePos.x, circlePos.y,
                1.0f, 1.0f,
                0.0f, 0.0f,
                size.x, size.y,
                center.x, center.y,
                0,
                1, 1, 1, 1);

            delete clickTexture;
        }
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

void TextBox::Reset()
{
    if (textTexture)
    {
        textTexture = nullptr;
        delete textTexture;
    }
    if (clickTexture)
    {
        clickTexture = nullptr;
        delete clickTexture;
    }
    textTextureFileName = nullptr;
    clickTextureFileName = nullptr;
    isDrawClickHere = true;
    isAlreadyPopUp = false;
    popUpFlag = false;
    popOutFlag = false;
    isStartTimer = false;
    timer = 0;
}
