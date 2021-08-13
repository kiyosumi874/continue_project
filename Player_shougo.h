//----------------------------------------------------------------------------------//
// @file         Player_shougo.h
// @brief        Player_shougo�N���X
// @note                       
// @author       ��� �Č� (shougo iguchi, @2021)
// @changelog
// 2021/ 8/7     �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once

class Player_shougo
{
public:

	 Player_shougo();    // �R���X�g���N�^
	~Player_shougo();    // �f�X�g���N�^

	void Update(float _deltaTime);    // �X�V
	void Draw()                  ;    // �`��
	void Load()                  ;    // ������

	const VECTOR& PlayerGetPosition() const{return mPlayerPos;}

private:
	float mDeltaTime;    // �f���^�^�C��
	// �L�����\��
	VECTOR mPlayerPos;
	int mModelHandle;
	int mAttachIndex;
	float mTotalTime;
	float mPlayTime;
	bool mJumpFlag;
};