#include "DxLib.h"

#include "TitleScene_kiyosumi.h"
#include "PlayScene_kiyosumi.h"

#include "TitleUI.h"
#include "TitleCamera.h"



/// <summary>
/// ������
/// </summary>
TitleScene_kiyosumi::TitleScene_kiyosumi()
	: mTitleUI(nullptr)
	, mTitleCamera(nullptr)
	, mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mSceneTransitionCount(0)
	, mStartButtonFlag(false)
{
	// �L�����\���f�o�b�O�p
	mHandle = MV1LoadModel("data/model/player/Alicia_solid.pmx");
	MV1SetScale(mHandle, VGet(0.5f, 0.5f, 0.5f));
	MV1SetPosition(mHandle, VGet(0, -5, 10));

}

/// <summary>
/// �㏈��
/// </summary>
TitleScene_kiyosumi::~TitleScene_kiyosumi()
{
	delete mTitleUI;
	delete mTitleCamera;
	MV1DeleteModel(mHandle);
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
	mDeltaTime = _deltaTime;
	// �^�C�g���J�����̍X�V
	mTitleCamera->Update();

	// �^�C�g��UI�̍X�V
	mTitleUI->Update(mDeltaTime);
	mStartButtonFlag = mTitleUI->GetStartButtonFlag();
	
	//// Enter�L�[�̘A�����͖h�~
	//if (!CheckHitKey(KEY_INPUT_RETURN))
	//{
	//	mInputReturnFlag = true;
	//}

	if (mStartButtonFlag)
	{
		mSceneTransitionCount += 1.0f * mDeltaTime;
	}

	// �V�[���J�ڏ���
	if (mSceneTransitionCount >= 0.5f)
	{
		// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new PlayScene_kiyosumi();
	}

	//// �V�[���J�ڏ���
	//if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
	//{
	//	mInputReturnFlag = false;
	//	// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
	//	return new PlayScene_kiyosumi();
	//}

	// �V�[�����ύX����Ă��Ȃ������玩���̃|�C���^��Ԃ�
	return this;
}

/// <summary>
/// �`��
/// </summary>
void TitleScene_kiyosumi::Draw()
{
	// �^�C�g���J�����̕`��
	mTitleCamera->Draw();
	// �^�C�g��UI�̕`��
	mTitleUI->Draw();

	// �L�����\���f�o�b�O�p
	MV1DrawModel(mHandle);
}

/// <summary>
/// ���y
/// </summary>
void TitleScene_kiyosumi::Sound()
{
}

/// <summary>
/// ������
/// </summary>
void TitleScene_kiyosumi::Load()
{
	mTitleUI = new TitleUI;
	mTitleCamera = new TitleCamera;
	mDeltaTime = 0.000001f;
	mInputReturnFlag = false;
	mSceneTransitionCount = 0;
	mStartButtonFlag = false;

	// �L�����\���f�o�b�O�p
	mHandle = MV1LoadModel("data/model/player/Alicia_solid.pmx");
	MV1SetScale(mHandle, VGet(0.5f, 0.5f, 0.5f));
	MV1SetPosition(mHandle, VGet(0, -5, 10));

	// �^�C�g���J�����̏�����
	mTitleCamera->Load();
	// �^�C�g��UI�̏�����
	mTitleUI->Load();

}
