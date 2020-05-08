#include "RogueAttack.h"
#include "TimeManager.h"
#include "HeroActionsEnum.h"
#include "Hero.h"

RogueAttack::RogueAttack(Hero* e) : HeroAction(e)
{
	timeRemaining = 0.35f;
	if (parent->velY > 0)
	{
		parent->gravityMult = 0.7f;
		parent->velY /= 2;
	}

	if (parent->imageReversed)
		parent->accelerate(-.7f);
	else
		parent->accelerate(.7f);
}


RogueAttack::~RogueAttack()
{

}

int RogueAttack::update()
{
	bool left = parent->getKeyState(KEYLEFT);
	bool right = parent->getKeyState(KEYRIGHT);


	if (right && !left)
		parent->accelerate(0.4f);
	else if (left && !right)
		parent->accelerate(-0.4f);

	timeRemaining -= TimeManager::DeltaTime;
	if (timeRemaining < 0)
	{
		parent->gravityMult = 1;
		if (parent->isAirborne)
			return (int)PlayerAction::FALLMAYROLL;
		bool down = parent->getKeyState(KEYDOWN);

		if (down)
			return (int)PlayerAction::CROUNCH;
		if ((left && !right) || (right && !left))
			return (int)PlayerAction::WALK;
		return (int)PlayerAction::STAND;
	}

	return -1;
}