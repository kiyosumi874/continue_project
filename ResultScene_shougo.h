//----------------------------------------------------------------------------------//
// @file         ResultScene_shougo.h
// @brief        ResultScene_shougoクラス
// @note         継承元:SceneBaseクラス              
// @author       井口 翔悟 (shougo iguchi, @2021)
// @changelog
// 2021/ 8/2     新規作成
//----------------------------------------------------------------------------------//

#pragma once
#include "SceneBase.h"

class ResultScene_shougo : public SceneBase
{
public:
    ResultScene_shougo(int _score);    // コンストラクタ
    ~ResultScene_shougo();    // デストラクタ

    SceneBase* Update(float _deltaTime)override;    // 更新
    void       Draw()                  override;    // 描画
    void       Sound()                 override;    // 音楽
    void       Load()                  override;    // 初期化
private:
    class ResultCamera_shougo* mResultCamera;    // リザルトカメラクラスへのポインタメンバ変数
    class ResultUI* mResultUI;        // リザルトUIクラスへのポインタメンバ変数
    float mDeltaTime;         // デルタタイム
    bool  mInputReturnFlag;   // Enterキーの連続入力防止
    int mScore;
};


