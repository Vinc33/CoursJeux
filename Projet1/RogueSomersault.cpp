#include "RogueSomersault.h"
#include "HeroActionsEnum.h"
#include "Timemanager.h"
#include "Hero.h"
#include <cmath>

enum direction { NA, EST, WEST };

RogueSomersault::RogueSomersault(Hero* e) : HeroAction(e)
{
	bool right = parent->getKeyState(KEYRIGHT);
	bool left = parent->getKeyState(KEYLEFT);
	if (right)
		parent->imageReversed = false;
	else if (left)
		parent->imageReversed = true;

	timeRemaining = 1.0f;
	chainAttack = false;
	parent->velY = 0;
	if (parent->isAirborne)
		parent->jump(1.2f);
	else
		parent->jump(1.3f);
	parent->isAirborne = true;
}

RogueSomersault::~RogueSomersault()
{

}

int RogueSomersault::update()
{
	timeRemaining -= TimeManager::DeltaTime;

	if (parent->velX > parent->maxVelX * 0.4f || -parent->velX > parent->maxVelX * 0.4f)
		parent->velX /= 1 + abs(parent->velX / 100) * TimeManager::DeltaTime;

	bool left = parent->getKeyState(KEYLEFT);
	bool right = parent->getKeyState(KEYRIGHT);

	if (timeRemaining < 0.7f)
	{
		if (parent->getKeyState(KEYSKILL1))
		{
			if (left != right)
			{
				if (left)
					chainDirection = direction::WEST;
				else
					chainDirection = direction::EST;
			}
			else
			{
				chainDirection = direction::NA;
			}

			if (parent->getKeyState(KEYDOWN))
			{
				chainItemStand = false;
				chainItemFront = false;
				chainItemDown = true;
				chainItemUp = false;
			}
			else if (parent->getKeyState(KEYUP))
			{
				chainItemStand = false;
				chainItemFront = false;
				chainItemDown = false;
				chainItemUp = true;
			}
			else if (left != right)
			{
				chainItemStand = false;
				chainItemFront = true;
				chainItemDown = false;
				chainItemUp = false;
			}
			else
			{
				chainItemStand = true;
				chainItemFront = false;
				chainItemDown = false;
				chainItemUp = false;
			}
		}

		if (parent->getKeyState(KEYATTACK))
			chainAttack = true;
	}

	if (timeRemaining > .45f)
	{
		if (right && !left)
			parent->accelerate(0.5f * (1 - timeRemaining));
		else if (left && !right)
			parent->accelerate(-0.5f * (1 - timeRemaining));

		if (parent->imageReversed)
			parent->accelerate(-1.8f * (1 - timeRemaining));
		else
			parent->accelerate(1.8f * (1 - timeRemaining));
	}


	if (timeRemaining < 0.35f)
	{
		parent->gravityMult = 1;
		switch (chainDirection)
		{
		case direction::EST:
			parent->imageReversed = false;
			break;

		case direction::WEST:
			parent->imageReversed = true;
			break;
		}

		if (chainItemUp)
		{
			parent->imageReversed = !parent->imageReversed;
			return (int)PlayerAction::ITEMUP;
		}
		if (chainItemDown)
		{
			parent->imageReversed = !parent->imageReversed;
			return (int)PlayerAction::ITEMDOWN;
		}
		if (chainItemFront)
		{
			parent->imageReversed = !parent->imageReversed;
			return (int)PlayerAction::ITEMFRONT;
		}
		if (chainItemStand)
		{
			parent->imageReversed = !parent->imageReversed;
			return (int)PlayerAction::ITEMSTAND;
		}
		if (chainAttack)
		{
			parent->imageReversed = !parent->imageReversed;
			return (int)PlayerAction::BASICATTACK;
		}

	}

	if (!parent->isAirborne)
	{
		parent->imageReversed = !parent->imageReversed;
		if (parent->getKeyState(KEYDOWN))
			return (int)PlayerAction::CROUNCH;

		if (right != left)
		{
			if (right)
				parent->accelerate(3);
			else
				parent->accelerate(-3);

			return (int)PlayerAction::WALK;
		}
		return ((int)PlayerAction::STAND);
	}

	if (timeRemaining < 0)
	{
		return (int)PlayerAction::FALL;
	}
	return -1;
}
