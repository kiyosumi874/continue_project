///8/27 �G�t�F�N�g�ǉ�
///by ���z��
///8/30�@staticObject���g���ăv�[���ǉ��@by ���z��
///----------------------------------------
#include "DxLib.h"
#include "PlayScene_YanoHaruto.h"
#include "ResultScene_YanoHaruto.h"
#include "TitleScene_YanoHaruto.h"
#include "PlayEffect.h"
#include "DxLib.h"
#include "Camera.h"
#include "ResultUI.h"
#include "ResultCamera.h"
#include "PlayerActor.h"
#include "StaticObjectActor.h"

//            ����TitleScene�Œ�`���Ă���̂ŏ����Ȃ��Ă���
//const char* MOVE_SCENE_IMG = "data/img/MoveScene.png";
//const float    FIRST_DELTA_TIME = 0.000001f;
//const char* PLAYER_MODEL_HANDLE = "data/model/player5/waterboy.pmx";
//const char* SOUND_CLICK_HANDLE = "data/sound/click_normal.mp3";
const char* PODIUM_MODEL = "data/model/podium/podium.mv1";
const VECTOR   RESULT_CAMERA_POS = VGet(0.0f, 1.0f, -2.0f);
const VECTOR   RESULT_PLAYER_SCALE = VGet(0.05f, 0.05f, 0.05f);
const VECTOR   RESULT_PLAYER_ROTATE = VGet(0.0f, /*90.0f * DX_PI_F / 180.0f*/0.0f, 0.0f);
const VECTOR   RESULT_PLAYER_POS = VGet(0.0f, 0.0f, 0.0f);



// SetGraphMode�̃p�����[�^
#define WINDOW_SCREEN_WIDTH  1920/**2/3*/
#define WINDOW_SCREEN_HEIGHT 1080/**2/3*/
#define COLOR_BIT_NUM 16

/// <summary>
/// ������
/// </summary>
ResultScene_YanoHaruto::ResultScene_YanoHaruto(int _score)
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mResultUI(nullptr)
	, mScore(_score)
	, mAlphaPal(255)
	, mAlphaPalFlag(false)
	, mMoveSceneHandle(-1)
	, mCheckHitFlag(false)
	, mConfetti()
	, mPool(nullptr)
	, mPlayer(nullptr)
	, mFadeSpeed(3)
	, mFireWork()
	, mStaticObjectActor(nullptr)
	, mCamera(nullptr)
	, mResultCamera(nullptr)
{
}

/// <summary>
/// �㏈��
/// </summary>
ResultScene_YanoHaruto::~ResultScene_YanoHaruto()
{
	delete mResultCamera;
	delete mResultUI;
	delete mPlayer;
	delete mCamera;
	delete mStaticObjectActor;
	delete mPool;
	for (int i = 0; i < FIREWORKS; i++)
	{
		mFireWork[i]->StopEffect();
		mFireWork[i]->Delete();
	}
	for (int i = 0; i < CONFETTIES; i++)
	{
		mConfetti[i]->StopEffect();
		mConfetti[i]->Delete();
	}
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="_deltaTime">�f���^�^�C��</param>
/// <returns>
/// Enter���������Ƃ��Ɏ��̃V�[����Instance�̃|�C���^��Ԃ�
/// ����ȊO�͎����̃|�C���^��Ԃ�
/// </returns>
SceneBase* ResultScene_YanoHaruto::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime / 1000000.0f;

	mPlayer->SetPlayerState(PlayerActor::PLAYER_STATE::STATE_RESULT_IDLE);
	mPlayer->UpdateActor(mDeltaTime);
	mPlayer->Update(mDeltaTime);

	// ���U���gUI�̍X�V
	mResultUI->Update(mDeltaTime);
	// ���U���gUI�ɃX�R�A��n��
	mResultUI->LoadScore(mScore);

	mCamera->Update(RESULT_CAMERA_POS, mPlayer->GetPosition());

	mStaticObjectActor->UpdateActor(mDeltaTime);
	mStaticObjectActor->Update(mDeltaTime);
	// Enter�L�[�̘A�����͖h�~
	if (!CheckHitKey(KEY_INPUT_RETURN))
	{
		mInputReturnFlag = true;
	}


	if (mAlphaPal >= 0 && !mAlphaPalFlag)
	{
		mAlphaPal -= mFadeSpeed;
	}
	else
	{
		mAlphaPalFlag = true;
	}

	if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag && mAlphaPalFlag)
	{
		mCheckHitFlag = true;
		mInputReturnFlag = false;
	}
	if (mCheckHitFlag)
	{
		mAlphaPal += mFadeSpeed;
	}
	// �V�[���J�ڏ���
	if (mAlphaPal >= 255)
	{
		//�G�t�F�N�g����------------------------------------------------------------------------------
		for (int i = 0; i < FIREWORKS; i++)
		{
			mFireWork[i]->StopEffect();
			mFireWork[i]->Delete();
		}
		for (int i = 0; i < CONFETTIES; i++)
		{
			mConfetti[i]->StopEffect();
			mConfetti[i]->Delete();
		}
		// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new TitleScene_YanoHaruto();
	}

	// �V�[�����ύX����Ă��Ȃ������玩���̃|�C���^��Ԃ�
	return this;
}

