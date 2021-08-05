#include "DxLib.h"
#include "ResultScene_kiyosumi.h"
#include "TitleScene_kiyosumi.h"
#include "ResultCamera.h"
#include "ResultUI.h"

/// <summary>
/// ������
/// </summary>
ResultScene_kiyosumi::ResultScene_kiyosumi(int _score)
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mResultCamera(nullptr)
	, mResultUI(nullptr)
	, mScore(_score)
{
}

/// <summary>
/// �㏈��
/// </summary>
ResultScene_kiyosumi::~ResultScene_kiyosumi()
{
	delete mResultCamera;
	delete mResultUI;
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="_deltaTime">�f���^�^�C��</param>
/// <returns>
/// Enter���������Ƃ��Ɏ��̃V�[����Instance�̃|�C���^��Ԃ�
/// ����ȊO�͎����̃|�C���^��Ԃ�
/// </returns>
SceneBase* ResultScene_kiyosumi::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;
	// ���U���g�J�����̍X�V
	mResultCamera->Update();
	// ���U���gUI�̍X�V
	mResultUI->Update(mDeltaTime);
	// ���U���gUI�ɃX�R�A��n��
	mResultUI->LoadScore(mScore);

	// Enter�L�[�̘A�����͖h�~
	if (!CheckHitKey(KEY_INPUT_RETURN))
	{
		mInputReturnFlag = true;
	}

	

	// �V�[���J�ڏ���
	if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
	{
		mInputReturnFlag = false;
		// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new TitleScene_kiyosumi();
	}

	// �V�[�����ύX����Ă��Ȃ������玩���̃|�C���^��Ԃ�
	return this;
}

/// <summary>
/// �`��
/// </summary>
void ResultScene_kiyosumi::Draw()
{
	// ���U���g�J�����̕`��
	mResultCamera->Draw();
	// ���U���gUI�̕`��
	mResultUI->Draw();
}

/// <summary>
/// ���y
/// </summary>
void ResultScene_kiyosumi::Sound()
{
}

/// <summary>
/// ������
/// </summary>
void ResultScene_kiyosumi::Load()
{
	mResultCamera = new ResultCamera;
	mResultUI = new ResultUI;

	// ���U���g�J�����̏�����
	mResultCamera->Load();
	// ���U���gUI�̏�����
	mResultUI->Load();
}
