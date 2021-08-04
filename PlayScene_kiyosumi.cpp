#include "DxLib.h"
#include "PlayScene_kiyosumi.h"
#include "ResultScene_kiyosumi.h"
#include "PlayUI.h"
#include "PlayCamera.h"

/// <summary>
/// ������
/// </summary>
PlayScene_kiyosumi::PlayScene_kiyosumi()
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mPlayCamera(nullptr)
	, mPlayUI(nullptr)
{
}

/// <summary>
/// �㏈��
/// </summary>
PlayScene_kiyosumi::~PlayScene_kiyosumi()
{
	delete mPlayCamera;
	delete mPlayUI;
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
	mDeltaTime = _deltaTime;
	// �v���C�J�����̍X�V
	mPlayCamera->Update();

	// �v���CUI�̍X�V
	mPlayUI->Update(mDeltaTime);

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
	// �v���C�J�����̕`��
	mPlayCamera->Draw();
	// �v���CUI�̕`��
	mPlayUI->Draw();
}

/// <summary>
/// ���y
/// </summary>
void PlayScene_kiyosumi::Sound()
{
}

/// <summary>
/// ������
/// </summary>
void PlayScene_kiyosumi::Load()
{
	mPlayCamera = new PlayCamera;
	mPlayUI = new PlayUI;
	// �v���C�J�����̏�����
	mPlayCamera->Load();
	// �v���CUI�̏�����
	mPlayUI->Load();
}
