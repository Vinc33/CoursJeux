#pragma once
#include "Character.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"
#include "EnumInput.h"

class Hero :
	public Character
{
public:
	Hero(string unitName, short playerID,  short baseDamage, short maxHP);
	~Hero();

	virtual void changeAction(int enumPlaceholder) {};

	bool getKeyState(INPUT key);

private:
	short playerID;
};

