#pragma once
#include <memory>
#include "../GameLib/vector.h"
#include "Effect.h"
#include "focus.h"
#include "stageMover.h"
#include "TextBox.h"

class TutorialBG
{
public:
    //enum class出ないものはint型としても使いたいのでenum classを使わない
    enum ExplosionPoint
    {
        CENTER,
        LEFT,
        TOP,
        RIGHT,
        BOTTOM,
    };

    enum TerrainStatus
    {
        UnBreakble = -1,
        Normal,
        Bomb,
        InExplosion,
        BurningFuse,
        None
    };

    enum PatternStatus
    {
        IsNotBomb,
        IsBomb
    };

    enum TexNo
    {
        Tile01,
        Tile02,
        Bomb01,
        Explosion,
        Reset
    };

    enum class MoveType
    {
        StartToInGame,
        InGameToEnd
    };
public:
    //------< 定数 >------------------------------------------------------------
    static const int STAGE_NUM = 3;         // ステージ数
    static const int CHIP_NUM_X = 14;       // マップの横方向のチップ数
    static const int CHIP_NUM_Y = 12;       // マップの縦方向のチップ数
    static const int CHIP_SIZE = 64;        // %演算子を使用するためint型を使用する
    DirectX::XMFLOAT2 chip_size_xmfloat2 = { CHIP_SIZE * 0.5 ,CHIP_SIZE * 0.5 };
    static const int EXPLOSION_CHIP_NUM = 5;
    static const int BOMB_NUM = 3;
    static const int BOMB_ROTATE_MAX = 3;
    static const int BOMB_TYPE_MAX = 3;

    static constexpr float CHIP_SIZE_F = 64.0f;
    static constexpr float WIDTH = static_cast<float>(CHIP_NUM_X * CHIP_SIZE);   // マップの幅（ドット）
    static constexpr float HEIGHT = static_cast<float>(CHIP_NUM_Y * CHIP_SIZE);   // マップの高さ（ドット）

    //ステージの余白
    DirectX::XMFLOAT2 Mapterrain_correction{ 200.0f + 32.0f - 64.0f ,0.0f + 32.0f - 64.0f };

    //テレインの中央に修正
    DirectX::XMFLOAT2 TerrainCenter_correction{ CHIP_SIZE_F / 2,CHIP_SIZE_F / 2 };

    //バクダン初期位置
    DirectX::XMFLOAT2 bomb_defpos[BOMB_NUM] =
    {
        {1096.0f,CHIP_SIZE_F + CHIP_SIZE * 0 + 10.0f},
        {1096.0f,CHIP_SIZE_F + CHIP_SIZE * 3 + 20.0f},
        {1096.0f,CHIP_SIZE_F + CHIP_SIZE * 6 + 30.0f},
    };
    DirectX::XMFLOAT2 bomb_changepos[BOMB_NUM] =
    {
        bomb_defpos[0],
        bomb_defpos[1],
        bomb_defpos[2],
    };

private:
    //------< 変数 >------------------------------------------------------------
    struct TerrainData
    {
        DirectX::XMFLOAT2 startPos;    //画面下の位置
        DirectX::XMFLOAT2 inGamePos;   //画面中央の位置
        DirectX::XMFLOAT2 endPos;      //画面上の位置
        DirectX::XMFLOAT2 currentPos;  //現在の位置
        int status;                    //状態
        int explosionTimer;            //爆破時間
        bool isAlredyChanged;          //すでに情報が変更されているか
        bool isChained;                //爆破が連鎖によって引き起こされたか否か
        bool isPutOn;                  //そのブロックがバクダンをおける状態か否か
        int DelayTimer;                //爆発の連鎖をずらす時間
        int terrain_endurance;         //マップタイルの耐久値
        int terrain_enduranceC;        //マップタイルの耐久値のチェック用
    };
    //1マスが持つ情報
    TerrainData terrainData[TutorialBG::STAGE_NUM][TutorialBG::CHIP_NUM_Y][TutorialBG::CHIP_NUM_X];

    //エフェクトの情報
    struct TerrainEffect
    {
        DirectX::XMFLOAT2 pos;
        bool exist;
        int animeMax;
        int animeNum;
        float timer;
        int tx, ty;
        float texSizeX;
        float playSpeed;
    };
    TerrainEffect TerrainExplosion[TutorialBG::STAGE_NUM][TutorialBG::CHIP_NUM_Y][TutorialBG::CHIP_NUM_X];

    TerrainEffect TerrainBomb[TutorialBG::STAGE_NUM][TutorialBG::CHIP_NUM_Y][TutorialBG::CHIP_NUM_X];


public:
    TutorialBG();
    ~TutorialBG();

    // 初期化
    void init(int stagenum);

    //終了化
    void deinit();

    // 更新
    void update();

    // 描画
    void drawTerrain();

    //チュートリアル
    void Tutorial();
    void Tutorial_0();
    void Tutorial_1();

