#include "select.h"
#include "all.h"
#include "game.h"

extern int stageNum;

Select::Select()
{

}

Select::~Select()
{

}

void Select::init()
{
    timer = 0;
}

void Select::deinit()
{

}

void Select::update()
{
    if (GameLib::input::TRG(0) & GameLib::input::PAD_START)
    {
        stageNum = 0;
        changeScene(Game::instance());  // �Q�[���V�[���ɐ؂�ւ�
    }
    timer++;
}

void Select::draw()
{

}
