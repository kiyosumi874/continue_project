//----------------------------------------------------------------------------------//
// @file         PlayScene.h
// @brief        PlaySceneクラス
// @note         継承元:SceneBaseクラス              
// @author       椎原 清澄 (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/29    新規作成
//----------------------------------------------------------------------------------//

#pragma once
#include "DxLib.h"
#include "SceneBase.h"

enum class GAME_MODE_STATE : unsigned char
{
    FADE_IN,
    CAMERA_MOVE,
    WAIT,
    CIRCLE_GAME,
    GAUGE_GAME,
    PENDULUM_GAME,
    GAYA,
    FADE_OUT
};

class PlayScene : public SceneBase
{
public:
    PlayScene();    // コンストラクタ
    PlayScene(float _deltaTime);    // コンストラクタ
    ~PlayScene();    // デストラクタ

    SceneBase* Update(float _deltaTime, int& _hiScore)override;    // 更新
    void       Draw()                  override;    // 描画
    void       Sound(float _deltaTime) override;    // 音楽
    void       Load()                  override;    // 初期化

private:
    void GameModeFadeInBehavior(float _deltaTime);
    void GameModeCameraMoveBehavior(float _deltaTime);
    void GameModeWaitBehavior(float _deltaTime);
    void GameModeCircleGameBehavior(float _deltaTime);
    void GameModeGaugeGameBehavior(float _deltaTime);
    void GameModePendulumGameBehavior(float _deltaTime);
    void GameModeGayaBehavior(float _deltaTime);
    void GameModeFadeOutBehavior(float _deltaTime);

    void LoadEX(int& _tmp, short& _count, int _handle);

    GAME_MODE_STATE mGameMode;

    //class PlayCamera* mPlayCamera;    // プレイカメラクラスへのポインタメンバ変数
    class Camera* mCamera;
    class PlayUI* mPlayUI;    // プレイUIクラスへのポインタメンバ変数
    class BGM* mBGM;
    //class BGM* mBGM2;
    class Audience* mAudience;       //観客へのポインタ
    //class Audience* mAudience2;       //観客へのポインタ
    class StaticObjectActor* mPool;
    class StaticObjectActor* mSky;
    class PlayerActor* mPlayer;
    class SE* mMetoronome;
    class SE* mClickNormal;
    class SE* mClickClitical;
    class SE* mKansei;
    class SE* mGayaGaya;
    class WaterObject* mWater;
    class Effect* mSmalleSplash;
    class Effect* mNormalSplash;
    class Effect* mBigSplash;
    class Effect* mFeather;
    VECTOR       mTargetPos;        //カメラの見ている座標

    bool  mInputReturnFlag;    // Enterキーの連続入力防止
    float mDeltaTime;
    int   mScore;

    int mStopCount;

    int mMoveSceneHandle;
    float mAlphaPal;
    bool mAlphaPalFlag;
    int mFadeSpeed;

    bool mBGMFlag;
    bool mBGMFlag2;

    bool mFlag;
    bool mFlag2;
    bool mFlag3;

    int mGameWaitCount;

    float mJumpPower;

    int mFontHandle;
    int mHandle;
};
