//----------------------------------------------------------------------------------//
// @file         TitleScene.h
// @brief        TitleSceneクラス
// @note         継承元:SceneBaseクラス              
// @author       椎原 清澄 (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/29    新規作成
//----------------------------------------------------------------------------------//

#pragma once
#include "SceneBase.h"

extern const float FIRST_DELTA_TIME;
extern const char* MOVE_SCENE_IMG;
extern const char* PLAYER_MODEL_HANDLE;
extern const char* SOUND_CLICK_HANDLE;

class TitleScene : public SceneBase
{
public:

    TitleScene();    // コンストラクタ
    ~TitleScene();    // デストラクタ

    SceneBase* Update(float _deltaTime, int& _hiScore)override;    // 更新
    void       Draw()                  override;    // 描画
    void       Sound(float _deltaTime)                 override;    // 音楽
    void       Load()                  override;    // 初期化

private:
    class Camera* mCamera;
    class TitleUI* mTitleUI;    // タイトルUIクラスへのポインタメンバ変数
    class BGM* mBGM;
    class SE* mClickNormal;
    class PlayerActor* mPlayer;
    class StaticObjectActor* mSky;
    class StaticObjectActor* mPool;
    class AudienceContoroller* mAudience;       //観客へのポインタ
    //class Audience* mAudience2;       //観客へのポインタ
    class WaterObject* mWater;

    enum class CAMERA_TYPE : unsigned char
    {
        CAMERA_1,
        CAMERA_2,
        CAMERA_3
    };
    CAMERA_TYPE mCameraType;

    bool mBGMFlag;
    bool  mInputReturnFlag;    // Enterキーの連続入力防止
    bool mClickNormalFlag;
    // スタートボタンのフラグ
    bool mStartButtonFlag;

    // スタートボタンを押したときのラグを作るCount
    float mSceneTransitionCount;


    int mMoveSceneHandle;
    int mLightHandle;
    int mLightHandle2;
    int mLightHandle3;
    int mLightHandle4;
    int mAlphaPal;
    bool mAlphaPalFlag;

    int mFadeSpeed;
    int mGridHandle;

};

