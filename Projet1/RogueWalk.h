#pragma once
#include "ActionEntity.h"
class RogueWalk :
	public ActionEntity
{
public:
	RogueWalk(Entity* e);
	~RogueWalk();
	int update();
private:
	bool jumpReady;
	bool attackReady;
	bool itemReady;
};

