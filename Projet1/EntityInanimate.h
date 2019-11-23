#pragma once
#include "EntityBase.h"
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
class EntityInanimate :
	public virtual EntityBase
{
public:
	EntityInanimate();
	~EntityInanimate();

	virtual void draw(sf::RenderTarget& target);

	void SetSprite(sf::Texture* t, bool reverseImage = false);

protected:
	sf::Sprite* sprite;
};

