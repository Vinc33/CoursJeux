#include "Entity.h"
#include "TimeManager.h"
#include "Action.h"

Entity::Entity()
{
	body = new RectangleShape();
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

	//temporary ground
	if (velY > 0 && position.getPosition().y > 321 - velY * TimeManager::DeltaTime)
	{
		isAirborne = false;
		position.setPosition(position.getPosition().x, 321);
		velY = 0;
	}
	//end temporary ground
}

void Entity::MoveOnHitBox()
{
	setPosition(body->getPosition());
}
