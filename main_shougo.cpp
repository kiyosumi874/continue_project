#include "DxLib.h"

#include "SceneBase.h"
#include "TitleScene_shougo.h"
#include "PlayScene_shougo.h"
#include "ResultScene_shougo.h"
#include "SceneManager_shougo.h"



// SetGraphModeのパラメータ
#define WINDOW_SCREEN_WIDTH  1920
#define WINDOW_SCREEN_HEIGHT 1080
#define COLOR_BIT_NUM 16

// メイン関数
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
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

	// デルタタイム管理用の変数をセット
	LONGLONG nowTime;
	LONGLONG time;
	float    deltaTime;

	// システム時間を取得
	time = GetNowHiPerformanceCount();

	// シーンマネージャークラスのインスタンスを生成
	SceneManager_shougo* scene = new SceneManager_shougo;


	// タイトルシーンをセット
	scene->SetScene(new TitleScene_shougo);


	deltaTime = 0.000001f;

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

		// 裏画面の内容を表画面に反映させる
		ScreenFlip();

		// 現在のシステム時間を取得
		nowTime = GetNowHiPerformanceCount();

		// 前回取得した時間からの経過時間を秒に変換してセット
		// ( GetNowHiPerformanceCount で取得できる値はマイクロ秒単位なので 1000000 で割ることで秒単位になる )
		deltaTime = (nowTime - time) / 1000000.0f;

		//	今回取得した時間を保存
		time = nowTime;

	}

	delete scene;

	// ＤＸライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}
