#include "RogueCrounch.h"
#include "HeroActionsEnum.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Hero.h"


RogueCrounch::RogueCrounch(Hero* e, float forceAction) : HeroAction(e)
{
	this->forceAction = forceAction;
}

RogueCrounch::~RogueCrounch()
{
}

int RogueCrounch::update()
{
	forceAction -= TimeManager::DeltaTime;
	if (parent->getKeyState(KEYJUMP))
		return (int)PlayerAction::ROLL;
	if (forceAction < 0)
	{
		bool down = parent->getKeyState(KEYDOWN);
		if (parent->getKeyState(KEYATTACK))
			return (int)PlayerAction::BASICATTACK;

		if (parent->getKeyState(KEYSKILL1))
		{
			if (parent->getKeyState(KEYUP))
				return (int)PlayerAction::ITEMUP;
			if (down)
				return (int)PlayerAction::ITEMDOWN;

			if (parent->getKeyState(KEYLEFT) != parent->getKeyState(KEYRIGHT))
				return (int)PlayerAction::ITEMFRONT;
			return (int)PlayerAction::ITEMSTAND;
		}

		if (!down)
			return (int)PlayerAction::STAND;
	}
	return -1;
}
