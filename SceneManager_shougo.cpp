#include "SceneManager_shougo.h"
#include "PlayScene_shougo.h"
#include "ResultScene_shougo.h"
#include "TitleScene_shougo.h"

/// <summary>
/// ������
/// </summary>
SceneManager_shougo::SceneManager_shougo()
	: mScene(nullptr)
{
}

/// <summary>
/// �㏈��
/// </summary>
SceneManager_shougo::~SceneManager_shougo()
{
	delete mScene;
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="_deltaTime">�f���^�^�C��</param>
void SceneManager_shougo::Update(float _deltaTime)
{
	SceneBase* tmpScene = mScene->Update(_deltaTime);    // ���݂̃V�[����ۑ�(public�̊֐��E�ϐ����Ăяo���Ƃ��̓A���[���Z�q(->)�@�v����)
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
void SceneManager_shougo::Draw()
{
	mScene->Draw();     // �V�[����`��
}

/// <summary>
/// ���y
/// </summary>
void SceneManager_shougo::Sound()
{
	mScene->Sound();    // BGM�𗬂�
}

/// <summary>
/// Set�֐�
/// </summary>
/// <param name="_scene">�V�[��</param>
void SceneManager_shougo::SetScene(SceneBase* _scene)
{
	if (mScene != nullptr)    // m_Scene����ł͂Ȃ��ꍇ
	{
		delete mScene;        // m_Scene������
	}
	mScene = _scene;          // �V�[���̍X�V
	mScene->Load();          // �V�[���̏�����
}
