#include "DxLib.h"
#include "ResultScene_kiyosumi.h"
#include "TitleScene_kiyosumi.h"

/// <summary>
/// ������
/// </summary>
ResultScene_kiyosumi::ResultScene_kiyosumi()
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mResultUI(new ResultUI)
{
}

/// <summary>
/// �㏈��
/// </summary>
ResultScene_kiyosumi::~ResultScene_kiyosumi()
{
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

	// ���U���gUI�̍X�V
	mResultUI->Update(mDeltaTime);

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
	// ���U���gUI�̕`��
	mResultUI->Draw();
	// �f�o�b�O�p
	printfDx("��ResultScene_kiyosumi\n");
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
	// ���U���gUI�̏�����
	mResultUI->Load();
}
