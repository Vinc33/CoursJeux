#pragma once
#include "EntityAnimated.h"
#include "EntityPhysic.h"
class HandBomb :
	public EntityAnimated,
	public EntityPhysic
{
public:
	HandBomb(float initialSpeed);
	~HandBomb();

	void update();
private:
	void addAnimations();
};

