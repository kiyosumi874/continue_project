#include "DxLib.h"
#include "BGM.h"

/// <summary>
/// 初期化
/// </summary>
BGM::BGM()
	: mSHandle(-1)
	, mVolumePal(0)
{
}

/// <summary>
/// 後処理
/// </summary>
BGM::~BGM()
{
	DeleteSoundMem(mSHandle);
}

/// <summary>
/// ミュージック再生
/// </summary>
void BGM::Play()
{
	PlaySoundMem(mSHandle, DX_PLAYTYPE_LOOP);
}

/// <summary>
/// 再生ストップ
/// </summary>
void BGM::Stop()
{
	StopSoundMem(mSHandle);
}

/// <summary>
/// ミュージックフェードイン
/// </summary>
/// <param name="_fadeInTime">フェードインにかける時間</param>
/// <param name="_deltaTime">デルタタイム</param>
void BGM::FadeInMusic(int _fadeInTime, float _deltaTime)
{
	mVolumePal += _fadeInTime * _deltaTime;
	ChangeVolumeSoundMem(mVolumePal, mSHandle);
}

/// <summary>
/// ミュージックフェードアウト
/// </summary>
/// <param name="_fadeOutTime">フェードアウトにかける時間</param>
/// <param name="_deltaTime">デルタタイム</param>
void BGM::FadeOutMusic(int _fadeOutTime, float _deltaTime)
{
	mVolumePal -= _fadeOutTime * _deltaTime;
	ChangeVolumeSoundMem(mVolumePal, mSHandle);
}

/// <summary>
/// ミュージック読み込み
/// </summary>
/// <param name="_fileName">メモリに読みこむ音ファイルのファイル名</param>
void BGM::LoadMusic(const char* _fileName)
{
	mSHandle = LoadSoundMem(_fileName);
}

/// <summary>
/// 現在ミュージックは再生中か？
/// </summary>
/// <returns>再生中ならTRUEを返す</returns>
bool BGM::IsPlaying()
{
	return CheckSoundMem(mSHandle);
}
