#include "DxLib.h"
#include "ResultScene.h"
#include "TitleScene.h"
#include "Camera.h"
#include "ResultUI.h"
#include "PlayerActor.h"
#include "StaticObjectActor.h"
#include "Effect.h"
#include "WaterObject.h"
#include "AudienceContoroller.h"
#include "SE.h"
#include "BGM.h"
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
ResultScene::ResultScene(int _score)
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
	, mConfetti(nullptr)
	//------------------------------------------9/26
	, mBadEffect(nullptr)
	, mBadEffectPos(VGet(0, -200, 0))
	, mBadSound(nullptr)
	, mFireWorks2(nullptr)
	, mFireWorksPos(VGet(33, 0, -58))
	, mVictory(nullptr)
	, mBadFlag(false)
	, mResultBgm(nullptr)
	, mBgmFlag(false)
{
	mCameraPosX = 22.0f;

	mCameraPosY = 2.9f;

	mCameraPosZ = -49.5f;

	mCameraTargetPosX = 30.0f;

	mCameraTargetPosY = 5.6f;

	mCameraTargetPosZ = -59.0f;

	//-----------------------------------------------------9/22���
	//mFireWorksPos = VGet(35.0f, 0.0f+30, -65.0f);
	mConfettiPos = VGet(30.0f, 10.0f, -54.0f);
	mFirstPlace = VGet(30.0f, 3.0f, -54.0f);
	mSecondPlace = VGet(30.0f, 2.0f, -51.5f);
	mThirdPlace = VGet(30.0f, 1.7f, -57.0f);

}

/// <summary>
/// �㏈��
/// </summary>
ResultScene::~ResultScene()
{
	delete mResultUI;
	delete mPlayer;
	delete mCamera;
	delete mPodium;
	//--------------------------------------------------9.20
	//mFireWorks->StopEffect3D();
	//mFireWorks->Delete();
	//delete mFireWorks;
	//mConfetti->StopEffect3D();
	//mConfetti->Delete();
	//delete mConfetti;

	////--------------------------------------------------9.26
	//mFireWorks2->StopEffect3D();
	//mFireWorks2->Delete();
	//delete mFireWorks2;
	//mBadEffect->StopEffect3D();
	//mBadEffect->Delete();
	//delete mBadEffect;

	delete mPool;
	delete mSky;
	delete mWater;
	delete mResultBgm;
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="_deltaTime">�f���^�^�C��</param>
/// <returns>
/// Enter���������Ƃ��Ɏ��̃V�[����Instance�̃|�C���^��Ԃ�
/// ����ȊO�͎����̃|�C���^��Ԃ�
/// </returns>
SceneBase* ResultScene::Update(float _deltaTime, int& _hiScore)
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
	mAudience->Update(_deltaTime);
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
		//------------------------------------------------9/22���
		/*mConfetti->StopEffect3D();
		mConfetti->Delete();
		mFireWorks->StopEffect3D();
		mFireWorks->Delete();*/
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
		mClickNormal->Play();
		//------------------------------------------------9/22���
		mConfetti->StopEffect3D();
		mConfetti->Delete();
		mFireWorks->StopEffect3D();
		mFireWorks->Delete();
		mFireWorks2->StopEffect3D();
		mFireWorks2->Delete();
		mBadEffect->StopEffect3D();
		mBadEffect->Delete();
		delete mConfetti;
		delete mFireWorks;
		delete mFireWorks2;
		delete mBadEffect;
	}
	if (mCheckHitFlag)
	{
		mAlphaPal += mFadeSpeed;
	}
	// �V�[���J�ڏ���
	if (mAlphaPal >= 255)
	{
		
		// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new TitleScene();
	}

	// �V�[�����ύX����Ă��Ȃ������玩���̃|�C���^��Ԃ�
	return this;
}

