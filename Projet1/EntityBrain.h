#pragma once
#include "Animator.h"
#include "EntityBase.h"
class Action;

class EntityBrain : public virtual EntityBase
{
public:
	EntityBrain();
	~EntityBrain();

	virtual void Update();
	virtual void ChangeAction(int enumIndex) = 0;

protected:
	Action* CurrentAction;
};