#pragma once
#include "HeroAction.h"
class MonkHoldAttack :
	public HeroAction
{
public:
	MonkHoldAttack(Hero* e);
	~MonkHoldAttack();
	int update();
private:
	void spawnParticle();
	float currentTime;
	float particleTimer;
};

