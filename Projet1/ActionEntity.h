#pragma once
#include "Action.h"
class Entity;

class ActionEntity :
	public Action
{
public:
	ActionEntity(Entity* e);
	~ActionEntity();

protected:
	Entity* parent;
};

