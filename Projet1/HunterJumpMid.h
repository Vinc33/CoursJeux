#pragma once
#include "HeroAction.h"
class HunterJumpMid :
	public HeroAction
{
public:
	HunterJumpMid(Hero* e);
	~HunterJumpMid();
	int update();
};

