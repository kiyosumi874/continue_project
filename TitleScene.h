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

class TitleScene : public SceneBase
{
public:

    TitleScene();    // コンストラクタ
    ~TitleScene();    // デストラクタ

    SceneBase* Update(float _deltaTime)override;    // 更新
    void       Draw()                  override;    // 描画
    void       Sound()                 override;    // 音楽
    void       Load()                  override;    // 初期化

private:
    class TitleCamera* mTitleCamera;    // タイトルカメラクラスへのポインタメンバ変数
    class TitleUI* mTitleUI;    // タイトルUIクラスへのポインタメンバ変数
    class BGM* mBGM;
    class SE* mClickNormal;
    float mDeltaTime;          // デルタタイム
    bool mBGMFlag;
    bool  mInputReturnFlag;    // Enterキーの連続入力防止
    bool mClickNormalFlag;
    // スタートボタンのフラグ
    bool mStartButtonFlag;

    // スタートボタンを押したときのラグを作るCount
    float mSceneTransitionCount;

    // キャラ表示デバッグ用
    int mHandle;
    int mAttachIndex;
    float mTotalTime;
    float mPlayTime;
    float x, z;

    int mMoveSceneHandle;
    float mAlphaPal;
    bool mAlphaPalFlag;

    int mFadeSpeed;

};

