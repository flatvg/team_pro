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

	void update();
	void draw();

private:
    static Title instance_;

    
    VECTOR2 cursorPos;
    VECTOR2 correctPos = { -60.0f,-72.0f };
    DirectX::XMVECTOR V1 = DirectX::XMVectorSet(0, 0, 0, 0);
    DirectX::XMVECTOR V3{};
    VECTOR2 circlePos;
    bool angleflag = false;
    float angle = 0.0f;
};

//******************************************************************************

#endif // !INCLUDED_TITLE
