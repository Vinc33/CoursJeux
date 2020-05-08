#include "RogueThrowKnife.h"
#include "Hero.h"
#include "ThrownKnife.h"
#include "HeroActionsEnum.h"

RogueThrowKnife::RogueThrowKnife(Hero* e) : RogueItemUse(e, .1f)
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
