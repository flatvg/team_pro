//******************************************************************************
//
//
//      main
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include "all.h"
#include "obj2d.h"
#include "scene.h"
#include "game.h"
#include "title.h"

//--------------------------------
//  WinMain�i�G���g���|�C���g�j
//--------------------------------
int APIENTRY wWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPWSTR, _In_ int)
{
    SceneManager sceneManager;
    sceneManager.execute(Title::instance());

    return 0;
}

//******************************************************************************