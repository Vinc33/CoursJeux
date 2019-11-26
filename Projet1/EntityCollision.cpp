#include "EntityCollision.h"
#include "Game.h" 


EntityCollision::EntityCollision()
{
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

void EntityCollision::init()
{
	body = new sf::RectangleShape();
	body->setSize(this->getDrawSize());
	hitbox = new Collider(body);
}


RectangleShape * EntityCollision::GetCollider()
{
	 return body; 
}
