#pragma once
#include "Hero.h"

class Hunter :
	public Hero
{
public:
	Hunter(short playerID);
	~Hunter();
	//DamageInfo getDamage() override;
	void changeAction(int enumIndex);
private:
	void addAnimations();
};
