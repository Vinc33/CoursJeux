#pragma once
#include "ActionEntity.h"
class HunterJumpMid :
	public ActionEntity
{
public:
	HunterJumpMid(Entity* e);
	~HunterJumpMid();
	int Update();
};

