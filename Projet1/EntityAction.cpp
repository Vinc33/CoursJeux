#include "EntityAction.h"

EntityAction::EntityAction(Entity* e) : Action((EntityStateMachine*)e)
{
	parent = e;
}

EntityAction::~EntityAction()
{
}
