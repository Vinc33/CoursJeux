#include "RogueThrowSawBlade.h"
#include "Hero.h"
#include "SawBlade.h"



RogueThrowSawBlade::RogueThrowSawBlade(Hero* e) : RogueItemUse(e, .4f)
{
	if (parent->imageReversed)
	{
		parent->accelerate(-.5f);
		parent->Spawn(new SawBlade(-575 + (int)(parent->velX / 2)), 116, 35);
	}
	else
	{
		parent->accelerate(.5f);
		parent->Spawn(new SawBlade(575 + (int)(parent->velX / 2)), 66, 35);
	}
}


RogueThrowSawBlade::~RogueThrowSawBlade()
{
}
