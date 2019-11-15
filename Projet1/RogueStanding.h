#pragma once
#include "ActionEntity.h"
class RogueStanding :
	public ActionEntity
{
public:
	RogueStanding(Entity* e);
	~RogueStanding();
	int Update();
};

