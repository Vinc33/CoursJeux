#pragma once
#include "Action.h"
class RogueSomersault :
	public Action
{
public:
	RogueSomersault(Entity* e);
	~RogueSomersault();
	int Update();
private:
	bool chainAttack;
	float timeRemaining;
};

