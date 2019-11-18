#include "EntityPhysic.h"
#include "TimeManager.h"
#include <cmath>

EntityPhysic::EntityPhysic()
{
	gravityMult = 1;
}


EntityPhysic::~EntityPhysic()
{

}


void EntityPhysic::accelerate(float x)
{
	if (x != 0 && (abs(velX) < maxVelX))
	{
		velX += (acc + drag) * x * TimeManager::DeltaTime;
		if (velX > maxVelX)
			velX = (float)maxVelX;
		else if (velX < -maxVelX)
			velX = (float)-maxVelX;
	}
}

void EntityPhysic::jump(float power)
{
	isAirborne = true;
	velY -= jumpingStrength * power;
}

void EntityPhysic::Update()
{
	int CurrentDrag = isAirborne ? airdrag : drag;
	position.move(velX * TimeManager::DeltaTime, 0);
	if (velX > 0)
	{
		velX -= CurrentDrag * TimeManager::DeltaTime;
		if (velX < 0)
			velX = 0;
	}
	else if (velX < 0)
	{
		velX += CurrentDrag * TimeManager::DeltaTime;
		if (velX > 0)
			velX = 0;
	}

	if (isAirborne)
	{
		position.move(0, velY * TimeManager::DeltaTime + 0.5f * acc * pow(TimeManager::DeltaTime, 2));
		velY += gravity * gravityMult * TimeManager::DeltaTime;
	}
}