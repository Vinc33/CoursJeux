#include "EntityInanimate.h"
#include <SFML\Graphics\Transformable.hpp>
#include <SFML\Graphics\drawable.hpp>

EntityInanimate::EntityInanimate()
{
	sprite = new sf::Sprite();
}


EntityInanimate::~EntityInanimate()
{
	delete sprite;
}

void EntityInanimate::draw(sf::RenderTarget& target)
{
	target.draw(*sprite, getTransform());
}

void EntityInanimate::SetSprite(sf::Texture* t, bool reverseImage)
{
	sf::IntRect uvRect;

	delete sprite;
	sprite = new sf::Sprite();
	sprite->setTexture(*t);

	if (reverseImage)
	{
		sprite->setOrigin( 0, 0 );
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