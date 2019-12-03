#pragma once
#include "EntityPhysic.h"
#include <SFML\Graphics\drawable.hpp>
class EntityForCollision :
	public EntityPhysic
{
public:
	EntityForCollision();
	~EntityForCollision();
	void draw(sf::RenderTarget& t);
};

