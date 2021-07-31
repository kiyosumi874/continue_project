#include "DxLib.h"

#include "TitleScene.h"
#include "PlayScene.h"

/// <summary>
/// ������
/// </summary>
TitleScene::TitleScene()
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
{
}

/// <summary>
/// �㏈��
/// </summary>
TitleScene::~TitleScene()
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
SceneBase* TitleScene::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;

	// Enter�L�[�̘A�����͖h�~
	if (!CheckHitKey(KEY_INPUT_RETURN))
	{
		mInputReturnFlag = true;
	}

	// �f�o�b�O�p
	printfDx("��TitleScene\n");

	// �V�[���J�ڏ���
	if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
	{
		mInputReturnFlag = false;
		// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new PlayScene();
	}

	// �V�[�����ύX����Ă��Ȃ������玩���̃|�C���^��Ԃ�
	return this;
}

/// <summary>
/// �`��
/// </summary>
void TitleScene::Draw()
{
}

/// <summary>
/// ���y
/// </summary>
void TitleScene::Sound()
{
}

/// <summary>
/// ������
/// </summary>
void TitleScene::Load()
{
}
