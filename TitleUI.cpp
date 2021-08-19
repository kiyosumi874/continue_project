#include "DxLib.h"
#include "TitleUI.h"

#define RED   GetColor(255, 0, 0)
#define GREEN GetColor(0, 255, 0)
#define BLUE  GetColor(0, 0, 255)
#define BLACK  GetColor(0, 0, 0)
#define WHITE  GetColor(255, 255, 255)
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
	, mStartButtonFontSize(170 /** 2 / 3*/)
	, mStartButtonFlag(false)
	, mInputReturnFlag(false)
{
	//                                     �쐬����t�H���g��,     �t�H���g�̃T�C�Y,  �t�H���g�̑���,                  �t�H���g�̃^�C�v, �����Z�b�g, ���̑���, �C�^���b�N�̂ɂ��邩�ǂ���
	mFontHandle = CreateFontToHandle("data/Fonts/meiryob.tcc", mStartButtonFontSize,              -1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4,         -1,        5,                       TRUE);
}

/// <summary>
/// �㏈��
/// </summary>
TitleUI::~TitleUI()
{
	DeleteFontToHandle(mFontHandle);
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
	// 1920*1080 * 2/3
	//if (!mStartButtonFlag)
	//{
	//	DrawBox(mStartButtonBeginX*2/3, mStartButtonBeginY * 2 / 3, mStartButtonEndX * 2 / 3, mStartButtonEndY * 2 / 3, GREEN, FALSE);
	//	//SetFontSize(mStartButtonFontSize);
	//	//DrawString(mStartButtonBeginX + 45, mStartButtonBeginY + 30, "Enter�L�[", RED);
	//	DrawStringToHandle(mStartButtonBeginX * 2 / 3 + 45, mStartButtonBeginY * 2 / 3 + 35, "Enter�L�[", WHITE, mFontHandle, BLACK);
	//}
	//else
	//{
	//	DrawBox(mStartButtonBeginX * 2 / 3, mStartButtonBeginY * 2 / 3, mStartButtonEndX * 2 / 3, mStartButtonEndY * 2 / 3, RED, FALSE);
	//	//SetFontSize(mStartButtonFontSize);
	//	//DrawString(mStartButtonBeginX + 45, mStartButtonBeginY + 30, "Enter�L�[", GREEN);
	//	DrawStringToHandle(mStartButtonBeginX * 2 / 3 + 45, mStartButtonBeginY * 2 / 3 + 35, "Enter�L�[", WHITE, mFontHandle, BLACK);
	//}

	// 1920*1080
	if (!mStartButtonFlag)
	{
		DrawBoxAA(mStartButtonBeginX, mStartButtonBeginY, mStartButtonEndX, mStartButtonEndY, GREEN, FALSE);
		//SetFontSize(mStartButtonFontSize);
		//DrawString(mStartButtonBeginX + 45, mStartButtonBeginY + 30, "Enter�L�[", RED);
		DrawStringToHandle(mStartButtonBeginX + 45, mStartButtonBeginY + 35, "Enter�L�[", WHITE, mFontHandle, BLACK);
	}
	else
	{
		DrawBoxAA(mStartButtonBeginX, mStartButtonBeginY, mStartButtonEndX, mStartButtonEndY, RED, FALSE);
		//SetFontSize(mStartButtonFontSize);
		//DrawString(mStartButtonBeginX + 45, mStartButtonBeginY + 30, "Enter�L�[", GREEN);
		DrawStringToHandle(mStartButtonBeginX + 45, mStartButtonBeginY + 35, "Enter�L�[", WHITE, mFontHandle, BLACK);
	}
}
 