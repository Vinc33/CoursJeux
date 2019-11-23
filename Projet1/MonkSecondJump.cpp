#include "MonkSecondJump.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"
#include "Entity.h"

MonkSecondJump::MonkSecondJump(Entity* e, bool canRoundhouse, bool canPunch, bool canDropkick) : ActionEntity(e)
{
	parent->gravityMult = 1.5;
	parent->isAirborne = true;
	parent->velY = 0;
	parent->jump();
	this->canRoundhouse = canRoundhouse;
	this->canPunch = canPunch;
	this->canDropkick = canDropkick;
}

MonkSecondJump::~MonkSecondJump()
{

}

int MonkSecondJump::update()
{
	bool right = InputManager::GetKeyState(Keys::RIGHT);
	bool left = InputManager::GetKeyState(Keys::LEFT);
	bool down = InputManager::GetKeyState(Keys::DOWN);
	bool up = InputManager::GetKeyState(Keys::UP);
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
		if (up && canRoundhouse)	
			return (int)PlayerAction::ROUNDHOUSE;
		if (down && canDropkick) 
			return (int)PlayerAction::DIVEKICK;
		if (canPunch) 
			return (int)PlayerAction::BASICATTACK;

	}

	if (right && !left)
		parent->accelerate(0.75);
	else if (left && !right)
		parent->accelerate(-0.75);

	return -1;
}

