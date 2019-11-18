#include "MonkJump.h"
#include "HeroActionsEnum.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Entity.h"
#include "Settings.h"

MonkJump::MonkJump(Entity* e, bool canRoundhouse, bool canPunch, bool canDropkick, bool canDoubleJump) : ActionEntity(e)
{
	parent->gravityMult = 1;
	doubleJumpReady = false;
	parent->jump();

	this->canPunch = canPunch;
	this->canDropkick = canDropkick;
	this->canDoubleJump = canDoubleJump;
	this->canRoundhouse = canRoundhouse;
}

MonkJump::~MonkJump()
{

}

int MonkJump::Update()
{

	bool right = InputManager::GetKeyState(Keys::RIGHT);
	bool left = InputManager::GetKeyState(Keys::LEFT);
	bool down = InputManager::GetKeyState(Keys::DOWN);
	bool up = InputManager::GetKeyState(Keys::UP);
	bool jump = InputManager::GetKeyState(Keys::A);
	bool attack = InputManager::GetKeyState(Keys::X);

	if (!parent->isAirborne)
	{
		parent->gravityMult = 1;
		if (down)
			return (int)PlayerAction::CROUNCH;
		if (right || left)
			return (int)PlayerAction::WALK;
		return ((int)PlayerAction::STAND);
	}

	if (attack)
	{
		parent->gravityMult = 1;
		if (up && canRoundhouse)	
			return (int)PlayerAction::ROUNDHOUSE;
		if (down && canDropkick) 
			return (int)PlayerAction::DIVEKICK;
		if (canPunch)
			return (int)PlayerAction::BASICATTACK;
	}

	if (jump)
	{
		parent->gravityMult = 1;
		if (canDoubleJump && doubleJumpReady)
			return (int)PlayerAction::SECONDJUMP;
	}
	else
	{
		parent->gravityMult = 2;
		doubleJumpReady = true;
	}

	if (right && !left)
	{
		parent->accelerate(0.5);
	}
	else if (left && !right)
	{
		parent->accelerate(-0.5);
	}

	return -1;
}