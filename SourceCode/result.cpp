#include "result.h"
#include "all.h"
#include "title.h"
#include "collision.h"

Result Result::instance_;

void Result::init()
{
    timer = 0;
}

void Result::deinit()
{
}

void Result::update()
{

    if (timer > 2)
    {
        if (GameLib::input::TRG(0) & GameLib::input::PAD_LC)      changeScene(Title::instance());
    }

    timer++;

}

void Result::draw()
{
    // ‰æ–ÊƒNƒŠƒA
    GameLib::clear(VECTOR4(1, 0, 0, 1));
    
}
