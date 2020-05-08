#include "MonkRisingKick.h"
#include "HeroActionsEnum.h"
#include "TimeManager.h"
#include "Hero.h"

MonkRisingKick::MonkRisingKick(Hero* e) : HeroAction(e)
{
	bool right = parent->getKeyState(KEYRIGHT);
	bool left = parent->getKeyState(KEYLEFT);
	if (right != left)
	{
		if (right)
			parent->imageReversed = false;
		else
			parent->imageReversed = true;
	}
	parent->isAirborne = true;
	timeRemaining = 0.350f;

	parent->velY = -75.0f;
}

MonkRisingKick::~MonkRisingKick()
{

}

int MonkRisingKick::update()
{
	timeRemaining -= TimeManager::DeltaTime;
	parent->velY = -75.0f;
	if (parent->imageReversed)
		parent->velX = -750.0f * timeRemaining - 100;
	else
		parent->velX = 750.0f * timeRemaining + 100;

	bool right = parent->getKeyState(KEYRIGHT);
	bool left = parent->getKeyState(KEYLEFT);
	bool down = parent->getKeyState(KEYDOWN);

	if (!parent->isAirborne)
	{
		parent->gravityMult = 1;

		if (down)
			return (int)PlayerAction::CROUNCH;

		if (right != left)
			return (int)PlayerAction::WALK;
		return ((int)PlayerAction::STAND);
	}

	if (timeRemaining < 0)
	{
		if (parent->isAirborne)
		{
			if (parent->getKeyState(KEYJUMP))
				return (int)PlayerAction::SECONDJUMP;
			else
				return (int)PlayerAction::FALL;
		}

		if (down)
			return (int)PlayerAction::CROUNCH;
		if (right != left)
			return (int)PlayerAction::WALK;
		return ((int)PlayerAction::STAND);
	}

	return -1;
}
