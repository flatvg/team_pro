#include "sprite_data.h"

using namespace GameLib;

// 2D画像ロードデータ
LoadTexture loadTexture[] = {
    {TEXNO::BOMB,           L"./Data/Images/bomb.png",     1U},
    {TEXNO::EXPLOSION0,     L"./Data/Images/explosion01.png",     1U},
    {TEXNO::EXPLOSION1,     L"./Data/Images/explosion02.png",     1U},
    {TEXNO::EXPLOSION2,     L"./Data/Images/explosion03.png",     1U},
    {TEXNO::FIRE0,          L"./Data/Images/fire01.png",     1U},
    {TEXNO::FIRE1,          L"./Data/Images/fire02.png",     1U},
    {-1,nullptr} // 終了フラグ
};

//------< マクロ >--------------------------------------------------------------
#define SPRITE_CENTER(texno,left,top,width,height)	{ (texno),(left),(top),(width),(height),(width)/2,(height)/2 }  // 画像の真ん中が中心
#define SPRITE_BOTTOM(texno,left,top,width,height)	{ (texno),(left),(top),(width),(height),(width)/2,(height)   }  // 画像の足元が中心

/*＜ 爆弾 ＞*/

// 爆弾 (黒)
SpriteData sprBomb_Black0 = SPRITE_CENTER(TEXNO::BOMB, 32 * 0, 32 * 0, 32, 32);
SpriteData sprBomb_Black1 = SPRITE_CENTER(TEXNO::BOMB, 32 * 1, 32 * 0, 32, 32);
SpriteData sprBomb_Black2 = SPRITE_CENTER(TEXNO::BOMB, 32 * 2, 32 * 0, 32, 32);
SpriteData sprBomb_Black3 = SPRITE_CENTER(TEXNO::BOMB, 32 * 3, 32 * 0, 32, 32);
SpriteData sprBomb_Black4 = SPRITE_CENTER(TEXNO::BOMB, 32 * 4, 32 * 0, 32, 32);

// 爆弾 (赤)
SpriteData sprBomb_Red0 = SPRITE_CENTER(TEXNO::BOMB, 32 * 0, 32 * 1, 32, 32);
SpriteData sprBomb_Red1 = SPRITE_CENTER(TEXNO::BOMB, 32 * 1, 32 * 1, 32, 32);
SpriteData sprBomb_Red2 = SPRITE_CENTER(TEXNO::BOMB, 32 * 2, 32 * 1, 32, 32);
SpriteData sprBomb_Red3 = SPRITE_CENTER(TEXNO::BOMB, 32 * 3, 32 * 1, 32, 32);
SpriteData sprBomb_Red4 = SPRITE_CENTER(TEXNO::BOMB, 32 * 4, 32 * 1, 32, 32);

// 爆弾 (青)
SpriteData sprBomb_Blue0 = SPRITE_CENTER(TEXNO::BOMB, 32 * 0, 32 * 2, 32, 32);
SpriteData sprBomb_Blue1 = SPRITE_CENTER(TEXNO::BOMB, 32 * 1, 32 * 2, 32, 32);
SpriteData sprBomb_Blue2 = SPRITE_CENTER(TEXNO::BOMB, 32 * 2, 32 * 2, 32, 32);
SpriteData sprBomb_Blue3 = SPRITE_CENTER(TEXNO::BOMB, 32 * 3, 32 * 2, 32, 32);
SpriteData sprBomb_Blue4 = SPRITE_CENTER(TEXNO::BOMB, 32 * 4, 32 * 2, 32, 32);

//爆弾 (黄)
SpriteData sprBomb_Yellow0 = SPRITE_CENTER(TEXNO::BOMB, 32 * 0, 32 * 3, 32, 32);
SpriteData sprBomb_Yellow1 = SPRITE_CENTER(TEXNO::BOMB, 32 * 1, 32 * 3, 32, 32);
SpriteData sprBomb_Yellow2 = SPRITE_CENTER(TEXNO::BOMB, 32 * 2, 32 * 3, 32, 32);
SpriteData sprBomb_Yellow3 = SPRITE_CENTER(TEXNO::BOMB, 32 * 3, 32 * 3, 32, 32);
SpriteData sprBomb_Yellow4 = SPRITE_CENTER(TEXNO::BOMB, 32 * 4, 32 * 3, 32, 32);

//爆弾 (紫)
SpriteData sprBomb_Purple0 = SPRITE_CENTER(TEXNO::BOMB, 32 * 0, 32 * 4, 32, 32);
SpriteData sprBomb_Purple1 = SPRITE_CENTER(TEXNO::BOMB, 32 * 1, 32 * 4, 32, 32);
SpriteData sprBomb_Purple2 = SPRITE_CENTER(TEXNO::BOMB, 32 * 2, 32 * 4, 32, 32);
SpriteData sprBomb_Purple3 = SPRITE_CENTER(TEXNO::BOMB, 32 * 3, 32 * 4, 32, 32);
SpriteData sprBomb_Purple4 = SPRITE_CENTER(TEXNO::BOMB, 32 * 4, 32 * 4, 32, 32);


/*＜ 爆発 ＞*/

