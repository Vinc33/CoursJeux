#pragma once
#include "ActionEntity.h"
class MonkPunch :
	public ActionEntity
{
public:
	MonkPunch(Entity* e);
	~MonkPunch();

	int Update();

private:
	float timeRemaining;
	float currentVelY;
};

