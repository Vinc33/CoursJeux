#include "HunterShoot.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"
#include "Timemanager.h"
#include "Entity.h"


HunterShoot::HunterShoot(Entity* e) : ActionEntity(e)
{
	timeRemaining = .4f;
}


HunterShoot::~HunterShoot()
{
}

int HunterShoot::update()
{
	timeRemaining -= TimeManager::DeltaTime;
	if (timeRemaining < 0)
	{
		bool right = InputManager::GetKeyState(Keys::RIGHT);
		bool left = InputManager::GetKeyState(Keys::LEFT);
		bool down = InputManager::GetKeyState(Keys::DOWN);

		if (down)
			return (int)PlayerAction::CROUNCH;

		if (right || left)
			return (int)PlayerAction::WALK;
		return ((int)PlayerAction::STAND);
	}
	return -1;
}
