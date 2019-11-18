#include "MonkFall.h"



MonkFall::MonkFall(Entity* e, bool canRoundhouse, bool canPunch, bool canDropkick, bool canDoubleJump, bool doubleJumpReady) : ActionEntity(e)
{
	parent->gravityMult = 1;
	this->canDoubleJump = canDoubleJump;
	this->canDropkick = canDropkick;
	this->canPunch = canPunch;
	this->canRoundhouse = canRoundhouse;
	this->doubleJumpReady = doubleJumpReady;
}


MonkFall::~MonkFall()
{

}

int MonkFall::Update()
{
	bool right = InputManager::GetKeyState(Keys::RIGHT);
	bool left = InputManager::GetKeyState(Keys::LEFT);
	bool down = InputManager::GetKeyState(Keys::DOWN);
	bool up = InputManager::GetKeyState(Keys::UP);
	bool jump = InputManager::GetKeyState(Keys::A);
	bool attack = InputManager::GetKeyState(Keys::X);

	if (!parent->isAirborne)
	{
		if (down)
			return (int)PlayerAction::CROUNCH;

		if (right || left)
			return (int)PlayerAction::WALK;
		return ((int)PlayerAction::STAND);
	}

	if (jump)
	{
		if (canDoubleJump && doubleJumpReady)
			return (int)PlayerAction::SECONDJUMP;
	}
	else
	{
		doubleJumpReady = true;
	}

	if (attack)
	{
		if (up && canRoundhouse)	return (int)PlayerAction::ROUNDHOUSE;
		if (down && canDropkick) return (int)PlayerAction::DIVEKICK;
		if (canPunch) return (int)PlayerAction::BASICATTACK;
	}

	if (!jump)

		if (right && !left)
			parent->accelerate(0.75);
		else if (left && !right)
			parent->accelerate(-0.75);

	return -1;
}
