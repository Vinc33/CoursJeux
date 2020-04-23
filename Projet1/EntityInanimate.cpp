#include "EntityInanimate.h"
#include <SFML\Graphics\Transformable.hpp>
#include <SFML\Graphics\drawable.hpp>

EntityInanimate::EntityInanimate()
{
	sprite = new sf::Sprite();
	hitbox = sprite->getGlobalBounds();
}


EntityInanimate::~EntityInanimate()
{
	delete sprite;
}

void EntityInanimate::draw(sf::RenderTarget& target)
{
	target.draw(*sprite, getTransform());
	hitbox = sprite->getGlobalBounds();
	hitbox.left = getPosition().x;
	hitbox.top = getPosition().y;
}

void EntityInanimate::drawHitBox(sf::RenderTarget & target)
{
	RectangleShape rs({ hitbox.width, hitbox.height });
	rs.setFillColor(Color(10, 100, 0, 100));
	rs.setPosition({ hitbox.left, hitbox.top });
	target.draw(rs);
}

void EntityInanimate::setSprite(sf::Texture* t, bool reverseImage)
{
	sf::IntRect uvRect;

	delete sprite;
	sprite = new sf::Sprite();
	sprite->setTexture(*t);

	if (reverseImage)
	{
		sprite->setOrigin(0, 0);
		setOrigin(0, 0);
		sprite->setScale({ -2, 2 });
	}
	else
	{
		sprite->setOrigin(0, 0);
		setOrigin(0, 0);
		sprite->setScale({ 2, 2 });
	}
}

FloatRect * EntityInanimate::getHitBox()
{
	return &hitbox;
}

FloatRect * EntityInanimate::getDrawLocation()
{
	//TODO
	return nullptr;
}
