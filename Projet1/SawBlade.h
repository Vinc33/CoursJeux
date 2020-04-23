#pragma once
#include "EntityAnimated.h"
#include "EntityPhysic.h"


class SawBlade :
	public EntityAnimated,
	public EntityPhysic
{
public:
	SawBlade(int initialSpeed);
	~SawBlade();

	void update();
};

