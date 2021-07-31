#include "DxLib.h"
#include "ResultScene_kiyosumi.h"
#include "TitleScene_kiyosumi.h"

/// <summary>
/// ������
/// </summary>
ResultScene_kiyosumi::ResultScene_kiyosumi()
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
{
}

/// <summary>
/// �㏈��
/// </summary>
ResultScene_kiyosumi::~ResultScene_kiyosumi()
{
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

	// Enter�L�[�̘A�����͖h�~
	if (!CheckHitKey(KEY_INPUT_RETURN))
	{
		mInputReturnFlag = true;
	}

	// �f�o�b�O�p
	printfDx("��ResultScene_kiyosumi\n");

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
}
