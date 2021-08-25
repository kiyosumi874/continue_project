//----------------------------------------------------------------------------------//
// @file         Actor.h
// @brief        Actorクラス
// @note         ゲームに登場するキャラクターや背景(ゲームオブジェクト)に継承させる親クラス              
// @author       椎原 清澄 (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 8/23    新規作成
//----------------------------------------------------------------------------------//

#pragma once

#include "DxLib.h"

class Actor
{
public:
	enum class State : unsigned char
	{
		Active,
		Paused,
		Dead
	};

	Actor();
	Actor(const TCHAR* _modelFile);
	virtual ~Actor();

	void Update(float _deltaTime);
	virtual void UpdateActor(float _deltaTime) = 0;


	void Draw();

	// Getters/setters　ゲッター・セッター
	const VECTOR& GetPosition()                const { return      mPosition; }    // 位置のゲット
	void          SetPosition(const VECTOR& _pos) { mPosition                = _pos;
		                                            mRecomputeWorldTransform = true; }    // 位置のセット
	const VECTOR& GetScale   ()                const { return      mScale;    }    // スケーリングのゲット
	void          SetScale   (const VECTOR& _scale)  { mScale                   = _scale; 
	                                                   mRecomputeWorldTransform = true;  }    // スケーリングのセット
	const VECTOR& GetRotation()                const { return      mRotate;   }    // 回転のゲット
	void          SetRotation(const VECTOR& _rotate) { mRotate                  = _rotate; 
	                                                   mRecomputeWorldTransform = true; }    // 回転のセット

	void          SetIsDrawable(bool _isDrawable) { mIsDrawable = _isDrawable; }

	void          ComputeWorldTransform();

	void          LoadModel(const TCHAR* _modelFile);
protected:
	int    mMHandle;
	bool   mIsDrawable;  // 描画可能かどうか
	State  mState;
	VECTOR mPosition;
	VECTOR mRotate;
	VECTOR mScale;

	bool   mRecomputeWorldTransform;                                                    // ワールド変換の再計算が必要か？



};