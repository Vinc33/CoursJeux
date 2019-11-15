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
	float timeRemaining;
};

