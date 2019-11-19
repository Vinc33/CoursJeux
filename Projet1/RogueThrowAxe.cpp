#include "RogueThrowAxe.h"
#include "Entity.h"
#include "ThrownAxe.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"


RogueThrowAxe::RogueThrowAxe(Entity* e) : RogueItemUse(e, .35f)
{
	if (parent->isFacingLeft)
	{
		parent->accelerate(-.5f);
		parent->Spawn(new ThrownAxe(-575 + (int)(parent->velX / 2)), 120, 48);
	}
	else
	{
		parent->accelerate(.5f);
		parent->Spawn(new ThrownAxe(575 + (int)(parent->velX / 2)), 84, 48);
	}
}


RogueThrowAxe::~RogueThrowAxe()
{

}

int RogueThrowAxe::Update()
{
	return RogueItemUse::Update();
}