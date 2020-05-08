#include "RogueWalk.h"
#include "HeroActionsEnum.h"
#include "Timemanager.h"
#include "Hero.h"


RogueWalk::RogueWalk(Hero* e) : HeroAction(e)
{
	bool right = parent->getKeyState(KEYRIGHT);
	bool left = parent->getKeyState(KEYLEFT);
	if (right != left)
	{
		if (right)
			parent->imageReversed = false;
		else
			parent->imageReversed = true;
	}

	if (!parent->getKeyState(KEYJUMP))
		jumpReady = true;

	if (!parent->getKeyState(KEYATTACK))
		attackReady = true;

	if (!parent->getKeyState(KEYSKILL1))
		itemReady = true;
	else
		itemReady = false;
}


RogueWalk::~RogueWalk()
{
}

int RogueWalk::update()
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
		if (itemReady)
		{
			if (parent->getKeyState(KEYUP))
				return (int)PlayerAction::ITEMUP;
			if (parent->getKeyState(KEYDOWN))
				return (int)PlayerAction::ITEMDOWN;
			if (right != left)
				return (int)PlayerAction::ITEMFRONT;
			return (int)PlayerAction::ITEMSTAND;
		}
	}
	else
	{
		itemReady = true;
	}

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

	if (parent->getKeyState(KEYATTACK))
	{
		if (attackReady)
			return (int)PlayerAction::BASICATTACK;
	}
	else
	{
		attackReady = true;
	}

	if (parent->getKeyState(KEYDOWN))
	{
		if (right != left)
			return (int)PlayerAction::ROLL;
		return (int)PlayerAction::CROUNCH;
	}
	if (left == right)
		return (int)PlayerAction::STAND;
	if ((!parent->imageReversed && left) || (parent->imageReversed && right))
		return (int)PlayerAction::WALK;
	return -1;
}
