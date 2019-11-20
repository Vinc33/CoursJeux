#pragma once
#include "EntityInanimate.h"
class Particle :
	public EntityInanimate
{
public:
	Particle(float lifeTime, float originX = 0, float originY = 0);
	~Particle();

	virtual void Update() = 0;
	void setOrigin(float x, float y);
	void MoveOrigin(float newX, float newY);

	float lifeTime;
private:
	float originX;
	float originY;
};

