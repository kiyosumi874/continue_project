#include "DxLib.h"
#include "PlayScene_kiyosumi.h"
#include "ResultScene.h"

/// <summary>
/// ������
/// </summary>
PlayScene_kiyosumi::PlayScene_kiyosumi()
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
{
}

/// <summary>
/// �㏈��
/// </summary>
PlayScene_kiyosumi::~PlayScene_kiyosumi()
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
SceneBase* PlayScene_kiyosumi::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;

	// Enter�L�[�̘A�����͖h�~
	if (!CheckHitKey(KEY_INPUT_RETURN))
	{
		mInputReturnFlag = true;
	}

	// �f�o�b�O�p
	printfDx("��PlayScene_kiyosumi\n");

	// �V�[���J�ڏ���
	if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
	{
		mInputReturnFlag = false;
		// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new ResultScene();
	}

	// �V�[�����ύX����Ă��Ȃ������玩���̃|�C���^��Ԃ�
	return this;
}

/// <summary>
/// �`��
/// </summary>
void PlayScene_kiyosumi::Draw()
{
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
}