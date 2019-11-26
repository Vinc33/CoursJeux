#include "ActionEntity.h"
#include "EntityBrain.h"


ActionEntity::ActionEntity(Entity* e) : Action((EntityBrain*)e)
{
	parent = e;
}


ActionEntity::~ActionEntity()
{

}
