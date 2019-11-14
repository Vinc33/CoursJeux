#pragma once
#include "Action.h"
class RogueJump :
	public Action
{
public:
	RogueJump(Entity* e, bool jump = true, bool canRoll = true);
	~RogueJump();
	int Update();
private:
	bool canRoll;
};

