#include "SceneManager.h"
#include "PlayScene.h"
#include "ResultScene.h"
#include "TitleScene.h"

/// <summary>
/// ������
/// </summary>
SceneManager::SceneManager()
	: mScene(nullptr)
{
}

/// <summary>
/// �㏈��
/// </summary>
SceneManager::~SceneManager()
{
	delete mScene;
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="_deltaTime">�f���^�^�C��</param>
void SceneManager::Update(float _deltaTime)
{
	SceneBase* tmpScene = mScene->Update(_deltaTime);    // ���݂̃V�[����ۑ�(public�̊֐��E�ϐ����Ăяo���Ƃ��̓A���[���Z�q(->)�@�v����)
	if (tmpScene != mScene)   // �V�[�����؂�ւ������
	{
		delete mScene    ;    // ���O�̃V�[��������
		mScene = tmpScene;    // �V�[�����X�V����
		mScene ->Load()  ;    // �V�[���̏�����
	}
}

/// <summary>
/// �`��
/// </summary>
void SceneManager::Draw()
{
	mScene->Draw();     // �V�[����`��
}

/// <summary>
/// ���y
/// </summary>
void SceneManager::Sound()
{
	mScene->Sound();    // BGM�𗬂�
}

/// <summary>
/// Set�֐�
/// </summary>
/// <param name="_scene">�V�[��</param>
void SceneManager::SetScene(SceneBase* _scene)
{
	if (mScene != nullptr)    // m_Scene����ł͂Ȃ��ꍇ
	{
		delete mScene;        // m_Scene������
	}
	mScene = _scene;          // �V�[���̍X�V
	mScene ->Load();          // �V�[���̏�����
}
