#include "EntityStateMachine.h"
#include "Action.h"


EntityStateMachine::EntityStateMachine()
{
	currentAction = new Action(this);
}


EntityStateMachine::~EntityStateMachine()
{
	
}

void EntityStateMachine::update()
{
	int i = currentAction->update();
	if (i != -1)
		this->changeAction(i);
}