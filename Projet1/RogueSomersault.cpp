#include "RogueSomersault.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"
#include "Timemanager.h"
#include "Entity.h"
#include <cmath>

enum direction { NA, EST, WEST };

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

	bool left = InputManager::GetKeyState(LEFT);
	bool right = InputManager::GetKeyState(RIGHT);

	if (timeRemaining < 0.7f)
	{
		if (InputManager::GetKeyState(B))
		{
			if (left != right)
			{
				if (left)
					chainDirection = direction::WEST;
				else
					chainDirection = direction::EST;
			}
			else
			{
				chainDirection = direction::NA;
			}

			if (InputManager::GetKeyState(DOWN))
			{
				chainItemStand = false;
				chainItemFront = false;
				chainItemDown = true;
				chainItemUp = false;
			}
			else if (InputManager::GetKeyState(UP))
			{
				chainItemStand = false;
				chainItemFront = false;
				chainItemDown = false;
				chainItemUp = true;
			}
			else if (left != right)
			{
				chainItemStand = false;
				chainItemFront = true;
				chainItemDown = false;
				chainItemUp = false;
			}
			else
			{
				chainItemStand = true;
				chainItemFront = false;
				chainItemDown = false;
				chainItemUp = false;
			}
		}

		if (InputManager::GetKeyState(X))
			chainAttack = true;
	}

	if (timeRemaining > .45f)
	{
		if (right && !left)
			parent->accelerate(0.5f * (1 - timeRemaining));
		else if (left && !right)
			parent->accelerate(-0.5f * (1 - timeRemaining));

		if (parent->isFacingLeft)
			parent->accelerate(-1.8f * (1 - timeRemaining));
		else
			parent->accelerate(1.8f * (1 - timeRemaining));
	}


	if (timeRemaining < 0.35f)
	{
		parent->gravityMult = 1;
		switch (chainDirection)
		{
		case direction::EST:
			parent->isFacingLeft = false;
			break;

		case direction::WEST:
			parent->isFacingLeft = true;
			break;
		}

		if (chainItemUp)
		{
			parent->isFacingLeft = !parent->isFacingLeft;
			return (int)PlayerAction::ITEMUP;
		}
		if (chainItemDown)
		{
			parent->isFacingLeft = !parent->isFacingLeft;
			return (int)PlayerAction::ITEMDOWN;
		}
		if (chainItemFront)
		{
			parent->isFacingLeft = !parent->isFacingLeft;
			return (int)PlayerAction::ITEMFRONT;
		}
		if (chainItemStand)
		{
			parent->isFacingLeft = !parent->isFacingLeft;
			return (int)PlayerAction::ITEMSTAND;
		}
		if (chainAttack)
		{
			parent->isFacingLeft = !parent->isFacingLeft;
			return (int)PlayerAction::BASICATTACK;
		}

	}

	if (!parent->isAirborne)
	{
		parent->isFacingLeft = !parent->isFacingLeft;
		if (InputManager::GetKeyState(DOWN))
			return (int)PlayerAction::CROUNCH;

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
