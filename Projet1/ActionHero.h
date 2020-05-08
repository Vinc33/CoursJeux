#pragma once
#include "Action.h"
class Hero;

class HeroAction :
	public Action
{
public:
	HeroAction(Hero* e);
	~HeroAction();

protected:
	Hero* parent;
};

