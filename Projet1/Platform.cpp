#include "Platform.h"



Platform::Platform(sf::Texture* texture, sf::Vector2f position)
{
	setPosition(position);
	setSprite(texture);
}

Platform::~Platform()
{

}

void Platform::draw(sf::RenderTarget & target)
{
	EntityInanimate::draw(target);
}

std::string Platform::toString()
{
	return "Platform";
}
