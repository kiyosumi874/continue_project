#include "DxLib.h"
#include "ResultUI.h"


/// <summary>
/// ������
/// </summary>
ResultUI::ResultUI()
	: mHandle(0)
	, mDeltaTime(0.000001f)
{
}

/// <summary>
/// �㏈��
/// </summary>
ResultUI::~ResultUI()
{
}

/// <summary>
/// �X�V
/// </summary>
/// <param name="_deltaTime">�f���^�^�C��</param>
void ResultUI::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;

	
}

/// <summary>
/// ������
/// </summary>
void ResultUI::Load()
{
}

/// <summary>
/// �`��
/// </summary>
void ResultUI::Draw()
{
	// �f�o�b�O�p
	printfDx("��ResultUI");
}
