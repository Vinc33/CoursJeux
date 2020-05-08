#include "MonkSecondJump.h"
#include "HeroActionsEnum.h"
#include "Hero.h"

MonkSecondJump::MonkSecondJump(Hero* e, bool canRoundhouse, bool canPunch, bool canDropkick) : HeroAction(e)
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
	bool right = parent->getKeyState(KEYRIGHT);
	bool left = parent->getKeyState(KEYLEFT);
	bool down = parent->getKeyState(KEYDOWN);
	bool up = parent->getKeyState(KEYUP);
	bool attack = parent->getKeyState(KEYATTACK);

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

