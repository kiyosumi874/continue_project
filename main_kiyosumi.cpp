#include "DxLib.h"

#include "SceneManager_kiyosumi.h"
#include "SceneBase.h"
#include "TitleScene_kiyosumi.h"
#include "PlayScene_kiyosumi.h"
#include "ResultScene_kiyosumi.h"
#include "EffekseerForDXLib.h"

void InitializeEffekseer();

// SetGraphModeのパラメータ
#define WINDOW_SCREEN_WIDTH  1920
#define WINDOW_SCREEN_HEIGHT 1080
#define COLOR_BIT_NUM 16

// メイン関数
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	int screenFlipCount;
	float deltaTime, startTime;
	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;    // エラーが起きたら直ちに終了
	}

	InitializeEffekseer();

	// 画面モードのセット
	SetGraphMode(WINDOW_SCREEN_WIDTH, WINDOW_SCREEN_HEIGHT, COLOR_BIT_NUM);
	// ウインドウモード・フルスクリーンモードの変更を行う
	ChangeWindowMode(TRUE);
	// 裏画面の設定
	SetDrawScreen(DX_SCREEN_BACK);
	// 画面の背景色を設定する
	SetBackgroundColor(255, 255, 255);
	// 計測中に別のウインドウがアクティブになっても問題が無いように常時実行フラグをセット
	SetAlwaysRunFlag(TRUE);

	// １フレームにかかる時間を計測
	ScreenFlip();
	screenFlipCount = 0;
	startTime = GetNowHiPerformanceCount();
	for (;;)
	{
		// 画面切り替えを行ってＶＹＳＮＣ待ちをする
		ScreenFlip();

		// １秒経過していたらループから抜ける
		if (GetNowHiPerformanceCount() - startTime >= 1000000.0f)
			break;

		// ScreenFlip を行った回数をインクリメント
		screenFlipCount++;
	}

	// 常時実行フラグを元に戻す
	SetAlwaysRunFlag(FALSE);

	// 計測時間を ScreenFlip を行った回数で割れば
	// ScreenFlip 一回辺りの時間が取得できます
	deltaTime = 1000000.0f / screenFlipCount;

	// シーンマネージャークラスのインスタンスを生成
	SceneManager_kiyosumi* scene = new SceneManager_kiyosumi;
	

	// タイトルシーンをセット
	scene->SetScene(new TitleScene_kiyosumi);
	//scene->SetScene(new ResultScene_kiyosumi(0));
	

	/*deltaTime = 0.000001f;*/

	// エスケープキーが押されるかウインドウが閉じられるまでループ
	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{

		// 画面消去
		ClearDrawScreen();
		float perfDelta = deltaTime / 1000000.0f;
		// シーン制御
		scene->Update(perfDelta);

		// 描画処理
		scene->Draw();

		// Effekseer側のカメラとDxライブラリ側のカメラを同期する
		Effekseer_Sync3DSetting();
		// Effekseerの更新
		UpdateEffekseer2D();
		UpdateEffekseer3D();
		// Effekseerの描画
		DrawEffekseer2D();
		DrawEffekseer3D();

		// BGM処理
		scene->Sound(perfDelta);

		// 裏画面の内容を表画面に反映させる
		ScreenFlip();

	}

	delete scene;

	// Effekseerの終了
	Effkseer_End();

	// ＤＸライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}

/// <summary>
/// Effekseerの初期化
/// </summary>
void InitializeEffekseer()
{
	// DXライブラリとEffekseerの初期化処理
	if (Effekseer_Init(8000) == -1)
	{
		printf("Effekseer初期化に失敗！\n");			                              // エラーが起きたら直ちに終了
	}

	//---------------------------------------------------+
	// Effekseer関連の初期化
	//---------------------------------------------------+
	SetUseDirect3DVersion(DX_DIRECT3D_11);                    // DirectX11を使用
	SetChangeScreenModeGraphicsSystemResetFlag(FALSE);
	Effekseer_SetGraphicsDeviceLostCallbackFunctions();
	Effekseer_Set2DSetting(WINDOW_SCREEN_WIDTH, WINDOW_SCREEN_HEIGHT);
	SetUseZBuffer3D(TRUE);                                    // ZBufferを使用
	SetWriteZBuffer3D(TRUE);                                  // ZBufferへの書き込みを許可
}
