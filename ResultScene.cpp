#include "DxLib.h"
#include "ResultScene.h"
#include "TitleScene.h"
#include "ResultCamera.h"
#include "ResultUI.h"
#include "Player.h"
#include "StaticObjectActor.h"

const char* MOVE_SCENE_IMG = "data/img/MoveScene.png";
const char* PODIUM_MODEL   = "data/model/podium/podium.mv1";

/// <summary>
/// ������
/// </summary>
ResultScene::ResultScene(int _score)
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mResultCamera(nullptr)
	, mResultUI(nullptr)
	, mScore(_score)
	, mAlphaPal(255)
	, mAlphaPalFlag(false)
	, mMoveSceneHandle(-1)
	, mCheckHitFlag(false)
	, mPlayer(nullptr)
	, mFadeSpeed(3)
	, mStaticObjectActor(nullptr)
{
}

/// <summary>
/// �㏈��
/// </summary>
ResultScene::~ResultScene()
{
	delete mResultCamera;
	delete mResultUI;
	delete mPlayer;
	delete mStaticObjectActor;
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="_deltaTime">�f���^�^�C��</param>
/// <returns>
/// Enter���������Ƃ��Ɏ��̃V�[����Instance�̃|�C���^��Ԃ�
/// ����ȊO�͎����̃|�C���^��Ԃ�
/// </returns>
SceneBase* ResultScene::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime / 1000000.0f;
	// ���U���g�J�����̍X�V
	mResultCamera->Update();
	// ���U���gUI�̍X�V
	mResultUI->Update(mDeltaTime);
	// ���U���gUI�ɃX�R�A��n��
	mResultUI->LoadScore(mScore);
	mPlayer->Update(mDeltaTime);


	mStaticObjectActor->UpdateActor(mDeltaTime);
	mStaticObjectActor->Update(mDeltaTime);
	// Enter�L�[�̘A�����͖h�~
	if (!CheckHitKey(KEY_INPUT_RETURN))
	{
		mInputReturnFlag = true;
	}


	if (mAlphaPal >= 0 && !mAlphaPalFlag)
	{
		mAlphaPal -= mFadeSpeed;
	}
	else
	{
		mAlphaPalFlag = true;
	}

	if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag && mAlphaPalFlag)
	{
		mCheckHitFlag = true;
		mInputReturnFlag = false;
	}
	if (mCheckHitFlag)
	{
		mAlphaPal += mFadeSpeed;
	}
	// �V�[���J�ڏ���
	if (mAlphaPal >= 255)
	{
		// �����𖞂����Ă����玟�̃V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return new TitleScene();
	}

	// �V�[�����ύX����Ă��Ȃ������玩���̃|�C���^��Ԃ�
	return this;
}

/// <summary>
/// �`��
/// </summary>
void ResultScene::Draw()
{
#if DEBUG_MODE

#endif

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	mPlayer->Draw();
	mStaticObjectActor->Draw();
	// ���U���g�J�����̕`��
	mResultCamera->Draw();
	// ���U���gUI�̕`��
	mResultUI->Draw();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mAlphaPal);
	DrawGraph(0, 0, mMoveSceneHandle, FALSE);
}

/// <summary>
/// ���y
/// </summary>
void ResultScene::Sound()
{
}

/// <summary>
/// ������
/// </summary>
void ResultScene::Load()
{

	mResultCamera = new ResultCamera;
	mResultUI = new ResultUI;
	mPlayer = new Player;
	mStaticObjectActor = new StaticObjectActor;

	mPlayer->Load();
	// ���U���g�J�����̏�����
	mResultCamera->Load();
	// ���U���gUI�̏�����
	mResultUI->Load();
	mMoveSceneHandle = LoadGraph(MOVE_SCENE_IMG);
	mStaticObjectActor->LoadModel(PODIUM_MODEL);
	mStaticObjectActor->SetScale(VGet(0.01f, 0.01f, 0.01f));
	mStaticObjectActor->SetRotation(VGet(0.0f, 90.0f * DX_PI_F / 180.0f, 0.0f));
	mStaticObjectActor->SetPosition(VGet(0.0f, 32.0f, -16.0f));
	mResultCamera->SetTargetPos(mPlayer->PlayerGetPosition());
}
