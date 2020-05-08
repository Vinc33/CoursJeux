#include "RogueStanding.h"
#include "HeroActionsEnum.h"
#include "Hero.h"
#include "Settings.h"



RogueStanding::RogueStanding(Hero* e) : HeroAction(e)
{
	if (!parent->getKeyState(KEYJUMP))
		jumpReady = true;
}


RogueStanding::~RogueStanding()
{
}

int RogueStanding::update()
{
	bool right = parent->getKeyState(KEYRIGHT);
	bool left = parent->getKeyState(KEYLEFT);

	if (right != left)
	{
		if (right)
			parent->accelerate(1);
		else
			parent->accelerate(-1);
	}

	if (parent->getKeyState(KEYSKILL1))
	{
		if (parent->getKeyState(KEYUP))
			return (int)PlayerAction::ITEMUP;
		if (parent->getKeyState(KEYDOWN))
			return (int)PlayerAction::ITEMDOWN;
		if (right != left)
			return (int)PlayerAction::ITEMFRONT;
		return (int)PlayerAction::ITEMSTAND;
	}

	if (parent->getKeyState(KEYATTACK))
		return (int)PlayerAction::BASICATTACK;

	if (parent->getKeyState(KEYJUMP))
	{
		if (jumpReady)
		{
			if (parent->getKeyState(KEYUP))
				return (int)PlayerAction::SOMERSAULT;
			else
				return (int)PlayerAction::JUMP;
		}
	}
	else
	{
		jumpReady = true;
	}

	if (right != left)
	{
		if (right)
		{
			if (parent->velX >= 50)
				return (int)PlayerAction::WALK;
		}
		else
		{
			if (parent->velX <= -50)
				return (int)PlayerAction::WALK;
		}
	}

	if (parent->getKeyState(KEYDOWN))
		return (int)PlayerAction::CROUNCH;

	return -1;
}