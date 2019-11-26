#pragma once
#include "Action.h"
class PingouinAttack :
	public Action
{
public:
	PingouinAttack(Entity* e);
	~PingouinAttack();

	int Update();

	float timeRemaining;
};

