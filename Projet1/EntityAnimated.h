#pragma once
#include "Animator.h"
#include "EntityBase.h"

class EntityAnimated : public virtual EntityBase
{
public:
	EntityAnimated();
	~EntityAnimated();

	virtual void Draw(sf::RenderTarget& target);

	bool isFacingLeft;

protected:
	Animator animator;
};

