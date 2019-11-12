#pragma once
#include "Action.h"
#include "HeroActionsEnum.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Entity.h"

class MonkFall :
	public Action
{
public:
	MonkFall(Entity* e, bool canRoundhouse, bool canPunch, bool canDropkick, bool canDoubleJump, bool doubleJumpReady = false);
	~MonkFall();

	int Update();
	bool canDoubleJump;
	bool canRoundhouse;
	bool canPunch;
	bool canDropkick;
	bool doubleJumpReady;
};

