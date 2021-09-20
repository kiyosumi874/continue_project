#include "DxLib.h"
#include "ResultScene_YanoHaruto.h"
#include "TitleScene_YanoHaruto.h"
#include "Camera.h"
#include "ResultUI.h"
#include "PlayerActor.h"
#include "StaticObjectActor.h"
#include "Effect.h"
#include "WaterObject.h"
//            ����TitleScene�Œ�`���Ă���̂ŏ����Ȃ��Ă���
//const char* MOVE_SCENE_IMG = "data/img/MoveScene.png";
//const float    FIRST_DELTA_TIME = 0.000001f;
//const char* PLAYER_MODEL_HANDLE = "data/model/player5/waterboy.pmx";
//const char* SOUND_CLICK_HANDLE = "data/sound/click_normal.mp3";
const char* PODIUM_MODEL = "data/model/podium/podium.mv1";
const VECTOR   RESULT_CAMERA_POS = VGet(2.0f, 1.0f, -3.0f);
const VECTOR   RESULT_PLAYER_SCALE = VGet(0.25f, 0.25f, 0.25f);
const VECTOR   RESULT_PLAYER_ROTATE = VGet(0.0f, 90.0f * DX_PI_F / 180.0f, 0.0f);
const VECTOR   RESULT_PLAYER_POS = VGet(0.0f, 0.76f, 0.0f);

/// <summary>
/// ������
/// </summary>
ResultScene_YanoHaruto::ResultScene_YanoHaruto(int _score)
	: mInputReturnFlag(false)
	, mResultUI(nullptr)
	, mScore(_score)
	, mAlphaPal(255)
	, mAlphaPalFlag(false)
	, mMoveSceneHandle(-1)
	, mCheckHitFlag(false)
	, mPlayer(nullptr)
	, mFadeSpeed(3)
	, mPodium(nullptr)
	, mCamera(nullptr)
	, mFireWorks(nullptr)
	, mPool(nullptr)
	, mWater(nullptr)
	//------------------------------------------������ǉ�
	, mConfetti(nullptr)
{
	mCameraPosX = 8.5f;

	mCameraPosY = 3.1f;

	mCameraPosZ = -49.0f;

	mCameraTargetPosX = 17.0f;

	mCameraTargetPosY = 4.0f;

	mCameraTargetPosZ = -54.0f;

}

/// <summary>
/// �㏈��
/// </summary>
ResultScene_YanoHaruto::~ResultScene_YanoHaruto()
{
	delete mResultUI;
	delete mPlayer;
	delete mCamera;
	delete mPodium;
	//--------------------------------------------------9.20
	mFireWorks->StopEffect3D();
	mFireWorks->Delete();
	delete mFireWorks;
	mConfetti->StopEffect3D();
	mConfetti->Delete();
	delete mConfetti;

	delete mPool;
	delete mSky;
	delete mWater;
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="_deltaTime">�f���^�^�C��</param>
/// <returns>
/// Enter���������Ƃ��Ɏ��̃V�[����Instance�̃|�C���^��Ԃ�
/// ����ȊO�͎����̃|�C���^��Ԃ�
/// </returns>
SceneBase* ResultScene_YanoHaruto::Update(float _deltaTime, int& _hiScore)
{
	mSky->Update(_deltaTime);
	mPodium->Update(_deltaTime);
	mPool->Update(_deltaTime);
	mPlayer->SetPlayerState(PlayerActor::PLAYER_STATE::STATE_RESULT_IDLE);
	// ���ʃV�F�[�_�[�̍X�V
	mWater->Update(_deltaTime);
	mWater->UpdateWaterShader(_deltaTime);     // ���ʗp�V�F�[�_�[�֏����Z�b�g����
	mPlayer->UpdateActor(_deltaTime);
	mPlayer->Update(_deltaTime);
	//���U���gUI�ɃX�R�A��n��
	mResultUI->LoadScore(mScore);
	// ���U���gUI�̍X�V
	mResultUI->Update(_deltaTime, _hiScore);
	/*if (CheckHitKey(KEY_INPUT_Q))
	{
		mCameraPosX += _deltaTime * 3.0f;
	}
	if (CheckHitKey(KEY_INPUT_A))
	{
		mCameraPosX -= _deltaTime * 3.0f;
	}
	if (CheckHitKey(KEY_INPUT_W))
	{
		mCameraPosY += _deltaTime * 3.0f;
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		mCameraPosY -= _deltaTime * 3.0f;
	}
	if (CheckHitKey(KEY_INPUT_E))
	{
		mCameraPosZ += _deltaTime * 3.0f;
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		mCameraPosZ -= _deltaTime * 3.0f;
	}

	if (CheckHitKey(KEY_INPUT_R))
	{
		mCameraTargetPosX += _deltaTime * 3.0f;
	}
	if (CheckHitKey(KEY_INPUT_F))
	{
		mCameraTargetPosX -= _deltaTime * 3.0f;
	}
	if (CheckHitKey(KEY_INPUT_T))
	{
		mCameraTargetPosY += _deltaTime * 3.0f;
	}
	if (CheckHitKey(KEY_INPUT_G))
	{
		mCameraTargetPosY -= _deltaTime * 3.0f;
	}
	if (CheckHitKey(KEY_INPUT_Y))
	{
		mCameraTargetPosZ += _deltaTime * 3.0f;
	}
	if (CheckHitKey(KEY_INPUT_H))
	{
		mCameraTargetPosZ -= _deltaTime * 3.0f;
	}
	mCamera->SetFuturePos   (VGet(mCameraPosX, mCameraPosY, mCameraPosZ));
	mCamera->SetFutureTarget(VGet(mCameraTargetPosX, mCameraTargetPosY, mCameraTargetPosZ));
	mCamera->SetPos         (VGet(mCameraPosX, mCameraPosY, mCameraPosZ));
	mCamera->SetTarget      (VGet(mCameraTargetPosX, mCameraTargetPosY, mCameraTargetPosZ));*/
	mCamera->Update(RESULT_CAMERA_POS, mPlayer->GetPosition(), _deltaTime);
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
	printfDx("CameraPosX:%f\n", mCameraPosX);
	printfDx("CameraPosY:%f\n", mCameraPosY);
	printfDx("CameraPosZ:%f\n", mCameraPosZ);
	printfDx("CameraAimPosX:%f\n", mCameraTargetPosX);
	printfDx("CameraAimPosY:%f\n", mCameraTargetPosY);
	printfDx("CameraAimPosZ:%f\n", mCameraTargetPosZ);
	printfDx("PlayerPosX:%f\n", mPlayer->GetPositionX());
	printfDx("PlayerPosY:%f\n", mPlayer->GetPositionY());
	printfDx("PlayerPosZ:%f\n", mPlayer->GetPositionZ());
	switch (mPlayer->GetPlayerState())
	{
	case PlayerActor::PLAYER_STATE::STATE_TITLE_IDLE:
		printfDx("NowState:TITLE_IDLE\n");
		break;

	case PlayerActor::PLAYER_STATE::STATE_PLAY_IDLE:
		printfDx("NowState:PLAY_IDLE\n");
		break;

	case PlayerActor::PLAYER_STATE::STATE_PLAY_GAME1:
		printfDx("NowState:PLAY_GAME1\n");
		break;

	case PlayerActor::PLAYER_STATE::STATE_PLAY_GAME2:
		printfDx("NowState:PLAY_GAME2\n");
		break;

	case PlayerActor::PLAYER_STATE::STATE_PLAY_GAME3:
		printfDx("NowState:PLAY_GAME3\n");
		break;

	case PlayerActor::PLAYER_STATE::STATE_RESULT_IDLE:
		printfDx("NowState:RESULT_IDLE\n");
		break;

	default:
		break;
	}
#endif

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	mSky->Draw();
	mPool->Draw();
	mWater->DrawWater();
	mPlayer->Draw();
	mPodium->Draw();
	//--------------------------------------------------------------9.20
	if (mFireWorks->GetNowPlaying3D()&&mScore>200)
	{
		mFireWorks->PlayEffekseer(VGet(33.0f,0.0f,-58.0f));
	}
	if (mConfetti->GetNowPlaying3D()&&mScore > 400)
	{
		mConfetti->PlayEffekseer(VGet(30.0f, 10.0f, -54.0f));
	}

	// ���U���gUI�̕`��
	mResultUI->Draw();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mAlphaPal);
	DrawGraph(0, 0, mMoveSceneHandle, FALSE);
}

