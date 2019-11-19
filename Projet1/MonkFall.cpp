#include "MonkFall.h"



MonkFall::MonkFall(Entity* e, bool canRoundhouse, bool canPunch, bool canDropkick, bool canJump) : ActionEntity(e)
{
	parent->gravityMult = 1;
	this->canDropkick = canDropkick;
	this->canPunch = canPunch;
	this->canRoundhouse = canRoundhouse;
	this->canJump = canJump;
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
	bool attack = InputManager::GetKeyState(Keys::X);

	if (!parent->isAirborne)
	{
		if (down)
			return (int)PlayerAction::CROUNCH;

		if (right != left)
			return (int)PlayerAction::WALK;
		return ((int)PlayerAction::STAND);
	}

	if (right != left)
	{
		if (right)
			parent->accelerate(0.75);
		else
			parent->accelerate(-0.75);
	}

	if (InputManager::GetKeyState(Keys::A) && canJump)
		return (int)PlayerAction::SECONDJUMP;

	if (attack)
	{
		if (up && canRoundhouse)
			return (int)PlayerAction::ROUNDHOUSE;
		if (down && canDropkick)
		{
			return (int)PlayerAction::DIVEKICK;
		}
		if (canPunch)
			return (int)PlayerAction::BASICATTACK;
	}


	return -1;
}
