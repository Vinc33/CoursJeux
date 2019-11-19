#pragma once
#include "EntityBase.h"
class EntityPhysic : public virtual EntityBase
{
public:
	EntityPhysic();
	~EntityPhysic();

	virtual void Update();

	void accelerate(float x);
	void jump(float powerMult = 1);

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

