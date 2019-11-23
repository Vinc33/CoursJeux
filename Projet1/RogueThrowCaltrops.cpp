#include "RogueThrowCaltrops.h"
#include "Caltrops.h"
#include "Entity.h"

RogueThrowCaltrops::RogueThrowCaltrops(Entity * e) : RogueItemUse(e, .05f)
{
	if (parent->imageReversed)
	{
		parent->accelerate(-.5f);
		parent->Spawn(new Caltrops(-300 + (parent->velX) * .9f), 120, 48);
		parent->Spawn(new Caltrops(-328 + (parent->velX) * .9f), 120, 48);
		parent->Spawn(new Caltrops(-350 + (parent->velX) * .9f), 120, 48);
	}
	else
	{
		parent->accelerate(.5f);
		parent->Spawn(new Caltrops(200 + (parent->velX) * .9f), 84, 48);
		parent->Spawn(new Caltrops(228 + (parent->velX) * .9f), 84, 48);
		parent->Spawn(new Caltrops(250 + (parent->velX) * .9f), 84, 48);
	}
}


RogueThrowCaltrops::~RogueThrowCaltrops()
{
}
