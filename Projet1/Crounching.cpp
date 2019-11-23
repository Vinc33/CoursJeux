#include "Crounching.h"
#include "HeroActionsEnum.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Entity.h"


Crounching::Crounching(Entity* e, float forceAction) : ActionEntity(e)
{
	this->forceAction = forceAction;
	bool left = InputManager::GetKeyState(LEFT);
	bool right = InputManager::GetKeyState(RIGHT);
	if (left && !right)
		parent->imageReversed = true;
	else if (!left && right)
		parent->imageReversed = false;
}

Crounching::~Crounching()
{

}

int Crounching::update()
{
	forceAction -= TimeManager::DeltaTime;
	if (InputManager::GetKeyState(X) && forceAction < 0)
		return (int)PlayerAction::CROUNCHATTACK;
	if (!InputManager::GetKeyState(DOWN) && forceAction < 0)
		return (int)PlayerAction::STAND;
	return -1;
}
