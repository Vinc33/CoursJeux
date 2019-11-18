#include "EntityBrain.h"



EntityBrain::EntityBrain()
{
	CurrentAction = new Action(this);
}


EntityBrain::~EntityBrain()
{

}

void EntityBrain::Update()
{
	int i = CurrentAction->Update();
	if (i != -1)
		this->ChangeAction(i);
}
