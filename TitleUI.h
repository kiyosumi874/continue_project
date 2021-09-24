//----------------------------------------------------------------------------------//
// @file         TitleUI.h
// @brief        TitleUI�N���X
// @note         �p����:UIBase�N���X              
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/31    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once
#include "UIBase.h"

class TitleUI : public UIBase
{
public:
	 TitleUI();    // �R���X�g���N�^
	~TitleUI();    // �f�X�g���N�^

	void Update(float _deltaTime)override;    // �X�V
	void Load()                  override;    // ���[�h
	void Draw()                  override;    // �`��

	void AlphaCount(float _deltaTime);

	// �X�^�[�g�{�^���̃t���O�̃Q�b�^�[
	const bool& GetStartButtonFlag() const { return mStartButtonFlag; }
private:
	float mDeltaTime;    // �f���^�^�C��

	// "Enter�L�[�������Ă�������"UI�p�ϐ�
	int   mHandlePressEnter;
	int mPosPressEnterX;
	int mPosPressEnterY;
	int mSizePressEnterW;
	int mSizePressEnterH;
	double mScalePressEnter;

	int   mHandle2;       // �n���h���i�[�ϐ�
	int mSize2X;
	int mSize2Y;

	// �^�C�g�����SUI�p�ϐ�
	int   mHandleTitleLogo;
	int mPosTitleLogoX;           // �`��̎n�_�ƂȂ�X���W
	int mPosTitleLogoY;           // �`��̎n�_�ƂȂ�Y���W
	int mSizeTitleLogoW;          // �^�C�g�����S�摜�̉��T�C�Y
	int mSizeTitleLogoH;          // �^�C�g�����S�摜�̏c�T�C�Y
	double mScaleTitleLogo;       // �`�掞�Ɏg�p����X�P�[��
	float mFloatingCounter;         // ���S�㉺�ɓ�����

	double mAlphaPal;
	int mAlphaCount;

	// �X�N���[���T�C�Y(�E�B���h�E�̏c�Ɖ�)
	int mScreenSizeW;
	int mScreenSizeH;

	// �X�^�[�g�{�^���̈ʒu�����߂�ϐ�
	int mStartButtonBeginX;    // �����X
	int mStartButtonBeginY;    // �����Y
	int mStartButtonEndX;      // �E����X
	int mStartButtonEndY;	   // �E����Y
	// �X�^�[�g�{�^���̃t�H���g�T�C�Y
	int mStartButtonFontSize;
	// �X�^�[�g�{�^���̃t���O
	bool mStartButtonFlag;

	bool mInputReturnFlag;    // Enter�L�[�̘A�����͖h�~

	int mFontHandle;

	float mTmpTime;
	bool mTmpTimeFlag;

};