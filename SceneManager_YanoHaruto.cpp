#include "SceneManager_YanoHaruto.h"
#include "PlayScene_YanoHaruto.h"
#include "ResultScene_YanoHaruto.h"
#include "TitleScene_YanoHaruto.h"

/// <summary>
/// ������
/// </summary>
SceneManager_YanoHaruto::SceneManager_YanoHaruto()
	: mScene(nullptr)
{
}

/// <summary>
/// �㏈��
/// </summary>
SceneManager_YanoHaruto::~SceneManager_YanoHaruto()
{
	delete mScene;
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="_deltaTime">�f���^�^�C��</param>
void SceneManager_YanoHaruto::Update(float _deltaTime, int& _hiScore)
{
	SceneBase* tmpScene = mScene->Update(_deltaTime, _hiScore);    // ���݂̃V�[����ۑ�(public�̊֐��E�ϐ����Ăяo���Ƃ��̓A���[���Z�q(->)�@�v����)
	if (tmpScene != mScene)   // �V�[�����؂�ւ������
	{
		delete mScene;    // ���O�̃V�[��������
		mScene = tmpScene;    // �V�[�����X�V����
		mScene->Load();    // �V�[���̏�����
	}
}

/// <summary>
/// �`��
/// </summary>
void SceneManager_YanoHaruto::Draw()
{
	mScene->Draw();     // �V�[����`��
}

/// <summary>
/// ���y
/// </summary>
void SceneManager_YanoHaruto::Sound(float _deltaTime)
{
	mScene->Sound(_deltaTime);    // BGM�𗬂�
}

/// <summary>
/// Set�֐�
/// </summary>
/// <param name="_scene">�V�[��</param>
void SceneManager_YanoHaruto::SetScene(SceneBase* _scene)
{
	if (mScene != nullptr)    // m_Scene����ł͂Ȃ��ꍇ
	{
		delete mScene;        // m_Scene������
	}
	mScene = _scene;          // �V�[���̍X�V
	mScene->Load();          // �V�[���̏�����
}
