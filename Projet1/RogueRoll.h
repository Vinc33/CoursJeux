#pragma once
#include "HeroAction.h"
enum direction;
class RogueRoll :
	public HeroAction
{
public:
	RogueRoll(Hero* e);
	~RogueRoll();
	int update();

private:
	float timeRemaining;
	bool jumpAtHalf;
	bool releasedJump;

	bool chainAttack;
	bool chainItemUp;
	bool chainItemDown;
	bool chainItemFront;
	bool chainItemStand;

	bool canChainItem;
	bool canChainAttack;

	direction chainDirection;
};

