#include "DxLib.h"
#include "SE.h"

/// <summary>
/// 初期化
/// </summary>
SE::SE()
	: mSHandle(-1)
{
}

/// <summary>
/// 後処理
/// </summary>
SE::~SE()
{
	DeleteSoundMem(mSHandle);
}

/// <summary>
/// サウンド再生
/// </summary>
void SE::Play()
{
	PlaySoundMem(mSHandle, DX_PLAYTYPE_BACK);
}

/// <summary>
/// サウンドストップ
/// </summary>
void SE::Stop()
{
	StopSoundMem(mSHandle);
}

/// <summary>
/// ミュージック読み込み
/// </summary>
/// <param name="_fileName">メモリに読みこむ音ファイルのファイル名</param>
void SE::LoadSound(const char* _fileName)
{
	mSHandle = LoadSoundMem(_fileName);
}

/// <summary>
/// 現在ミュージックは再生中か？
/// </summary>
/// <returns>再生中ならTRUEを返す</returns>
bool SE::IsPlaying()
{
	// 再生中ならTRUEを返す
	return CheckSoundMem(mSHandle);
}
