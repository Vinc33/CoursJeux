#include "EntityAnimated.h"
#include <fstream>
#include <iostream>
#include <map>


EntityAnimated::EntityAnimated()
{
	imageReversed = false;
}

EntityAnimated::~EntityAnimated()
{
	std::map<std::string, Animation*>::iterator it;
	for (it = animations.begin(); it != animations.end(); it++)
		delete it->second;
}

void EntityAnimated::addAnimation(Animation* a, std::string name)
{
	animations.insert(make_pair(name, a));
	if (size(animations) == 1)
		currentAnimation = animations[name];
}

void EntityAnimated::changeAnimation(std::string name)
{
	currentAnimation->restart();
	currentAnimation = animations[name];
	currentAnimation->reversed = imageReversed;
}

void EntityAnimated::update()
{
	currentAnimation->update();
	currentAnimation->reversed = imageReversed;
	currentAnimation->updateHitbox();

	hitbox = currentAnimation->GetSprite()->getGlobalBounds();
	hitbox.left = getPosition().x;
	hitbox.top = getPosition().y;
}

void EntityAnimated::draw(sf::RenderTarget& target)
{
	target.draw(*currentAnimation->GetSprite(), getTransform());
}

void EntityAnimated::drawHitBox(sf::RenderTarget& target)
{
	RectangleShape rs({ getHitBox()->width, getHitBox()->height });
	rs.setFillColor(Color(10, 100, 0, 100));
	rs.setPosition({ getHitBox()->left - currentAnimation->GetSprite()->getOrigin().x * 2, getHitBox()->top - currentAnimation->GetSprite()->getOrigin().y * 2 });
	target.draw(rs);
}

FloatRect* EntityAnimated::getHitBox()
{
	return &hitbox;
}

FloatRect* EntityAnimated::getDrawLocation()
{
	//TODO
	return nullptr;
}

void EntityAnimated::jumpToFrame(unsigned int index)
{
	currentAnimation->JumpToFrame(index);
}