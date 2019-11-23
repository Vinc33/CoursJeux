#pragma once
#include "Hero.h"

enum RogueWeapon
{
	NONE,
	KNIFE,
	AXE,
	CALTROPS
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
	float frontToolTimer;
	float frontToolCooldown;
	float standToolTimer;
	float standToolCooldown;

	RogueWeapon equipedDown;
	RogueWeapon equipedUp;
	RogueWeapon equipedFront;
	RogueWeapon equipedStand;
};

