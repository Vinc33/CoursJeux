#pragma once
#include "EntityBase.h"
#include "Collider.h"
class EntityCollision :
	public virtual EntityBase
{
public:
	EntityCollision();
	~EntityCollision();

	virtual void update();

	RectangleShape* GetCollider();
	Collider* hitbox;


protected:
	sf::RectangleShape* body;
};

