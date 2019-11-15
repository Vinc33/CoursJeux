#pragma once
#include "ActionEntity.h"
class RogueRoll :
	public ActionEntity
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

