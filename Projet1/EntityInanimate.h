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

	virtual FloatRect* getHitBox();

	virtual Transform getTransform();

	virtual Vector2f getOrigin();
	virtual void setOrigin(Vector2f origin);

	virtual Vector2f getPosition();
	virtual void setPosition(Vector2f origin);
	virtual void setPosition(float x, float y);
	virtual void move(float x, float y);

	virtual float getRotation();
	virtual void setRotation(float angle);
	virtual void rotate(float angle);

protected:
	sf::Sprite* sprite;
	sf::FloatRect hitbox;
};

