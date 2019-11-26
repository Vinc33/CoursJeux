#include "RogueThrowKnife.h"
#include "Entity.h"
#include "ThrownKnife.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"

RogueThrowKnife::RogueThrowKnife(Entity* e) : RogueItemUse(e, .1f)
{
	if (parent->imageReversed)
	{
		parent->accelerate(-.5f);
		parent->Spawn(new ThrownKnife(-1500), 60, 78);
	}
	else
	{
		parent->accelerate(.5f);
		parent->Spawn(new ThrownKnife(1500), 144, 78);
	}
}


RogueThrowKnife::~RogueThrowKnife()
{
	
}

int RogueThrowKnife::update()
{
	return RogueItemUse::update();
}
