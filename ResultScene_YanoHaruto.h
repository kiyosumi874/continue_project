#pragma once
#pragma once
#include "SceneBase.h"

class ResultScene_YanoHaruto : public SceneBase
{
public:
    ResultScene_YanoHaruto();    // コンストラクタ
    ~ResultScene_YanoHaruto();    // デストラクタ

    SceneBase* Update(float _deltaTime)override;    // 更新
    void       Draw()                  override;    // 描画
    void       Sound()                 override;    // 音楽
    void       Load()                  override;    // 初期化
private:
    float mDeltaTime;         // デルタタイム
    bool  mInputReturnFlag;   // Enterキーの連続入力防止
};

