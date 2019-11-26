#pragma once
#include "ActionEntity.h"
class RogueCrounch :
	public ActionEntity
{
public:
	RogueCrounch(Entity* e, float forceAction = 0.0f);
	~RogueCrounch();
	int update();
private:
	float forceAction;
};
