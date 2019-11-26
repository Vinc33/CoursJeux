#include "MonkWalking.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"
#include "Timemanager.h"
#include "Entity.h"


MonkWalking::MonkWalking(Entity* e) : ActionEntity(e)
{
	bool right = InputManager::GetKeyState(Keys::RIGHT);
	bool left = InputManager::GetKeyState(Keys::LEFT);
	if (right)
		parent->imageReversed = false;
	else if (left)
		parent->imageReversed = true;
}

MonkWalking::~MonkWalking()
{
}

int MonkWalking::update()
{
	bool right = InputManager::GetKeyState(Keys::RIGHT);
	bool left = InputManager::GetKeyState(Keys::LEFT);
	bool down = InputManager::GetKeyState(Keys::DOWN);
	bool up = InputManager::GetKeyState(Keys::UP);
	bool jump = InputManager::GetKeyState(Keys::A);
	bool attack = InputManager::GetKeyState(Keys::X);

	if (right && !left)
		parent->accelerate(1);
	else if (left && !right)
		parent->accelerate(-1);

	if (jump)
		return (int)PlayerAction::JUMP;
	if (down)
		return (int)PlayerAction::CROUNCH;
	if (attack)
	{
		if (up)
			return (int)PlayerAction::NOJUMPROUNDHOUSE;
		return (int)PlayerAction::BASICATTACK;
	}
	if (left == right || (parent->velX > 0 && left) || (parent->velX < 0 && right))
		return (int)PlayerAction::STAND;
	return -1;
}