#pragma once
#include "ActionEntity.h"
class HunterShoot :
	public ActionEntity
{
public:
	HunterShoot(Entity* e);
	~HunterShoot();
	int update();
private:
	float timeRemaining;
};

