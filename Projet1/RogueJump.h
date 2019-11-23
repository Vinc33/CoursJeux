#pragma once
#include "ActionEntity.h"
class RogueJump :
	public ActionEntity
{
public:
	RogueJump(Entity* e, bool jump = true, bool canRoll = true);
	~RogueJump();
	int update();
private:
	bool canRoll;
};

