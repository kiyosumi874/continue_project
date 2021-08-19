#include "DxLib.h"
#include "PlayScene_shougo.h"
#include "ResultScene_shougo.h"
#include "PlayUI.h"
#include "PlayCamera_shougo.h"
#include "Object_shougo.h"
#include "Player.h"

/// <summary>
/// ������
/// </summary>
PlayScene_shougo::PlayScene_shougo()
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mPlayCamera(nullptr)
	, mPlayUI(nullptr)
	, mObject(nullptr)
	, mPlayer(nullptr)
	, mGameCountFlag3(true)
	, mScore(0)
{
}

/// <summary>
/// �㏈��
/// </summary>
PlayScene_shougo::~PlayScene_shougo()
{
	delete mPlayCamera;
	delete mPlayUI;
	delete mObject;
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
SceneBase* PlayScene_shougo::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;

	// �v���CUI�̍X�V
	mPlayUI->Update(mDeltaTime);
	mGameCountFlag3 = mPlayUI->GetGameCountFlag3();
	mScore = mPlayUI->GetScore();

	// �v���C���[�̍X�V
	mPlayer->Update(mDeltaTime);

	mPlayCamera->SetTargetPosition(mPlayer->PlayerGetPosition());

	// �v���C�J�����̍X�V
	mPlayCamera->Update();

	// �V�[���J�ڏ���
	if (!mGameCountFlag3)
	{
		// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new ResultScene_shougo(mScore);
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
void PlayScene_shougo::Draw()
{
	// �v���C�J�����̕`��
	mPlayCamera->Draw();
	// �v���C���[�̕`��
	mPlayer->Draw();
	// �X�e�[�W�̕`��
	mObject->Draw();
	// �v���CUI�̕`��
	mPlayUI->Draw();
	
}

/// <summary>
/// ���y
/// </summary>
void PlayScene_shougo::Sound()
{
}

/// <summary>
/// ������
/// </summary>
void PlayScene_shougo::Load()
{
	mPlayCamera = new PlayCamera_shougo;
	mPlayUI = new PlayUI;
	mObject = new Object_shougo;
	mPlayer = new Player;
	// �v���C�J�����̏�����
	mPlayCamera->Load();
	// �v���CUI�̏�����
	mPlayUI->Load();
}
