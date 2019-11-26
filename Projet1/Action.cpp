#include "Action.h"
#include "Entity.h"
#include "EntityBrain.h"

Action::Action(EntityBrain* e)
{
	p = e;
}

Action::~Action()
{

}


int Action::update()
{
	return -1;
}
