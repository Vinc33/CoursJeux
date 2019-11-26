/*#include "Entity.h"
#include "TimeManager.h"
#include "Action.h"

Entity::Entity()
{
	body = new RectangleShape();
	CurrentAction = new Action(this);
	gravityMult = 1;
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

void Entity::accelerate(float x)
{
	if (x != 0 && (abs(velX) < maxVelX))
	{
		velX += (acc + drag) * x * TimeManager::DeltaTime;
		if (velX > maxVelX)
			velX = (float)maxVelX;
		else if (velX < -maxVelX)
			velX = (float)-maxVelX;
	}
}

void Entity::jump(float power)
{
	isAirborne = true;
	velY -= jumpingStrength * power;
}

void Entity::ChangeAction(int enumIndex)
{
}

void Entity::Update()
{
	int i = CurrentAction->Update();
	if (i != -1)
		this->ChangeAction(i);

	int CurrentDrag = isAirborne ? airdrag : drag;
	position.move(velX * TimeManager::DeltaTime, 0);
	if (velX > 0)
	{
		velX -= CurrentDrag * TimeManager::DeltaTime;
		if (velX < 0)
			velX = 0;
	}
	else if (velX < 0)
	{
		velX += CurrentDrag * TimeManager::DeltaTime;
		if (velX > 0)
			velX = 0;
	}

	//temporary ground
	if (velY > 0 && position.getPosition().y > 321 - velY * TimeManager::DeltaTime)
	{
		isAirborne = false;
		position.setPosition(position.getPosition().x, 321);
		velY = 0;
	}	
	//end temporary ground

	if (isAirborne)
	{
		position.move(0, velY * TimeManager::DeltaTime + 0.5f * acc * TimeManager::DeltaTime * TimeManager::DeltaTime);
		velY += gravity * gravityMult * TimeManager::DeltaTime;
	}
}

void Entity::Draw(sf::RenderTarget& target)
{
	animator.Update();
	Sprite* s = animator.GetSprite(isFacingLeft);
	target.draw(*s, position.getTransform());
}

void Entity::MoveOnHitBox()
{
	setPosition(body->getPosition());
}
*/