#pragma once
#include "ActionEntity.h"
class MonkJump :
	public ActionEntity
{
public:
	MonkJump(Entity* e, bool canRoundhouse, bool canPunch, bool canDropkick, bool canJump);
	~MonkJump();

	int update();
private:
	bool doubleJumpReady;
	bool canPunch;
	bool canDropkick;
	bool canJump;
	bool canRoundhouse;
};

