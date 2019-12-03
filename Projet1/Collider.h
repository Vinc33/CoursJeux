#pragma once
#include <SFML\Graphics.hpp>
#include "EntityBase.h"
#include "EntityForCollision.h" 
using namespace sf;
class Collider
{
public:
	Collider(RectangleShape* _body);
	~Collider();

	bool checkCollision(RectangleShape* other, float push);
	bool checkCollision(RectangleShape* other, float push, EntityBase* e);
	sf::Vector2f GetHalfSize(RectangleShape* _body) { return _body->getSize() / 2.0f; }


private :
	sf::RectangleShape* body;
};

