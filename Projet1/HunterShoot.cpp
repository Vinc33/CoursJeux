#include "HunterShoot.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"
#include "Timemanager.h"


HunterShoot::HunterShoot(Hero* e) : HeroAction(e)
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
		bool right = parent->getKeyState(KEYRIGHT);
		bool left = parent->getKeyState(KEYLEFT);
		bool down = parent->getKeyState(KEYDOWN);

		if (down)
			return (int)PlayerAction::CROUNCH;

		if (right || left)
			return (int)PlayerAction::WALK;
		return ((int)PlayerAction::STAND);
	}
	return -1;
}
