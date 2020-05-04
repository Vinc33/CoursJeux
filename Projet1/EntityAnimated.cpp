#include "EntityAnimated.h"
#include <fstream>
#include <iostream>
#include <map>


EntityAnimated::EntityAnimated()
{
	imageReversed = false;
	sprite = new Sprite();
}

EntityAnimated::~EntityAnimated()
{
	std::map<std::string, Animation*>::iterator it;
	for (it = animations.begin(); it != animations.end(); it++)
		delete it->second;
	delete sprite;
}

void EntityAnimated::addAnimation(Animation* a, std::string name)
{
	a->init(sprite);
	animations.insert(make_pair(name, a));
	if (size(animations) == 1)
		currentAnimation = animations[name];
}

void EntityAnimated::changeAnimation(std::string name)
{
	currentAnimation->restart();
	currentAnimation = animations[name];
	currentAnimation->reversed = imageReversed;

	//currentAnimation->GetSprite().
}

void EntityAnimated::update()
{
	currentAnimation->update();
	currentAnimation->reversed = imageReversed;
	currentAnimation->updateHitbox();

	hitbox = sprite->getLocalBounds();
}

void EntityAnimated::draw(sf::RenderTarget& target)
{
	target.draw(*sprite);
}

void EntityAnimated::drawHitBox(sf::RenderTarget& target)
{
	RectangleShape rs({ getHitBox()->width, getHitBox()->height });
	rs.setFillColor(Color(10, 100, 0, 100));
	rs.setOrigin(getOrigin());
	rs.setPosition(getPosition());
	rs.setRotation(getRotation());
	rs.setScale(sprite->getScale());
	target.draw(rs);
}

void EntityAnimated::jumpToFrame(unsigned int index)
{
	currentAnimation->jumpToFrame(index);
}


FloatRect* EntityAnimated::getHitBox()
{
	return &hitbox;
}

Transform EntityAnimated::getTransform()
{
	return sprite->getTransform();
}

Vector2f EntityAnimated::getOrigin()
{
	return sprite->getOrigin();
}

void EntityAnimated::setOrigin(Vector2f origin)
{
	sprite->setOrigin(origin);
}

Vector2f EntityAnimated::getPosition()
{
	return sprite->getPosition();
}

void EntityAnimated::setPosition(Vector2f origin)
{
	return sprite->setPosition(origin);
}

void EntityAnimated::setPosition(float x, float y)
{
	return sprite->setPosition(x, y);
}

void EntityAnimated::move(float x, float y)
{
	sprite->move(x, y);
}

float EntityAnimated::getRotation()
{
	return sprite->getRotation();
}

void EntityAnimated::setRotation(float angle)
{
	return sprite->setRotation(angle);
}

void EntityAnimated::rotate(float angle)
{
	return sprite->rotate(angle);
}