#include "RogueRoll.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"
#include "Timemanager.h"
#include "Entity.h"


RogueRoll::RogueRoll(Entity* e) : Action(e)
{
	bool right = InputManager::GetKeyState(Keys::RIGHT);
	bool left = InputManager::GetKeyState(Keys::LEFT);
	if (right)
		parent->isFacingLeft = false;
	else if (left)
		parent->isFacingLeft = true;
	parent->isAirborne = true;
	timeRemaining = 0.80f;
	jumpAtHalf = false;
	releasedJump = false;

	parent->gravityMult = 1.1f;
	chainAttack = false;
}

RogueRoll::~RogueRoll()
{
}

int RogueRoll::Update()
{
	timeRemaining -= TimeManager::DeltaTime;

	if (parent->isFacingLeft)
		parent->accelerate(-1.8f);
	else
		parent->accelerate(1.8f);


	if (timeRemaining > .25f)
	{
		if (!InputManager::GetKeyState(A))
			jumpAtHalf = false;
		else
			jumpAtHalf = true;
	}
	else
	{
		if (jumpAtHalf)
		{
			if (!parent->isAirborne)
				parent->jump();
			jumpAtHalf = false;
		}
	}

	if (timeRemaining < 0.7 && InputManager::GetKeyState(X))
		chainAttack = true;

	if (timeRemaining < 0.2 && chainAttack)
	{
		parent->gravityMult = 1;
		parent->isFacingLeft = !parent->isFacingLeft;
		return (int)PlayerAction::BASICATTACK;
	}

	if (timeRemaining < 0)
	{
		parent->gravityMult = 1;
		parent->isFacingLeft = !parent->isFacingLeft;

		if (parent->isAirborne)
		{
			return (int)PlayerAction::FALL;
		}
		else
		{
			if (InputManager::GetKeyState(DOWN))
				return (int)PlayerAction::CROUNCH;
			if (InputManager::GetKeyState(Keys::RIGHT))
				parent->isFacingLeft = false;
			if (InputManager::GetKeyState(Keys::LEFT))
				parent->isFacingLeft = true;
			return (int)PlayerAction::STAND;
		}
	}
	return -1;
}