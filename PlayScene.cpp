#include "PlayScene.h"
#include "ResultScene.h"
#include "PlayUI.h"
#include "PlayCamera.h"
#include "BGM.h"
#include "Audience.h"
#include "Pool.h"
#include "Player.h"


/// <summary>
/// ������
/// </summary>
PlayScene::PlayScene()
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mPlayCamera(nullptr)
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
{
}

/// <summary>
/// �㏈��
/// </summary>
PlayScene::~PlayScene()
{
	delete mPlayCamera;
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
	// �v���C�J�����̍X�V
	mPlayCamera->Update();
	//�ϋq�̍X�V
	mAudience->Update();
	// �v���CUI�̍X�V
	mPlayUI->Update(mDeltaTime);
	// �v���C���[�̍X�V
	mPlayer->Update(mDeltaTime);
	mGameCountFlag3 = mPlayUI->GetGameCountFlag3();
	// �v���C���[���[�V�����J�n
	mPlayer->SetFlag(mGameCountFlag3);

	mScore = mPlayUI->GetScore();

	if (mAlphaPal >= 0 && !mAlphaPalFlag)
	{
		mAlphaPal -= 400.0f * mDeltaTime;
	}
	else
	{
		mAlphaPalFlag = true;
	}
	if (!mGameCountFlag3)
	{
		mAlphaPal += 400.0f * mDeltaTime;
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
	mPlayCamera = new PlayCamera;
	mPlayUI = new PlayUI;
	mBGM = new BGM;
	mPool = new Pool;
	mAudience = new Audience;
	mPlayer = new Player;
	// �v���C�J�����̏�����
	mPlayCamera->Load();
	mTargetPos = mAudience->mGetAudiencePos();
	mPlayCamera->SetTargetPos(mTargetPos);
	// �v���CUI�̏�����
	mPlayUI->Load();
	mBGM->LoadMusic("data/sound/�v���̃��[���r�[�g.mp3");
}