    //爆弾をドラッグ
    void dragBomb();

    //爆弾を回転
    void rotateBomb();

    //爆弾をドロップ
    void dropBomb();

    //爆弾をリセット
    void resetButton();

    //爆弾を置いた後のリセット
    void resetBombPostProcess();

    //そのブロックにバクダンが設置可能か
    void SetIsPutOn();

    bool IsPutOn(int s, int y, int x);

    bool SearchAdjacentTerrain(int status);

    //ステージを移動
    bool moveStages(std::unique_ptr<StageMover> &stageMover);
    bool moveStage(int stageNum, MoveType moveType);

    //ステージの移動フラグを設定
    void setMoveFlags();

    //エフェクトを更新
    void updateEffect(TerrainEffect& effect);

    //爆発箇所計算
    DirectX::XMINT2 CalcExplosionPoint(DirectX::XMINT2 BaseExplosionPoint, ExplosionPoint point);
    DirectX::XMINT2 CalcCenterPoint(DirectX::XMINT2 BaseExplosionPoint);
    DirectX::XMINT2 CalcLeftPoint(DirectX::XMINT2 BaseExplosionPoint);
    DirectX::XMINT2 CalcTopPoint(DirectX::XMINT2 BaseExplosionPoint);
    DirectX::XMINT2 CalcRightPoint(DirectX::XMINT2 BaseExplosionPoint);
    DirectX::XMINT2 CalcBottomPoint(DirectX::XMINT2 BaseExplosionPoint);

    //爆発箇所を確定させる
    int SetExplosionPoint(int stageNum, DirectX::XMINT2 explosionPoint, ExplosionPoint point, int delayIndex);
    int SetCenterPoint(int stageNum, int center, DirectX::XMINT2 centerPos, int delayIndex);
    int SetLeftPoint(int stageNum, int center, int left, DirectX::XMINT2 leftPos, DirectX::XMINT2 centerPos, int delayIndex);
    int SetTopPoint(int stageNum, int center, int top, DirectX::XMINT2 topPos, DirectX::XMINT2 centerPos, int delayIndex);
    int SetRightPoint(int stageNum, int center, int right, DirectX::XMINT2 rightPos, DirectX::XMINT2 centerPos, int delayIndex);
    int SetBottomPoint(int stageNum, int center, int bottom, DirectX::XMINT2 bottomPos, DirectX::XMINT2 centerPos, int delayIndex);

    //bomb地形の設定
    void SetTerrainData(int stageNum, DirectX::XMINT2 terrainPos, int delayIndex);

    //すでに指定した箇所が変更されているか
    bool IsAlreadyChanged(int stageNum, DirectX::XMINT2 terrainPos);

    //バクダンを設置
    void SetBomb(int stageNum, DirectX::XMINT2 terrainPos, ExplosionPoint point, int delayIndex);

    //連鎖が終わる
    void finishChain(int stageNum, DirectX::XMINT2 terrainPos);

    //terrainの初期化
    void InitTerrain(TerrainStatus terrainStatus, int stageNum, DirectX::XMINT2 terrainPos);
    void InitTerrain(TerrainStatus terrainStatus, int s, int x, int y);

    //terrainのpositionの設定
    void SetTerrainPos(DirectX::XMINT2 terrainPos, int stageNum);

    bool finish_game;

private:

    int stageNum;
    int timer;                      //全体の時間
    int explosionTime = 50;         //爆発が残留する時間
    int delayTime = 20;             //爆発の連鎖する間隔
    int operatbleCursorTime = 5;    //誤操作を防ぐための操作不能時間
    DirectX::XMFLOAT2  cursorPos;   //カーソルの位置
    bool drag_con = false;

    //スコア関連
    int act;
    int score;
    int score_add;
    int score_counter;

    DirectX::XMFLOAT2     reset_scale = { 0.45,0.45 };
    DirectX::XMFLOAT2     reset_pos = { 90,650 };
    DirectX::XMFLOAT2     reset_center = { 200, 100 };

    //ボム関連
    int bomb_typenum[BOMB_TYPE_MAX];
    int bomb_trun[BOMB_ROTATE_MAX];
    int bomb_waitingarea;
    bool bomb_notset = false;
    bool bomb_release = false;
    bool bomb_reset = false;
    bool bomb_movingtype = false;
    bool bomb_roopchecker = false;

    //右、左クリックなどをしているか否か
    bool isClickL;
    bool isClickR;
    bool isZ;
    bool isX;
    bool isC;

    Effect burningFuse;

    std::unique_ptr<Focus> focuses[2];

    bool moveStageFlags[STAGE_NUM];

    int nowStage = 0;

    std::unique_ptr<StageMover> stageMovers[STAGE_NUM];

    std::unique_ptr<TextBox> textBoxes[4];

    int tutorialNum;

    bool isTutorialClear[STAGE_NUM];

    bool isDrawStage[STAGE_NUM];

    int stageAct[STAGE_NUM];

    bool isReset;
};