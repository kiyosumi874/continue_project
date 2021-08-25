#include "DxLib.h"

#include "SceneManager_YanoHaruto.h"
#include "SceneBase.h"
#include "TitleScene_YanoHaruto.h"
#include "PlayScene_YanoHaruto.h"
#include "ResultScene_YanoHaruto.h"
#include "EffekseerForDXLib.h"

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
	SceneManager_YanoHaruto* scene = new SceneManager_YanoHaruto;

	// �^�C�g���V�[�����Z�b�g
	scene->SetScene(new TitleScene_YanoHaruto);

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

		// Effekseer���̃J������Dx���C�u�������̃J�����𓯊�����
		Effekseer_Sync3DSetting();
		// Effekseer�̍X�V
		UpdateEffekseer3D();
		// Effekseer�̕`��
		DrawEffekseer3D();
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

	// Effekseer�̏I��
	Effkseer_End();
	// �c�w���C�u�����̌�n��
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}/// <summary>
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
	SetUseZBuffer3D(TRUE);                                    // ZBuffer���g�p
	SetWriteZBuffer3D(TRUE);                                  // ZBuffer�ւ̏������݂�����
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
	SetUseZBuffer3D(TRUE);                                    // ZBuffer���g�p
	SetWriteZBuffer3D(TRUE);                                  // ZBuffer�ւ̏������݂�����
}
