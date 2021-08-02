#include "SceneManager_kiyosumi.h"
#include "PlayScene_kiyosumi.h"
#include "ResultScene_kiyosumi.h"
#include "TitleScene_kiyosumi.h"

/// <summary>
/// ������
/// </summary>
SceneManager_kiyosumi::SceneManager_kiyosumi()
	: mScene(nullptr)
{
}

/// <summary>
/// �㏈��
/// </summary>
SceneManager_kiyosumi::~SceneManager_kiyosumi()
{
	delete mScene;
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="_deltaTime">�f���^�^�C��</param>
void SceneManager_kiyosumi::Update(float _deltaTime)
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
void SceneManager_kiyosumi::Draw()
{
	mScene->Draw();     // �V�[����`��
}

/// <summary>
/// ���y
/// </summary>
void SceneManager_kiyosumi::Sound()
{
	mScene->Sound();    // BGM�𗬂�
}

/// <summary>
/// Set�֐�
/// </summary>
/// <param name="_scene">�V�[��</param>
void SceneManager_kiyosumi::SetScene(SceneBase* _scene)
{
	if (mScene != nullptr)    // m_Scene����ł͂Ȃ��ꍇ
	{
		delete mScene;        // m_Scene������
	}
	mScene = _scene;          // �V�[���̍X�V
	mScene->Load();          // �V�[���̏�����
}
