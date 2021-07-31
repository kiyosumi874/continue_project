#include "DxLib.h"

#include "SceneManager_kiyosumi.h"
#include "SceneBase.h"
#include "TitleScene_kiyosumi.h"
#include "PlayScene_kiyosumi.h"
#include "ResultScene_kiyosumi.h"

// SetGraphMode�̃p�����[�^
#define WINDOW_SCREEN_WIDTH  1920
#define WINDOW_SCREEN_HEIGHT 1080
#define COLOR_BIT_NUM 16

// ���C���֐�
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		return -1;    // �G���[���N�����璼���ɏI��
	}

	// ��ʃ��[�h�̃Z�b�g
	SetGraphMode(WINDOW_SCREEN_WIDTH, WINDOW_SCREEN_HEIGHT, COLOR_BIT_NUM);
	// �E�C���h�E���[�h�E�t���X�N���[�����[�h�̕ύX���s��
	ChangeWindowMode(TRUE);
	// ����ʂ̐ݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	// �f���^�^�C���Ǘ��p�̕ϐ����Z�b�g
	LONGLONG nowTime;
	LONGLONG time;
	float    deltaTime;

	// �V�X�e�����Ԃ��擾
	time = GetNowHiPerformanceCount();

	// �V�[���}�l�[�W���[�N���X�̃C���X�^���X�𐶐�
	SceneManager_kiyosumi* scene = new SceneManager_kiyosumi;

	// �^�C�g���V�[�����Z�b�g
	scene->SetScene(new TitleScene_kiyosumi);

	deltaTime = 0.000001f;

	// �G�X�P�[�v�L�[��������邩�E�C���h�E��������܂Ń��[�v
	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		// ��ʏ���
		ClearDrawScreen();

		// �V�[������
		scene->Update(deltaTime);

		// �`�揈��
		scene->Draw();

		// BGM����
		scene->Sound();

		// ����ʂ̓��e��\��ʂɔ��f������
		ScreenFlip();

		// ���݂̃V�X�e�����Ԃ��擾
		nowTime = GetNowHiPerformanceCount();

		// �O��擾�������Ԃ���̌o�ߎ��Ԃ�b�ɕϊ����ăZ�b�g
		// ( GetNowHiPerformanceCount �Ŏ擾�ł���l�̓}�C�N���b�P�ʂȂ̂� 1000000 �Ŋ��邱�Ƃŕb�P�ʂɂȂ� )
		deltaTime = (nowTime - time) / 1000000.0f;

		//	����擾�������Ԃ�ۑ�
		time = nowTime;

	}

	delete scene;

	// �c�w���C�u�����̌�n��
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}