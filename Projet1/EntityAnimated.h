#pragma once
#include "Animation.h"
#include "EntityBase.h"

#include <iostream>
//#include <SFML\Graphics\Sprite.hpp>
#include <string>

class EntityAnimated : public virtual EntityBase
{
public:
	EntityAnimated();
	~EntityAnimated();

	bool imageReversed;

	virtual void update();
	virtual void draw(sf::RenderTarget& target);
	virtual void drawHitBox(sf::RenderTarget& target);

	void addAnimation(Animation* a, std::string name);
	void changeAnimation(std::string name);
	void jumpToFrame(unsigned int index);


	virtual FloatRect* getHitBox();

	virtual Transform getTransform();

	virtual Vector2f getOrigin();
	virtual void setOrigin(Vector2f origin);

	virtual Vector2f getPosition();
	virtual void setPosition(Vector2f position);
	virtual void setPosition(float x, float y);
	virtual void move(float x, float y);

	virtual float getRotation();
	virtual void setRotation(float angle);
	virtual void rotate(float angle);
protected:
	Animation * currentAnimation;
	std::map<std::string, Animation *> animations;
	sf::FloatRect hitbox;
	sf::Sprite* sprite;
};

