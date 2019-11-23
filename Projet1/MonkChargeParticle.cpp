#include "MonkChargeParticle.h"
#include "TimeManager.h"
#include <ctime>

MonkChargeParticle::MonkChargeParticle(bool reversed, float originX, float originY) : Particle(0.6f, originX, originY)
{
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("Assets\\Particle\\MonkCharge.png");

	SetSprite(texture, reversed);
	position.setOrigin(sprite->getTextureRect().width / 2.0f, sprite->getTextureRect().height / 2.0f);

	isCounterClockwise = reversed;
}


MonkChargeParticle::~MonkChargeParticle()
{
}

void MonkChargeParticle::update()
{
	sprite->scale({ 1 - 2.2f * TimeManager::DeltaTime , 1 - 2.2f * TimeManager::DeltaTime });
	
	if (isCounterClockwise)
	{
		position.rotate(-720 * TimeManager::DeltaTime);
		position.setOrigin(-sprite->getTextureRect().width / 2 * sprite->getScale().x, sprite->getTextureRect().height / 2 * sprite->getScale().y);
	}
	else
	{
		position.rotate(720 * TimeManager::DeltaTime);
		position.setOrigin(sprite->getTextureRect().width / 2 * sprite->getScale().x, sprite->getTextureRect().height / 2 * sprite->getScale().y);
	}
}
