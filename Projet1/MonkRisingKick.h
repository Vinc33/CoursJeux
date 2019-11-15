#pragma once
#include "ActionEntity.h"
class MonkRisingKick :
	public ActionEntity
{
public:
	MonkRisingKick(Entity* e);
	~MonkRisingKick();
	int Update();
private:
	float timeRemaining;
};

