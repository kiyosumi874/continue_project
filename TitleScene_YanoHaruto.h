//----------------------------------------------------------------------------------//
// @file         TitleScene_YanoHaruto.h
// @brief        TitleScene_YanoHarutoクラス
// @note         継承元:SceneBaseクラス              
// @author       椎原 清澄 (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/29    新規作成 8/30 矢野　タイトルシーンから
//----------------------------------------------------------------------------------//

#pragma once
#include "SceneBase.h"
extern const float FIRST_DELTA_TIME;
extern const char* MOVE_SCENE_IMG;
extern const char* PLAYER_MODEL_HANDLE;
extern const char* SOUND_CLICK_HANDLE;

class TitleScene_YanoHaruto : public SceneBase
{
public:

    TitleScene_YanoHaruto();    // コンストラクタ
    ~TitleScene_YanoHaruto();    // デストラクタ

    SceneBase* Update(float _deltaTime)override;    // 更新
    void       Draw()                  override;    // 描画
    void       Sound()                 override;    // 音楽
    void       Load()                  override;    // 初期化

private:
    class Camera* mCamera;
    class TitleUI* mTitleUI;    // タイトルUIクラスへのポインタメンバ変数
    class BGM* mBGM;
    class SE* mClickNormal;
    class PlayerActor* mPlayer;
    float mDeltaTime;          // デルタタイム
    bool mBGMFlag;
    bool  mInputReturnFlag;    // Enterキーの連続入力防止
    bool mClickNormalFlag;
    // スタートボタンのフラグ
    bool mStartButtonFlag;

    // スタートボタンを押したときのラグを作るCount
    float mSceneTransitionCount;


    int mMoveSceneHandle;
    int mAlphaPal;
    bool mAlphaPalFlag;

    int mFadeSpeed;

};
