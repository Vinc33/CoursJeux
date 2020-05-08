#pragma once
#include "HeroAction.h"
class MonkDiveKick :
	public HeroAction
{
public:
	MonkDiveKick(Hero* e);
	~MonkDiveKick();

	int update();
private:
	float countDown;
};

