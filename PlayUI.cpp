#include "DxLib.h"
#include "PlayUI.h"
#include "SE.h"
#include "Effect.h"
#include <math.h>

#define GRAVITY 9.80665f

/// <summary>
/// ������
/// </summary>
PlayUI::PlayUI()
	: mScore(0)
	, mInputReturnFlag(false)
	, mClickNormalFlag(false)
	, mClickCriticalFlag(false)
	, mMetoronomeFlag(false)
	// CircleGame
	, mCircleSpeed(0)
	, mCircleOutX(960)
	, mCircleOutY(540)
	, mCircleOutRadius(200)
	, mCircleOutColor(GetColor(0, 0, 255))
	, mCircleOutFillFlag(false)
	, mCircleOutLineThickness(3)
	, mCircleInX(960)
	, mCircleInY(540)
	, mCircleInRadius(30)
	, mCircleInColor(GetColor(255, 0, 0))
	, mCircleInFillFlag(true)
	, mPlayCircleGameFlag(true)
	// GaugeGame
	, mGaugeSpeed(0)
	, mGaugeOutBeginX(920)
	, mGaugeOutBeginY(360)
	, mGaugeOutEndX(1000)
	, mGaugeOutEndY(720)
	, mGaugeOutColor(GetColor(0, 0, 255))
	, mGaugeOutFillFlag(false)
	, mGaugeInBeginX(920)
	, mGaugeInBeginY(720)
	, mGaugeInEndX(1000)
	, mGaugeInEndY(720)
	, mGaugeInColor(GetColor(255, 0, 0))
	, mGaugeInFillFlag(true)
	, mPlayGaugeGameFlag(true)
	// PendulumGame
	, mPendulumSpeed(0)
	, mPendulumOutX(960)
	, mPendulumOutY(700)
	, mPendulumOutRadius(30)
	, mPendulumOutColor(GetColor(0, 0, 255))
	, mPendulumOutFillFlag(false)
	, mPendulumOutLineThickness(3)
	, mPendulumInX(960+300)
	, mPendulumInFx(960)
	, mPendulumInY(700-300)
	, mPendulumInFy(400)
	, mPendulumInAngle(0.0f)
	, mPendulumInAngleSpeed(0.0f)
	, mPendulumLength(300)
	, mPendulumInRadius(30)
	, mPendulumInColor(GetColor(255, 0, 0))
	, mPendulumInFillFlag(true)
	, mPlayPendulumGameFlag(true)
	, mFontHandle(-1)
	, mDrawGameState(DRAW_GAME_STATE::DRAW_NULL)
	//-------------------------------------------------- Effect�ǉ�
	, mCriticalEffect(nullptr)
	, mUIEffect(nullptr)
	, mBadEffect(nullptr)
	, mBadFlag(false)
{
	tmpX = 565;
	tmpY = 880;
}

/// <summary>
/// �㏈��
/// </summary>
PlayUI::~PlayUI()
{
	DeleteFontToHandle(mFontHandle);
	//----------------------------------------------------------------------�G�t�F�N�g�ǉ�
	mCriticalEffect->StopEffect2D();
	mCriticalEffect->Delete();
	delete mCriticalEffect;
	mUIEffect->StopEffect2D();
	mUIEffect->Delete();
	delete mUIEffect;
	mBadEffect->StopEffect2D();
	mBadEffect->Delete();
	delete mBadEffect;
}

/// <summary>
/// �X�V
/// </summary>
/// <param name="_deltaTime">�f���^�^�C��</param>
void PlayUI::Update(float _deltaTime)
{
	/*if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		tmpX += 15;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		tmpX += -15;
	}
	if (CheckHitKey(KEY_INPUT_UP))
	{
		tmpY += -15;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		tmpY += 15;
	}*/
}

