//------------------------------------------+
//8/30�X�^�e�B�b�N�I�u�W�F�N�g���g�����v�[���̃��f���ǉ�
//�W/30�A�N�^�[���g�����ϋq�̒ǉ�
//8/30�C���N���[�h����audience.h�ړ�
//by ���
//------------------------------------------+

#include "PlayScene_YanoHaruto.h"
#include "ResultScene_YanoHaruto.h"
#include "TitleScene.h"
#include "PlayUI.h"
#include "Camera.h"
#include "BGM.h"
#include "StaticObjectActor.h"
#include "PlayerActor.h"

const VECTOR   PLAY_CAMERA_POS = VGet(0.0f, 1.0f, -2.0f);
const VECTOR   PLAY_PLAYER_SCALE = VGet(0.05f, 0.05f, 0.05f);
const VECTOR   PLAY_PLAYER_ROTATE = VGet(0.0f, /*90.0f * DX_PI_F / 180.0f*/0.0f, 0.0f);
const VECTOR   PLAY_PLAYER_POS = VGet(0.0f, 0.0f, 0.0f);

//�v�[���̃��f��
const char* POOL_MODEL = "data/model/pool/pool.mv1";

/// <summary>
/// ������
/// </summary>
PlayScene_YanoHaruto::PlayScene_YanoHaruto()
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
	//-------------------------------------------------------------------
	//8/30�ǉ������
	, mAudiencePos(VGet(-45.5f, 10.0f, -30.0f))
	, mAudienceGroundHeight(10.0f)  //�ŏ��Ɏ��̉��������ϋq�̍���
	, mAudienceHighestJumpLine(5.0f)
	, mAudienceJumpPower(0.1f)
	, mAudienceDownFlag(false)
	, mPool(nullptr)
	, mAudience()
	//-------------------------------------------------------------------
	, mMoveSceneHandle(LoadGraph("data/img/MoveScene.png"))
	, mBGM(nullptr)
	, mBGMFlag(false)
	, mTargetPos(VGet(0.0f, 0.0f, 0.0f))
	, mPlayer(nullptr)
	, mFadeSpeed(3)
{
}

/// <summary>
/// �㏈��
/// </summary>
PlayScene_YanoHaruto::~PlayScene_YanoHaruto()
{
	//delete mPlayCamera;
	delete mCamera;
	delete mPlayUI;
	delete mBGM;
	delete mPool;
	//�ϋq�̏���
	for (int i = 0; i < AudienceLine; i++)
	{
		for (int j = 0; j < AudienceNum; j++)
		{
			delete mAudience[i][j];
		}
	}
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
SceneBase* PlayScene_YanoHaruto::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime / 1000000.0f;
	//�ϋq�̍X�V
	//8/30���------------------------------------------------
	for (int i = 0; i < AudienceLine; i++)
	{
		for (int j = 0; j < AudienceNum; j++)
		{
			mAudienceDownFlag = mAudience[i][j]->GetDownFlag();
			mAudience[i][j]->Update(_deltaTime);
			if (mAudienceDownFlag)
			{
				mAudiencePos.y -= mAudienceJumpPower;
			}
			else
			{
				mAudiencePos.y += mAudienceJumpPower;
			}
		}
	}
	//-------------------------------------------------------------
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
		return new ResultScene_YanoHaruto(mScore);
	}

	// �V�[�����ύX����Ă��Ȃ������玩���̃|�C���^��Ԃ�
	return this;
}

/// <summary>
/// �`��
/// </summary>
void PlayScene_YanoHaruto::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	//�ϋq�̕`�� 8/30
	//---------------------------------------------------------
	for (int i = 0; i < AudienceLine; i++)
	{
		for (int j = 0; j < AudienceNum; j++)
		{
			mAudience[i][j]->Draw();
		}
	}
	//---------------------------------------------------------
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
void PlayScene_YanoHaruto::Sound()
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
void PlayScene_YanoHaruto::Load()
{
	mCamera = new Camera;
	mPlayUI = new PlayUI;
	mBGM = new BGM;
	mPool = new StaticObjectActor;

	//�ϋq�̎��̉� 8/30
	//-------------------------------------------------------------------------------------------------
	for (int i = 0; i < AudienceLine; i++)
	{
		for (int j = 0; j < AudienceNum; j++)
		{
			mAudience[i][j] = new Audience(mAudienceGroundHeight,mAudienceHighestJumpLine);
		}
	}
	//-------------------------------------------------------------------------------------------------
	
	mPlayer = new PlayerActor;

	//�v�[���̎��̉��@8/30
	//-------------------------------------------------------------------------------------------------
	mPool->LoadModel(POOL_MODEL);
	mPool->SetScale(VGet(0.005f, 0.005f, 0.005f));
	mPool->SetRotation(VGet(0.0f, 0.0f, 0.0f));
	mPool->SetPosition(VGet(0.0f, 0.0f, 0.0f));
	//-------------------------------------------------------------------------------------------------
	
	mPlayer->LoadModel(PLAYER_MODEL_HANDLE);
	mPlayer->SetScale(PLAY_PLAYER_SCALE);
	mPlayer->SetRotation(PLAY_PLAYER_ROTATE);
	mPlayer->SetPosition(PLAY_PLAYER_POS);

	
	mTargetPos = mAudience[0][0]->GetPosition();

	// �v���CUI�̏�����
	mPlayUI->Load();
	mBGM->LoadMusic("data/sound/�v���̃��[���r�[�g.mp3");
}
