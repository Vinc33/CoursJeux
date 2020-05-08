#include "RogueItemUse.h"
#include "Hero.h"
#include "TimeManager.h"
#include "HeroActionsEnum.h"


RogueItemUse::RogueItemUse(Hero* e, float timer) : HeroAction(e)
{
	this->timer = timer;
}


RogueItemUse::~RogueItemUse()
{
}

int RogueItemUse::update()
{
	timer -= TimeManager::DeltaTime;
	if (timer < 0)
	{
		if (parent->isAirborne)
			return (int)PlayerAction::FALL;

		if (parent->getKeyState(KEYDOWN))
			return (int)PlayerAction::CROUNCH;

		if (parent->getKeyState(KEYRIGHT) != parent->getKeyState(KEYLEFT))
			return (int)PlayerAction::WALK;

		return ((int)PlayerAction::STAND);
	}
	return -1;
}
