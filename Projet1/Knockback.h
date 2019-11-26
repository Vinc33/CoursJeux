#pragma once
#include "ActionEntity.h"

class Knockback :
	public ActionEntity
{
public:
	Knockback(int initialForceX, int initialForceY, Entity* e);
	~Knockback();

	int update();
};

