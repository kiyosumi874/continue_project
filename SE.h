//----------------------------------------------------------------------------------//
// @file         SE.h
// @brief        SE�N���X
// @note                       
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 8/18    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once

class SE
{

public:
	SE();
	~SE();
	void          Play();       // �Đ�
	void          Stop();       // �X�g�b�v
	void          LoadSound(const char *_fileName); // �T�E���h�t�@�C���ǂݍ���
	bool          IsPlaying();  // ���ݍĐ������H

private:
	int           mSHandle;      // �Đ�Handle
};
