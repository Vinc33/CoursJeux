#pragma once
#include "ActionEntity.h"
class MonkRoundhouse :
	public ActionEntity
{
public:
	MonkRoundhouse(Entity* e, bool asDoubleJump, bool canPunch, bool canDropkick);
	~MonkRoundhouse();

	int Update();
private:
	float timeRemaining;
	bool chainKick;
	bool chainPunch;
	bool canChainAttack;

	bool canPunch;
	bool canDropkick;
};

