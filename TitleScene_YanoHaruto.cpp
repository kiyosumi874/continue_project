#include "DxLib.h"

#include "TitleScene_YanoHaruto.h"
#include "PlayScene_YanoHaruto.h"

/// <summary>
/// ������
/// </summary>
TitleScene_YanoHaruto::TitleScene_YanoHaruto()
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
{
}

/// <summary>
/// �㏈��
/// </summary>
TitleScene_YanoHaruto::~TitleScene_YanoHaruto()
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
SceneBase* TitleScene_YanoHaruto::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;

	// Enter�L�[�̘A�����͖h�~
	if (!CheckHitKey(KEY_INPUT_RETURN))
	{
		mInputReturnFlag = true;
	}

	// �f�o�b�O�p
	printfDx("��TitleSceneYano\n");

	// �V�[���J�ڏ���
	if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
	{
		mInputReturnFlag = false;
		// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new PlayScene_YanoHaruto();
	}

	// �V�[�����ύX����Ă��Ȃ������玩���̃|�C���^��Ԃ�
	return this;
}

/// <summary>
/// �`��
/// </summary>
void TitleScene_YanoHaruto::Draw()
{
}

/// <summary>
/// ���y
/// </summary>
void TitleScene_YanoHaruto::Sound()
{
}

/// <summary>
/// ������
/// </summary>
void TitleScene_YanoHaruto::Load()
{
}
