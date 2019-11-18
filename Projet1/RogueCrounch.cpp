#include "RogueCrounch.h"
#include "HeroActionsEnum.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Entity.h"


RogueCrounch::RogueCrounch(Entity* e, float forceAction) : ActionEntity(e)
{
	this->forceAction = forceAction;
}

RogueCrounch::~RogueCrounch()
{
}

int RogueCrounch::Update()
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
