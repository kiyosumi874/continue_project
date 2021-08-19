#include "DxLib.h"
#include "SE.h"

/// <summary>
/// ������
/// </summary>
SE::SE()
	: mSHandle(-1)
{
}

/// <summary>
/// �㏈��
/// </summary>
SE::~SE()
{
	DeleteSoundMem(mSHandle);
}

/// <summary>
/// �T�E���h�Đ�
/// </summary>
void SE::Play()
{
	PlaySoundMem(mSHandle, DX_PLAYTYPE_BACK);
}

/// <summary>
/// �T�E���h�X�g�b�v
/// </summary>
void SE::Stop()
{
	StopSoundMem(mSHandle);
}

/// <summary>
/// �~���[�W�b�N�ǂݍ���
/// </summary>
/// <param name="_fileName">�������ɓǂ݂��މ��t�@�C���̃t�@�C����</param>
void SE::LoadSound(const char* _fileName)
{
	mSHandle = LoadSoundMem(_fileName);
}

/// <summary>
/// ���݃~���[�W�b�N�͍Đ������H
/// </summary>
/// <returns>�Đ����Ȃ�TRUE��Ԃ�</returns>
bool SE::IsPlaying()
{
	// �Đ����Ȃ�TRUE��Ԃ�
	return CheckSoundMem(mSHandle);
}
