#include "MonkDiveKick.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"
#include "TimeManager.h"
#include "Entity.h"
#include "Settings.h"


MonkDiveKick::MonkDiveKick(Entity* e) : Action(e)
{
	parent->gravityMult = 1;
	bool right = InputManager::GetKeyState(Keys::RIGHT);
	bool left = InputManager::GetKeyState(Keys::LEFT);
	if (right)
		parent->isFacingLeft = false;
	else if (left)
		parent->isFacingLeft = true;
	parent->isAirborne = true;
	countDown = 0.350f;
}


MonkDiveKick::~MonkDiveKick()
{
}

int MonkDiveKick::Update()
{
	//parent->velY = .0f - parent->gravity;

	//if (countDown = )
	if (parent->isFacingLeft)
		parent->velX = (-1300.0f * countDown - parent->maxVelX * 1.8f) ;
	else
		parent->velX = (1300.0f * countDown + parent->maxVelX * 1.8f) ;

	countDown -= TimeManager::DeltaTime;

	bool right = InputManager::GetKeyState(Keys::RIGHT);
	bool left = InputManager::GetKeyState(Keys::LEFT);
	bool down = InputManager::GetKeyState(Keys::DOWN);

	if (!parent->isAirborne)
	{
		if (parent->velX > parent->maxVelX * 2.0f)
			parent->velX = parent->maxVelX * 2.0f;

		if (down)
			return (int)PlayerAction::CROUNCH;

		if (right || left)
			return (int)PlayerAction::WALK;
		return ((int)PlayerAction::STAND);
	}

	if (countDown < 0)
	{
		if (!InputManager::GetKeyState(Keys::X) || abs(parent->velX) <= 1.4 * parent->maxVelX)
		{
			if (parent->isAirborne)
				return (int)PlayerAction::FALL;
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
	}
	return -1;
}
