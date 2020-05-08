#pragma once
#include "HeroAction.h"
class HunterJump :
	public HeroAction
{
public:
	HunterJump(Hero* e);
	~HunterJump();
	int update();
};