/// <summary>
/// ���y
/// </summary>
void ResultScene_YanoHaruto::Sound(float _deltaTime)
{
}

/// <summary>
/// ������
/// </summary>
void ResultScene_YanoHaruto::Load()
{

	mCamera = new Camera;
	mResultUI = new ResultUI;
	mPlayer = new PlayerActor;
	mPodium = new StaticObjectActor;
	mPool = new StaticObjectActor;
	//------------------------------------------------------------------size�ύX
	mFireWorks = new Effect("data/effect/hanabi.efk", 1.0f);
	mSky = new StaticObjectActor;
	mConfetti = new Effect("data/effect/confetti.efk", 1.0f);

	// ���U���gUI�̏�����
	mResultUI->Load();
	mMoveSceneHandle = LoadGraph(MOVE_SCENE_IMG);
	// ���ʃI�u�W�F�N�g(���f���̓y���C�`�̐����`)
	mWater = new WaterObject;
	mWater->SetScale(VGet(150.0f, 1.0f, 225.0f));
	mWater->SetPosition(VGet(0.0f, -5.25f, -55.0f));
	mPlayer->LoadModel(PLAYER_MODEL_HANDLE);
	mPlayer->SetScale(RESULT_PLAYER_SCALE);
	mPlayer->SetRotation(RESULT_PLAYER_ROTATE);
	mPlayer->SetPosition(VGet(30.0f, 3.0f, -54.0f));

	mSky->LoadModel("data/model/Skydome_X5/Dome_X501.pmx");

	mCamera->SetFuturePos(VGet(22.0f, 2.9f, -49.5f));
	mCamera->SetFutureTarget(VGet(30.0f, 5.5f, -57.0f));
	mCamera->SetPos(VGet(22.0f, 2.9f, -49.5f));
	mCamera->SetTarget(VGet(30.0f, 5.5f, -57.0f));

	mPodium->LoadModelTex("data/model/podium/Stand.mv1", "data/model/podium/podium.png");
	mPodium->SetScale(VGet(0.5f, 0.5f, 0.5f));
	mPodium->SetRotation(VGet(0.0f, 180.0f * DX_PI_F / 180.0f, 0.0f));
	mPodium->SetPosition(VGet(30.0f, 0.5f, -54.0f));

	mPool->LoadModelTex("data/model/pool/Stadium.mv1", "data/model/pool/Pool.png");
	mPool->SetScale(VGet(1.0f, 1.0f, 1.0f));
	mPool->SetRotation((VGet(0.0f, 0.0f, 0.0f)));
	mPool->SetPosition((VGet(0.0f, 0.0f, 0.0f)));
}
