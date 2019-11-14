#pragma once
#include "Action.h"
class RogueStanding :
	public Action
{
public:
	RogueStanding(Entity* e);
	~RogueStanding();
	int Update();
};

