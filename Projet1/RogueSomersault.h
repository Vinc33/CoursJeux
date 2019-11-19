#pragma once
#include "ActionEntity.h"
class RogueSomersault :
	public ActionEntity
{
public:
	RogueSomersault(Entity* e);
	~RogueSomersault();
	int Update();
private:
	bool chainAttack;
	bool chainItemUp;
	bool chainItemDown;
	float timeRemaining;
};

