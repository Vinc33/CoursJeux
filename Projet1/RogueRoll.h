#pragma once
#include "ActionEntity.h"
enum direction;
class RogueRoll :
	public ActionEntity
{
public:
	RogueRoll(Entity* e);
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

	direction chainDirection;
};

