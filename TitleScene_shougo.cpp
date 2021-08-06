#include "DxLib.h"

#include "TitleScene_shougo.h"
#include "PlayScene_shougo.h"

#include "TitleUI.h"
#include "TitleCamera_shougo.h"



/// <summary>
/// ������
/// </summary>
TitleScene_shougo::TitleScene_shougo()
	: mTitleCamera(nullptr)
	, mTitleUI(nullptr)
	, mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mSceneTransitionCount(0)
	, mStartButtonFlag(false)
	, mRotate(0.0f)
{
	// �L�����\���f�o�b�O�p
	mHandle = MV1LoadModel("data/model/player/Alicia_solid.pmx");
	MV1SetScale(mHandle, VGet(0.5f, 0.5f, 0.5f));
	MV1SetPosition(mHandle, VGet(0, -5, 10));

}

/// <summary>
/// �㏈��
/// </summary>
TitleScene_shougo::~TitleScene_shougo()
{
	delete mTitleCamera;
	delete mTitleUI;
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
SceneBase* TitleScene_shougo::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;
	// �^�C�g���J�����̍X�V
	mTitleCamera->Update();


	// �L�����\���f�o�b�O�p
	mRotate += 5.0f * mDeltaTime;
	MV1SetRotationXYZ(mHandle, VGet(0.0f, mRotate, 0.0f));

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
		return new PlayScene_shougo();
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
void TitleScene_shougo::Draw()
{
	// �^�C�g���J�����̕`��
	mTitleCamera->Draw();

	// �L�����\���f�o�b�O�p
	MV1DrawModel(mHandle);

	// �^�C�g��UI�̕`��
	mTitleUI->Draw();
}

/// <summary>
/// ���y
/// </summary>
void TitleScene_shougo::Sound()
{
}

/// <summary>
/// ������
/// </summary>
void TitleScene_shougo::Load()
{
	mTitleCamera = new TitleCamera_shougo;
	mTitleUI = new TitleUI;

	// �^�C�g���J�����̏�����
	mTitleCamera->Load();
	// �^�C�g��UI�̏�����
	mTitleUI->Load();

}
