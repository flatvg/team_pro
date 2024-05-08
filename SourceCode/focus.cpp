#include "all.h"
#include "focus.h"

using namespace GameLib;

int Focus::instanceNum = -1;

void Focus::update()
{
    if (focusOnFlag)
    {
        isDraw = true;
        if (focusFactor > focusFactorMin)
        {
            focusFactor += focusOnFactor;
        }
        else focusOnFlag = false;
    }
    if (unFocusFlag)
    {
        if (focusFactor < focusFactorMax)
        {
            focusFactor += UnFocusFactor;
        }
        else
        {
            unFocusFlag = false;
            isDraw = false;
        }
    }

    timer++;
}

void Focus::render()
{
    if (isDraw)
    {
        DepthStencil::instance().set(DepthStencil::MODE::MASK);
        primitive::circle(
            focusPos,
            focusRadius * focusFactor,
            focusSize,
            0
        );

        DepthStencil::instance().set(DepthStencil::MODE::EXCLUSIVE);
        primitive::rect(
            0, 0,
            window::getWidth(), window::getHeight(),
            0, 0,
            0,
            0.0f, 0.0f, 0.0f, 1.9f * (1.0f - focusFactor));


        DepthStencil::instance().set(DepthStencil::MODE::NONE);
    }
}

void Focus::Reset()
{
    focusPos = VECTOR2(-300.0f, -300.0f);
    focusSize = VECTOR2(1.0f, 1.0f);
    focusOnFlag = false;
    unFocusFlag = false;
    isDraw = true;
}
