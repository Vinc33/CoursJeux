#include "RogueJump.h"
#include "HeroActionsEnum.h"
#include "Hero.h"
#include "TimeManager.h"

RogueJump::RogueJump(Hero* e, bool jump, bool canRoll) : HeroAction(e)
{
	if (jump)
	{
		parent->isAirborne = true;
		parent->velY = 0;
		parent->jump();
	}
	parent->gravityMult = 1;
	this->canRoll = canRoll;
	lastJumpInputTimer = 1;
}

RogueJump::~RogueJump()
{

}

int RogueJump::update()
{
	bool right = parent->getKeyState(KEYRIGHT);
	bool left = parent->getKeyState(KEYLEFT);
	bool jump = parent->getKeyState(KEYJUMP);

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

		if (parent->getKeyState(KEYDOWN))
			return (int)PlayerAction::CROUNCH;

		if (right != left)
			return (int)PlayerAction::WALK;
		return ((int)PlayerAction::STAND);
	}

	if (right && !left)
		parent->accelerate(0.5f);
	else if (left && !right)
		parent->accelerate(-0.5f);

	if (parent->getKeyState(KEYUP) && parent->velY < -parent->jumpingStrength * 0.8f)
		return(int)PlayerAction::SOMERSAULT;

	if (parent->getKeyState(KEYSKILL1))
	{
		if (canUseItem)
		{
			parent->gravityMult = 1;
			if (parent->getKeyState(KEYDOWN))
				return (int)PlayerAction::ITEMDOWN;
			if (parent->getKeyState(KEYUP))
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

	if (parent->getKeyState(KEYATTACK))
	{
		if (canAttack)
			return (int)PlayerAction::BASICATTACK;
	}
	else
	{
		canAttack = true;
	}

	if (parent->getKeyState(KEYDOWN) && jump && canRoll)
	{
		parent->gravityMult = 1;
		return(int)PlayerAction::ROLL;
	}

	return -1;
}
