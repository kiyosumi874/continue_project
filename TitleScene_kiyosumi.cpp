#include "DxLib.h"
#include <math.h>

#include "TitleScene_kiyosumi.h"
#include "PlayScene_kiyosumi.h"

#include "TitleUI.h"
#include "BGM.h"
#include "SE.h"
#include "PlayerActor.h"
#include "Camera.h"
#include "StaticObjectActor.h"

const char* MOVE_SCENE_IMG = "data/img/MoveScene.png";
const char* PLAYER_MODEL_HANDLE = "data/model/player5/waterboy.pmx";
const char* BGM_HANDLE = "data/sound/�T�C�N�����O_3.mp3";
const char* SOUND_CLICK_HANDLE = "data/sound/click_normal.mp3";
const VECTOR   TITLE_PLAYER_SCALE = VGet(0.5f, 0.5f, 0.5f);
const VECTOR   TITLE_PLAYER_ROTATE = VGet(0.0f, /*90.0f * DX_PI_F / 180.0f*/0.0f, 0.0f);
const VECTOR   TITLE_PLAYER_POS = VGet(0.0f, 31.5f, 0.0f);
const VECTOR   TITLE_CAMERA_POS = VGet(45.0f, 53.0f, -18.0f);
const VECTOR   TITLE_POOL_SCALE = VGet(1.0f, 1.0f, 1.0f);
const VECTOR   TITLE_POOL_ROTATE = VGet(0.0f, /*90.0f * DX_PI_F / 180.0f*/0.0f, 0.0f);
const VECTOR   TITLE_POOL_POS = VGet(0.0f, 0.0f, 0.0f);
const int         MAX_ALPHA_PAL = 255;
const int        IMG_FADE_SPEED = 3; 

/// <summary>
/// ������
/// </summary>
TitleScene_kiyosumi::TitleScene_kiyosumi()
	: mCamera(nullptr)
	, mTitleUI(nullptr)
	, mBGM(nullptr)
	, mPlayer(nullptr)
	, mClickNormal(nullptr)
	, mPool(nullptr)
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
	mMoveCircle.mPosX = 0.0f;
	mMoveCircle.mPosY = 31.5f;
	mMoveCircle.mPosZ = 0.0f;
	mMoveCircle.mAngle = 0.0f;
	mMoveCircle.mLength = 25.0f;
}

/// <summary>
/// �㏈��
/// </summary>
TitleScene_kiyosumi::~TitleScene_kiyosumi()
{
	delete mCamera;
	delete mTitleUI;
	delete mBGM;
	delete mClickNormal;
	delete mPlayer;
	delete mPool;
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
	static VECTOR cameraPos = VGet(0.0f, 40.0f, -25.0f);
	
	mMoveCircle.mCenterX = mPlayer->GetPositionX();
	mMoveCircle.mCenterY = mPlayer->GetPositionY();
	mMoveCircle.mCenterZ = mPlayer->GetPositionZ();
	

	// ���S���W�Ɋp�x�ƒ������g�p�����~�̈ʒu�����Z����
	// �x���@�̊p�x���ʓx�@�ɕϊ�
	float radius = mMoveCircle.mAngle * DX_PI_F / 180.0f;

	// �O�p�֐����g�p���A�~�̈ʒu������o���B
	float add_x = cos(radius) * mMoveCircle.mLength;
	float add_z = sin(radius) * mMoveCircle.mLength;

	// ���ʂłł��ʒu�𒆐S�ʒu�ɉ��Z���A�����`��ʒu�Ƃ���
	mMoveCircle.mPosX = mMoveCircle.mCenterX + add_x * _deltaTime;
	mMoveCircle.mPosZ = mMoveCircle.mCenterZ + add_z * _deltaTime;

	// �p�x�X�V
	mMoveCircle.mAngle += 1.0f;

	mPool->Update(_deltaTime);

	// �v���C���[�̍X�V
	mPlayer->UpdateActor(_deltaTime);  // 1
	mPlayer->Update(_deltaTime);       // 2 ���̏��Ԃŏ���
	// �^�C�g��UI�̍X�V
	mTitleUI->Update(_deltaTime);
	cameraPos = VAdd(cameraPos, VGet(mMoveCircle.mPosX, 0.0f,mMoveCircle.mPosZ));
	// �J�����̍X�V
	mCamera->Update(cameraPos, mPlayer->GetPosition());
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
		return new PlayScene_kiyosumi();
	}

	// �V�[�����ύX����Ă��Ȃ������玩���̃|�C���^��Ԃ�
	return this;
}

/// <summary>
/// �`��
/// </summary>
void TitleScene_kiyosumi::Draw()
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
	mPool->Draw();
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
void TitleScene_kiyosumi::Sound(float _deltaTime)
{
	// �t�F�[�h�C��/�t�F�[�h�A�E�g(BGM)
	if (mStartButtonFlag && mAlphaPalFlag)
	{
		mBGM->FadeOutMusic(500, _deltaTime);
	}
	else
	{
		mBGM->FadeInMusic(250, _deltaTime);
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
void TitleScene_kiyosumi::Load()
{
	// ���̉�
	mCamera = new Camera;
	mTitleUI = new TitleUI;
	mBGM = new BGM;
	mClickNormal = new SE;
	mPlayer = new PlayerActor;
	mPool = new StaticObjectActor;
	mTitleUI->Load();
	mClickNormal->LoadSound(SOUND_CLICK_HANDLE);
	mBGM->LoadMusic(BGM_HANDLE);
	mMoveSceneHandle = LoadGraph(MOVE_SCENE_IMG);

	mPool->LoadModelTex("data/model/pool/Stadium.mv1", "data/model/pool/Pool.png");
	mPool->SetScale   (TITLE_POOL_SCALE);
	mPool->SetRotation(TITLE_POOL_ROTATE);
	mPool->SetPosition(TITLE_POOL_POS);

	mPlayer->SetPlayerState(PlayerActor::PLAYER_STATE::STATE_TITLE_IDLE);
	mPlayer->LoadModel(PLAYER_MODEL_HANDLE);
	mPlayer->SetScale(TITLE_PLAYER_SCALE);
	mPlayer->SetRotation(TITLE_PLAYER_ROTATE);
	mPlayer->SetPosition(TITLE_PLAYER_POS);
}

