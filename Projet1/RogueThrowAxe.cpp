#include "RogueThrowAxe.h"
#include "Entity.h"
#include "ThrownAxe.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"


RogueThrowAxe::RogueThrowAxe(Entity* e) : RogueItemUse(e, .35f)
{
	if (parent->imageReversed)
	{
		parent->accelerate(-.5f);
		parent->Spawn(new ThrownAxe(-575 + (int)(parent->velX / 2 )), 116, 35);
	}
	else
	{
		parent->accelerate(.5f);
		parent->Spawn(new ThrownAxe(575 + (int)(parent->velX / 2 )), 66, 35);
	}
}


RogueThrowAxe::~RogueThrowAxe()
{

}

int RogueThrowAxe::update()
{
	return RogueItemUse::update();
}