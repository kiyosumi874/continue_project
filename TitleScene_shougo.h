//----------------------------------------------------------------------------------//
// @file         TitleScene_shougo.h
// @brief        TitleScene_shougoクラス
// @note         継承元:SceneBaseクラス              
// @author       井口 翔悟 (shougo iguchi, @2021)
// @changelog
// 2021/ 8/5    新規作成
//----------------------------------------------------------------------------------//

#pragma once
#include "SceneBase.h"

class TitleScene_shougo : public SceneBase
{
public:

    TitleScene_shougo();    // コンストラクタ
    ~TitleScene_shougo();    // デストラクタ

    SceneBase* Update(float _deltaTime)override;    // 更新
    void       Draw()                  override;    // 描画
    void       Sound()                 override;    // 音楽
    void       Load()                  override;    // 初期化

private:
    class TitleCamera* mTitleCamera;    // タイトルカメラクラスへのポインタメンバ変数
    class TitleUI* mTitleUI;    // タイトルUIクラスへのポインタメンバ変数
    float mDeltaTime;          // デルタタイム
    bool  mInputReturnFlag;    // Enterキーの連続入力防止
    // スタートボタンのフラグ
    bool mStartButtonFlag;

    // スタートボタンを押したときのラグを作るCount
    float mSceneTransitionCount;

    // キャラ表示デバッグ用
    int mHandle;
    float mRotate;
};
