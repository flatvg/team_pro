#include "all.h"
#include "focus.h"

using namespace GameLib;

void Focus::update()
{
    if (focusOnFlag)
    {
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
        else unFocusFlag = false;
    }

    timer++;
}

void Focus::render()
{
    if (timer > 40)//åÎëÄçÏëjé~
    {
        DepthStencil::instance().set(DepthStencil::MODE::MASK);
        primitive::circle(
            focusPos,
            focusRadius * focusFactor,
            VECTOR2(1,1),
            0);
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
