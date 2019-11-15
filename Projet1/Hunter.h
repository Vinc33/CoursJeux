#pragma once
#include "Hero.h"

enum Bullet { NORMAL, FIERY, MAGIC, EXPLOSIVE };

class Hunter :
	public Hero
{
public:
	Hunter();
	~Hunter();
	//DamageInfo GetDamage() override;
	void ChangeAction(int enumIndex);
private:
	Bullet EquipedBullet;
	void AddAnimations();
};
