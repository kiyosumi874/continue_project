#include "DxLib.h"
#include "Audience.h"
#include "ResultScene_YanoHaruto.h"
#include "PlayScene_YanoHaruto.h"
#include "PlayCamera_YanoHaruto.h"
#include "Pool.h"

/// <summary>
/// ������
/// </summary>
PlayScene_YanoHaruto::PlayScene_YanoHaruto()
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
{
	mTargetPos = VGet(0.0f, 0.0f, 0.0f);
}

/// <summary>
/// �㏈��
/// </summary>
PlayScene_YanoHaruto::~PlayScene_YanoHaruto()
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
SceneBase* PlayScene_YanoHaruto::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;
	//�v���C�J�����̍X�V
	mPlayCamera->Update();
	//�ϋq�̍X�V
	mAudience->Update();
	// Enter�L�[�̘A�����͖h�~
	if (!CheckHitKey(KEY_INPUT_RETURN))
	{
		mInputReturnFlag = true;
	}

	// �f�o�b�O�p
	printfDx("��PlayScene_YanoHaruto\n");

	// �V�[���J�ڏ���
	if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
	{
		mInputReturnFlag = false;
		// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new ResultScene_YanoHaruto();
	}

	// �V�[�����ύX����Ă��Ȃ������玩���̃|�C���^��Ԃ�
	return this;
}

/// <summary>
/// �`��8/12�ǉ�
/// </summary>
void PlayScene_YanoHaruto::Draw()
{
	mAudience->Draw();
	mPool->Draw();
	mPlayCamera->Draw();
}

/// <summary>
/// ���y
/// </summary>
void PlayScene_YanoHaruto::Sound()
{
}

/// <summary>
/// ������8/12�ǋL
/// </summary>
void PlayScene_YanoHaruto::Load()
{	
	mPool = new Pool;
	mAudience = new Audience;
	mPlayCamera = new PlayCamera_YanoHaruto;
	mTargetPos = mAudience->mGetAudiencePos();
	mPlayCamera->mSetTargetPos(mTargetPos);
}
