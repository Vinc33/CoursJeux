#pragma once
#include "EntityInanimate.h"
class Particle :
	public EntityInanimate
{
public:
	Particle(EntityBase * parent ,float lifeTime, float originX = 0, float originY = 0);
	~Particle();

	virtual void update() = 0;

	void onParentMove();

	float lifeTime;

private:
	EntityBase* parent;
	float lastParentPosX;
	float lastParentPosY;
};

