#pragma once
#include "HeroAction.h"
class RogueItemUse :
	public HeroAction
{
public:
	RogueItemUse(Hero* e, float timer);
	~RogueItemUse();

	int update();
protected:
	float timer;
};

