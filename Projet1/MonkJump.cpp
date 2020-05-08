#include "MonkJump.h"
#include "HeroActionsEnum.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Hero.h"
#include "Settings.h"

MonkJump::MonkJump(Hero* e, bool canRoundhouse, bool canPunch, bool canDropkick, bool canJump) : HeroAction(e)
{
	parent->gravityMult = 1;

	this->canPunch = canPunch;
	this->canDropkick = canDropkick;
	this->canJump = canJump;
	this->canRoundhouse = canRoundhouse;
}

MonkJump::~MonkJump()
{

}

int MonkJump::update()
{

	bool right = parent->getKeyState(KEYRIGHT);
	bool left = parent->getKeyState(KEYLEFT);
	bool down = parent->getKeyState(KEYDOWN);

	if (!parent->isAirborne)
	{
		parent->gravityMult = 1;
		if (down)
			return (int)PlayerAction::CROUNCH;
		if (right || left)
			return (int)PlayerAction::WALK;
		return ((int)PlayerAction::STAND);
	}

	if (parent->getKeyState(KEYATTACK))
	{
		parent->gravityMult = 1;
		if (parent->getKeyState(KEYUP) && canRoundhouse)	
			return (int)PlayerAction::ROUNDHOUSE;
		if (down && canDropkick) 
			return (int)PlayerAction::DIVEKICK;
		if (canPunch)
			return (int)PlayerAction::BASICATTACK;
	}

	if (parent->getKeyState(KEYJUMP))
	{
		parent->gravityMult = 1;
		if (canJump && doubleJumpReady)
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