#include "Falling.h"
#include "Entity.h"
#include "HeroActionsEnum.h"
#include "InputManager.h"

Falling::Falling(Entity* e) : ActionEntity(e)
{

}


Falling::~Falling()
{
}

int Falling::Update()
{
	bool left = InputManager::GetKeyState(LEFT);
	bool right = InputManager::GetKeyState(RIGHT);

	if (right && !left)
		parent->accelerate(0.5);
	else if (left && !right)
		parent->accelerate(-0.5);

	if (!parent->isAirborne)
	{
		if (InputManager::GetKeyState(DOWN))
			return (int)PlayerAction::CROUNCH;
		if (left != right)
			return (int)PlayerAction::WALK;
		return (int)PlayerAction::STAND;
	}
	return -1;
}