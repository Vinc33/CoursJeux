#include "PingouinCrouch.h"
#include "HeroActionsEnum.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Entity.h"


PingouinCrouch::PingouinCrouch(Entity* e, float forceAction) : Action(e)
{
	this->forceAction = forceAction;
}

PingouinCrouch::~PingouinCrouch()
{
}

int PingouinCrouch::Update()
{
	bool down = InputManager::GetKeyState(DOWN);
	bool jump = InputManager::GetKeyState(A);
	forceAction -= TimeManager::DeltaTime;
	if (InputManager::GetKeyState(X) && forceAction < 0)
		return (int)PlayerAction::CROUNCHATTACK;
	if (!down && forceAction < 0)
		return (int)PlayerAction::STAND;
	if (jump)
		return (int)PlayerAction::ROLL;
	return -1;
}
