#pragma once
#include "Hero.h"

enum Bullet { NORMAL, FIERY, MAGIC, EXPLOSIVE };

class Hunter :
	public Hero
{
public:
	Hunter();
	~Hunter();
	//DamageInfo getDamage() override;
	void changeAction(int enumIndex);
private:
	Bullet equipedBullet;
	void addAnimations();
};
