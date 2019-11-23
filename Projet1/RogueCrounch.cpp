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
	bool jump = InputManager::GetKeyState(A);
	bool down = InputManager::GetKeyState(DOWN);
	forceAction -= TimeManager::DeltaTime;
	if (jump)
		return (int)PlayerAction::ROLL;
	if (forceAction < 0)
	{
		if (InputManager::GetKeyState(X))
			return (int)PlayerAction::BASICATTACK;

		if (InputManager::GetKeyState(B))
		{
			if (InputManager::GetKeyState(UP))
				return (int)PlayerAction::ITEMUP;
			if (down)
				return (int)PlayerAction::ITEMDOWN;
			if (InputManager::GetKeyState(LEFT) && InputManager::GetKeyState(RIGHT))
				return (int)PlayerAction::ITEMFRONT;
			return (int)PlayerAction::ITEMSTAND;
		}

		if (!down && forceAction < 0)
			return (int)PlayerAction::STAND;
	}
	return -1;
}
