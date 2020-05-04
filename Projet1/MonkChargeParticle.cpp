#include "MonkChargeParticle.h"
#include "TimeManager.h"
#include <ctime>
#include "Manager\AssetManager.h"

MonkChargeParticle::MonkChargeParticle(bool reversed, float originX, float originY) : Particle(0.6f, originX, originY)
{
	sf::Texture* texture = &AssetManager::getTexture("monk_charge_particle");

	setSprite(texture, reversed);
	setOrigin({ sprite->getTextureRect().width / 2.0f, sprite->getTextureRect().height / 2.0f });

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
		rotate(-720 * TimeManager::DeltaTime);
		setOrigin({ sprite->getTextureRect().width / 2 * sprite->getScale().x, sprite->getTextureRect().height / 2 * sprite->getScale().y });
	}
	else
	{
		rotate(720 * TimeManager::DeltaTime);
		setOrigin({sprite->getTextureRect().width / 2 * sprite->getScale().x, sprite->getTextureRect().height / 2 * sprite->getScale().y });
	}
}
