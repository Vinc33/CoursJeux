#pragma once
#include "Action.h"
class RogueWalk :
	public Action
{
public:
	RogueWalk(Entity* e);
	~RogueWalk();
	int Update();
};

