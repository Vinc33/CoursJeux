#pragma once
#include "HeroAction.h"
class MonkJump :
	public HeroAction
{
public:
	MonkJump(Hero* e, bool canRoundhouse, bool canPunch, bool canDropkick, bool canJump);
	~MonkJump();

	int update();
private:
	bool doubleJumpReady;
	bool canPunch;
	bool canDropkick;
	bool canJump;
	bool canRoundhouse;
};

