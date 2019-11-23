#pragma once
#include "ActionEntity.h"

enum direction;

class RogueSomersault :
	public ActionEntity
{
public:
	RogueSomersault(Entity* e);
	~RogueSomersault();
	int Update();
private:
	bool chainAttack;
	bool chainItemStand;
	bool chainItemFront;
	bool chainItemUp;
	bool chainItemDown;
	direction chainDirection;
	float timeRemaining;
};

