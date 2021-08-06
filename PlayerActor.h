//----------------------------------------------------------------------------------//
// @file         PlayerActor.h
// @brief        PlayerActor�N���X
// @note         PlayerActor�N���X
// @author       ��� �Č� (iguchi shougo, @2021)
// @changelog
// 2021/ 8/1    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once

class PlayerActor
{
public:
	 PlayerActor();    // �R���X�g���N�^
	~PlayerActor();    // �f�X�g���N�^

	void Update(float _deltaTime);    // �X�V����
	void   Draw()                ;    // �`�揈��
	void   Init()                ;    // ����������

private:
	VECTOR mPlayerPos;    // �v���C���[�̃|�W�V����
	VECTOR mVelocity ;    // �ړ������x
	VECTOR mMove     ;    // �ړ����x

	int mModelHandle ;    // ���f���n���h��
};