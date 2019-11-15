#pragma once
#include "Animator.h"
#include "Action.h"
#include "EntityBase.h"

class EntityBrain
{
public:
	EntityBrain();
	~EntityBrain();

	void Update();

	virtual void ChangeAction(int enumIndex) = 0;

protected:
	Action* CurrentAction;
};