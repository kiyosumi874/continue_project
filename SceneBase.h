//----------------------------------------------------------------------------------//
// @file         SceneBase.h
// @brief        SceneBaseクラス
// @note         SceneBaseクラス
// @author       椎原 清澄 (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/29    新規作成
//----------------------------------------------------------------------------------//

#pragma once

// シーンベースクラス
class SceneBase
{
public:
	         SceneBase()   ;    // コンストラクタ
	virtual ~SceneBase() {};    // 仮想デストラクタ

	virtual SceneBase* Update(float _deltaTime, int& _hiScore) = 0;    // シーンの更新処理 (オーバーライド必須)
	virtual void       Draw()                   = 0;    // シーンの描画処理 (オーバーライド必須)
	virtual void       Sound(float _deltaTime)  = 0;    // 音楽	  (オーバーライド必須)
	virtual void       Load()                   = 0;    // 初期化 (オーバーライド必須)

	protected:
	int mVolumePal     ;    // 音量
	int mNormalFontSize;    // フォントサイズ
};