#include "RogueThrowSpear.h"
#include "Entity.h"
#include "Spear.h"


RogueThrowSpear::RogueThrowSpear(Entity* e) : RogueItemUse(e, .3f)
{
	if (parent->imageReversed)
	{
		parent->accelerate(-.7f);
		parent->Spawn(new Spear(-1000 + (parent->velX / 3)), 155, 70);
	}
	else
	{
		parent->accelerate(-.7f);
		parent->Spawn(new Spear(1000 + (parent->velX / 3)), 100, 70);
	}
}


RogueThrowSpear::~RogueThrowSpear()
{
}
