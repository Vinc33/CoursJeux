#pragma once
#include "HeroAction.h"
class RogueWalk :
	public HeroAction
{
public:
	RogueWalk(Hero* e);
	~RogueWalk();
	int update();
private:
	bool jumpReady;
	bool attackReady;
	bool itemReady;
};

