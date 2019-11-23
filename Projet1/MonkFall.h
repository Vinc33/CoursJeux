#pragma once
#include "ActionEntity.h"
#include "HeroActionsEnum.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Entity.h"

class MonkFall :
	public ActionEntity
{
public:
	MonkFall(Entity* e, bool canRoundhouse, bool canPunch, bool canDropkick, bool canJump);
	~MonkFall();

	int update();
private:
	bool canRoundhouse;
	bool canPunch;
	bool canDropkick;
	bool canJump;
};

