#pragma once

class StageMover
{
public:
    StageMover(int srcStageIndex, int dstStageIndex)
        :srcStageIndex(srcStageIndex),
         dstStageIndex(dstStageIndex)
    {
        isMove = false;
        isFinish = false;
        moveFlag = false;
    }
    ~StageMover() {}

public:
    void Update();

    bool IsMove() { return isMove; }

    void FinishMove();

    int  GetSrcIndex() { return srcStageIndex; }

    int  GetDstIndex() { return dstStageIndex; }

    void SetMoveFlag(bool flag);

    void SetSrcIndex(int srcIndex) { srcStageIndex = srcIndex; }

    void SetDstIndex(int dstIndex) { dstStageIndex = dstIndex; }

private:
    int srcStageIndex;
    int dstStageIndex;
    bool isMove;
    bool moveFlag;
    bool isFinish;
};