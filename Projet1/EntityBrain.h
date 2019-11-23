#pragma once
#include "Animator.h"
#include "EntityBase.h"
class Action;

class EntityBrain : public virtual EntityBase
{
public:
	EntityBrain();
	~EntityBrain();

	virtual void update();
	virtual void changeAction(int enumIndex) = 0;

protected:
	Action* currentAction;
};