#include "Particle.h"



Particle::Particle(float lifeTime, float offsetX, float offsetY)
{
	setPosition(offsetX, offsetY);
	this->lifeTime = lifeTime;
}

Particle::~Particle()
{

}

void Particle::parentMove(float newX, float newY)
{
	move((newX - parentPosX), (newY - parentPosY));
	parentPosX = newX;
	parentPosY = newY;
}

void Particle::setParentPosition(float x, float y)
{
	parentPosX = x;
	parentPosY = y;
}
