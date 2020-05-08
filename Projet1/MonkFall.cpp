#include "MonkFall.h"
#include "Hero.h"


MonkFall::MonkFall(Hero* e, bool canRoundhouse, bool canPunch, bool canDropkick, bool canJump) : HeroAction(e)
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

int MonkFall::update()
{
	bool right = parent->getKeyState(KEYRIGHT);
	bool left = parent->getKeyState(KEYLEFT);
	bool down = parent->getKeyState(KEYDOWN);
	bool up = parent->getKeyState(KEYUP);
	bool attack = parent->getKeyState(KEYATTACK);

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

	if (parent->getKeyState(KEYJUMP) && canJump)
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
