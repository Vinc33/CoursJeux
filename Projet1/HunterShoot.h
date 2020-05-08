#pragma once
#include "HeroAction.h"
#include "Hero.h"
class HunterShoot :
	public HeroAction
{
public:
	HunterShoot(Hero* e);
	~HunterShoot();
	int update();
private:
	float timeRemaining;
};

