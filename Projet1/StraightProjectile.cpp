#include "StraightProjectile.h"
#include "TimeManager.h"


StraightProjectile::StraightProjectile(float speedX, float speedY)
{
	this->speedX = speedX;
	this->speedY = speedY;
}


StraightProjectile::~StraightProjectile()
{
}

void StraightProjectile::update()
{
	move(speedX * TimeManager::DeltaTime, speedY * TimeManager::DeltaTime);
}
