#pragma once
#include "HeroAction.h"
class MonkRoundhouse :
	public HeroAction
{
public:
	MonkRoundhouse(Hero* e, bool asDoubleJump, bool canPunch, bool canDropkick, bool canJump);
	~MonkRoundhouse();

	int update();
private:
	float timeRemaining;
	bool chainKick;
	bool chainPunch;
	bool canChainAttack;

	bool canJump;
	bool canPunch;
	bool canDropkick;
};

