#pragma once
#include "EntityAnimated.h"
#include "EntityPhysic.h"
#include "EntityCollision.h"
class ThrownAxe :
	public EntityAnimated,
	public EntityPhysic,
	public EntityCollision

{
public:
	ThrownAxe(int initialSpeed);
	~ThrownAxe();
	void update();
};

