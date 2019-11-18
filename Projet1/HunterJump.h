#pragma once
#include "ActionEntity.h"
class HunterJump :
	public ActionEntity
{
public:
	HunterJump(Entity* e);
	~HunterJump();
	int Update();
};

