#include "Particle.h"



Particle::Particle(float lifeTime, float originX, float originY)
{
	position.setPosition(originX, originY);
	this->lifeTime = lifeTime;
	this->originX = 0;
	this->originY = 0;
}

Particle::~Particle()
{

}

void Particle::MoveOrigin(float newOriginX, float newOriginY)
{
	position.setPosition(newOriginX + position.getPosition().x - originX, newOriginY + position.getPosition().y - originY);
	originX = newOriginX;
	originY = newOriginY;
}
