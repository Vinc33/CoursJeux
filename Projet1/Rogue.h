#pragma once
#include "Hero.h"
#include "HeroActionsEnum.h"

enum RogueWeapon
{
	NONE,
	KNIFE,
	AXE,
	CALTROPS,
	SPEAR,
	HANDBOMB,
	SAWBLADE
};

class Rogue :
	public Hero
{
public:
	Rogue(short playerID);
	~Rogue();

	void changeAction(int enumIndex);
	void update();

	std::string toString();
private:
	void addAnimations();
	void useWeapon(RogueWeapon weapon);

	float attackTimer;
	float attackCooldown;
	float delayedActionTimer;
	PlayerAction nextAction;
	bool checkForDelayedAction;

	float itemTimer;
	float itemCooldown;
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

