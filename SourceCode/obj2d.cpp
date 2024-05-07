//******************************************************************************
//
//
//      OBJ2Dクラス
//
//
//******************************************************************************

//------< インクルード >----------------------------------------------------------
#include "obj2d.h"
#include "..//GameLib/util.h"
#include "..//GameLib/game_lib.h"

using namespace GameLib;

//--------------------------------------------------------------
//  コンストラクタ
//--------------------------------------------------------------
OBJ2D::OBJ2D(
    Renderer* renderer,
    Collider* collider,
    BG* bg,
    ActorComponent* actorComponent,
    ItemComponent* itemComponent,
    WeaponComponent* weaponComponent
)
    :transform_(new Transform)
    , renderer_(renderer)
    , collider_(collider)
    , bg_(bg)
    , actorComponent_(actorComponent)
    , itemComponent_(itemComponent)
    , weaponComponent_(weaponComponent)
{
    if (transform_) transform_->setOBJ2D(this);
    if (renderer_) renderer_->setOBJ2D(this);
    if (collider_) collider_->setOBJ2D(this);
    if (actorComponent_) actorComponent_->setOBJ2D(this);
    if (itemComponent_) itemComponent_->setOBJ2D(this);
    if (weaponComponent_) weaponComponent_->setOBJ2D(this);
}

//--------------------------------------------------------------
//  デストラクタ
//--------------------------------------------------------------
OBJ2D::~OBJ2D()
{
    safe_delete(transform_);
    safe_delete(weaponComponent_);
    safe_delete(itemComponent_);
    safe_delete(actorComponent_);
    safe_delete(collider_);
    safe_delete(renderer_);
}

//--------------------------------------------------------------
//  移動
//--------------------------------------------------------------
void OBJ2D::move()
{
    if (behavior_) behavior_->move(this);
    if (eraser_) eraser_->erase(this);
}

//--------------------------------------------------------------
//  描画
//--------------------------------------------------------------
void Renderer::draw(const VECTOR2& scrollPos)
{
    if (data_)
    {
        data_->draw(obj_->transform_->position_ - scrollPos,
            obj_->transform_->scale_, obj_->transform_->rotation_, color_);  // dataのdrawメソッドでスプライトを描画する
    }
}

//--------------------------------------------------------------
//  アニメーション更新
//--------------------------------------------------------------
//  戻り値：true  アニメが先頭に戻る瞬間
//        :false それ以外
//--------------------------------------------------------------
bool Renderer::animeUpdate()
{
    if (animeData_ == nullptr)
    {
        assert(!"animeUpdate関数でAnimeDataがnullptr");
        return false;
    }

    if (anime_.pPrev != animeData_)         // アニメデータが切り替わったとき
    {
        anime_.pPrev = animeData_;
        anime_.patNum = 0;	                // 先頭から再生
        anime_.frame = 0;
    }

    animeData_ += anime_.patNum;
    data_ = animeData_->data;               // 現在のパターン番号に該当する画像を設定

    anime_.frame++;
    if (anime_.frame >= animeData_->frame)  // 設定フレーム数表示したら
    {
        anime_.frame = 0;
        anime_.patNum++;                    // 次のパターンへ
        if ((animeData_ + 1)->frame < 0)    // 終了コードのとき
        {
            anime_.patNum = 0;              // 先頭へ戻る
            return true;
        }
    }

    return false;
}

//******************************************************************************
//
//
//      OBJ2DManagerクラス
//
//
//******************************************************************************

//--------------------------------------------------------------
//  初期化
//--------------------------------------------------------------
void OBJ2DManager::init()
{
    //リストのOBJ2Dを全てクリアする
    objList_.clear();
}

//--------------------------------------------------------------
//  リストへ追加
//--------------------------------------------------------------
OBJ2D* OBJ2DManager::add(OBJ2D* obj, Behavior* behavior, const VECTOR2& pos)
{
    obj->behavior_ = behavior;           // behavior_に引数のbehaviorを代入
    obj->transform_->position_ = pos;                // position_に引数のposを代入

    objList_.emplace_back(obj);            // リストにobjを追加する
    return obj;       // 今追加したobjのアドレスを返す（何かで使えるように）
}

OBJ2D* OBJ2DManager::insert(std::list<OBJ2D*>::iterator& iter, OBJ2D* obj, Behavior* behavior, const VECTOR2& pos)
{
    obj->behavior_ = behavior;
    obj->transform_->position_ = pos;
    objList_.insert(iter, obj);
    return obj;
}

