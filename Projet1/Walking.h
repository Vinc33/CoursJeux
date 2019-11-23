#pragma once
#include "ActionEntity.h"
class Walking :
	public ActionEntity
{
public:
	Walking(Entity* e);
	~Walking();
	int update();
private:
	float turnCharacter;
};

