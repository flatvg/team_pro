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
#define WHITE 1,1,1,1
#define BLACK 0,0,0,1

//画像パス
#define BACK          L"./Data/Images/back.png"
#define TILE01        L"./Data/Images/blockchip01.png"
#define TILE02        L"./Data/Images/block01.png"
#define BREAKETILE    L"./Data/Images/blockchip02.png"
#define FIRE03        L"./Data/Images/fire03.png"
#define BOMB01        L"./Data/Images/bomb_re01.png"
#define EXPLOSION     L"./Data/Images/explosion02.png"
#define RESET         L"./Data/Images/reset.png"
#define STAGE1        L"./Data/Images/stage1.png"
#define STAGE2        L"./Data/Images/stage2.png"
#define STAGE3        L"./Data/Images/stage3.png"
#define SHAPE         L"./Data/Images/shape.png"
#define CLICKEXPLODE  L"./Data/Images/click.png"
#define TEXT0         L"./Data/Images/Text0.png"
#define TEXT1         L"./Data/Images/Text1.png"
#define TEXT2         L"./Data/Images/Text2.png"
#define TEXT3         L"./Data/Images/Text3.png"
#define TEXT4         L"./Data/Images/Text4.png"
#define TEXT5         L"./Data/Images/Text5.png"
#define TEXT6         L"./Data/Images/Text6.png"
#define TEXT7         L"./Data/Images/Text7.png"
#define TEXT8         L"./Data/Images/Text8.png"
#define TEXT9         L"./Data/Images/Text9.png"
#define TEXT10        L"./Data/Images/Text10.png"
#define TEXT11        L"./Data/Images/Text11.png"
#define TEXT12        L"./Data/Images/Text12.png"
#define TEXT13        L"./Data/Images/Text13.png"
#define TEXT14        L"./Data/Images/Text14.png"
#define TEXT15        L"./Data/Images/Text15.png"
#define TEXT16        L"./Data/Images/Text16.png"
#define TEXT17        L"./Data/Images/Text17.png"
#define TEXT18        L"./Data/Images/Text18.png"
#define TEXT19        L"./Data/Images/Text19.png"
#define TEXT20        L"./Data/Images/Text20.png"
#define MODORU        L"./Data/Images/modoru.png"
#define NUMBER        L"./Data/Images/num.png"
#define LCLICK        L"./Data/Images/mouse_left.png"
#define CURSOR        L"./Data/Images/pointer_a.png"
#define CLOSEHAND     L"./Data/Images/hand_small_point.png"
#define CURSORPA      L"./Data/Images/hand_open.png"
#define CURSORGOO     L"./Data/Images/hand_closed.png"

#endif // !INCLUDED_COMMON
