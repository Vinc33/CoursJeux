#pragma once
#include "ActionEntity.h"
class RogueAttack :
	public ActionEntity
{
public:
	RogueAttack(Entity* e);
	~RogueAttack();

	int update();

	float timeRemaining;
};

