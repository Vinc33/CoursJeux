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

void Entity::update()
{
	EntityBrain::update();
	EntityPhysic::update();
	EntityParticleEmitter::update();
	EntityCollision::update();

	//temporary ground
	if (velY > 0 && getPosition().y > 321 - velY * TimeManager::DeltaTime)
	{
		isAirborne = false;
		setPosition(getPosition().x, 320);
		velY = 0;
	}
	//end temporary ground
}

void Entity::draw(sf::RenderTarget& target)
{
	EntityAnimated::draw(target);
	EntityParticleEmitter::draw(target);
}

