#include "RogueRoll.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"
#include "Timemanager.h"
#include "Entity.h"

enum direction { NA, EST, WEST };

RogueRoll::RogueRoll(Entity* e) : ActionEntity(e)
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
	chainItemUp = false;
	chainItemDown = false;
	chainItemFront = false;
	chainItemStand = false;
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

	if (timeRemaining < 0.2 && !parent->isAirborne && (chainAttack || chainItemDown || chainItemUp))
	{
		parent->gravityMult = 1;
		parent->isFacingLeft = !parent->isFacingLeft;
		if (chainAttack)
			return (int)PlayerAction::BASICATTACK;
		else if (chainItemUp)
			return (int)PlayerAction::ITEMUP;
		else
			return (int)PlayerAction::ITEMDOWN;
	}

	if (timeRemaining < 0)
	{
		parent->gravityMult = 1;
		parent->isFacingLeft = !parent->isFacingLeft;

		if (chainAttack)
			return (int)PlayerAction::BASICATTACK;
		if (chainItemUp)
			return (int)PlayerAction::ITEMUP;
		if (chainItemDown)
			return (int)PlayerAction::ITEMDOWN;
		if (parent->isAirborne)
			return (int)PlayerAction::FALL;
		if (InputManager::GetKeyState(DOWN))
			return (int)PlayerAction::CROUNCH;

		bool right = InputManager::GetKeyState(Keys::RIGHT);
		bool left = InputManager::GetKeyState(Keys::LEFT);

		if (right != left)
		{
			if (right)
				parent->isFacingLeft = false;
			else
				parent->isFacingLeft = true;
		}
		return (int)PlayerAction::STAND;
	}
	return -1;
}