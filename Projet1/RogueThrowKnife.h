#pragma once
#include "RogueItemUse.h"
class RogueThrowKnife :
	public RogueItemUse
{
public:
	RogueThrowKnife(Entity* e);
	~RogueThrowKnife();

	int update();
};

