//----------------------------------------------------------------------------------//
// @file         ResultScene.h
// @brief        ResultSceneクラス
// @note         継承元:SceneBaseクラス              
// @author       椎原 清澄 (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/29    新規作成
// 2021/ 8/25    cameraとplayerのクラスを追加
//----------------------------------------------------------------------------------//

#pragma once
#include "SceneBase.h"

class ResultScene : public SceneBase
{
public:
    ResultScene(int _score);    // コンストラクタ
    ~ResultScene();    // デストラクタ

    SceneBase* Update(float _deltaTime, int& _hiScore)override;    // 更新
    void       Draw()                  override;    // 描画
    void       Sound(float _deltaTime)                 override;    // 音楽
    void       Load()                  override;    // 初期化
private:
    class Camera* mCamera;
    class ResultUI* mResultUI;        // リザルトUIクラスへのポインタメンバ変数
    class PlayerActor* mPlayer;
    class AudienceContoroller* mAudience;
    class StaticObjectActor* mPodium;
    class StaticObjectActor* mPool;
    class StaticObjectActor* mSky;
    class Effect* mFireWorks;
    class Effect* mConfetti;     //紙吹雪
    class WaterObject* mWater;

    bool  mInputReturnFlag;   // Enterキーの連続入力防止
    int mScore;

    int mMoveSceneHandle;
    float mAlphaPal;
    bool mAlphaPalFlag;
    bool mCheckHitFlag;

    int mFadeSpeed;

    float mCameraPosX;
    float mCameraPosY;
    float mCameraPosZ;
    float mCameraTargetPosX;
    float mCameraTargetPosY;
    float mCameraTargetPosZ;

    VECTOR mFireWorksPos;
    VECTOR mConfettiPos;
    VECTOR mFirstPlace;
    VECTOR mSecondPlace;
    VECTOR mThirdPlace;

};

