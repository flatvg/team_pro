#include "all.h"

using namespace GameLib;

void audio_init()
{
	//music::load(TITLE_BGM, L"./Data/Musics/title.wav");
	//music::load(GAME_BGM, L"./Data/Musics/game.wav");
	//music::load(TUTORIAL_BGM, L"./Data/Musics/tutrial.wav");

	//sound::load(SOUNDS, L"./Data/Sunds/sounds.xwb");

	//music::setVolume(TITLE_BGM, 0.3f);
	//music::setVolume(GAME_BGM, 0.3f);
	//music::setVolume(TUTORIAL_BGM, 0.3f);

	//sound::setVolume(SOUNDS, JUMP, 0.15f);
	//sound::setVolume(SOUNDS, BREAK, 0.15f);
	//sound::setVolume(SOUNDS, SELECT, 0.5f);
	//sound::setVolume(SOUNDS, START, 0.4f);
}

void audio_deinit()
{
	music::clear();
}
