#include "DxLib.h"
#include <math.h>

#include "TitleScene.h"
#include "PlayScene.h"

#include "TitleUI.h"
#include "TitleCamera.h"
#include "BGM.h"



/// <summary>
/// ������
/// </summary>
TitleScene::TitleScene()
	: mTitleCamera(nullptr)
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
TitleScene::~TitleScene()
{
	delete mTitleCamera;
	delete mTitleUI;
	delete mBGM;
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
SceneBase* TitleScene::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime / 1000000.0f;
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
	MV1SetPosition(mHandle, VGet(0.0f + 5.0f * sin(x * DX_PI_F / 180.0f), -7.0f, 10.0f + 5.0f * cos(z * DX_PI_F / 180.0f)));

	// �^�C�g���J�����̍X�V
	mTitleCamera->Update();


	// �^�C�g��UI�̍X�V
	mTitleUI->Update(mDeltaTime);
	mStartButtonFlag = mTitleUI->GetStartButtonFlag();
	if (mAlphaPal >= 0 && !mAlphaPalFlag)
	{
		mAlphaPal -= 400.0f * mDeltaTime;
	}
	else
	{
		mAlphaPalFlag = true;
	}
	if (mStartButtonFlag && mAlphaPalFlag)
	{
		mAlphaPal += 400.0f * mDeltaTime;
	}

	// �V�[���J�ڏ���
	if (mAlphaPal >= 255)
	{
		// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new PlayScene();
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
void TitleScene::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	// �^�C�g���J�����̕`��
	mTitleCamera->Draw();

	// �L�����\���f�o�b�O�p
	MV1DrawModel(mHandle);

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
	mTitleCamera = new TitleCamera;
	mTitleUI = new TitleUI;
	mBGM = new BGM;


	// �^�C�g���J�����̏�����
	mTitleCamera->Load();
	// �^�C�g��UI�̏�����
	mTitleUI->Load();
	mBGM->LoadMusic("data/sound/�T�C�N�����O_3.mp3");
}
