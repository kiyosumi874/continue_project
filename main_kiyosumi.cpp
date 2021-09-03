#include "DxLib.h"

#include "SceneManager_kiyosumi.h"
#include "SceneBase.h"
#include "TitleScene_kiyosumi.h"
#include "PlayScene_kiyosumi.h"
#include "ResultScene_kiyosumi.h"
#include "EffekseerForDXLib.h"

void InitializeEffekseer();

// SetGraphMode�̃p�����[�^
#define WINDOW_SCREEN_WIDTH  1920
#define WINDOW_SCREEN_HEIGHT 1080
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

	InitializeEffekseer();

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
	SceneManager_kiyosumi* scene = new SceneManager_kiyosumi;
	

	// �^�C�g���V�[�����Z�b�g
	scene->SetScene(new TitleScene_kiyosumi);
	//scene->SetScene(new ResultScene_kiyosumi(0));
	

	/*deltaTime = 0.000001f;*/

	// �G�X�P�[�v�L�[��������邩�E�C���h�E��������܂Ń��[�v
	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{

		// ��ʏ���
		ClearDrawScreen();
		float perfDelta = deltaTime / 1000000.0f;
		// �V�[������
		scene->Update(perfDelta);

		// �`�揈��
		scene->Draw();

		// Effekseer���̃J������Dx���C�u�������̃J�����𓯊�����
		Effekseer_Sync3DSetting();
		// Effekseer�̍X�V
		UpdateEffekseer2D();
		UpdateEffekseer3D();
		// Effekseer�̕`��
		DrawEffekseer2D();
		DrawEffekseer3D();

		// BGM����
		scene->Sound(perfDelta);

		// ����ʂ̓��e��\��ʂɔ��f������
		ScreenFlip();

	}

	delete scene;

	// Effekseer�̏I��
	Effkseer_End();

	// �c�w���C�u�����̌�n��
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}

/// <summary>
/// Effekseer�̏�����
/// </summary>
void InitializeEffekseer()
{
	// DX���C�u������Effekseer�̏���������
	if (Effekseer_Init(8000) == -1)
	{
		printf("Effekseer�������Ɏ��s�I\n");			                              // �G���[���N�����璼���ɏI��
	}

	//---------------------------------------------------+
	// Effekseer�֘A�̏�����
	//---------------------------------------------------+
	SetUseDirect3DVersion(DX_DIRECT3D_11);                    // DirectX11���g�p
	SetChangeScreenModeGraphicsSystemResetFlag(FALSE);
	Effekseer_SetGraphicsDeviceLostCallbackFunctions();
	Effekseer_Set2DSetting(WINDOW_SCREEN_WIDTH, WINDOW_SCREEN_HEIGHT);
	SetUseZBuffer3D(TRUE);                                    // ZBuffer���g�p
	SetWriteZBuffer3D(TRUE);                                  // ZBuffer�ւ̏������݂�����
}
