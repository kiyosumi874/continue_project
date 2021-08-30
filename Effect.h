//-----------------------------------------------------------------------+
// �G�t�F�N�g�N���X                         
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+
#pragma once

// �C���N���[�h�t�@�C��
#include "DxLib.h"
#include "EffekseerForDXLib.h"


class Effect
{

public:

	Effect(const char* sourceEffectHandle);
	Effect(const char* sourceEffectHandle, float _scale);
	~Effect();

	void Delete();

	// Efekseer3D�̒P���Đ�
	void PlayEffekseer(const VECTOR in_playPos);

	// Effekseer3D�̃T�C�Y���w�肵���Đ�
	void ChangeSizePlayEffekseer(const VECTOR in_playPos, const VECTOR in_size);

	// 2D��Effekseer�Đ�
	void PlayEffekseer2D(const VECTOR in_playPos);

	void StopEffect2D();
	void StopEffect3D();

	const int GetNowPlaying2D();    // �G�t�F�N�g���Đ������ǂ���(0:�Đ���  1:�Đ�����Ă��Ȃ�)
	const int GetNowPlaying3D();    // �G�t�F�N�g���Đ������ǂ���(0:�Đ���  1:�Đ�����Ă��Ȃ�)

	// �Đ����̃G�t�F�N�g�̍��W�Z�b�^�[
	void SetPlayingEffectPos(const VECTOR& _playPos);

	// �Đ����G�t�F�N�g�̉�]�l�Z�b�^�[
	void SetPlayingEffectRotation(const VECTOR& _dirVec);

	// �Đ����̃G�t�F�N�g�̊g�嗦��ύX����
	void SetPlayingEffectScale(const float in_sizeX, const float in_sizeY, const float in_sizeZ) { SetScalePlayingEffekseer3DEffect(m_playingEffect, in_sizeX, in_sizeY, in_sizeZ); }

private:

	VECTOR m_playPos;          // �G�t�F�N�g�̍��W

	int m_effectHandle;        // ��_���[�W�G�t�F�N�g�̃n���h��
	int m_playingEffect;
};