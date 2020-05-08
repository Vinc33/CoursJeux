#pragma once
#include "EntityAction.h"

class Knockback :
	public EntityAction
{
public:
	Knockback(int initialForceX, int initialForceY, Entity* e);
	~Knockback();

	int update();
};

