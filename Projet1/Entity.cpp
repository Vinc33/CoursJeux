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
	EntityStateMachine::update();
	EntityPhysic::update();
	EntityAnimated::update();
	EntityParticleEmitter::update();

	//temporary ground
	if (velY > 0 && getPosition().y > 200 - velY * TimeManager::DeltaTime)
	{
		isAirborne = false;
		setPosition({ getPosition().x, 200 });
		velY = 0;
	}
	//end temporary ground
}

void Entity::draw(sf::RenderTarget& target)
{
	EntityAnimated::draw(target);
	EntityParticleEmitter::draw(target);
}