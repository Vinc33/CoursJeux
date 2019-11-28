#include "EntityCollision.h"
#include "Game.h" 


EntityCollision::EntityCollision()
{
}


EntityCollision::~EntityCollision()
{
	delete body;
}

void EntityCollision::init()
{
	body = new sf::RectangleShape();
	body->setSize(this->getDrawSize());
	hitbox = new Collider(body);
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

void EntityCollision::drawCollisionShape(sf::RenderTarget& target)
{
	target.draw(*body);
}


