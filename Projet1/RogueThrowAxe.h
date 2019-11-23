#pragma once
#include "RogueItemUse.h"
class RogueThrowAxe :
	public RogueItemUse
{
public:
	RogueThrowAxe(Entity* e);
	~RogueThrowAxe();

	int update();
};

