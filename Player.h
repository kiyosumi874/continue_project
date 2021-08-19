//----------------------------------------------------------------------------------//
// @file         Player.h
// @brief        Player�N���X
// @note                       
// @author       ��� �Č� (shougo iguchi, @2021)
// @changelog
// 2021/ 8/7     �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once
#include "DxLib.h"
class Player
{
public:

	 Player();    // �R���X�g���N�^
	~Player();    // �f�X�g���N�^

	void Update(float _deltaTime);    // �X�V
	void Draw()                  ;    // �`��
	void Load()                  ;    // ������

	const VECTOR& PlayerGetPosition() const{return mPlayerPos;}

private:
	float mDeltaTime;    // �f���^�^�C��
	// �L�����\��
	VECTOR mPlayerPos;
	VECTOR mScale;   // ���f���̊g��l
	int mModelHandle;
	int mAttachIndex;
	float mTotalTime;
	float mPlayTime;
	bool mJumpFlag;
};