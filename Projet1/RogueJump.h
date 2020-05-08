#pragma once
#include "HeroAction.h"
class RogueJump :
	public HeroAction
{
public:
	RogueJump(Hero* e, bool jump = true, bool canRoll = true);
	~RogueJump();
	int update();
private:
	bool canRoll;
	bool canAttack;
	bool canUseItem;
	bool chainJump;
	float lastJumpInputTimer;
};