/// <summary>
/// �`��
/// </summary>
void ResultScene_YanoHaruto::Draw()
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
	mPlayer->Draw();

	mPool->Draw();
	mStaticObjectActor->Draw();

	// ���U���gUI�̕`��
	mResultUI->Draw();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mAlphaPal);
	DrawGraph(0, 0, mMoveSceneHandle, FALSE);
	//�G�t�F�N�g�Đ�--------------------------------------------------------------------------------------------
	for (int i = 0; i < FIREWORKS; i++)
	{
		//�G�t�F�N�g���Đ����I�������Đ��ĊJ
		if (mFireWork[i]->GetNowPlaying3D())
		{
			int j = -2 + i;
			mFireWork[i]->PlayEffekseer(VGet(j, 0, 0));
		}
	}
	for (int i = 0; i < CONFETTIES; i++)
	{
		if (mConfetti[i]->GetNowPlaying3D())
		{
			int j = -1 + i;
			mConfetti[i]->PlayEffekseer(VGet(j, 0, 0));
		}
	}
	//----------------------------------------------------------------------------------------------------------
}

/// <summary>
/// ���y
/// </summary>
void ResultScene_YanoHaruto::Sound()
{
}

/// <summary>
/// ������
/// </summary>
void ResultScene_YanoHaruto::Load()
{
	//�G�t�F�N�g�ǉ�-----------------------------------------------------------------------------------------------
	for (int i = 0; i < FIREWORKS; i++)
	{
		mFireWork[i] = new PlayEffect("data/effect/hanabi.efk", 0.1f);
	}
	for (int i = 0; i < CONFETTIES; i++)
	{
		mConfetti[i] = new PlayEffect("data/effect/confetti.efk", 0.1f);
	}//------------------------------------------------------------------------------------------------------------

	mCamera = new Camera;
	mResultUI = new ResultUI;
	mPlayer = new PlayerActor;
	mPool = new StaticObjectActor;
	mStaticObjectActor = new StaticObjectActor;
	mResultCamera = new ResultCamera;

	// ���U���gUI�̏�����
	mResultUI->Load();
	mMoveSceneHandle = LoadGraph(MOVE_SCENE_IMG);

	//�v�[���ǉ�8/30-----------------------------------------------------------------------------------------------
	mPool->LoadModel("data/model/pool/pool.mv1");
	mPool->SetScale(VGet(0.005f, 0.005f, 0.005f));
	mPool->SetRotation(VGet(0.0f, 0.0f, 0.0f));
	mPool->SetPosition(VGet(0.0f, 0.0f, 0.0f));
	//--------------------------------------------------------------------------------------------------------------

	mPlayer->LoadModel(PLAYER_MODEL_HANDLE);
	mPlayer->SetScale(RESULT_PLAYER_SCALE);
	mPlayer->SetRotation(RESULT_PLAYER_ROTATE);
	mPlayer->SetPosition(RESULT_PLAYER_POS);

	mStaticObjectActor->LoadModel(PODIUM_MODEL);
	mStaticObjectActor->SetScale(VGet(0.005f, 0.005f, 0.005f));
	mStaticObjectActor->SetRotation(VGet(0.0f, 90.0f * DX_PI_F / 180.0f, 0.0f));
	mStaticObjectActor->SetPosition(VGet(0.0f, -2.5f, 2.0f));
}