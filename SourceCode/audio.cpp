#include "all.h"
#include "audio.h"
using namespace GameLib;

void audio_init()
{
    // ���y�t�@�C���ǂݍ���
    music::load(0, L"./Data/Musics/game.wav");
    music::load(1, L"./Data/Musics/title.wav");

    // ���ʉ��ǂݍ���
    sound::load(0, L"./Data/Sounds/sounds1.xwb");

    music::setVolume(TITLE_BGM, 0.3f);
    music::setVolume(GAME_BGM, 0.3f);

    // ���ʉ��{�����[��
    //GameLib::sound::setVolume(XWB_SOUNDS1, XWB_SOUNDS1_EXPLOSION, 1.0f);
    //GameLib::sound::setVolume(XWB_SOUNDS1, XWB_SOUNDS1_SELECT, 1.0f);

}

void audio_deinit()
{
    GameLib::music::clear();
}
