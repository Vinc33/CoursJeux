#include "EntityCollision.h"
#include "Game.h" 


EntityCollision::EntityCollision()
{
	body = new sf::RectangleShape();
	hitbox = new Collider(body);
}


EntityCollision::~EntityCollision()
{
	delete body;
}

void EntityCollision::update()
{
	GameView::Game::AddForCheckCollision(this);
	body->setPosition(getPosition());
}

RectangleShape * EntityCollision::GetCollider()
{
	 return body; 
}
