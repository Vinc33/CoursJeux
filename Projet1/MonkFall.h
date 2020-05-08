#pragma once
#include "HeroAction.h"
#include "HeroActionsEnum.h"

class MonkFall :
	public HeroAction
{
public:
	MonkFall(Hero* e, bool canRoundhouse, bool canPunch, bool canDropkick, bool canJump);
	~MonkFall();

	int update();
private:
	bool canRoundhouse;
	bool canPunch;
	bool canDropkick;
	bool canJump;
};

