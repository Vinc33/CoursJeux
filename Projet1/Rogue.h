#pragma once
#include "Hero.h"

enum RogueWeapon
{
	NONE,
	KNIFE,
	AXE
};

class Rogue :
	public Hero
{
public:
	Rogue();
	~Rogue();

	void ChangeAction(int enumIndex);
	void Update();
private:
	void addAnimations();
	void useWeapon(RogueWeapon weapon);

	float downToolTimer;
	float downToolCooldown;
	float upToolTimer;
	float upToolCooldown;

	RogueWeapon EquipedDown;
	RogueWeapon EquipedUp;
};

