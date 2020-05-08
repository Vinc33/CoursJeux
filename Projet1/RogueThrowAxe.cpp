#include "RogueThrowAxe.h"
#include "Hero.h"
#include "ThrownAxe.h"
#include "HeroActionsEnum.h"


RogueThrowAxe::RogueThrowAxe(Hero* e) : RogueItemUse(e, .35f)
{
	if (parent->imageReversed)
	{
		parent->accelerate(-.5f);
		parent->Spawn(new ThrownAxe(-260 + (int)(parent->velX / 2 )), 20, 35);
	}
	else
	{
		parent->accelerate(.5f);
		parent->Spawn(new ThrownAxe(260 + (int)(parent->velX / 2 )), -20, 35);
	}
}


RogueThrowAxe::~RogueThrowAxe()
{

}

int RogueThrowAxe::update()
{
	return RogueItemUse::update();
}