/// <summary>
/// ������
/// </summary>
void PlayUI::Load()
{
	
	mFontHandle = CreateFontToHandle("data/Fonts/meiryob.tcc", 170 * 2 / 3, -1, DX_FONTTYPE_ANTIALIASING_4X4, -1, 5, FALSE);
	mHandle = LoadGraph("data/img/taiming.png");
	mHandle2 = LoadGraph("data/img/keyboard_Enter2.png");
	mGaugeHandle = LoadGraph("data/img/PlayUI2-1.png");
	mGaugeHandle2 = LoadGraph("data/img/PlayUI2-2.png");
	//----------------------------------------------------------------------------�G�t�F�N�g�ǉ�
	mCriticalEffect = new Effect("data/effect/UIEffect2.efk", 50.0f);
	mUIEffect = new Effect("data/effect/UIEffect1.efk", 50.0f);
	mBadEffect = new Effect("data/effect/BadEffect.efk", 40.0f);
}

/// <summary>
/// �`��
/// </summary>
void PlayUI::Draw()
{
	// �f�o�b�O�p
	//DrawFormatStringToHandle(0, 0, GetColor(0, 255, 0), mFontHandle,"�X�R�A�F%d", mScore);

	//DrawStringToHandle()
	
	

	if (mDrawGameState == DRAW_GAME_STATE::DRAW_CIRCLE_GAME)
	{
		// �����̉~
		DrawCircleAA(mCircleInX - 150, mCircleInY + 50, 32, 64, GetColor(0,0,0), mCircleInFillFlag);
		DrawCircleAA(mCircleInX-150, mCircleInY+50, mCircleInRadius, 64, mCircleInColor, mCircleInFillFlag);
		// �O���̉~
		DrawCircleAA(mCircleOutX-150, mCircleOutY+50, mCircleOutRadius, 64, mCircleOutColor, mCircleOutFillFlag, mCircleOutLineThickness);
		DrawExtendGraph(tmpX, tmpY, tmpX + 1233 * 2 / 3, tmpY + 161 * 2 / 3, mHandle, TRUE);
		//DrawStringToHandle(480 + 45, 825 + 35, "���^�C�~���O�悭����", GetColor(255, 255, 255), mFontHandle);
	}

	if (mDrawGameState == DRAW_GAME_STATE::DRAW_GAUGE_GAME)
	{
		DrawGraph(mGaugeOutBeginX - 150, mGaugeOutBeginY + 50, mGaugeHandle, TRUE);
		// �����̎l�p
		DrawBoxAA(mGaugeInBeginX - 150+3, mGaugeInBeginY + 50+3, mGaugeInEndX - 139, mGaugeInEndY + 87, mGaugeInColor, mGaugeInFillFlag);
		// �O���̎l�p
		DrawGraph(mGaugeOutBeginX - 150, mGaugeOutBeginY + 50, mGaugeHandle2, TRUE);

		/*DrawBoxAA(mGaugeOutBeginX - 150, mGaugeOutBeginY + 50, mGaugeOutEndX - 150, mGaugeOutEndY + 50, mGaugeOutColor, mGaugeOutFillFlag);
		DrawBoxAA(mGaugeOutBeginX - 150 - 1, mGaugeOutBeginY + 50 - 1, mGaugeOutEndX - 150 + 1, mGaugeOutEndY + 50 + 1, mGaugeOutColor, mGaugeOutFillFlag);
		DrawBoxAA(mGaugeOutBeginX - 150 - 2, mGaugeOutBeginY + 50 - 2, mGaugeOutEndX - 150 + 2, mGaugeOutEndY + 50 + 2, mGaugeOutColor, mGaugeOutFillFlag);
		*/
		DrawExtendGraph(tmpX, tmpY, tmpX + 1233 * 2 / 3, tmpY + 161 * 2 / 3, mHandle, TRUE);
		//DrawStringToHandle(480 + 45, 825 + 35, "���^�C�~���O�悭����", GetColor(255, 255, 255), mFontHandle);
	}

	if (mDrawGameState == DRAW_GAME_STATE::DRAW_PENDULUM_GAME)
	{
		// �����̉~
		DrawCircleAA(mPendulumInX - 150, mPendulumInY + 50, 31, 64, GetColor(0,0,0), mPendulumInFillFlag);
		DrawCircleAA(mPendulumInX - 150, mPendulumInY + 50, mPendulumInRadius, 64, mPendulumInColor, mPendulumInFillFlag);
		// �O���̉~
		DrawCircleAA(mPendulumOutX - 150, mPendulumOutY + 50, mPendulumOutRadius, 64, mPendulumOutColor, mPendulumOutFillFlag, mPendulumOutLineThickness);
		DrawExtendGraph(tmpX, tmpY, tmpX + 1233 * 2 / 3, tmpY + 161 * 2 / 3, mHandle, TRUE);
		//DrawStringToHandle(480 + 45, 825 + 35, "���^�C�~���O�悭����", GetColor(255, 255, 255), mFontHandle);
	}
	/*clsDx();
	printfDx("X:%d\n", tmpX);
	printfDx("Y:%d\n", tmpY);*/
	
}

