#include "RogueThrowSmallBomb.h"
#include "Entity.h"
#include "HandBomb.h"
#include "TimeManager.h"
#include "InputManager.h"



RogueThrowSmallBomb::RogueThrowSmallBomb(Hero* e) : RogueItemUse(e, .15f)
{
	if (parent->imageReversed)
	{
		parent->accelerate(-.5f);
		parent->Spawn(new HandBomb(parent, -475.0f + (int)(parent->velX / 2)), 88, 50);
	}
	else
	{
		parent->accelerate(.5f);
		parent->Spawn(new HandBomb(parent, 475.0f + (int)(parent->velX / 2)), 146, 50);
	}
}


RogueThrowSmallBomb::~RogueThrowSmallBomb()
{
}
