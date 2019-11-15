#pragma once
#include "ActionEntity.h"
class Jumping : 
	public ActionEntity
{
public:
	Jumping(Entity* e, bool canDoubleJump = false);
	~Jumping();

	int Update();
private:
	bool canDoubleJump;
	bool doubleJumpReady;
};

