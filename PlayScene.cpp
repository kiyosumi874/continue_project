#include "PlayScene.h"
#include "ResultScene.h"
#include "TitleScene.h"
#include "PlayUI.h"
#include "Camera.h"
#include "BGM.h"
#include "Audience.h"
#include "Pool.h"
#include "PlayerActor.h"

const VECTOR   PLAY_CAMERA_POS = VGet(0.0f, 1.0f, -2.0f);
const VECTOR   PLAY_PLAYER_SCALE = VGet(0.05f, 0.05f, 0.05f);
const VECTOR   PLAY_PLAYER_ROTATE = VGet(0.0f, /*90.0f * DX_PI_F / 180.0f*/0.0f, 0.0f);
const VECTOR   PLAY_PLAYER_POS = VGet(0.0f, 0.0f, 0.0f);

/// <summary>
/// ������
/// </summary>
PlayScene::PlayScene()
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mCamera(nullptr)
	, mPlayUI(nullptr)
	, mGameCountFlag3(true)
	, mScore(0)
	, mPlayCircleGameFlag(true)
	, mPlayGaugeGameFlag(false)
	, mPlayPendulumGameFlag(false)
	, mAlphaPal(255)
	, mAlphaPalFlag(false)
	, mMoveSceneHandle(LoadGraph("data/img/MoveScene.png"))
	, mBGM(nullptr)
	, mBGMFlag(false)
	, mTargetPos(VGet(0.0f, 0.0f, 0.0f))
	, mPool(nullptr)
	, mAudience(nullptr)
	, mPlayer(nullptr)
	, mFadeSpeed(3)
{
}

/// <summary>
/// �㏈��
/// </summary>
PlayScene::~PlayScene()
{
	//delete mPlayCamera;
	delete mCamera;
	delete mPlayUI;
	delete mBGM;
	delete mPool;
	delete mAudience;
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
SceneBase* PlayScene::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime / 1000000.0f;
	//�ϋq�̍X�V
	mAudience->Update(0);
	// �v���CUI�̍X�V
	mPlayUI->Update(mDeltaTime);
	// �v���C���[�̍X�V
	mPlayer->SetPlayerState(PlayerActor::PLAYER_STATE::STATE_PLAY_IDLE);
	mPlayer->UpdateActor(mDeltaTime);
	mPlayer->Update(mDeltaTime);

	// �J�����̍X�V
	mCamera->Update(PLAY_CAMERA_POS, mTargetPos);

	// �U��q�Q�[���I���̃t���O
	mGameCountFlag3 = mPlayUI->GetGameCountFlag3();
	//// �v���C���[���[�V�����J�n
	//mPlayer->SetFlag(mGameCountFlag3);

	mScore = mPlayUI->GetScore();

	if (mAlphaPal >= 0 && !mAlphaPalFlag)
	{
		mAlphaPal -= mFadeSpeed;
	}
	else
	{
		mAlphaPalFlag = true;
	}
	if (!mGameCountFlag3)
	{
		mAlphaPal += mFadeSpeed;
	}
	// �V�[���J�ڏ���
	if (mAlphaPal >= 255)
	{
		// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new ResultScene(mScore);
	}

	// �V�[�����ύX����Ă��Ȃ������玩���̃|�C���^��Ԃ�
	return this;
}

/// <summary>
/// �`��
/// </summary>
void PlayScene::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	mAudience->Draw();
	mPool->Draw();
	// �v���C���[�̕`��
	mPlayer->Draw();
	// �v���CUI�̕`��
	mPlayUI->Draw();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mAlphaPal);
	DrawGraph(0, 0, mMoveSceneHandle, FALSE);
}

/// <summary>
/// ���y
/// </summary>
void PlayScene::Sound()
{
	if (!mGameCountFlag3)
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
	mPlayUI->Sound();
}

/// <summary>
/// ������
/// </summary>
void PlayScene::Load()
{
	mCamera = new Camera;
	mPlayUI = new PlayUI;
	mBGM = new BGM;
	mPool = new Pool;
	mAudience = new Audience;
	mPlayer = new PlayerActor;

	mPlayer->LoadModel(PLAYER_MODEL_HANDLE);
	mPlayer->SetScale   (PLAY_PLAYER_SCALE);
	mPlayer->SetRotation(PLAY_PLAYER_ROTATE);
	mPlayer->SetPosition(PLAY_PLAYER_POS);

	mTargetPos = mAudience->mGetAudiencePos();

	// �v���CUI�̏�����
	mPlayUI->Load();
	mBGM->LoadMusic("data/sound/�v���̃��[���r�[�g.mp3");
}
