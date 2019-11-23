#pragma once
#include "EntityBase.h"
class EntityCollision :
	public virtual EntityBase
{
public:
	EntityCollision();
	~EntityCollision();

	void Update();

	RectangleShape* GetCollider();
	Collider* hitbox;


protected:
	sf::RectangleShape* body;
};

