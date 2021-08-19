#include "DxLib.h"
#include "PlayScene_kiyosumi.h"
#include "ResultScene_kiyosumi.h"
#include "PlayUI.h"
#include "PlayCamera.h"
#include "BGM.h"

/// <summary>
/// ������
/// </summary>
PlayScene_kiyosumi::PlayScene_kiyosumi()
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
{
}

/// <summary>
/// �㏈��
/// </summary>
PlayScene_kiyosumi::~PlayScene_kiyosumi()
{
	delete mPlayCamera;
	delete mPlayUI;
	delete mBGM;
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="_deltaTime">�f���^�^�C��</param>
/// <returns>
/// Enter���������Ƃ��Ɏ��̃V�[����Instance�̃|�C���^��Ԃ�
/// ����ȊO�͎����̃|�C���^��Ԃ�
/// </returns>
SceneBase* PlayScene_kiyosumi::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime / 1000000.0f;
	// �v���C�J�����̍X�V
	mPlayCamera->Update();

	// �v���CUI�̍X�V
	mPlayUI->Update(mDeltaTime);
	mGameCountFlag3 = mPlayUI->GetGameCountFlag3();

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
		return new ResultScene_kiyosumi(mScore);
	}

	//// Enter�L�[�̘A�����͖h�~
	//if (!CheckHitKey(KEY_INPUT_RETURN))
	//{
	//	mInputReturnFlag = true;
	//}

	//// �V�[���J�ڏ���
	//if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
	//{
	//	mInputReturnFlag = false;
	//	// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
	//	return new ResultScene_kiyosumi();
	//}

	// �V�[�����ύX����Ă��Ȃ������玩���̃|�C���^��Ԃ�
	return this;
}

/// <summary>
/// �`��
/// </summary>
void PlayScene_kiyosumi::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	// �v���C�J�����̕`��
	mPlayCamera->Draw();
	// �v���CUI�̕`��
	mPlayUI->Draw();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mAlphaPal);
	DrawGraph(0, 0, mMoveSceneHandle, FALSE);
}

/// <summary>
/// ���y
/// </summary>
void PlayScene_kiyosumi::Sound()
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
void PlayScene_kiyosumi::Load()
{
	////�u�ǂݍ��ݒ��v�̕\��
	//DrawString(0, 0, "Now Loading ...", GetColor(255, 255, 255));
	mPlayCamera = new PlayCamera;
	mPlayUI = new PlayUI;
	mBGM = new BGM;
	// �v���C�J�����̏�����
	mPlayCamera->Load();
	// �v���CUI�̏�����
	mPlayUI->Load();
	mBGM->LoadMusic("data/sound/�v���̃��[���r�[�g.mp3");
}
