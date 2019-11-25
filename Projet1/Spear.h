#pragma once
#include "EntityInanimate.h"
#include "EntityPhysic.h"
class Spear :
	public EntityInanimate,
	public EntityPhysic
{
public:
	Spear(float initialSpeed);
	~Spear();

	void update();
private:
	Vector2f lastPosition;
	float timer;
};

