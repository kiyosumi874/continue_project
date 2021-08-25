//----------------------------------------------------------------------------------//
// @file         StaticObjectActor.h
// @brief        StaticObjectActorクラス
// @note         継承元:Actorクラス              
// @author       椎原 清澄 (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 8/23    新規作成
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
