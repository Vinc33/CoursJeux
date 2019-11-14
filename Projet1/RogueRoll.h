#pragma once
#include "Action.h"
class RogueRoll :
	public Action
{
public:
	RogueRoll(Entity* e);
	~RogueRoll();
	int Update();
private:
	float timeRemaining;
	bool jumpAtHalf;
	bool releasedJump;
	bool chainAttack;
	bool sommersault;
};

