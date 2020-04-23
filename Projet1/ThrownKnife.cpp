#include "ThrownKnife.h"
#include "TimeManager.h"
#include "Manager\AssetManager.h"

ThrownKnife::ThrownKnife(float speed) : StraightProjectile(speed)
{
	sf::Texture* texture = &AssetManager::getTexture("knife");
	setSprite(texture, speed < 0);
}

ThrownKnife::~ThrownKnife()
{

}