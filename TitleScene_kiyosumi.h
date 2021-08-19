//----------------------------------------------------------------------------------//
// @file         TitleScene_kiyosumi.h
// @brief        TitleScene_kiyosumiクラス
// @note         継承元:SceneBaseクラス              
// @author       椎原 清澄 (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/31    新規作成
//----------------------------------------------------------------------------------//

#pragma once
#include "SceneBase.h"

class TitleScene_kiyosumi : public SceneBase
{
public:

     TitleScene_kiyosumi();    // コンストラクタ
    ~TitleScene_kiyosumi();    // デストラクタ

    SceneBase* Update(float _deltaTime)override;    // 更新
    void       Draw()                  override;    // 描画
    void       Sound()                 override;    // 音楽
    void       Load()                  override;    // 初期化

private:
    class TitleCamera* mTitleCamera;    // タイトルカメラクラスへのポインタメンバ変数
    class TitleUI*         mTitleUI;    // タイトルUIクラスへのポインタメンバ変数
    class BGM*                 mBGM;
    float mDeltaTime;          // デルタタイム
    bool mBGMFlag;
    bool  mInputReturnFlag;    // Enterキーの連続入力防止
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
};

