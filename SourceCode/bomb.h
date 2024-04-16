#pragma once

#include "obj2d.h"
#include "work.h"

void setBomb(OBJ2DManager* obj2dManager, BG* bg);

class BaseBombBehavior : public Behavior
{
protected:
    struct Param
    {
        GameLib::SpriteData* SPR_ITEM = nullptr;
        VECTOR2 SIZE = {};
        GameLib::fRECT ATTACK_BOX = {};
        VECTOR2 SCALE = { 1,1 };
    } param_;

    const Param* getParam() const { return &param_; }

private:
    void move(OBJ2D* obj) const;

    OBJ_TYPE getType() const override { return OBJ_TYPE::ITEM; }
    OBJ_TYPE getAttackType() const override { return OBJ_TYPE::PLAYER; }
};

class CrossBomb : public BaseBombBehavior
{
public:
    CrossBomb();
    void hit(OBJ2D* src, OBJ2D* dst) const override;
};
EXTERN CrossBomb crossBomb;

class NormalBomb : public BaseBombBehavior
{
public:
    NormalBomb();
    void hit(OBJ2D* src, OBJ2D* dst) const override;
};
EXTERN NormalBomb normalBomb;

class OneWayBomb : public BaseBombBehavior
{
public:
    OneWayBomb();
    void hit(OBJ2D* src, OBJ2D* dst) const override;
};
EXTERN OneWayBomb oneWayBomb;
