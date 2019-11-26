#include "EntityBrain.h"
#include "Action.h"



EntityBrain::EntityBrain()
{
	currentAction = new Action(this);
}


EntityBrain::~EntityBrain()
{

}

void EntityBrain::update()
{
	int i = currentAction->update();
	if (i != -1)
		this->changeAction(i);
}
