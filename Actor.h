//----------------------------------------------------------------------------------//
// @file         Actor.h
// @brief        Actor�N���X
// @note         �Q�[���ɓo�ꂷ��L�����N�^�[��w�i(�Q�[���I�u�W�F�N�g)�Ɍp��������e�N���X              
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 8/23    �V�K�쐬
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

	// Getters/setters�@�Q�b�^�[�E�Z�b�^�[
	const VECTOR& GetPosition()                const { return      mPosition; }    // �ʒu�̃Q�b�g
	void          SetPosition(const VECTOR& _pos) { mPosition                = _pos;
		                                            mRecomputeWorldTransform = true; }    // �ʒu�̃Z�b�g
	const VECTOR& GetScale   ()                const { return      mScale;    }    // �X�P�[�����O�̃Q�b�g
	void          SetScale   (const VECTOR& _scale)  { mScale                   = _scale; 
	                                                   mRecomputeWorldTransform = true;  }    // �X�P�[�����O�̃Z�b�g
	const VECTOR& GetRotation()                const { return      mRotate;   }    // ��]�̃Q�b�g
	void          SetRotation(const VECTOR& _rotate) { mRotate                  = _rotate; 
	                                                   mRecomputeWorldTransform = true; }    // ��]�̃Z�b�g

	void          SetIsDrawable(bool _isDrawable) { mIsDrawable = _isDrawable; }

	void          ComputeWorldTransform();

	void          LoadModel(const TCHAR* _modelFile);
protected:
	int    mMHandle;
	bool   mIsDrawable;  // �`��\���ǂ���
	State  mState;
	VECTOR mPosition;
	VECTOR mRotate;
	VECTOR mScale;

	bool   mRecomputeWorldTransform;                                                    // ���[���h�ϊ��̍Čv�Z���K�v���H



};