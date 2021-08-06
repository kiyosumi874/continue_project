//----------------------------------------------------------------------------------//
// @file         UIBase.h
// @brief        UIBaseクラス
// @note         UIBaseクラス
// @author       椎原 清澄 (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/31    新規作成
//----------------------------------------------------------------------------------//

#pragma once

// UIベースクラス
class UIBase
{
public:
	         UIBase()   ;    // コンストラクタ
	virtual ~UIBase() {};    // 仮想デストラクタ

	virtual void Update(float _deltaTime) = 0;    // シーンの更新処理 (オーバーライド必須)
	virtual void Draw()                   = 0;    // シーンの描画処理 (オーバーライド必須)
	virtual void Load()                   = 0;    // 初期化 (オーバーライド必須)
protected:
	float mDeltaTime;    // デルタタイム
	int   mHandle;       // ハンドル格納変数
};