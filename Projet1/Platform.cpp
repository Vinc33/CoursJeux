#include "Platform.h"



Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	body = new RectangleShape();
	body->setSize(size);
	//body->setOrigin(size / 2.0f);
	body->setTexture(texture);
	body->setPosition(position);
	hitbox = new Collider(body);
}


Platform::~Platform()
{
}

void Platform::draw(sf::RenderWindow& window) {
	window.draw(*body);
}