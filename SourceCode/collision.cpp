#include "collision.h"

bool collision_center(DirectX::XMFLOAT2 Apos, DirectX::XMFLOAT2 Bpos, DirectX::XMFLOAT2 collection)
{
    bool RE = false;

    //                                       C
    //(Apos.x,Apos.y).----------------------------------------------.
    //               |                                              |
    //               |                                              |
    //               |                                              |
    //               |        collectoin                            |
    //            A  |<------------------> .(Bpos.x,Bpos.y)         | B
    //               |                                              |
    //               |                                              |
    //               |                                              |
    //               |                                              |
    //               .----------------------------------------------.
    //                                      D
    if (
        Apos.x > Bpos.x - collection.x &&  //A
        Apos.x < Bpos.x + collection.x &&  //B
        Apos.y > Bpos.y - collection.y &&  //C
        Apos.y < Bpos.y + collection.y     //D
        )RE = true;

    return RE;
}
