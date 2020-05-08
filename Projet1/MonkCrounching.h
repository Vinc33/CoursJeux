#pragma once
#include "HeroAction.h"
class MonkCrounching :
	public HeroAction
{
public:
	MonkCrounching(Hero* e, float forceAction);
	~MonkCrounching();
	int update();
private:
	float forceAction;
	float forceActionCounter;
};

