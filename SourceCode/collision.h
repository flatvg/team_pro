#pragma once
#include "all.h"
#include <direct.h>

bool collision_center(
    DirectX::XMFLOAT2 Apos/*カーソル*/,
    DirectX::XMFLOAT2 Bpos/*爆弾位置*/,
    DirectX::XMFLOAT2 collection);
