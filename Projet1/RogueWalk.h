#pragma once
#include "ActionEntity.h"
class RogueWalk :
	public ActionEntity
{
public:
	RogueWalk(Entity* e);
	~RogueWalk();
	int Update();
};

