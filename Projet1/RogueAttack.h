#pragma once
#include "HeroAction.h"
class RogueAttack :
	public HeroAction
{
public:
	RogueAttack(Hero* e);
	~RogueAttack();

	int update();

	float timeRemaining;
};

