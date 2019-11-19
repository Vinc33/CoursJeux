#include "EntityAnimated.h"



EntityAnimated::EntityAnimated()
{
}


EntityAnimated::~EntityAnimated()
{

}

void EntityAnimated::Draw(sf::RenderTarget& target)
{
	animator.Update();
	sf::Sprite* s = animator.GetSprite(isFacingLeft);
	target.draw(*s, position.getTransform());
}
