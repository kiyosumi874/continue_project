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
	, mPlayFlag(true)
	, mScale(VGet(0.5f,0.5f,0.5f))
{
	MV1SetPosition(mModelHandle, mPlayerPos);
	MV1SetScale(mModelHandle, mScale);
	mAttachIndex = MV1AttachAnim(mModelHandle, 0, -1, FALSE);
	mTotalTime = MV1GetAttachAnimTotalTime(mModelHandle, mAttachIndex);
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

	if (mPlayFlag == false)
	{
		if (mPlayerPos.z < -17.f && mJumpFlag == false)
		{
			if (mPlayerPos.y > 35.0f)
			{
				mJumpFlag = true;
			}

			mPlayerPos.y += 5.0f * mDeltaTime;
		}

		if (mJumpFlag == true) //��э��ݏ���
		{
			mPlayerPos.y -= 20.0f * mDeltaTime;
		}
		else
		{
			mPlayerPos.z -= 10.0f * mDeltaTime;
		}

		// �Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ�0�ɖ߂�
		if (mPlayTime >= mTotalTime)
		{
			mPlayTime = mTotalTime;
		}
		else
		{
			mPlayTime += 40.0f * mDeltaTime;
		}
		mAttachIndex = MV1AttachAnim(mModelHandle, 0, -1, FALSE);
	}
	if(mPlayFlag == true)
	{
		mPlayTime += 15.0f * mDeltaTime;
		if (mPlayTime >= mTotalTime)
		{
			mPlayTime = 0.0f;
		}
		mAttachIndex = MV1AttachAnim(mModelHandle, 1, -1, FALSE);
	}

	// �Đ����Ԃ��Z�b�g����
	MV1SetAttachAnimTime(mModelHandle, mAttachIndex, mPlayTime);
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
