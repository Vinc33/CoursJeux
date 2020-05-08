#pragma once
#include "HeroAction.h"
class MonkWalking :
	public HeroAction
{
public:
	MonkWalking(Hero* e);
	~MonkWalking();
	int update();
};