/// <summary>
/// �`��
/// </summary>
void ResultScene::Draw()
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
	mAudience->Draw();
	mWater->DrawWater();
	mPlayer->Draw();
	mPodium->Draw();

	//--------------------------------------------------------------9.20
	if (mBadEffect->GetNowPlaying2D() && 201 > mScore/* && !mBadFlag*/)
	{
		mBadEffect->PlayEffekseer2D(mBadEffectPos);
		/*mBadFlag = true;*/
	}
	else if (mFireWorks->GetNowPlaying3D() && 401 > mScore && mScore > 200)
	{
		mFireWorks->PlayEffekseer(mFireWorksPos);
	}
	else if (mFireWorks->GetNowPlaying3D() && mScore > 400)
	{
		mFireWorks->PlayEffekseer(mFireWorksPos);
	}
	else if (mConfetti->GetNowPlaying3D() && mScore > 500)
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
void ResultScene::Sound(float _deltaTime)
{
	if (!mBgmFlag)
	{
		mResultBgm->Play();
		mBgmFlag = true;
	}
	if (mCheckHitFlag)
	{
		mResultBgm->FadeOutMusic(150, _deltaTime);
	}
	else
	{
		mResultBgm->FadeInMusic(150, _deltaTime);
	}
}

/// <summary>
/// ������
/// </summary>
void ResultScene::Load()
{

	mCamera = new Camera;
	mResultUI = new ResultUI;
	mPlayer = new PlayerActor;
	mPodium = new StaticObjectActor;
	mPool = new StaticObjectActor;
	mClickNormal = new SE;
	mResultBgm = new BGM;
	mResultBgm->LoadMusic("data/sound/result.mp3");
	mClickNormal->LoadSound("data/sound/click_normal.wav");
	//-------------------------------------------------------9.26
	mFireWorks2 = new Effect("data/effect/Fireworks2.efk", 1.0f);
	mBadEffect = new Effect("data/effect/BadEffect.efk", 40.0f);
	mBadSound = new SE();
	mBadSound->LoadSound("data/sound/Onmtp-Negative02-2.mp3");
	if (mScore < 201)
	{
		mBadSEflag = true;
	}
	else
	{
		mBadSEflag = false;
	}
	mVictory = new SE();
	//mVictory->LoadSound("data/sound/");

	//------------------------------------------------------------------size�ύX
	mFireWorks = new Effect("data/effect/hanabi.efk", 1.0f);
	mSky = new StaticObjectActor;
	mConfetti = new Effect("data/effect/confetti.efk", 1.0f);

	mAudience = new AudienceContoroller();
	mAudience->LoadAudience();
	mAudience->SetAudience();

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

	if (mScore > 500)
	{
		mPlayer->SetPosition(mFirstPlace);
	}
	else if (mScore > 300)
	{
		mPlayer->SetPosition(mSecondPlace);
	}
	else
	{
		mPlayer->SetPosition(mThirdPlace);
	}

	mSky->LoadModel("data/model/Skydome_X5/Dome_X501.pmx");

	mCamera->SetFuturePos(VGet(22.0f, 2.9f, -49.5f));
	mCamera->SetFutureTarget(VGet(30.0f, 5.6f, -59.0f));
	mCamera->SetPos(VGet(22.0f, 2.9f, -49.5f));
	mCamera->SetTarget(VGet(30.0f, 5.5f, -57.0f));

	mPodium->LoadModel("data/model/podium/Stand.mv1");
	int texHandle = LoadGraph("data/model/podium/Stand.png");
	mPodium->SetScale(VGet(0.5f, 0.5f, 0.5f));
	//mPodium->SetRotation(VGet(0.0f, 180.0f * DX_PI_F / 180.0f, 0.0f));
	mPodium->SetPosition(VGet(30.0f, 0.5f, -54.0f));
	MV1SetTextureGraphHandle(mPodium->GetHandle(), 0, texHandle, TRUE);

	mPool->LoadModelTex("data/model/pool/Stadium.mv1", "data/model/pool/Stadium0.png");
	mPool->SetScale(VGet(1.0f, 1.0f, 1.0f));
	mPool->SetRotation((VGet(0.0f, 0.0f, 0.0f)));
	mPool->SetPosition((VGet(0.0f, 0.0f, 0.0f)));
}
