#include "DxLib.h"
#include <math.h>

#include "TitleScene.h"
#include "PlayScene.h"

#include "TitleUI.h"
#include "TitleCamera.h"
#include "BGM.h"
#include "SE.h"

#include "PlayerActor_kiyosumi.h"
#include "Camera.h"



/// <summary>
/// ������
/// </summary>
TitleScene::TitleScene()
	/*: mTitleCamera(nullptr)*/
	: mCamera(nullptr)
	, mTitleUI(nullptr)
	, mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mSceneTransitionCount(0)
	, mStartButtonFlag(false)
	, mAlphaPal(255)
	, mAlphaPalFlag(false)
	, mMoveSceneHandle(LoadGraph("data/img/MoveScene.png"))
	, mBGMFlag(false)
	, mBGM(nullptr)
	, mClickNormal(nullptr)
	, mClickNormalFlag(false)
	, mFadeSpeed(3)
	, mPlayer(nullptr)
{
	// �L�����\���f�o�b�O�p
	//mHandle = MV1LoadModel("data/model/podium/podium.mv1");
	//mAttachIndex = MV1AttachAnim(mHandle, 0, -1, FALSE);
	//mTotalTime = MV1GetAttachAnimTotalTime(mHandle, mAttachIndex);
	//mPlayTime = 0.0f;
	//MV1SetScale(mHandle, VGet(0.01f, 0.01f, 0.01f));
	//MV1SetPosition(mHandle, VGet(0, 0.0f, 10));
}

/// <summary>
/// �㏈��
/// </summary>
TitleScene::~TitleScene()
{
	//delete mTitleCamera;
	delete mCamera;
	delete mTitleUI;
	delete mBGM;
	delete mClickNormal;
	delete mPlayer;
	//MV1DeleteModel(mHandle);
	//MV1DetachAnim(mHandle, mAttachIndex);
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="_deltaTime">�f���^�^�C��</param>
/// <returns>
/// Enter���������Ƃ��Ɏ��̃V�[����Instance�̃|�C���^��Ԃ�
/// ����ȊO�͎����̃|�C���^��Ԃ�
/// </returns>
SceneBase* TitleScene::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime / 1000000.0f;
	//// �L�����\���f�o�b�O�p
	//mPlayTime += 50.0f * mDeltaTime;
	//// �Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ��O�ɖ߂�
	//if (mPlayTime >= mTotalTime)
	//{
	//	mPlayTime = 0.0f;
	//}
	//// �Đ����Ԃ��Z�b�g����
	//MV1SetAttachAnimTime(mHandle, mAttachIndex, mPlayTime);
	//x += 150.0f * mDeltaTime;
	//z += 150.0f * mDeltaTime;
	//MV1SetPosition(mHandle, VGet(0.0f + 5.0f * sin(x * DX_PI_F / 180.0f), 0.0f, 10.0f + 5.0f * cos(z * DX_PI_F / 180.0f)));

	// �^�C�g���J�����̍X�V
	//mTitleCamera->Update();
	mCamera->Update(VGet(0,0,-1), mPlayer->GetPosition());

	mPlayer->UpdateActor(mDeltaTime);
	mPlayer->Update(mDeltaTime);

	// �^�C�g��UI�̍X�V
	mTitleUI->Update(mDeltaTime);
	mStartButtonFlag = mTitleUI->GetStartButtonFlag();
	if (0 <= mAlphaPal && !mAlphaPalFlag)
	{
		mAlphaPal -= mFadeSpeed;
	}
	else
	{
		mAlphaPalFlag = true;
	}
	if (mStartButtonFlag && mAlphaPalFlag)
	{
		mAlphaPal += mFadeSpeed;
	}

	// �V�[���J�ڏ���
	if (mAlphaPal >= 255)
	{
		// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new PlayScene();
	}

	// �V�[�����ύX����Ă��Ȃ������玩���̃|�C���^��Ԃ�
	return this;
}

/// <summary>
/// �`��
/// </summary>
void TitleScene::Draw()
{
#ifdef _DEBUG
	clsDx();
	printfDx("%f\n", mCamera->GetPositionX());
	printfDx("%f\n", mCamera->GetPositionY());
	printfDx("%f\n",mCamera->GetPositionZ());
#endif
	
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	// �^�C�g���J�����̕`��
	//mTitleCamera->Draw();

	mPlayer->Draw();
	// �L�����\���f�o�b�O�p
	/*MV1DrawModel(mHandle);*/

	// �^�C�g��UI�̕`��
	mTitleUI->Draw();

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mAlphaPal);
	DrawGraph(0, 0, mMoveSceneHandle, FALSE);




	//DrawFormatString(0, 0, GetColor(0, 255, 0), "delta:%f", mDeltaTime);
}

/// <summary>
/// ���y
/// </summary>
void TitleScene::Sound()
{
	if (mStartButtonFlag && mAlphaPalFlag)
	{
		mBGM->FadeOutMusic(500, mDeltaTime);
	}
	else
	{
		mBGM->FadeInMusic(250, mDeltaTime);
	}

	if (mStartButtonFlag && mAlphaPalFlag && !mClickNormalFlag)
	{
		mClickNormalFlag = true;
		mClickNormal->Play();
	}

	if (!mBGMFlag)
	{
		mBGM->Play();
		mBGMFlag = true;
	}
}

/// <summary>
/// ������
/// </summary>
void TitleScene::Load()
{
	//mTitleCamera = new TitleCamera;
	mCamera = new Camera;
	mTitleUI = new TitleUI;
	mBGM = new BGM;
	mClickNormal = new SE;
	mPlayer = new PlayerActor_kiyosumi;


	// �^�C�g���J�����̏�����
	//mTitleCamera->Load();
	
	// �^�C�g��UI�̏�����
	mTitleUI->Load();
	mClickNormal->LoadSound("data/sound/click_normal.mp3");
	mBGM->LoadMusic("data/sound/�T�C�N�����O_3.mp3");

	mPlayer->LoadModel("data/model/player5/waterboy.pmx");
	mPlayer->SetScale(VGet(0.05f, 0.05f, 0.05f));
	mPlayer->SetRotation(VGet(0.0f, /*90.0f * DX_PI_F / 180.0f*/0.0f, 0.0f));
	mPlayer->SetPosition(VGet(0.0f, -1.0f, 1.0f));
}
