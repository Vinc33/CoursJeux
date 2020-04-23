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
	virtual FloatRect* getHitBox();
	virtual FloatRect* getDrawLocation();

	void addAnimation(Animation * a, std::string name);
	void changeAnimation(std::string name);
	void jumpToFrame(unsigned int index);

protected:
	Animation * currentAnimation;
	std::map<std::string, Animation *> animations;
	sf::FloatRect hitbox;
};

