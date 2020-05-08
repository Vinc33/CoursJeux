#pragma once
#include "HeroAction.h"

enum direction;

class RogueSomersault :
	public HeroAction
{
public:
	RogueSomersault(Hero* e);
	~RogueSomersault();
	int update();
private:
	bool chainAttack;
	bool chainItemStand;
	bool chainItemFront;
	bool chainItemUp;
	bool chainItemDown;
	direction chainDirection;
	float timeRemaining;
};

