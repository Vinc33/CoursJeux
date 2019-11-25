#include "Particle.h"



Particle::Particle(float lifeTime, float offsetX, float offsetY)
{
	setPosition(offsetX, offsetY);
	this->lifeTime = lifeTime;
}

Particle::~Particle()
{

}

void Particle::setOrigin(float x, float y)
{
	originX = x;
	originY = y;
}

void Particle::MoveOrigin(float newX, float newY)
{
	move((newX - originX), (newY - originY));
	originX = newX;
	originY = newY;
}
