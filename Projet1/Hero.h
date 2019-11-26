#pragma once
#include "Character.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"

class Hero :
	public Character
{
public:
	Hero(string unitName, short baseDamage, short maxHP);
	~Hero();
	virtual void changeAction(int enumPlaceholder) = 0;
};

