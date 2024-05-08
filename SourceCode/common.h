#ifndef INCLUDED_COMMON
#define	INCLUDED_COMMON

//******************************************************************************
//
//
//      common
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include <DirectXMath.h>

//------< �֐� >----------------------------------------------------------------

static float(*const ToRadian)(float) = DirectX::XMConvertToRadians;  // �p�x�����W�A����
static float(*const ToDegree)(float) = DirectX::XMConvertToDegrees;  // ���W�A�����p�x��

//�F
#define RED   1,0,0,1
#define GREEN 0,1,0,1
#define BLUE  0,0,1,1
#define WHITE 1,1,1,1
#define BLACK 0,0,0,1

//�摜�p�X
#define BACK          L"./Data/Images/back.png"
#define TILE01        L"./Data/Images/blockchip01.png"
#define TILE02        L"./Data/Images/block01.png"
#define BREAKETILE    L"./Data/Images/blockchip02.png"
#define FIRE03        L"./Data/Images/fire03.png"
#define BOMB01        L"./Data/Images/bomb_re01.png"
#define EXPLOSION     L"./Data/Images/explosion02.png"
#define RESET         L"./Data/Images/reset.png"
#define STAGE1        L"./Data/Images/stage1.png"
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
#define NUMBER        L"./Data/Images/num.png"
#define LCLICK        L"./Data/Images/mouse_left.png"

#endif // !INCLUDED_COMMON
