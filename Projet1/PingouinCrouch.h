#pragma once
#include "Action.h"
class PingouinCrouch :
	public Action
{
public:
	PingouinCrouch(Entity* e, float forceAction = 0.0f);
	~PingouinCrouch();
	int Update();
private:
	float forceAction;
};
