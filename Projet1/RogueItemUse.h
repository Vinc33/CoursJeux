#pragma once
#include "ActionEntity.h"
class RogueItemUse :
	public ActionEntity
{
public:
	RogueItemUse(Entity* e, float timer);
	~RogueItemUse();

	int update();
protected:
	float timer;
};

