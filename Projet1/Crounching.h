#pragma once
#include "ActionEntity.h"
class Crounching :
	public ActionEntity
{
public:
	Crounching(Entity* e, float forceAction = 0.0f);
	~Crounching();
	int Update();
private:
	float forceAction;
};

