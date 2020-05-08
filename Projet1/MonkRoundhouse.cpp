#include "MonkRoundhouse.h"
#include "HeroActionsEnum.h"
#include "TimeManager.h"
#include "Hero.h"


MonkRoundhouse::MonkRoundhouse(Hero* e, bool asDoubleJump, bool canPunch, bool canDropkick, bool canJump) : HeroAction(e)
{
	bool left = parent->getKeyState(KEYLEFT);
	bool right = parent->getKeyState(KEYRIGHT);
	if (left && !right)
		parent->imageReversed = true;
	else if (!left && right)
		parent->imageReversed = false;

	if (asDoubleJump)
	{
		parent->gravityMult = 1.5;
		parent->velY = 0;
		parent->jump();
		if (parent->imageReversed)
			parent->velX = (float)-parent->maxVelX*1.2f;
		else
			parent->velX = (float)parent->maxVelX*1.2f;
	}
	timeRemaining = 0.5f;

	this->canPunch = canPunch;
	this->canDropkick = canDropkick;
	this->canJump = canJump;
}

MonkRoundhouse::~MonkRoundhouse()
{

}

int MonkRoundhouse::update()
{
	timeRemaining -= TimeManager::DeltaTime;
	bool right = parent->getKeyState(KEYRIGHT);
	bool left = parent->getKeyState(KEYLEFT);
	bool down = parent->getKeyState(KEYDOWN);
	bool attack = parent->getKeyState(KEYATTACK);
	bool jump = parent->getKeyState(KEYJUMP);

	if (right && !left)
		parent->accelerate(0.75);
	else if (left && !right)
		parent->accelerate(-0.75);

	if (attack)
	{
		if (canChainAttack)
		{
			if (down && canDropkick)
				chainKick = true;
			else if (canPunch)
				chainPunch = true;
		}
	}
	else
	{
		canChainAttack = true;
	}

	if (timeRemaining < .3) 
	{
		if (chainPunch && !chainKick)
		{
			return (int)PlayerAction::BASICATTACK;
		}
		if (chainKick)
		{
			parent->velY = 100;
			return(int)PlayerAction::DIVEKICK;
		}
	}

	if (timeRemaining < 0 && timeRemaining < .2)
	{
		parent->gravityMult = 1;

		if (parent->isAirborne)
		{
			if (canJump && jump)
				return (int)PlayerAction::SECONDJUMP;
			return (int)PlayerAction::FALL;
		}
		if (down) return (int)PlayerAction::CROUNCH;
		if (right != left) return (int)PlayerAction::WALK;
		return ((int)PlayerAction::STAND);
	}

	return -1;
}
