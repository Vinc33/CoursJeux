#pragma once
#include "ActionEntity.h"
class MonkPunch :
	public ActionEntity
{
public:
	MonkPunch(Entity* e, bool canJump);
	~MonkPunch();

	int update();

private:
	float timeRemaining;
	bool canJump;
};