// 爆発1
SpriteData sprExplosion1_0 = SPRITE_CENTER(TEXNO::EXPLOSION0, 120 * 0, 120 * 0, 120, 120);
SpriteData sprExplosion1_1 = SPRITE_CENTER(TEXNO::EXPLOSION0, 120 * 1, 120 * 0, 120, 120);
SpriteData sprExplosion1_2 = SPRITE_CENTER(TEXNO::EXPLOSION0, 120 * 2, 120 * 0, 120, 120);
SpriteData sprExplosion1_3 = SPRITE_CENTER(TEXNO::EXPLOSION0, 120 * 3, 120 * 0, 120, 120);
SpriteData sprExplosion1_4 = SPRITE_CENTER(TEXNO::EXPLOSION0, 120 * 4, 120 * 0, 120, 120);
SpriteData sprExplosion1_5 = SPRITE_CENTER(TEXNO::EXPLOSION0, 120 * 5, 120 * 0, 120, 120);
SpriteData sprExplosion1_6 = SPRITE_CENTER(TEXNO::EXPLOSION0, 120 * 6, 120 * 0, 120, 120);
SpriteData sprExplosion1_7 = SPRITE_CENTER(TEXNO::EXPLOSION0, 120 * 7, 120 * 0, 120, 120);

// 爆発2
SpriteData sprExplosion2_0 = SPRITE_CENTER(TEXNO::BOMB, 120 * 0, 120 * 0, 120, 120);
SpriteData sprExplosion2_1 = SPRITE_CENTER(TEXNO::BOMB, 120 * 1, 120 * 0, 120, 120);
SpriteData sprExplosion2_2 = SPRITE_CENTER(TEXNO::BOMB, 120 * 2, 120 * 0, 120, 120);
SpriteData sprExplosion2_3 = SPRITE_CENTER(TEXNO::BOMB, 120 * 3, 120 * 0, 120, 120);
SpriteData sprExplosion2_4 = SPRITE_CENTER(TEXNO::BOMB, 120 * 4, 120 * 0, 120, 120);
SpriteData sprExplosion2_5 = SPRITE_CENTER(TEXNO::BOMB, 120 * 5, 120 * 0, 120, 120);
SpriteData sprExplosion2_6 = SPRITE_CENTER(TEXNO::BOMB, 120 * 6, 120 * 0, 120, 120);

// 爆発3
SpriteData sprExplosion3_0 = SPRITE_CENTER(TEXNO::BOMB, 320 * 0, 120 * 0, 320, 120);
SpriteData sprExplosion3_1 = SPRITE_CENTER(TEXNO::BOMB, 320 * 0, 120 * 1, 320, 120);
SpriteData sprExplosion3_2 = SPRITE_CENTER(TEXNO::BOMB, 320 * 0, 120 * 2, 320, 120);
SpriteData sprExplosion3_3 = SPRITE_CENTER(TEXNO::BOMB, 320 * 0, 120 * 3, 320, 120);
SpriteData sprExplosion3_4 = SPRITE_CENTER(TEXNO::BOMB, 320 * 0, 120 * 4, 320, 120);
SpriteData sprExplosion3_5 = SPRITE_CENTER(TEXNO::BOMB, 320 * 0, 120 * 5, 320, 120);
SpriteData sprExplosion3_6 = SPRITE_CENTER(TEXNO::BOMB, 320 * 0, 120 * 6, 320, 120);
SpriteData sprExplosion3_7 = SPRITE_CENTER(TEXNO::BOMB, 320 * 0, 120 * 7, 320, 120);
SpriteData sprExplosion3_8 = SPRITE_CENTER(TEXNO::BOMB, 320 * 0, 120 * 8, 320, 120);


/*＜ 火 ＞*/

// 火1
SpriteData sprFire1_0 = SPRITE_CENTER(TEXNO::BOMB, 120 * 0, 120 * 0, 120, 120);
SpriteData sprFire1_1 = SPRITE_CENTER(TEXNO::BOMB, 120 * 1, 120 * 0, 120, 120);
SpriteData sprFire1_2 = SPRITE_CENTER(TEXNO::BOMB, 120 * 2, 120 * 0, 120, 120);
SpriteData sprFire1_3 = SPRITE_CENTER(TEXNO::BOMB, 120 * 3, 120 * 0, 120, 120);
SpriteData sprFire1_4 = SPRITE_CENTER(TEXNO::BOMB, 120 * 4, 120 * 0, 120, 120);
SpriteData sprFire1_5 = SPRITE_CENTER(TEXNO::BOMB, 120 * 5, 120 * 0, 120, 120);
SpriteData sprFire1_6 = SPRITE_CENTER(TEXNO::BOMB, 120 * 6, 120 * 0, 120, 120);
SpriteData sprFire1_7 = SPRITE_CENTER(TEXNO::BOMB, 120 * 7, 120 * 0, 120, 120);
SpriteData sprFire1_8 = SPRITE_CENTER(TEXNO::BOMB, 120 * 8, 120 * 0, 120, 120);
SpriteData sprFire1_9 = SPRITE_CENTER(TEXNO::BOMB, 120 * 9, 120 * 0, 120, 120);

// 火2
SpriteData sprFire2_0 = SPRITE_CENTER(TEXNO::BOMB, 120 * 0, 120 * 0, 120, 120);
SpriteData sprFire2_1 = SPRITE_CENTER(TEXNO::BOMB, 120 * 1, 120 * 0, 120, 120);
SpriteData sprFire2_2 = SPRITE_CENTER(TEXNO::BOMB, 120 * 2, 120 * 0, 120, 120);
SpriteData sprFire2_3 = SPRITE_CENTER(TEXNO::BOMB, 120 * 3, 120 * 0, 120, 120);
SpriteData sprFire2_4 = SPRITE_CENTER(TEXNO::BOMB, 120 * 4, 120 * 0, 120, 120);
SpriteData sprFire2_5 = SPRITE_CENTER(TEXNO::BOMB, 120 * 5, 120 * 0, 120, 120);
SpriteData sprFire2_6 = SPRITE_CENTER(TEXNO::BOMB, 120 * 6, 120 * 0, 120, 120);
SpriteData sprFire2_7 = SPRITE_CENTER(TEXNO::BOMB, 120 * 7, 120 * 0, 120, 120);