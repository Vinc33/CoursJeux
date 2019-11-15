#pragma once
#include "ActionEntity.h"
class MonkJump :
	public ActionEntity
{
public:
	MonkJump(Entity* e, bool canRoundhouse, bool canPunch, bool canDropkick, bool canDoubleJump);
	~MonkJump();

	int Update();
private:
	bool doubleJumpReady;

	bool canPunch;
	bool canDropkick;
	bool canDoubleJump;
	bool canRoundhouse;
};

