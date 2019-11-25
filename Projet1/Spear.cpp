#include "Spear.h"
#include "TimeManager.h"
#include <cmath>

#define PI 3.14159265

Spear::Spear(float initialSpeed)
{
	maxVelX = 10000;
	velX = initialSpeed;
	jumpingStrength = 200;
	airdrag = 400;
	gravity = 1100;
	lastPosition = getPosition();

	jump();

	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("Assets\\ToolAndMagic\\Spear.png");
	SetSprite(texture, initialSpeed < 0);

	if (initialSpeed < 0)
		setRotation(10);
	else
		setRotation(-10);
	timer = 0.0f;
}


Spear::~Spear()
{
}

void Spear::update()
{
	timer += TimeManager::DeltaTime;
	EntityPhysic::update();

	if (timer > 0.1f)
	{
		float angle = (float)(atan2(lastPosition.y - getPosition().y, abs(lastPosition.x - getPosition().x)) * 180 / PI);
		if (velX < 0)
			setRotation(angle);
		else
			setRotation(-angle);
	}

	lastPosition = getPosition();

}
