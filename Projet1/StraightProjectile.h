#pragma once
#include "EntityInanimate.h"
class StraightProjectile : public EntityInanimate
{
public:
	StraightProjectile(float speedX, float speedY = 0);
	~StraightProjectile();

	virtual void Update();

private:
	float speedX;
	float speedY;
};

