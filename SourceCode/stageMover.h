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
        isChangeStageIndex = true;
    }
    ~StageMover() {}

public:
    void Update();

    bool IsMove() { return isMove; }

    bool IsChangeStageIndex() { return isChangeStageIndex; }

    void FinishMove();

    int  GetSrcIndex() { return srcStageIndex; }

    int  GetDstIndex() { return dstStageIndex; }

    void SetMoveFlag(bool flag);

    void SetSrcIndex(int srcIndex) { srcStageIndex = srcIndex; }

    void SetDstIndex(int dstIndex) { dstStageIndex = dstIndex; }

    void SetInChangeStageIndex(bool flag) { isChangeStageIndex = flag; }

private:
    int srcStageIndex;
    int dstStageIndex;
    bool isMove;
    bool moveFlag;
    bool isFinish;
    bool isChangeStageIndex;
};