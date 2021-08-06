//----------------------------------------------------------------------------------//
// @file         CameraBase.h
// @brief        CameraBaseクラス
// @note         CameraBaseクラス
// @author       井口 翔悟  (shougo iguchi, @2021)
// @changelog
// 2021/ 8/ 2    新規作成
//----------------------------------------------------------------------------------//

#pragma once

// UIベースクラス
class CameraBase
{
public:
	CameraBase() {};    // コンストラクタ
	virtual ~CameraBase() {};    // 仮想デストラクタ

	virtual void Update() = 0;    // シーンの更新処理 (オーバーライド必須)
	virtual void Draw() = 0;    // シーンの描画処理 (オーバーライド必須)
	virtual void Load() = 0;    // 初期化 (オーバーライド必須)
};
