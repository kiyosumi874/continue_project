//----------------------------------------------------------------------------------//
// @file         BGM.h
// @brief        BGM�N���X
// @note                       
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 8/18    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once

class BGM
{
public:
	BGM();
	~BGM();
	void        Play();                                 // �~���[�W�b�N�Đ�
	void		Stop();                                 // �Đ��X�g�b�v
	void        FadeInMusic(int _fadeInTime, float _deltaTime);            // �~���[�W�b�N�t�F�[�h�C��
	void		FadeOutMusic(int _fadeOutTime, float _deltaTime);          // �~���[�W�b�N�t�F�[�h�A�E�g
	void        LoadMusic(const char* _fileName); // �~���[�W�b�N�ǂݍ���
	bool		IsPlaying();                            // ���݃~���[�W�b�N�͍Đ������H


private:
	int mSHandle;      // ���ʂ�ݒ肷�鉹�̎��ʔԍ�(�T�E���h�n���h��)
	int mVolumePal;    // �ݒ肷�鉹��(0 �` 255)
};