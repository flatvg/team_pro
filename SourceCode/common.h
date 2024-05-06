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
#define BACK L"./Data/Images/back.png"
#define TILE01 L"./Data/Images/test_tile.png"
#define TILE02 L"./Data/Images/test_tile02.png"
#define FIRE03 L"./Data/Images/fire03.png"
#define BOMB01 L"./Data/Images/bomb_re01.png"
#define EXPLOSION L"./Data/Images/explosion02.png"
#define RESET L"./Data/Images/reset.png"

#endif // !INCLUDED_COMMON
