#include "ThrownKnife.h"
#include "TimeManager.h"

ThrownKnife::ThrownKnife(float speed) : StraightProjectile(speed)
{
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("Assets\\ToolAndMagic\\ThrownKnife.png");
	SetSprite(texture, speed < 0);
}

ThrownKnife::~ThrownKnife()
{

}