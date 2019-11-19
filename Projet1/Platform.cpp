#include "Platform.h"



Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	body = new RectangleShape();
	body->setSize(size);
	body->setOrigin(size / 2.0f);
	body->setTexture(texture);
	body->setPosition(position);
	/*
	currentSprite = Sprite();
	currentSprite.setTexture(*texture);
	currentSprite.setScale(2, 2);
	currentSprite.setTextureRect(*(sf::IntRect*)body);
	*/
	
}


Platform::~Platform()
{
}

void Platform::Draw(sf::RenderWindow& window) {
	window.draw(*body);
}