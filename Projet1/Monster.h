#pragma once
#include "Character.h"
class Monster :
	public Character
{
public:
	Monster(string unitName, short baseDamage, short maxHP);
	~Monster();
protected:
	void changeAction(int enumPlaceholder) override;
};

