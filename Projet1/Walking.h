#pragma once
#include "ActionEntity.h"
class Walking :
	public ActionEntity
{
public:
	Walking(Entity* e);
	~Walking();
	int Update();
private:
	float turnCharacter;
};

