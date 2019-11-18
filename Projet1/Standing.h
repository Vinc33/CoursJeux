#pragma once
#include "ActionEntity.h"
class Standing :
	public ActionEntity
{
public:
	Standing(Entity* e);
	~Standing();
	int Update();
};

