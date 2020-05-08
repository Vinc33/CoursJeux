#include "MonkPunch.h"
#include "HeroActionsEnum.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "hero.h"



MonkPunch::MonkPunch(Hero* e, bool canJump) : HeroAction(e)
{
	timeRemaining = 0.375f;
}

MonkPunch::~MonkPunch()
{
	
}

int MonkPunch::update()
{
	if (parent->isAirborne)
	{
		parent->velY = 2 * parent->acc * TimeManager::DeltaTime * TimeManager::DeltaTime;
	}
	timeRemaining -= TimeManager::DeltaTime;
	if (timeRemaining < .4f && timeRemaining > .3f)
	{
		parent->velY = 0;
		if (parent->imageReversed)
			parent->accelerate(-3);
		else
			parent->accelerate(3);
	}
	if (timeRemaining < 0)
	{
		if (parent->isAirborne)
		{
			parent->velY = 0;
			if (canJump)
				return (int)PlayerAction::SECONDJUMP;
			return (int)PlayerAction::FALL;
		}
		bool right = parent->getKeyState(KEYRIGHT);
		bool left = parent->getKeyState(KEYLEFT);
		bool down = parent->getKeyState(KEYDOWN);
		bool holdingJump = parent->getKeyState(KEYJUMP);

		if (down)
			return (int)PlayerAction::CROUNCH;
		if (right || left)
			return (int)PlayerAction::WALK;
		return ((int)PlayerAction::STAND);
	}
	return -1;
}
