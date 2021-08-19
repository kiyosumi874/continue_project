//----------------------------------------------------------------------------------//
// @file         BGM.h
// @brief        BGMクラス
// @note                       
// @author       椎原 清澄 (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 8/18    新規作成
//----------------------------------------------------------------------------------//

#pragma once

class BGM
{
public:
	BGM();
	~BGM();
	void        Play();                                 // ミュージック再生
	void		Stop();                                 // 再生ストップ
	void        FadeInMusic(int _fadeInTime, float _deltaTime);            // ミュージックフェードイン
	void		FadeOutMusic(int _fadeOutTime, float _deltaTime);          // ミュージックフェードアウト
	void        LoadMusic(const char* _fileName); // ミュージック読み込み
	bool		IsPlaying();                            // 現在ミュージックは再生中か？


private:
	int mSHandle;      // 音量を設定する音の識別番号(サウンドハンドル)
	int mVolumePal;    // 設定する音量(0 ～ 255)
};