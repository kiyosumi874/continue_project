#include "DxLib.h"
#include "ResultScene_YanoHaruto.h"
#include "TitleScene_YanoHaruto.h"

/// <summary>
/// ������
/// </summary>
ResultScene_YanoHaruto::ResultScene_YanoHaruto(int _score)
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mScore(_score)
{
}

/// <summary>
/// �㏈��
/// </summary>
ResultScene_YanoHaruto::~ResultScene_YanoHaruto()
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
SceneBase* ResultScene_YanoHaruto::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;

	// Enter�L�[�̘A�����͖h�~
	if (!CheckHitKey(KEY_INPUT_RETURN))
	{
		mInputReturnFlag = true;
	}

	// �f�o�b�O�p
	printfDx("��ResultScene_YanoHaruto\n");

	// �V�[���J�ڏ���
	if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
	{
		mInputReturnFlag = false;
		// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new TitleScene_YanoHaruto();
	}

	// �V�[�����ύX����Ă��Ȃ������玩���̃|�C���^��Ԃ�
	return this;
}

/// <summary>
/// �`��
/// </summary>
void ResultScene_YanoHaruto::Draw()
{
}

/// <summary>
/// ���y
/// </summary>
void ResultScene_YanoHaruto::Sound()
{
}

/// <summary>
/// ������
/// </summary>
void ResultScene_YanoHaruto::Load()
{
}
