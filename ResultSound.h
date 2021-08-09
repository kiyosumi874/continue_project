//----------------------------------------------------------------------------------//
// @file         ResultSound.h
// @brief        ResultSoundクラス
// @note         ResultSoundクラス             
// @author       椎原 清澄 (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 8/ 7    新規作成
//----------------------------------------------------------------------------------//

#pragma once

class ResultSound
{
public:
	ResultSound();    // コンストラクタ
	~ResultSound();    // デストラクタ

	void Update();    // 更新
	void Play();    // 曲をかける
	void Load();    // ロード

private:

};