//--------------------------------------------------------------
//  更新
//--------------------------------------------------------------
void OBJ2DManager::update()
{
    // 移動
    for (auto& obj : objList_)   // objListの全ての要素をループし、itという名前で各要素にアクセス
    {
        obj->move();              // itのmoveメソッドを呼ぶ
    }

    // 空ノードの削除
    auto iter = objList_.begin();
    while (iter != objList_.end())
    {
        if ((*iter)->behavior_)
        {
            iter++;
        }
        else
        {
            safe_delete(*iter);
            iter = objList_.erase(iter);
        }
    }
}

//--------------------------------------------------------------
//  描画
//--------------------------------------------------------------
bool predFunc(OBJ2D* obj1, OBJ2D* obj2)
{
    return obj1->zOrder_ < obj2->zOrder_;
}

void OBJ2DManager::draw(const VECTOR2& scrollPos)
{
    constexpr float LIMIT = 256.0f;

    objList_.sort([](OBJ2D* obj1, OBJ2D* obj2) {return obj1->zOrder_ < obj2->zOrder_; });

    for (auto& obj : objList_)
    {
        const VECTOR2 screenPos = obj->transform_->position_ - scrollPos;
        if (screenPos.x < -LIMIT ||
            screenPos.x > window::getWidth() + LIMIT ||
            screenPos.y < -LIMIT ||
            screenPos.y > window::getHeight() + LIMIT)
            continue;

        obj->renderer_->draw(scrollPos);

        obj->collider_->draw(scrollPos);
    }
}

//--------------------------------------------------------------
//  デストラクタ
//--------------------------------------------------------------
OBJ2DManager::~OBJ2DManager()
{
    // メモリを解放する
    for (auto& obj : objList_)
    {
        safe_delete(obj);
    }

    // リストのOBJ2Dを全てクリアする
    objList_.clear();
}

void Collider::draw(const VECTOR2& scrollPos)
{
    if (isDrawHitRect_)
    {
        VECTOR2 pos = VECTOR2(hitBox_.left, hitBox_.top) - scrollPos;
        VECTOR2 size = { hitBox_.right - hitBox_.left, hitBox_.bottom - hitBox_.top };
        VECTOR2 center{ 0, 0 };
        VECTOR4 blue{ 0,0,1,0.5f };
        primitive::rect(pos, size, center, 0, blue);
    }

    if (isDrawAttackRect_)
    {
        VECTOR2 pos = VECTOR2(attackBox_.left, attackBox_.top) - scrollPos;
        VECTOR2 size = { attackBox_.right - attackBox_.left, attackBox_.bottom - attackBox_.top };
        VECTOR2 center{ 0, 0 };
        VECTOR4 red{ 1,0,0,0.5f };
        primitive::rect(pos, size, center, 0, red);
    }
}

void Collider::calcHitBox(const GameLib::fRECT& rc)
{
    hitBox_ = {
        obj_->transform_->position_.x + rc.left,
        obj_->transform_->position_.y + rc.top,
        obj_->transform_->position_.x + rc.right,
        obj_->transform_->position_.y + rc.bottom
    };
}

void Collider::calcAttackBox(const GameLib::fRECT& rc)
{
    attackBox_ = {
        obj_->transform_->position_.x + rc.left,
        obj_->transform_->position_.y + rc.top,
        obj_->transform_->position_.x + rc.right,
        obj_->transform_->position_.y + rc.bottom
    };
}

bool Collider::hitCheck(Collider* other)
{
    if (attackBox_.right < other->hitBox_.left ||
        attackBox_.left > other->hitBox_.right ||
        attackBox_.bottom < other->hitBox_.top ||
        attackBox_.top > other->hitBox_.bottom) return false;

    return true;
}

bool Collider::hitCheck(OBJ2D* obj)
{
    return hitCheck(obj->collider_);
}

void ActorComponent::damaged()
{
    if (damageTimer_ <= 0)return;

    padTrg_ = 0;
    padState_ = 0;
    --damageTimer_;
}


void ActorComponent::muteki()
{
    if (mutekiTimer_ <= 0)return;

    VECTOR4 color = obj_->renderer_->color_;
    color.w = 0.0f;
    if (mutekiTimer_ & 0x01)
        color.w = 1.0f;
    obj_->renderer_->color_ = color;

    --mutekiTimer_;
}
