#pragma once
#include "HeroAction.h"
class RogueStanding :
	public HeroAction
{
public:
	RogueStanding(Hero* e);
	~RogueStanding();

	int update();
private:
	bool jumpReady;
};

