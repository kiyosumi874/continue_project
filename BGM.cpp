#include "DxLib.h"
#include "BGM.h"

/// <summary>
/// ������
/// </summary>
BGM::BGM()
	: mSHandle(-1)
	, mVolumePal(0)
{
}

/// <summary>
/// �㏈��
/// </summary>
BGM::~BGM()
{
	DeleteSoundMem(mSHandle);
}

/// <summary>
/// �~���[�W�b�N�Đ�
/// </summary>
void BGM::Play()
{
	PlaySoundMem(mSHandle, DX_PLAYTYPE_LOOP);
}

/// <summary>
/// �Đ��X�g�b�v
/// </summary>
void BGM::Stop()
{
	StopSoundMem(mSHandle);
}

/// <summary>
/// �~���[�W�b�N�t�F�[�h�C��
/// </summary>
/// <param name="_fadeInTime">�t�F�[�h�C���ɂ����鎞��</param>
/// <param name="_deltaTime">�f���^�^�C��</param>
void BGM::FadeInMusic(int _fadeInTime, float _deltaTime)
{
	mVolumePal += _fadeInTime * _deltaTime;
	ChangeVolumeSoundMem(mVolumePal, mSHandle);
}

/// <summary>
/// �~���[�W�b�N�t�F�[�h�A�E�g
/// </summary>
/// <param name="_fadeOutTime">�t�F�[�h�A�E�g�ɂ����鎞��</param>
/// <param name="_deltaTime">�f���^�^�C��</param>
void BGM::FadeOutMusic(int _fadeOutTime, float _deltaTime)
{
	mVolumePal -= _fadeOutTime * _deltaTime;
	ChangeVolumeSoundMem(mVolumePal, mSHandle);
}

/// <summary>
/// �~���[�W�b�N�ǂݍ���
/// </summary>
/// <param name="_fileName">�������ɓǂ݂��މ��t�@�C���̃t�@�C����</param>
void BGM::LoadMusic(const char* _fileName)
{
	mSHandle = LoadSoundMem(_fileName);
}

/// <summary>
/// ���݃~���[�W�b�N�͍Đ������H
/// </summary>
/// <returns>�Đ����Ȃ�TRUE��Ԃ�</returns>
bool BGM::IsPlaying()
{
	return CheckSoundMem(mSHandle);
}
