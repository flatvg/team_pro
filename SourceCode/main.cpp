//******************************************************************************
//
//
//      main
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
#include "all.h"
#include "obj2d.h"
#include "scene.h"
#include "game.h"
#include "title.h"
#include "result.h"

//--------------------------------
//  WinMain（エントリポイント）
//--------------------------------
int APIENTRY wWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPWSTR, _In_ int)
{
    SceneManager sceneManager;
    sceneManager.execute(Result::instance());

    return 0;
}

//******************************************************************************
