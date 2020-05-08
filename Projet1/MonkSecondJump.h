#pragma once
#include "HeroAction.h"
class MonkSecondJump :
	public HeroAction
{
public:
	MonkSecondJump(Hero* e, bool canRoundhouse, bool canPunch, bool canDropkick);
	~MonkSecondJump();

	int update();
private:
	bool canRoundhouse;
	bool canPunch;
	bool canDropkick;
};

