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
