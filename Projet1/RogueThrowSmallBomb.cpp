#include "RogueThrowSmallBomb.h"
#include "Entity.h"
#include "HandBomb.h"
#include "TimeManager.h"
#include "InputManager.h"



RogueThrowSmallBomb::RogueThrowSmallBomb(Entity* e) : RogueItemUse(e, .15f)
{
	if (parent->imageReversed)
	{
		parent->accelerate(-.5f);
		parent->Spawn(new HandBomb(-475 + (int)(parent->velX / 2)), 88, 50);
	}
	else
	{
		parent->accelerate(.5f);
		parent->Spawn(new HandBomb(475 + (int)(parent->velX / 2)), 146, 50);
	}
}


RogueThrowSmallBomb::~RogueThrowSmallBomb()
{
}
