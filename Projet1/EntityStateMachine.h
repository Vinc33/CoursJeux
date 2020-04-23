#pragma once
#include "EntityBase.h"
class Action;

class EntityStateMachine : public virtual EntityBase
{
public:
	EntityStateMachine();
	~EntityStateMachine();

	virtual void update();
	virtual void changeAction(int enumIndex) = 0;

protected:
	Action* currentAction;
};