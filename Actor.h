//----------------------------------------------------------------------------------//
// @file         Actor.h
// @brief        Actorクラス
// @note         ゲームに登場するキャラクターや背景(ゲームオブジェクト)に継承させる親クラス              
// @author       椎原 清澄 (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 8/23    新規作成
//----------------------------------------------------------------------------------//

#pragma once

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
	virtual ~Actor();

	virtual void Update(float _deltaTime) = 0;

	// Getters/setters　ゲッター・セッター
	const VECTOR& GetPosition()                const { return      mPosition; }    // 位置のゲット
	void          SetPosition(const VECTOR& _pos)    { mPosition = _pos;      }    // 位置のセット
	const VECTOR& GetScale   ()                const { return      mScale;    }    // スケーリングのゲット
	void          SetScale   (const VECTOR& _scale)  { mScale    = _scale;    }    // スケーリングのセット
	const VECTOR& GetRotation()                const { return      mRotate;   }    // 回転のゲット
	void          SetRotation(const VECTOR& _rotate) { mRotate   = _rotate;   }    // 回転のセット

protected:
	State  mState;
	VECTOR mPosition;
	VECTOR mRotate;
	VECTOR mScale;

};