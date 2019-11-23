#pragma once
#include "ActionEntity.h"
class MonkRisingKick :
	public ActionEntity
{
public:
	MonkRisingKick(Entity* e);
	~MonkRisingKick();
	int update();
private:
	float timeRemaining;
};

