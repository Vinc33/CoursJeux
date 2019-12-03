#include "MagicBulletCandy.h"
#include "TimeManager.h"

using namespace sf;

float MagicBulletCandy::lerp(float a, float b, float f)
{
	return a + f * (b - a);
}

MagicBulletCandy::MagicBulletCandy(float lifeTime, sf::Transformable* _posToFollow, float _offset) : Particle(lifeTime)
{
	posToFollow = _posToFollow;
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("Assets\\Particle\\BulletCandy.png");
	SetSprite(texture, false);
	position.setOrigin(4.5, 2);
	this->offset = _offset;
	position.rotate(rand()%360);
}

MagicBulletCandy::~MagicBulletCandy()
{

}

void MagicBulletCandy::Update()
{
	degree += 1;
	position.setPosition(posToFollow->getPosition().x - offset, posToFollow->getPosition().y);
	//position.setPosition({ lerp(position.getPosition().x,posToFollow->getPosition().x, tracking), lerp(position.getPosition().y,posToFollow->getPosition().y, 0) });
	position.rotate(degree);
}
