#include "stageMover.h"

void StageMover::Update()
{
    if (moveFlag && !isFinish)
    {
        isMove = true;
    }
}

void StageMover::FinishMove()
{
    isMove = false;
    isFinish = true;
}

void StageMover::SetMoveFlag(bool flag)
{
    if (flag)
    {
        moveFlag = true;
    }
}
