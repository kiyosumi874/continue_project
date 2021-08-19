//----------------------------------------------------------------------------------//
// @file         SE.h
// @brief        SEクラス
// @note                       
// @author       椎原 清澄 (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 8/18    新規作成
//----------------------------------------------------------------------------------//

#pragma once

class SE
{

public:
	SE();
	~SE();
	void          Play();       // 再生
	void          Stop();       // ストップ
	void          LoadSound(const char *_fileName); // サウンドファイル読み込み
	bool          IsPlaying();  // 現在再生中か？

private:
	int           mSHandle;      // 再生Handle
};
