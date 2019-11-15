#pragma once
#include "ActionEntity.h"
class Falling :
	public ActionEntity
{
public:
	Falling(Entity* e);
	~Falling();
	int Update();
};

