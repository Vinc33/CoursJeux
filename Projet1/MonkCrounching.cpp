#include "MonkCrounching.h"
#include "HeroActionsEnum.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Entity.h"


MonkCrounching::MonkCrounching(Entity* e, float forceAction) : ActionEntity(e)
{
	this->forceAction = forceAction;
	forceActionCounter = 0;
	bool left = InputManager::GetKeyState(LEFT);
	bool right = InputManager::GetKeyState(RIGHT);
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
	if (forceActionCounter < 100 && InputManager::GetKeyState(UP) && InputManager::GetKeyState(A))
		return (int)PlayerAction::SECONDJUMP;
	if (InputManager::GetKeyState(X) && forceAction < forceActionCounter)
		return (int)PlayerAction::CROUNCHATTACK;
	if (!InputManager::GetKeyState(DOWN) && forceAction < forceActionCounter)
		return (int)PlayerAction::STAND;
	return -1;
}
