#include "EntityInanimate.h"
#include <SFML\Graphics\Transformable.hpp>
#include <SFML\Graphics\drawable.hpp>

EntityInanimate::EntityInanimate()
{
	sprite = new sf::Sprite();
	hitbox = sprite->getLocalBounds();
}


EntityInanimate::~EntityInanimate()
{
	delete sprite;
}

void EntityInanimate::setSprite(sf::Texture* t, bool reverseImage)
{
	sprite->setTexture(*t);

	if (reverseImage)
	{
		sprite->setScale({ -1, 1 });
	}
	else
	{
		sprite->setScale({ 1, 1 });
	}
}

void EntityInanimate::draw(sf::RenderTarget& target)
{
	target.draw(*sprite);

	hitbox = sprite->getLocalBounds();
	hitbox.left = getPosition().x;
	hitbox.top = getPosition().y;
}

void EntityInanimate::drawHitBox(sf::RenderTarget & target)
{
	RectangleShape rs({ getHitBox()->width, getHitBox()->height });
	rs.setFillColor(Color(10, 100, 0, 100));
	rs.setOrigin(getOrigin());
	rs.setPosition(getPosition());
	rs.setRotation(getRotation());
	rs.setScale(sprite->getScale());
	target.draw(rs);
}

FloatRect * EntityInanimate::getHitBox()
{
	return &hitbox;
}

Transform EntityInanimate::getTransform()
{
	return sprite->getTransform();
}

Vector2f EntityInanimate::getOrigin()
{
	return sprite->getOrigin();
}

void EntityInanimate::setOrigin(Vector2f origin)
{
	sprite->setOrigin(origin);
}

Vector2f EntityInanimate::getPosition()
{
	return sprite->getPosition();
}

void EntityInanimate::setPosition(Vector2f origin)
{
	sprite->setPosition(origin);
}

void EntityInanimate::setPosition(float x, float y)
{
	sprite->setPosition(x, y);
}

void EntityInanimate::move(float x, float y)
{
	sprite->move(x, y);
}

float EntityInanimate::getRotation()
{
	return sprite->getRotation();
}

void EntityInanimate::setRotation(float angle)
{
	sprite->setRotation(angle);
}

void EntityInanimate::rotate(float angle)
{
	sprite->rotate(angle);
}
