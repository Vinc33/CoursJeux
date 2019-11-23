#include "Standing.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"
#include "Entity.h"
#include "Settings.h"

Standing::Standing(Entity* e) : ActionEntity(e)
{

}


Standing::~Standing()
{

}

int Standing::update()
{
	bool right = InputManager::GetKeyState(Keys::RIGHT);
	bool left = InputManager::GetKeyState(Keys::LEFT);
	bool down = InputManager::GetKeyState(Keys::DOWN);
	bool up = InputManager::GetKeyState(Keys::UP);
	bool jump = InputManager::GetKeyState(Keys::A);
	bool attack = InputManager::GetKeyState(Keys::X);

	if (jump)
		return (int)PlayerAction::JUMP;
	else if (down)
		return (int)PlayerAction::CROUNCH;
	else if (attack)
	{
		if (up)
			return (int)PlayerAction::NOJUMPROUNDHOUSE;
		return (int)PlayerAction::BASICATTACK;

	}

	if (right && !left )
	{
		parent->accelerate(1);
		if (parent->velX >= 50)
			return (int)PlayerAction::WALK;
	}
	else if (left && !right)
	{
		parent->accelerate(-1);
		if (parent->velX <= -50)
			return (int)PlayerAction::WALK;
	}
	
	return -1;
}
