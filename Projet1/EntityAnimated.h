#pragma once
#include "Animator.h"
#include "EntityBase.h"

class EntityAnimated : public virtual EntityBase
{
public:
	EntityAnimated();
	~EntityAnimated();

	virtual void draw(sf::RenderTarget& target);

	bool imageReversed;

protected:
	Animator animator;
};

