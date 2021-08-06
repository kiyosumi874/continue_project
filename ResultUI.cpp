#include "DxLib.h"
#include "ResultUI.h"
#include "PlayUI.h"


/// <summary>
/// ������
/// </summary>
ResultUI::ResultUI()
	: mHandle(0)
	, mDeltaTime(0.000001f)
	, mScore(0)
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
	DrawFormatString(700, 540, GetColor(0, 255, 0), "�X�R�A�F%d", mScore);
}

/// <summary>
/// �X�R�A�����炤�֐�
/// </summary>
/// <param name="_score">�X�R�A</param>
void ResultUI::LoadScore(int _score)
{
	mScore = _score;
}
