#include "ActionEntity.h"
#include "EntityStateMachine.h"


ActionEntity::ActionEntity(Entity* e) : Action((EntityStateMachine*)e)
{
	parent = e;
}


ActionEntity::~ActionEntity()
{

}
