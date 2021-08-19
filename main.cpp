#include "DxLib.h"

#include "SceneManager.h"
#include "SceneBase.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "ResultScene.h"



// SetGraphMode�̃p�����[�^
#define WINDOW_SCREEN_WIDTH  1920/**2/3*/
#define WINDOW_SCREEN_HEIGHT 1080/**2/3*/
#define COLOR_BIT_NUM 16

// ���C���֐�
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	int screenFlipCount;
	float deltaTime, startTime;
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
	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(255, 255, 255);
	// �v�����ɕʂ̃E�C���h�E���A�N�e�B�u�ɂȂ��Ă���肪�����悤�ɏ펞���s�t���O���Z�b�g
	SetAlwaysRunFlag(TRUE);

	// �P�t���[���ɂ����鎞�Ԃ��v��
	ScreenFlip();
	screenFlipCount = 0;
	startTime = GetNowHiPerformanceCount();
	for (;;)
	{
		// ��ʐ؂�ւ����s���Ău�x�r�m�b�҂�������
		ScreenFlip();

		// �P�b�o�߂��Ă����烋�[�v���甲����
		if (GetNowHiPerformanceCount() - startTime >= 1000000.0f)
			break;

		// ScreenFlip ���s�����񐔂��C���N�������g
		screenFlipCount++;
	}

	// �펞���s�t���O�����ɖ߂�
	SetAlwaysRunFlag(FALSE);

	// �v�����Ԃ� ScreenFlip ���s�����񐔂Ŋ����
	// ScreenFlip ���ӂ�̎��Ԃ��擾�ł��܂�
	deltaTime = 1000000.0f / screenFlipCount;

	// �V�[���}�l�[�W���[�N���X�̃C���X�^���X�𐶐�
	SceneManager* scene = new SceneManager;


	// �^�C�g���V�[�����Z�b�g
	scene->SetScene(new TitleScene);


	/*deltaTime = 0.000001f;*/

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
		printfDx("%f\n", deltaTime / 1000000.0f);
		// ����ʂ̓��e��\��ʂɔ��f������
		ScreenFlip();

	}

	delete scene;

	// �c�w���C�u�����̌�n��
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}