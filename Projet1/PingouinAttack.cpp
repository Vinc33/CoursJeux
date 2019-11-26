#include "PingouinAttack.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"
#include "Entity.h"

PingouinAttack::PingouinAttack(Entity* e) : Action(e)
{
	timeRemaining = 0.35f;
}


PingouinAttack::~PingouinAttack()
{

}

int PingouinAttack::Update()
{
	bool left = InputManager::GetKeyState(LEFT);
	bool right = InputManager::GetKeyState(RIGHT);

	if (right && !left)
		parent->accelerate(-0.5);
	else if (left && !right)
		parent->accelerate(0.5);

	timeRemaining -= TimeManager::DeltaTime;
	if (timeRemaining < 0)
	{
		bool down = InputManager::GetKeyState(DOWN);

		if (down)
			return (int)PlayerAction::CROUNCH;
		if ((left && !right) || (right && !left))
			return (int)PlayerAction::WALK;
		return (int)PlayerAction::STAND;
	}

	return -1;
}