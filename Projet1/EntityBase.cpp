#include "EntityBase.h"



EntityBase::EntityBase()
{
}


EntityBase::~EntityBase()
{
}

void EntityBase::draw(sf::RenderTarget& target)
{
}

void EntityBase::drawHitBox(sf::RenderTarget& target)
{
}

FloatRect* EntityBase::getHitBox()
{
	return nullptr;
}

void EntityBase::onCollision(EntityBase* e)
{
}

EntityBase::COLLISIONEFFECT* EntityBase::getCollisionEffects()
{
	return nullptr;
}

std::string EntityBase::toString()
{
	return "EntityBase";
}