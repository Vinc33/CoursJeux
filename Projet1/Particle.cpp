#include "Particle.h"



Particle::Particle(EntityBase* parent, float lifeTime, float offsetX, float offsetY)
{
	lastParentPosX = parent->getPosition().x;
	lastParentPosY = parent->getPosition().y;
	this->parent = parent;
	setPosition(lastParentPosX + offsetX, lastParentPosY + offsetY);
	this->lifeTime = lifeTime;
}

Particle::~Particle()
{

}

void Particle::onParentMove()
{
	move((parent->getPosition().x - lastParentPosX), (parent->getPosition().y - lastParentPosY));
	lastParentPosX = parent->getPosition().x;
	lastParentPosY = parent->getPosition().y;
}