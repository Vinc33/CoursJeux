#pragma once
#include "ActionEntity.h"
class Entity;
class MonkSecondJump :
	public ActionEntity
{
public:
	MonkSecondJump(Entity* e, bool canRoundhouse, bool canPunch, bool canDropkick);
	~MonkSecondJump();

	int Update();
private:
	bool canRoundhouse;
	bool canPunch;
	bool canDropkick;
};

