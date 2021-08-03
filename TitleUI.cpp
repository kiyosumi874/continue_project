#include "DxLib.h"
#include "TitleUI.h"

#define RED   GetColor(255, 0, 0)
#define GREEN GetColor(0, 255, 0)
#define BLUE  GetColor(0, 0, 255)
/// <summary>
/// ������
/// </summary>
TitleUI::TitleUI()
	: mHandle(0)
	, mDeltaTime(0.000001f)
	, mStartButtonBeginX(480)
	, mStartButtonBeginY(675)
	, mStartButtonEndX(1440)
	, mStartButtonEndY(945)
	, mStartButtonFontSize(200)
	, mStartButtonFlag(false)
	, mInputReturnFlag(false)
{
}

/// <summary>
/// �㏈��
/// </summary>
TitleUI::~TitleUI()
{

}

/// <summary>
/// �X�V
/// </summary>
/// <param name="_deltaTime">�f���^�^�C��</param>
void TitleUI::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;

	// Enter�L�[�̘A�����͖h�~
	if (!CheckHitKey(KEY_INPUT_RETURN))
	{
		mInputReturnFlag = true;
	}

	if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
	{
		mInputReturnFlag = false;
		mStartButtonFlag = true;
	}
}

/// <summary>
/// ������
/// </summary>
void TitleUI::Load()
{
	mStartButtonFlag = false;
	mHandle = 0;
	mDeltaTime = 0.000001f;
	mStartButtonBeginX = 480;
	mStartButtonBeginY = 675;
	mStartButtonEndX = 1440;
	mStartButtonEndY = 945;
	mStartButtonFontSize = 200;
	mStartButtonFlag = false;
	mInputReturnFlag = false;
}

/// <summary>
/// �`��
/// </summary>
void TitleUI::Draw()
{
	//----------------//
	// �X�^�[�g�{�^�� //
    //----------------//
	
	if (!mStartButtonFlag)
	{
		DrawBox(mStartButtonBeginX, mStartButtonBeginY, mStartButtonEndX, mStartButtonEndY, GREEN, FALSE);
		SetFontSize(mStartButtonFontSize);
		DrawString(mStartButtonBeginX + 45, mStartButtonBeginY + 30, "Enter�L�[", RED);
	}
	else
	{
		DrawBox(mStartButtonBeginX, mStartButtonBeginY, mStartButtonEndX, mStartButtonEndY, RED, FALSE);
		SetFontSize(mStartButtonFontSize);
		DrawString(mStartButtonBeginX + 45, mStartButtonBeginY + 30, "Enter�L�[", GREEN);
	}
	
}
 