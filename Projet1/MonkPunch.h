#pragma once
#include "ActionEntity.h"
class MonkPunch :
	public ActionEntity
{
public:
	MonkPunch(Entity* e, bool canJump);
	~MonkPunch();

	int Update();

private:
	float timeRemaining;
	bool canJump;
};

