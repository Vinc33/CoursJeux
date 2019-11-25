#include "RogueJump.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"
#include "Entity.h"
#include "TimeManager.h"

RogueJump::RogueJump(Entity* e, bool jump, bool canRoll) : ActionEntity(e)
{
	if (jump)
	{
		parent->isAirborne = true;
		parent->velY = 0;
		parent->jump();
	}
	parent->gravityMult = 1;
	this->canRoll = canRoll;
}

RogueJump::~RogueJump()
{

}

int RogueJump::update()
{
	bool right = InputManager::GetKeyState(Keys::RIGHT);
	bool left = InputManager::GetKeyState(Keys::LEFT);
	bool jump = InputManager::GetKeyState(Keys::A);

	if (jump)
	{
		parent->gravityMult = 1;
		lastJumpInputTimer = .0f;
	}
	else
	{
		parent->gravityMult = 1.5f;
		lastJumpInputTimer += TimeManager::DeltaTime;
		if (lastJumpInputTimer < .26f)
			chainJump = true;
		else
			chainJump = false;
	}

	if (!parent->isAirborne)
	{
		parent->gravityMult = 1;
		if (chainJump)
			return (int)PlayerAction::CHAINEDJUMP;

		if (InputManager::GetKeyState(Keys::DOWN))
			return (int)PlayerAction::CROUNCH;

		if (right || left)
			return (int)PlayerAction::WALK;
		return ((int)PlayerAction::STAND);
	}

	if (right && !left)
		parent->accelerate(0.5f);
	else if (left && !right)
		parent->accelerate(-0.5f);

	if (InputManager::GetKeyState(UP) && parent->velY < -parent->jumpingStrength * 0.8f)
		return(int)PlayerAction::SOMERSAULT;

	if (InputManager::GetKeyState(B))
	{
		if (canUseItem)
		{
			parent->gravityMult = 1;
			if (InputManager::GetKeyState(Keys::DOWN))
				return (int)PlayerAction::ITEMDOWN;
			if (InputManager::GetKeyState(Keys::UP))
				return (int)PlayerAction::ITEMUP;
			if (right != left)
				return (int)PlayerAction::ITEMFRONT;
			return (int)PlayerAction::ITEMSTAND;
		}
	}
	else
	{
		canUseItem = true;
	}

	if (InputManager::GetKeyState(X))
	{
		if (canAttack)
			return (int)PlayerAction::BASICATTACK;
	}
	else
	{
		canAttack = true;
	}

	if (InputManager::GetKeyState(Keys::DOWN) && jump && canRoll)
	{
		parent->gravityMult = 1;
		return(int)PlayerAction::ROLL;
	}

	return -1;
}
