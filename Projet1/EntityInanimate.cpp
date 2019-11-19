#include "EntityInanimate.h"
#include <SFML\Graphics\Transformable.hpp>
#include <SFML\Graphics\Drawable.hpp>

EntityInanimate::EntityInanimate()
{
	sprite = new sf::Sprite();
}


EntityInanimate::~EntityInanimate()
{
	delete sprite;
}

void EntityInanimate::Draw(sf::RenderTarget& target)
{
	target.draw(*sprite, position.getTransform());
}

void EntityInanimate::SetSprite(sf::Texture* t, bool reverseImage)
{
	sf::IntRect uvRect;

	delete sprite;
	sprite = new sf::Sprite();
	sprite->setTexture(*t);

	if (reverseImage)
	{
		sprite->setOrigin({ sprite->getGlobalBounds().width, 0 });
		sprite->setScale({ -2, 2 });
	}
	else
		sprite->setScale({ 2, 2 });
}