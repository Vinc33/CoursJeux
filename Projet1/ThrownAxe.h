#pragma once
#include "EntityAnimated.h"
#include "EntityPhysic.h"
class ThrownAxe :
	public EntityAnimated,
	public EntityPhysic
{
public:
	ThrownAxe(int initialSpeed);
	~ThrownAxe();
};

