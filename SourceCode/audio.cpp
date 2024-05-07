#include "all.h"
#include "audio.h"
using namespace GameLib;

void audio_init()
{
    // 音楽ファイル読み込み
    music::load(0, L"./Data/Musics/game.wav");
    music::load(1, L"./Data/Musics/title.wav");

    // 効果音読み込み
    sound::load(0, L"./Data/Sounds/sounds1.xwb");

    music::setVolume(TITLE_BGM, 0.3f);
    music::setVolume(GAME_BGM, 0.3f);

    // 効果音ボリューム
    //GameLib::sound::setVolume(XWB_SOUNDS1, XWB_SOUNDS1_EXPLOSION, 1.0f);
    //GameLib::sound::setVolume(XWB_SOUNDS1, XWB_SOUNDS1_SELECT, 1.0f);

}

void audio_deinit()
{
    GameLib::music::clear();
}
