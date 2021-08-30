//-----------------------------------------------------------------------+
// エフェクトクラス                         
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+

// インクルードファイル
#include "Effect.h"

// コンストラクタ
Effect::Effect(const char* sourceEffectHandle)
	:m_effectHandle(-1)
	, m_playPos(VGet(0, 0, 0))
	, m_playingEffect(-1)
{
	// モデルのロード
	m_effectHandle = LoadEffekseerEffect(sourceEffectHandle, 1.5f);
	if (m_effectHandle == -1)
	{
		printfDx("エフェクト読み込み失敗");
	}

}

// コンストラクタ2 (スケール指定)
Effect::Effect(const char* sourceEffectHandle, float _scale)
	:m_effectHandle(-1)
	, m_playPos(VGet(0, 0, 0))
	, m_playingEffect(-1)
{
	// モデルのロード
	m_effectHandle = LoadEffekseerEffect(sourceEffectHandle, _scale);
	if (m_effectHandle == -1)
	{
		printfDx("エフェクト読み込み失敗");
	}

}

// デストラクタ
Effect::~Effect()
{
	// 処理なし
}


// 解放処理
void Effect::Delete()
{
	StopEffect2D();
	StopEffect3D();
	DeleteEffekseerEffect(m_effectHandle);
}

// エフェクトの再生を止める
void Effect::StopEffect2D()
{
	StopEffekseer2DEffect(m_playingEffect);
	m_playingEffect = IsEffekseer2DEffectPlaying(m_playingEffect);
}

// エフェクトの再生を止める
void Effect::StopEffect3D()
{
	StopEffekseer3DEffect(m_playingEffect);
	m_playingEffect = IsEffekseer3DEffectPlaying(m_playingEffect);
}
/// <summary>
/// 3Dエフェクトを再生中かを調べる
/// </summary>
/// <returns> 再生中：0, それ以外：1 </returns>
const int Effect::GetNowPlaying3D()
{
	return IsEffekseer3DEffectPlaying(m_playingEffect);
}

/// <summary>
/// 2Dエフェクトを再生中かを調べる
/// </summary>
/// <returns> 再生中：0, それ以外：1 </returns>
const int Effect::GetNowPlaying2D()
{
	return IsEffekseer2DEffectPlaying(m_playingEffect);
}


/// <summary>
/// 再生中のエフェクトの座標を変える
/// </summary>
/// <param name="_size"></param>
void Effect::SetPlayingEffectPos(const VECTOR& _playPos)
{
	SetPosPlayingEffekseer3DEffect(m_playingEffect, _playPos.x, _playPos.y, _playPos.z);
}

/// <summary>
/// 再生中エフェクトの回転
/// </summary>
/// <param name="_dirVec"></param>
void Effect::SetPlayingEffectRotation(const VECTOR& _dirVec)
{
	SetRotationPlayingEffekseer3DEffect(m_playingEffect, _dirVec.x, _dirVec.y, _dirVec.z);
}

// Effekseer3Dの描画
void Effect::PlayEffekseer(const VECTOR in_playPos)
{
	// printfDx(" (X座標 : %f, Y座標 : %f, Z座標 : %f ", in_playPos.x, in_playPos.y, in_playPos.z);

	// printfDx("エフェクト再生");

	// エフェクトの座標を更新
	m_playPos = in_playPos;

	// エフェクトの描画
	m_playingEffect = PlayEffekseer3DEffect(m_effectHandle);

	// エフェクトを再生する座標を指定
	SetPosPlayingEffekseer3DEffect(m_playingEffect, m_playPos.x, m_playPos.y, m_playPos.z);
}


// Effekseer3Dのサイズを指定した再生
void Effect::ChangeSizePlayEffekseer(const VECTOR in_playPos, const VECTOR in_size)
{
	// エフェクトの座標更新
	m_playPos = in_playPos;

	// エフェクトの描画
	m_playingEffect = PlayEffekseer3DEffect(m_effectHandle);

	// エフェクトのサイズを設定
	SetScalePlayingEffekseer3DEffect(m_playingEffect, in_size.x, in_size.y, in_size.z);

	// エフェクトを再生する座標を指定
	SetPosPlayingEffekseer3DEffect(m_playingEffect, m_playPos.x, m_playPos.y, m_playPos.z);

}

void Effect::PlayEffekseer2D(const VECTOR in_playPos)
{
	// エフェクトの座標を更新
	m_playPos = in_playPos;

	// エフェクトの描画
	m_playingEffect = PlayEffekseer2DEffect(m_effectHandle);

	// エフェクトを再生する座標を指定
	SetPosPlayingEffekseer2DEffect(m_playingEffect, m_playPos.x, m_playPos.y, m_playPos.z);

}
