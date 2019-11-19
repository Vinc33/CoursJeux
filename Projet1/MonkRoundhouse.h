#pragma once
#include "ActionEntity.h"
class MonkRoundhouse :
	public ActionEntity
{
public:
	MonkRoundhouse(Entity* e, bool asDoubleJump, bool canPunch, bool canDropkick, bool canJump);
	~MonkRoundhouse();

	int Update();
private:
	float timeRemaining;
	bool chainKick;
	bool chainPunch;
	bool canChainAttack;

	bool canJump;
	bool canPunch;
	bool canDropkick;
};

