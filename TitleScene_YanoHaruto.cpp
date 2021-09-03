#include "DxLib.h"
#include <math.h>

#include "TitleScene_YanoHaruto.h"
#include "PlayScene_YanoHaruto.h"

#include "TitleUI.h"
#include "BGM.h"
#include "SE.h"
#include "PlayerActor.h"
#include "Camera.h"

const float    FIRST_DELTA_TIME = 0.000001f;
const char* MOVE_SCENE_IMG = "data/img/MoveScene.png";
const char* PLAYER_MODEL_HANDLE = "data/model/player5/waterboy.pmx";
const char* BGM_HANDLE = "data/sound/�T�C�N�����O_3.mp3";
const char* SOUND_CLICK_HANDLE = "data/sound/click_normal.mp3";
const VECTOR   TITLE_PLAYER_SCALE = VGet(0.05f, 0.05f, 0.05f);
const VECTOR   TITLE_PLAYER_ROTATE = VGet(0.0f, /*90.0f * DX_PI_F / 180.0f*/0.0f, 0.0f);
const VECTOR   TITLE_PLAYER_POS = VGet(0.0f, 0.0f, 0.0f);
const VECTOR   TITLE_CAMERA_POS = VGet(0.0f, 2.0f, -2.0f);
const int         MAX_ALPHA_PAL = 255;
const int        IMG_FADE_SPEED = 3;

/// <summary>
/// ������
/// </summary>
TitleScene_YanoHaruto::TitleScene_YanoHaruto()
	: mDeltaTime(FIRST_DELTA_TIME)
	, mCamera(nullptr)
	, mTitleUI(nullptr)
	, mBGM(nullptr)
	, mPlayer(nullptr)
	, mClickNormal(nullptr)
	, mInputReturnFlag(false)
	, mStartButtonFlag(false)
	, mAlphaPalFlag(false)
	, mBGMFlag(false)
	, mClickNormalFlag(false)
	, mSceneTransitionCount(0)
	, mMoveSceneHandle(NULL)
	, mAlphaPal(MAX_ALPHA_PAL)
	, mFadeSpeed(IMG_FADE_SPEED)
{
}

/// <summary>
/// �㏈��
/// </summary>
TitleScene_YanoHaruto::~TitleScene_YanoHaruto()
{
	delete mCamera;
	delete mTitleUI;
	delete mBGM;
	delete mClickNormal;
	delete mPlayer;
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="_deltaTime">�f���^�^�C��</param>
/// <returns>
/// Enter���������Ƃ��Ɏ��̃V�[����Instance�̃|�C���^��Ԃ�
/// ����ȊO�͎����̃|�C���^��Ԃ�
/// </returns>
SceneBase* TitleScene_YanoHaruto::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime / 1000000.0f;

	// �v���C���[�̍X�V
	mPlayer->SetPlayerState(PlayerActor::PLAYER_STATE::STATE_TITLE_IDLE);
	mPlayer->UpdateActor(mDeltaTime);  // 1
	mPlayer->Update(mDeltaTime);       // 2 ���̏��Ԃŏ���

	// �^�C�g��UI�̍X�V
	mTitleUI->Update(mDeltaTime);

	// �J�����̍X�V
	mCamera->Update(TITLE_CAMERA_POS, mPlayer->GetPosition());
	// �t�F�[�h�C��
	if (0 <= mAlphaPal && !mAlphaPalFlag)
	{
		mAlphaPal -= mFadeSpeed;
	}
	else
	{
		mAlphaPalFlag = true;
	}

	mStartButtonFlag = mTitleUI->GetStartButtonFlag();
	// �t�F�[�h�A�E�g
	if (mStartButtonFlag && mAlphaPalFlag)
	{
		mAlphaPal += mFadeSpeed;
	}

	// �V�[���J�ڏ���
	if (mAlphaPal >= 255)
	{
		// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new PlayScene_YanoHaruto();
	}

	// �V�[�����ύX����Ă��Ȃ������玩���̃|�C���^��Ԃ�
	return this;
}

/// <summary>
/// �`��
/// </summary>
void TitleScene_YanoHaruto::Draw()
{
#ifdef _DEBUG
	// �f�o�b�O���[�h���̂ݎ��s
	clsDx();
	printfDx("CameraPosX:%f\n", mCamera->GetPositionX());
	printfDx("CameraPosY:%f\n", mCamera->GetPositionY());
	printfDx("CameraPosZ:%f\n", mCamera->GetPositionZ());
	printfDx("CameraAimPosX:%f\n", mCamera->GetAimTargetPositionX());
	printfDx("CameraAimPosY:%f\n", mCamera->GetAimTargetPositionY());
	printfDx("CameraAimPosZ:%f\n", mCamera->GetAimTargetPositionZ());
	printfDx("PlayerPosX:%f\n", mPlayer->GetPositionX());
	printfDx("PlayerPosY:%f\n", mPlayer->GetPositionY());
	printfDx("PlayerPosZ:%f\n", mPlayer->GetPositionZ());
#endif

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	// �v���C���[�̕`��
	mPlayer->Draw();
	// �^�C�g��UI�̕`��
	mTitleUI->Draw();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mAlphaPal);
	DrawGraph(0, 0, mMoveSceneHandle, FALSE);
}

/// <summary>
/// ���y
/// </summary>
void TitleScene_YanoHaruto::Sound()
{
	// �t�F�[�h�C��/�t�F�[�h�A�E�g(BGM)
	if (mStartButtonFlag && mAlphaPalFlag)
	{
		mBGM->FadeOutMusic(500, mDeltaTime);
	}
	else
	{
		mBGM->FadeInMusic(250, mDeltaTime);
	}

	// ENTER�L�[���������Ƃ��̉�
	if (mStartButtonFlag && mAlphaPalFlag && !mClickNormalFlag)
	{
		mClickNormalFlag = true;
		mClickNormal->Play();
	}

	// ��x����BGM���Đ�
	if (!mBGMFlag)
	{
		mBGM->Play();
		mBGMFlag = true;
	}
}

/// <summary>
/// ������
/// </summary>
void TitleScene_YanoHaruto::Load()
{
	// ���̉�
	mCamera = new Camera;
	mTitleUI = new TitleUI;
	mBGM = new BGM;
	mClickNormal = new SE;
	mPlayer = new PlayerActor;

	mTitleUI->Load();
	mClickNormal->LoadSound(SOUND_CLICK_HANDLE);
	mBGM->LoadMusic(BGM_HANDLE);
	mMoveSceneHandle = LoadGraph(MOVE_SCENE_IMG);
	mPlayer->LoadModel(PLAYER_MODEL_HANDLE);
	mPlayer->SetScale(TITLE_PLAYER_SCALE);
	mPlayer->SetRotation(TITLE_PLAYER_ROTATE);
	mPlayer->SetPosition(TITLE_PLAYER_POS);
}
