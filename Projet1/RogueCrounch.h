#pragma once
#include "HeroAction.h"
class RogueCrounch :
	public HeroAction
{
public:
	RogueCrounch(Hero* e, float forceAction = 0.0f);
	~RogueCrounch();
	int update();
private:
	float forceAction;
};
