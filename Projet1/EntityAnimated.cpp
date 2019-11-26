#include "EntityAnimated.h"



EntityAnimated::EntityAnimated()
{
}


EntityAnimated::~EntityAnimated()
{

}

void EntityAnimated::draw(sf::RenderTarget& target)
{
	animator.update();
	sf::Sprite* s = animator.GetSprite(imageReversed);
	target.draw(*s, getTransform());
}

Vector2f EntityAnimated::getDrawSize()
{
	return {(float) animator.GetSprite()->getTextureRect().width, (float)animator.GetSprite()->getTextureRect().height };
}
