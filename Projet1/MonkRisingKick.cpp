#include "MonkRisingKick.h"
#include "HeroActionsEnum.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Entity.h"
#include "Settings.h"

MonkRisingKick::MonkRisingKick(Entity* e) : ActionEntity(e)
{
	bool right = InputManager::GetKeyState(Keys::RIGHT);
	bool left = InputManager::GetKeyState(Keys::LEFT);
	if (right != left)
	{
		if (right)
			parent->isFacingLeft = false;
		else
			parent->isFacingLeft = true;
	}
	parent->isAirborne = true;
	timeRemaining = 0.350f;

	parent->velY = -150.0f;
}

MonkRisingKick::~MonkRisingKick()
{

}

int MonkRisingKick::Update()
{
	timeRemaining -= TimeManager::DeltaTime;
	parent->velY = -150.0f;
	if (parent->isFacingLeft)
		parent->velX = -1500.0f * timeRemaining - 200;
	else
		parent->velX = 1500.0f * timeRemaining + 200;

	bool right = InputManager::GetKeyState(Keys::RIGHT);
	bool left = InputManager::GetKeyState(Keys::LEFT);
	bool down = InputManager::GetKeyState(Keys::DOWN);

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
			if (InputManager::GetKeyState(Keys::A))
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
