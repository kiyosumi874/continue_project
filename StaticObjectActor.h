//----------------------------------------------------------------------------------//
// @file         StaticObjectActor.h
// @brief        StaticObjectActor�N���X
// @note         �p����:Actor�N���X              
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 8/23    �V�K�쐬
//----------------------------------------------------------------------------------//


#pragma once
#include "Actor.h"

class StaticObjectActor : public Actor
{
public:
	 StaticObjectActor();
	~StaticObjectActor();

	void UpdateActor(float _deltaTime)override;
private:
};
