#ifndef INCLUDED_COMMON
#define	INCLUDED_COMMON

//******************************************************************************
//
//
//      common
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
#include <DirectXMath.h>

//------< 関数 >----------------------------------------------------------------

static float(*const ToRadian)(float) = DirectX::XMConvertToRadians;  // 角度をラジアンに
static float(*const ToDegree)(float) = DirectX::XMConvertToDegrees;  // ラジアンを角度に

//色
#define RED   1,0,0,1
#define GREEN 0,1,0,1
#define BLUE  0,0,1,1
#define WHITE 0,0,0,1
#define BLACK 1,1,1,1

//画像パス
#define FIRE03 L"./Data/Images/fire03.png"
#define BOMB01 L"./Data/Images/bomb_re01.png"
#define EXPLOSION L"./Data/Images/explosion02.png"

#endif // !INCLUDED_COMMON
