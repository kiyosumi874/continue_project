#include "DxLib.h"
#include "PlayUI.h"

/// <summary>
/// ������
/// </summary>
PlayUI::PlayUI()
	: mHandle(0)
	, mDeltaTime(0.000001f)
{
}

/// <summary>
/// �㏈��
/// </summary>
PlayUI::~PlayUI()
{
}

/// <summary>
/// �X�V
/// </summary>
/// <param name="_deltaTime">�f���^�^�C��</param>
void PlayUI::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;
}

/// <summary>
/// ������
/// </summary>
void PlayUI::Load()
{
}

/// <summary>
/// �`��
/// </summary>
void PlayUI::Draw()
{
	// �f�o�b�O�p
	printfDx("��PlayUI");
}
