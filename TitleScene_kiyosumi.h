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
#include "TitleUI.h"

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
    TitleUI* mTitleUI;    // タイトルUIクラスへのポインタメンバ変数
    float mDeltaTime;          // デルタタイム
    bool  mInputReturnFlag;    // Enterキーの連続入力防止
    // スタートボタンのフラグ
    bool mStartButtonFlag;

    float mSceneTransitionCount;
};

