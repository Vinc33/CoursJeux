#pragma once
#include "Action.h"
class Entity;

class EntityAction :
	public Action
{
public:
	EntityAction(Entity* e);
	~EntityAction();

protected:
	Entity* parent;
};

