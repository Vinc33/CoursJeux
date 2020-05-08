#include "MonkCrounching.h"
#include "HeroActionsEnum.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Hero.h"


MonkCrounching::MonkCrounching(Hero* e, float forceAction) : HeroAction(e)
{
	this->forceAction = forceAction;
	forceActionCounter = 0;
	bool left = parent->getKeyState(KEYLEFT);
	bool right = parent->getKeyState(KEYRIGHT);
	if (left && !right)
		parent->imageReversed = true;
	else if (!left && right)
		parent->imageReversed = false;
}

MonkCrounching::~MonkCrounching()
{

}

int MonkCrounching::update()
{
	forceActionCounter += TimeManager::DeltaTime;
	if (forceActionCounter < 100 && parent->getKeyState(KEYUP) && parent->getKeyState(KEYJUMP))
		return (int)PlayerAction::SECONDJUMP;
	if (parent->getKeyState(KEYATTACK) && forceAction < forceActionCounter)
		return (int)PlayerAction::CROUNCHATTACK;
	if (!parent->getKeyState(KEYDOWN) && forceAction < forceActionCounter)
		return (int)PlayerAction::STAND;
	return -1;
}
