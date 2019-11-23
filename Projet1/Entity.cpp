#include "Entity.h"
#include "TimeManager.h"
#include "Action.h"

Entity::Entity()
{
	particlesMoveWithParent = true;
}

Entity::~Entity()
{
}

void Entity::setPosition(const sf::Vector2f& pos)
{
	position.setPosition(pos.x, pos.y);
}
void Entity::setPosition(const int& x, const int& y)
{
	position.setPosition((float)x, (float)y);
}

void Entity::update()
{
	EntityBrain::update();
	EntityPhysic::update();
	EntityParticleEmitter::update();
	EntityCollision::update();

	//temporary ground
	if (velY > 0 && position.getPosition().y > 321 - velY * TimeManager::DeltaTime)
	{
		isAirborne = false;
		position.setPosition(position.getPosition().x, 320);
		velY = 0;
	}
	//end temporary ground
}

void Entity::draw(sf::RenderTarget& target)
{
	EntityAnimated::draw(target);
	EntityParticleEmitter::draw(target);
}

