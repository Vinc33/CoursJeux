#pragma once
#include "ActionEntity.h"
class MonkCrounching :
	public ActionEntity
{
public:
	MonkCrounching(Entity* e, float forceAction);
	~MonkCrounching();
	int Update();
private:
	float forceAction;
	float forceActionCounter;
};

