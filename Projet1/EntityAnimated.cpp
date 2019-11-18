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
	Sprite* s = animator.GetSprite(isFacingLeft);
	target.draw(*s, position.getTransform());
}
