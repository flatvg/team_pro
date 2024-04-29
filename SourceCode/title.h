#ifndef INCLUDED_TITLE
#define	INCLUDED_TITLE

//******************************************************************************
//
//
//      タイトルシーン
//
//
//******************************************************************************

//==============================================================================
//
//      Titleクラス
//
//==============================================================================

class Title : public Scene
{
public:
    static Title* instance() { return &instance_; }

    void init();
    void deinit();
    void update();
    void draw();
    void draw_init_status();

private:
    static Title instance_;

    VECTOR2 cursorPos;
    VECTOR2 correctPos = { -60.0f,-72.0f };
    DirectX::XMVECTOR V1 = DirectX::XMVectorSet(0, 0, 0, 0);
    DirectX::XMVECTOR V3{};
    VECTOR2 circlePos;
    bool angleflag = false;
    float angle = 0.0f;

    struct draw_texture
    {
        DirectX::XMFLOAT2 position;
        DirectX::XMFLOAT2 scale;
        DirectX::XMFLOAT2 center;
        DirectX::XMFLOAT4 color;
        float angle;
    };

    draw_texture title_draw;
    draw_texture game_draw;
    draw_texture tutorial_draw;
    float title_timer;
    float A_timer;
    float slide_x;
};

//******************************************************************************

#endif // !INCLUDED_TITLE
