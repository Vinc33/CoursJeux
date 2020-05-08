#pragma once
#include "HeroAction.h"
class Standing :
	public HeroAction
{
public:
	Standing(Hero* e);
	~Standing();
	int update();
};

