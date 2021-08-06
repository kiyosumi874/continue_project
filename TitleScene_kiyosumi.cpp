#include "DxLib.h"
#include <math.h>

#include "TitleScene_kiyosumi.h"
#include "PlayScene_kiyosumi.h"

#include "TitleUI.h"
#include "TitleCamera.h"



/// <summary>
/// ������
/// </summary>
TitleScene_kiyosumi::TitleScene_kiyosumi()
	: mTitleCamera(nullptr)
	, mTitleUI(nullptr)
	, mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mSceneTransitionCount(0)
	, mStartButtonFlag(false)
{
	// �L�����\���f�o�b�O�p
	mHandle = MV1LoadModel("data/model/player4/�����.pmx");
	mAttachIndex = MV1AttachAnim(mHandle, 0, -1, FALSE);
	mTotalTime = MV1GetAttachAnimTotalTime(mHandle, mAttachIndex);
	mPlayTime = 0.0f; 
	MV1SetScale(mHandle, VGet(0.5f, 0.5f, 0.5f));
	MV1SetPosition(mHandle, VGet(0, -7.0, 10));
	x = 0.0f;
	z = 0.0f;
}

/// <summary>
/// �㏈��
/// </summary>
TitleScene_kiyosumi::~TitleScene_kiyosumi()
{
	delete mTitleCamera;
	delete mTitleUI;
	MV1DeleteModel(mHandle);
	MV1DetachAnim(mHandle, mAttachIndex);
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="_deltaTime">�f���^�^�C��</param>
/// <returns>
/// Enter���������Ƃ��Ɏ��̃V�[����Instance�̃|�C���^��Ԃ�
/// ����ȊO�͎����̃|�C���^��Ԃ�
/// </returns>
SceneBase* TitleScene_kiyosumi::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;
	// �L�����\���f�o�b�O�p
	mPlayTime += 50.0f * mDeltaTime;
	// �Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ��O�ɖ߂�
	if (mPlayTime >= mTotalTime)
	{
		mPlayTime = 0.0f;
	}
	// �Đ����Ԃ��Z�b�g����
	MV1SetAttachAnimTime(mHandle, mAttachIndex, mPlayTime);
	x += 150.0f * mDeltaTime;
	z += 150.0f * mDeltaTime;
	MV1SetPosition(mHandle, VGet(0.0f+5*sin(x*DX_PI_F/180.0f), -7.0f, 10.0f + 5*cos(z * DX_PI_F / 180.0f)));

	// �^�C�g���J�����̍X�V
	mTitleCamera->Update();


	// �^�C�g��UI�̍X�V
	mTitleUI->Update(mDeltaTime);
	mStartButtonFlag = mTitleUI->GetStartButtonFlag();
	
	//// Enter�L�[�̘A�����͖h�~
	//if (!CheckHitKey(KEY_INPUT_RETURN))
	//{
	//	mInputReturnFlag = true;
	//}

	if (mStartButtonFlag)
	{
		mSceneTransitionCount += 1.0f * mDeltaTime;
	}

	// �V�[���J�ڏ���
	if (mSceneTransitionCount >= 0.5f)
	{
		// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new PlayScene_kiyosumi();
	}

	//// �V�[���J�ڏ���
	//if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
	//{
	//	mInputReturnFlag = false;
	//	// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
	//	return new PlayScene_kiyosumi();
	//}

	// �V�[�����ύX����Ă��Ȃ������玩���̃|�C���^��Ԃ�
	return this;
}

/// <summary>
/// �`��
/// </summary>
void TitleScene_kiyosumi::Draw()
{
	// �^�C�g���J�����̕`��
	mTitleCamera->Draw();

	// �L�����\���f�o�b�O�p
	MV1DrawModel(mHandle);

	// �^�C�g��UI�̕`��
	mTitleUI->Draw();
}

/// <summary>
/// ���y
/// </summary>
void TitleScene_kiyosumi::Sound()
{
}

/// <summary>
/// ������
/// </summary>
void TitleScene_kiyosumi::Load()
{
	mTitleCamera = new TitleCamera;
	mTitleUI = new TitleUI;

	// �^�C�g���J�����̏�����
	mTitleCamera->Load();
	// �^�C�g��UI�̏�����
	mTitleUI->Load();

}
