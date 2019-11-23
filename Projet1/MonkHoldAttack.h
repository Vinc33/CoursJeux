#pragma once
#include "ActionEntity.h"
class MonkHoldAttack :
	public ActionEntity
{
public:
	MonkHoldAttack(Entity* e);
	~MonkHoldAttack();
	int update();
private:
	float currentTime;
	float particleTimer;
};

