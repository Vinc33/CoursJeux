#pragma once
#include "HeroAction.h"
class MonkRisingKick :
	public HeroAction
{
public:
	MonkRisingKick(Hero* e);
	~MonkRisingKick();
	int update();
private:
	float timeRemaining;
};

