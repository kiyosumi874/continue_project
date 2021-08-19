#include "DxLib.h"

#include "SceneManager.h"
#include "SceneBase.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "ResultScene.h"



// SetGraphModeのパラメータ
#define WINDOW_SCREEN_WIDTH  1920/**2/3*/
#define WINDOW_SCREEN_HEIGHT 1080/**2/3*/
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
	SceneManager* scene = new SceneManager;


	// タイトルシーンをセット
	scene->SetScene(new TitleScene);


	/*deltaTime = 0.000001f;*/

	// エスケープキーが押されるかウインドウが閉じられるまでループ
	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{

		// 画面消去
		ClearDrawScreen();

		// シーン制御
		scene->Update(deltaTime);

		// 描画処理
		scene->Draw();

		// BGM処理
		scene->Sound();
		printfDx("%f\n", deltaTime / 1000000.0f);
		// 裏画面の内容を表画面に反映させる
		ScreenFlip();

	}

	delete scene;

	// ＤＸライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}