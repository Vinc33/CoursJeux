#pragma once
#include "ActionEntity.h"
class MonkCrounching :
	public ActionEntity
{
public:
	MonkCrounching(Entity* e, float forceAction);
	~MonkCrounching();
	int update();
private:
	float forceAction;
	float forceActionCounter;
};

