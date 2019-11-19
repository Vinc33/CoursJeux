#include "Entity.h"
#include "TimeManager.h"
#include "Action.h"

Entity::Entity()
{
	body = new sf::RectangleShape();
	particlesMoveWithParent = true;
}

Entity::~Entity()
{
	delete body;
}

void Entity::setPosition(const sf::Vector2f& pos)
{
	position.setPosition(pos.x, pos.y);
}
void Entity::setPosition(const int& x, const int& y)
{
	position.setPosition((float)x, (float)y);
}

void Entity::Update()
{
	EntityBrain::Update();
	EntityPhysic::Update();
	EntityParticleEmitter::Update();

	//temporary ground
	if (velY > 0 && position.getPosition().y > 321 - velY * TimeManager::DeltaTime)
	{
		isAirborne = false;
		position.setPosition(position.getPosition().x, 321);
		velY = 0;
	}
	//end temporary ground
}

void Entity::Draw(sf::RenderTarget& target)
{
	EntityAnimated::Draw(target);
	EntityParticleEmitter::Draw(target);
}

void Entity::MoveOnHitBox()
{
}
