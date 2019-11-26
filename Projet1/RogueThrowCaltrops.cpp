#include "RogueThrowCaltrops.h"
#include "Caltrops.h"
#include "Entity.h"

RogueThrowCaltrops::RogueThrowCaltrops(Entity * e) : RogueItemUse(e, .05f)
{
	if (parent->imageReversed)
	{
		parent->accelerate(-.5f);
		parent->Spawn(new Caltrops(-200 + (parent->velX) * .9f), 88, 90);
		parent->Spawn(new Caltrops(-226 + (parent->velX) * .9f), 88, 90);
		parent->Spawn(new Caltrops(-250 + (parent->velX) * .9f), 88, 90);
	}
	else
	{
		parent->accelerate(.5f);
		parent->Spawn(new Caltrops(200 + (parent->velX) * .9f), 146, 90);
		parent->Spawn(new Caltrops(226 + (parent->velX) * .9f), 146, 90);
		parent->Spawn(new Caltrops(250 + (parent->velX) * .9f), 146, 90);
	}
}

RogueThrowCaltrops::~RogueThrowCaltrops()
{
}
