#include "RogueThrowCaltrops.h"
#include "Caltrops.h"
#include "Hero.h"

RogueThrowCaltrops::RogueThrowCaltrops(Hero * e) : RogueItemUse(e, .05f)
{
	if (parent->imageReversed)
	{
		parent->accelerate(-.5f);
		parent->Spawn(new Caltrops(-120 + (parent->velX) * .9f), -10, 10);
		parent->Spawn(new Caltrops(-133 + (parent->velX) * .9f), -10, 10);
		parent->Spawn(new Caltrops(-155 + (parent->velX) * .9f), -10, 10);
	}
	else
	{
		parent->accelerate(.5f);
		parent->Spawn(new Caltrops(120 + (parent->velX) * .9f), 10, 10);
		parent->Spawn(new Caltrops(133 + (parent->velX) * .9f), 10, 10);
		parent->Spawn(new Caltrops(155 + (parent->velX) * .9f), 10, 10);
	}
}

RogueThrowCaltrops::~RogueThrowCaltrops()
{
}
