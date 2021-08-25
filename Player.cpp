#include "Player.h"



/// <summary>
/// ������
/// </summary>
Player::Player()
//                          �Œ�   Player�̑O��
	: mPlayerPos(VGet(0.0f, 32.0f, -16.0f))
	, mDeltaTime(0.000001f)
	, mModelHandle(MV1LoadModel("data/model/player5/waterboy.pmx"))
	, mAttachIndex(NULL)
	, mTotalTime(NULL)
	, mPlayTime(0.0f)
	, mJumpFlag(false)
	, mScale(VGet(0.5f, 0.5f, 0.5f))
{
	MV1SetPosition(mModelHandle, mPlayerPos);
	MV1SetScale(mModelHandle, mScale);
	//MV1AttachAnim(mModelHandle,0,-1,FALSE)
	//MV1GetAttachAnimTotalTime(mModelHandle,mAttachIndex)
}

/// <summary>
/// �㏈��
/// </summary>
Player::~Player()
{
	MV1DeleteModel(mModelHandle);
	MV1DetachAnim(mModelHandle, mAttachIndex);
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="_deltaTime"></param>
void Player::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;

	//mPlayTime += 0.5f;

	//if (mPlayerPos.z < 30 && mJumpFlag == false)
	//{
	//	mJumpFlag = true;
	//	mPlayerPos.y += 5;
	//}

	//if (mJumpFlag == true) //�n�ʂɂ߂荞�܂Ȃ�����
	//{
	//	mPlayerPos.y -= 0.4;		
	//}
	//else
	//{
	//	mPlayerPos.z -= 0.1;
	//}

	// �Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ�0�ɖ߂�
	if (mPlayTime >= mTotalTime)
	{
		mPlayTime = 0.0f;
	}

	// �Đ����Ԃ��Z�b�g����
	//MV1SetAttachAnimTime(mModelHandle, mAttachIndex, mPlayTime);
	MV1SetPosition(mModelHandle, mPlayerPos);
}

/// <summary>
/// �`�揈��
/// </summary>
void Player::Draw()
{
	MV1DrawModel(mModelHandle);
}

/// <summary>
/// ������
/// </summary>
void Player::Load()
{
}
