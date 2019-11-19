#pragma once
#include "EntityAnimated.h"
#include "EntityBrain.h"
#include "EntityPhysic.h"

class Action;

class Entity :
	public EntityAnimated,
	public EntityBrain,
	public EntityPhysic
{
public:
	Entity();
	~Entity();

	void setPosition(const sf::Vector2f& pos);
	void setPosition(const int& x, const int& y);

	void Update();
	RectangleShape* GetCollider() { return body; }

	void MoveOnHitBox();

protected:
	sf::RectangleShape* body;
};

