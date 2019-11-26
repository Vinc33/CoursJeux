#pragma once
#include "EntityBase.h"

class EntitySpawner : public virtual EntityBase
{
public:
	EntitySpawner();
	~EntitySpawner();

	void Spawn(EntityBase* e, int offsetX, int offsetY);
};

