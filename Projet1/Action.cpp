#include "Action.h"
#include "Entity.h"
#include "EntityStateMachine.h"

Action::Action(EntityStateMachine* e)
{
	stateMachine = e;
}

Action::~Action()
{

}


int Action::update()
{
	return -1;
}