void PlayUI::Sound(class SE* _metoronome, class SE* _clickNormal, class SE* _clickClitical)
{
	
	if (mClickCriticalFlag)
	{
		_clickClitical->Play();
		mClickCriticalFlag = false;
	}
	if (mClickNormalFlag)
	{
		_clickNormal->Play();
		mClickNormalFlag = false;
	}
	if (mPlayPendulumGameFlag)
	{
		if ((940 <= mPendulumInX && mPendulumInX <= 980) && !mMetoronomeFlag)
		{
			_metoronome->Play();
			mMetoronomeFlag = true;
		}
		if (!(940 <= mPendulumInX && mPendulumInX <= 980))
		{
			mMetoronomeFlag = false;
		}
	}
}

void PlayUI::CircleGameBehavior(float _deltaTime)
{
	// Enter�L�[�̘A�����͖h�~
	if (!CheckHitKey(KEY_INPUT_RETURN))
	{
		mInputReturnFlag = true;
	}
	mCircleOutRadius += -200.0f * _deltaTime;
	if (mCircleOutRadius <= 0)
	{
		mCircleOutRadius = 200.0f;
	}

	if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
	{
		if (mCircleOutRadius <= 40.0f)
		{
			mScore += 200;
			mCircleOutRadius = 30.0f;
			mCircleInColor = GetColor(0, 255, 0);
			mClickCriticalFlag = true;
			//-------------------------------------------------------------------------�N���e�B�J���G�t�F�N�g�ǉ�
			mCriticalEffect->PlayEffekseer2D(VGet(mCircleInX-50-60, mCircleInY, 0));
		}
		else if (mCircleOutRadius <= 120.0f)
		{
			mScore += 100;
			mClickNormalFlag = true;
			//----------------------------------------------------------------------------�G�t�F�N�g�ǉ�
			mUIEffect->PlayEffekseer2D(VGet(mCircleInX-50-60, mCircleInY, 0));
		}
		else
		{
			//--------------------------------------------9/18
			mBadEffect->PlayEffekseer2D(VGet(0, -200, 0));
			mScore += 0;
			mClickNormalFlag = true;
		}
		mInputReturnFlag = false;
		mPlayCircleGameFlag = false;
	}
}

void PlayUI::GaugeGameBehavior(float _deltaTime)
{
	static bool flag = false;
	// Enter�L�[�̘A�����͖h�~
	if (!CheckHitKey(KEY_INPUT_RETURN))
	{
		mInputReturnFlag = true;
	}
	/*mGaugeInBeginY += -300.0f * _deltaTime;
	if (mGaugeInBeginY <= 360.0f)
	{
		mGaugeInBeginY = 720.0f;
	}*/
	if (mGaugeInBeginY <= 360.0f)
	{
		flag = true;
	}
	if (mGaugeInBeginY >= 760.0f)
	{
		flag = false;
	}

	if (flag)
	{
		mGaugeInBeginY += 300.0f * _deltaTime;
	}
	else
	{
		mGaugeInBeginY += -300.0f * _deltaTime;
	}

	if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
	{
		if (mGaugeInBeginY <= 370.0f)
		{
			mScore += 200;
			mGaugeInBeginY = 360.0f;
			mGaugeInColor = GetColor(0, 255, 0);
			mClickCriticalFlag = true;
			//------------------------------------------------------------------------�N���e�B�J���G�t�F�N�g�ǉ�
			mCriticalEffect->PlayEffekseer2D(VGet(mCircleInX-50-60, mCircleInY, 0));
		}
		else if (mGaugeInBeginY <= 560.0f)
		{
			mScore += 100;
			mClickNormalFlag = true;
			//----------------------------------------------------------------------------�G�t�F�N�g�ǉ�
			mUIEffect->PlayEffekseer2D(VGet(mCircleInX-50-60, mCircleInY, 0));
		}
		else
		{
			mScore += 0;
			mClickNormalFlag = true;
			//----------------------------------------------------------9/18�ǉ�
			mBadEffect->PlayEffekseer2D(VGet(0, -200, 0));
		}
		mInputReturnFlag = false;
		mPlayGaugeGameFlag = false;
	}
	//------------------------------------------------------------------------�N���A����O�Ȃ�G�t�F�N�g�폜
	else
	{
		mCriticalEffect->StopEffect2D();
		mUIEffect->StopEffect2D();
		mBadEffect->StopEffect2D();
	}
}

