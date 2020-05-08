#pragma once
#include "HeroAction.h"
class MonkPunch :
	public HeroAction
{
public:
	MonkPunch(Hero* e, bool canJump);
	~MonkPunch();

	int update();

private:
	float timeRemaining;
	bool canJump;
};

