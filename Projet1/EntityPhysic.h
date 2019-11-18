#pragma once
#include "EntityBase.h"
class EntityPhysic : public virtual EntityBase
{
public:
	EntityPhysic();
	~EntityPhysic();

	void Update();

	void accelerate(float x);
	void jump(float power = 1);

	bool isAirborne;
	int maxVelX;
	float velX;
	float velY;
	int acc;
	int drag;
	int jumpingStrength;
	int gravity;
	float gravityMult;
	int airdrag;
	//int maxFallSpeed;
};

