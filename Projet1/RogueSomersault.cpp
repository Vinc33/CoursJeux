#include "RogueSomersault.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"
#include "Timemanager.h"
#include "Entity.h"
#include <cmath>


RogueSomersault::RogueSomersault(Entity* e) : ActionEntity(e)
{
	bool right = InputManager::GetKeyState(Keys::RIGHT);
	bool left = InputManager::GetKeyState(Keys::LEFT);
	if (right)
		parent->isFacingLeft = false;
	else if (left)
		parent->isFacingLeft = true;

	timeRemaining = 1.0f;
	chainAttack = false;
	parent->velY = 0;
	if (parent->isAirborne)
		parent->jump(1.2f);
	else
		parent->jump(1.3f);
	parent->isAirborne = true;
}

RogueSomersault::~RogueSomersault()
{

}

int RogueSomersault::Update()
{
	timeRemaining -= TimeManager::DeltaTime;

	if (parent->velX > parent->maxVelX * 0.4f || -parent->velX > parent->maxVelX * 0.4f)
		parent->velX /= 1 + abs(parent->velX / 100) * TimeManager::DeltaTime;

	if (timeRemaining < 0.7f && InputManager::GetKeyState(X))
	{
		if (InputManager::GetKeyState(DOWN))
		{
			chainItemDown = true;
			chainItemUp = false;
			chainAttack = false;
		}
		else if (InputManager::GetKeyState(UP))
		{
			chainItemDown = false;
			chainItemUp = true;
			chainAttack = false;
		}
		else
		{
			chainItemDown = false;
			chainItemUp = false;
			chainAttack = true;
		}
	}

	if (timeRemaining > .45f)
	{
		bool left = InputManager::GetKeyState(LEFT);
		bool right = InputManager::GetKeyState(RIGHT);

		if (right && !left)
			parent->accelerate(0.5f * (1 - timeRemaining));
		else if (left && !right)
			parent->accelerate(-0.5f * (1 - timeRemaining));

		if (parent->isFacingLeft)
			parent->accelerate(-1.8f * (1 - timeRemaining));
		else
			parent->accelerate(1.8f * (1 - timeRemaining));
	}


	if (timeRemaining < 0.35f && (chainAttack || chainItemDown || chainItemUp))
	{
		parent->gravityMult = 1;
		parent->isFacingLeft = !parent->isFacingLeft;
		bool right = InputManager::GetKeyState(Keys::RIGHT);
		bool left = InputManager::GetKeyState(Keys::LEFT);

		if (chainItemUp)
		{
			if (right != left)
			{
				if (right)
					parent->isFacingLeft = false;
				else
					parent->isFacingLeft = true;
			}
			return (int)PlayerAction::ITEMUP;
		}
		if (chainItemDown)
		{
			if (right != left)
			{
				if (right)
					parent->isFacingLeft = false;
				else
					parent->isFacingLeft = true;
			}
			return (int)PlayerAction::ITEMDOWN;
		}

		return (int)PlayerAction::BASICATTACK;
	}

	if (!parent->isAirborne)
	{
		parent->isFacingLeft = !parent->isFacingLeft;
		if (InputManager::GetKeyState(DOWN))
			return (int)PlayerAction::CROUNCH;

		bool right = InputManager::GetKeyState(RIGHT);
		bool left = InputManager::GetKeyState(LEFT);

		if (right != left)
		{
			if (right)
				parent->accelerate(3);
			else
				parent->accelerate(-3);

			return (int)PlayerAction::WALK;
		}
		return ((int)PlayerAction::STAND);
	}

	if (timeRemaining < 0)
	{
		return (int)PlayerAction::FALL;
	}
	return -1;
}
