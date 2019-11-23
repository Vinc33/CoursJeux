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
	target.draw(*s, position.getTransform());
}
