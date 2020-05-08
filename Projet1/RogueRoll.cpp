#include "RogueRoll.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"
#include "Timemanager.h"
#include "Hero.h"

enum direction { NA, EST, WEST };

RogueRoll::RogueRoll(Hero* e) : HeroAction(e)
{
	if (parent->getKeyState(KEYRIGHT))
		parent->imageReversed = false;
	else if (parent->getKeyState(KEYLEFT))
		parent->imageReversed = true;
	parent->isAirborne = true;
	parent->gravityMult = 1.1f;

	timeRemaining = 0.80f;

	chainDirection = NA;
	jumpAtHalf = false;
	releasedJump = false;
	chainAttack = false;
	chainItemUp = false;
	chainItemDown = false;
	chainItemFront = false;
	chainItemStand = false;

	if (!parent->getKeyState(KEYSKILL1))
		canChainItem = true;
	else
		canChainItem = false;

	if (!parent->getKeyState(KEYATTACK))
		canChainAttack = true;
	else
		canChainAttack = false;

}

RogueRoll::~RogueRoll()
{

}

int RogueRoll::update()
{
	timeRemaining -= TimeManager::DeltaTime;

	if (parent->imageReversed)
		parent->accelerate(-1.8f);
	else
		parent->accelerate(1.8f);


	if (timeRemaining > .25f)
	{
		if (!parent->getKeyState(KEYJUMP))
			jumpAtHalf = false;
		else
			jumpAtHalf = true;
	}
	else
	{
		if (jumpAtHalf)
		{
			if (!parent->isAirborne)
				parent->jump();
			jumpAtHalf = false;
		}
	}

	bool item = parent->getKeyState(KEYSKILL1);
	bool attack = parent->getKeyState(KEYATTACK);
	if (!item)
		canChainItem = true;
	if (!attack)
		canChainAttack = true;

	if (timeRemaining < 0.7)
	{
		if (item && canChainItem)
		{
			if (parent->imageReversed)
				chainDirection = direction::WEST;
			else
				chainDirection = direction::EST;

			bool right = parent->getKeyState(KEYRIGHT);
			bool left = parent->getKeyState(KEYLEFT);
			if (right != left)
			{
				if (right)
					chainDirection = direction::WEST;
				else
					chainDirection = direction::EST;
			}

			if (parent->getKeyState(KEYDOWN))
			{
				chainItemDown = true;
				chainItemUp = false;
				chainItemFront = false;
				chainItemStand = false;
			}
			else if (parent->getKeyState(KEYUP))
			{
				chainItemDown = false;
				chainItemUp = true;
				chainItemFront = false;
				chainItemStand = false;
			}
			else if (right != left)
			{
				chainItemDown = false;
				chainItemUp = false;
				chainItemFront = true;
				chainItemStand = false;
			}
			else
			{
				chainItemDown = false;
				chainItemUp = false;
				chainItemFront = false;
				chainItemStand = true;
			}
		}
		else if (canChainAttack && attack)
			chainAttack = true;
	}

	if (timeRemaining < 0.2 && !parent->isAirborne)
	{
		if (chainItemDown || chainItemUp || chainItemFront || chainItemStand)
		{
			parent->gravityMult = 1;

			if (chainDirection == direction::EST)
				parent->imageReversed = false;
			else if (chainDirection == direction::WEST)
				parent->imageReversed = true;
			else
				parent->imageReversed = !parent->imageReversed;

			if (chainItemUp)
				return (int)PlayerAction::ITEMUP;
			if (chainItemDown)
				return (int)PlayerAction::ITEMDOWN;
			if (chainItemFront)
				return (int)PlayerAction::ITEMFRONT;

			if (chainItemStand)
				return (int)PlayerAction::ITEMSTAND;
		}

		if (chainAttack)
		{
			parent->gravityMult = 1;
			parent->imageReversed = !parent->imageReversed;
			return (int)PlayerAction::BASICATTACK;
		}
	}

	if (timeRemaining < 0)
	{
		parent->gravityMult = 1;
		if (chainDirection == direction::EST)
			parent->imageReversed = false;
		else if (chainDirection == direction::WEST)
			parent->imageReversed = true;

		if (chainItemUp)
			return (int)PlayerAction::ITEMUP;
		if (chainItemDown)
			return (int)PlayerAction::ITEMDOWN;
		if (chainItemFront)
			return (int)PlayerAction::ITEMFRONT;

		parent->imageReversed = !parent->imageReversed;
		if (chainItemStand)
			return (int)PlayerAction::ITEMSTAND;

		if (chainAttack)
			return (int)PlayerAction::BASICATTACK;

		if (parent->isAirborne)
			return (int)PlayerAction::FALL;
		if (parent->getKeyState(KEYDOWN))
			return (int)PlayerAction::CROUNCH;

		bool right = parent->getKeyState(KEYRIGHT);
		bool left = parent->getKeyState(KEYLEFT);

		if (right != left)
		{
			if (right)
				parent->imageReversed = false;
			else
				parent->imageReversed = true;
		}
		return (int)PlayerAction::STAND;
	}
	return -1;
}