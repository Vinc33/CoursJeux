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

	virtual void setSprite(sf::Texture* t, bool reverseImage = false);

	virtual void draw(sf::RenderTarget& target);
	virtual void drawHitBox(sf::RenderTarget& target);
	virtual FloatRect * getHitBox();
	virtual FloatRect * getDrawLocation();

protected:
	sf::Sprite* sprite;
	sf::FloatRect hitbox;
};

