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
	mFontHandle = CreateFontToHandle("data/Fonts/meiryob.tcc", 170 /** 2 / 3*/, -1, DX_FONTTYPE_ANTIALIASING_4X4, -1, 5, FALSE);
}

/// <summary>
/// �㏈��
/// </summary>
ResultUI::~ResultUI()
{
	DeleteFontToHandle(mFontHandle);
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
	DrawFormatStringToHandle(400 /** 2 / 3*/, 540 /** 2 / 3*/, GetColor(0, 255, 0), mFontHandle, "�X�R�A�F%d", mScore);
}

/// <summary>
/// �X�R�A�����炤�֐�
/// </summary>
/// <param name="_score">�X�R�A</param>
void ResultUI::LoadScore(int _score)
{
	mScore = _score;
}