void PlayUI::PendulumGameBehavior(float _deltaTime)
{
	// Enter�L�[�̘A�����͖h�~
	if (!CheckHitKey(KEY_INPUT_RETURN))
	{
		mInputReturnFlag = true;
	}
	// ���݂̏d��̈ʒu
	auto rad = mPendulumInAngle * DX_PI_F / 180.0f;
	auto px = mPendulumInFx + cos(rad) * mPendulumLength;
	auto py = mPendulumInFy + sin(rad) * mPendulumLength;

	// �d�͈ړ��ʂ𔽉f�����d��̈ʒu
	auto vx = px - mPendulumInFx;
	auto vy = py - mPendulumInFy;
	auto t = -(vy * GRAVITY) / (vx * vx + vy * vy);
	auto gx = px + t * vx;
	auto gy = py + GRAVITY + t * vy;

	// �Q�̏d��̈ʒu�̊p�x��
	auto r = atan2(gy - mPendulumInFy, gx - mPendulumInFx) * 180.0 / DX_PI_F;

	// �p�x�����p���x�ɉ��Z
	auto sub = r - mPendulumInAngle;
	sub -= floor(sub / 360.0) * 360.0;
	if (sub < -180.0)
	{
		sub += 360.0;
	}
	if (sub > 180.0)
	{
		sub -= 360.0;
	}
	mPendulumInAngleSpeed += sub;

	// �p�x�Ɋp���x�����Z                       speed(�ϐ��ɂ�����)
	mPendulumInAngle += mPendulumInAngleSpeed * 3.0f * _deltaTime;

	// �V�����d��̈ʒu
	rad = mPendulumInAngle * DX_PI_F / 180.0f;
	px = mPendulumInFx + cos(rad) * mPendulumLength;
	py = mPendulumInFy + sin(rad) * mPendulumLength;

	// �d��̍��W
	mPendulumInX = px;
	mPendulumInY = py;


	if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
	{
		if (940.0f <= mPendulumInX && mPendulumInX <= 980.0f)
		{
			mPendulumInX = 960.0f;
			mPendulumInY = 700.0f;
			mScore += 200;
			mPendulumInColor = GetColor(0, 255, 0);
			mClickCriticalFlag = true;
			//-------------------------------------------------------------------------�N���e�B�J���G�t�F�N�g�ǉ�
			mCriticalEffect->PlayEffekseer2D(VGet(mPendulumInX-50-60, mPendulumInY, 0));
		}
		else if (820.0f <= mPendulumInX && mPendulumInX < 940.0f || 980.0f < mPendulumInX && mPendulumInX <= 1100.0f)
		{
			mScore += 100;
			mClickNormalFlag = true;
			//----------------------------------------------------------------------------�G�t�F�N�g�ǉ�
			mUIEffect->PlayEffekseer2D(VGet(mPendulumInX-50-60, mPendulumInY, 0));

		}
		else
		{
			mScore += 0;
			mClickNormalFlag = true;
			//----------------------------------------------------------9/18�ǉ�
			mBadEffect->PlayEffekseer2D(VGet(0, -200, 0));
		}

		mInputReturnFlag = false;
		mPlayPendulumGameFlag = false;
	}
	//------------------------------------------------------------------------�N���A����O�Ȃ�G�t�F�N�g�폜
	else
	{
		mCriticalEffect->StopEffect2D();
		mUIEffect->StopEffect2D();
		mBadEffect->StopEffect2D();
	}
}
