#pragma once
#include "EntityAnimated.h"
#include "EntityPhysic.h"
class Caltrops :
	public EntityAnimated,
	public EntityPhysic
{
public:
	Caltrops(float initialSpeed);
	~Caltrops();

	void update();
};

