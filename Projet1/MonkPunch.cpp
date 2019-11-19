#include "MonkPunch.h"
#include "HeroActionsEnum.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Entity.h"



MonkPunch::MonkPunch(Entity* e, bool canJump) : ActionEntity(e)
{
	timeRemaining = 0.375f;
}

MonkPunch::~MonkPunch()
{
	
}

int MonkPunch::Update()
{
	if (parent->isAirborne)
	{
		parent->velY = 2 * parent->acc * TimeManager::DeltaTime * TimeManager::DeltaTime;
	}
	timeRemaining -= TimeManager::DeltaTime;
	if (timeRemaining < .4f && timeRemaining > .3f)
	{
		parent->velY = 0;
		if (parent->isFacingLeft)
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
		bool right = InputManager::GetKeyState(Keys::RIGHT);
		bool left = InputManager::GetKeyState(Keys::LEFT);
		bool down = InputManager::GetKeyState(Keys::DOWN);
		bool holdingJump = InputManager::GetKeyState(Keys::A);

		if (down)
			return (int)PlayerAction::CROUNCH;
		if (right || left)
			return (int)PlayerAction::WALK;
		return ((int)PlayerAction::STAND);
	}
	return -1;
}
