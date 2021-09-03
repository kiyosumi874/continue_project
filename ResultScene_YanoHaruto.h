#pragma once
#include "SceneBase.h"

/// <summary>
/// 8/27エフェクト追加　by矢野陽大
/// </summary>
/// 
#define FIREWORKS 4
#define CONFETTIES  3
class ResultScene_YanoHaruto : public SceneBase
{
public:
    ResultScene_YanoHaruto(int _score);    // コンストラクタ
    ~ResultScene_YanoHaruto();             // デストラクタ

    SceneBase* Update(float _deltaTime)override;    // 更新
    void       Draw()                  override;    // 描画
    void       Sound()                 override;    // 音楽
    void       Load()                  override;    // 初期化
private:
    class Camera*                      mCamera;
    class PlayerActor*                 mPlayer;
    class PlayEffect*                  mFireWork[FIREWORKS]; //花火
    class PlayEffect*                  mConfetti[CONFETTIES];//紙吹雪
    class StaticObjectActor*           mPool;                //プールのポインタ
    class ResultCamera*                mResultCamera;    // リザルトカメラクラスへのポインタメンバ変数
    class ResultUI*                    mResultUI;        // リザルトUIクラスへのポインタメンバ変数
    class StaticObjectActor*           mStaticObjectActor;
    float mDeltaTime;         // デルタタイム
    bool  mInputReturnFlag;   // Enterキーの連続入力防止
    int mScore;

    int mMoveSceneHandle;
    float mAlphaPal;
    bool mAlphaPalFlag;
    bool mCheckHitFlag;

    int mFadeSpeed;
};
