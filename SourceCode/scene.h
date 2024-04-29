#ifndef INCLUDED_SCENE
#define INCLUDED_SCENE

//******************************************************************************
//
//
//      シーン
//
//
//******************************************************************************

//==============================================================================
//
//      Sceneクラス
//
//==============================================================================
class Scene
{
protected:
    int state;          // 状態
    int timer;          // タイマー
    Scene* nextScene;   // 次のシーン

public:
    Scene* execute();   // 実行処理

    virtual void init()
    { // 初期化処理
        state = 0;
        timer = 0;
        nextScene = nullptr;
    };
    virtual void deinit() {};   // 終了処理
    virtual void update() {};   // 更新処理
    virtual void draw()   {};   // 描画処理

    GameLib::fRECT makeRect(DirectX::XMFLOAT2 pos, DirectX::XMFLOAT2 size) { return GameLib::fRECT(pos.x, pos.y, pos.x + size.x, pos.y + size.y); }

    void changeScene(Scene *scene) { nextScene = scene; }   // シーン変更処理
    Scene *getScene() const { return nextScene; }           // nextSceneのゲッター
};

//******************************************************************************
//
//
//      シーン管理
//
//
//******************************************************************************

//==============================================================================
//
//      SceneManagerクラス
//
//==============================================================================

class SceneManager
{
public:
    void execute(Scene*);  // 実行処理
};

//******************************************************************************

#endif // !INCLUDED_SCENE
