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
	void spawnParticle();
	float currentTime;
	float particleTimer;
};

