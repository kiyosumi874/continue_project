//----------------------------------------------------------------------------------//
// @file         TitleSound.h
// @brief        TitleSoundクラス
// @note         TitleSoundクラス             
// @author       椎原 清澄 (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 8/ 7    新規作成
//----------------------------------------------------------------------------------//

#pragma once

class TitleSound
{
public:
	TitleSound();    // コンストラクタ
	~TitleSound();    // デストラクタ

	void Update();    // 更新
	void Play();    // 曲をかける
	void Load();    // ロード

private:

};