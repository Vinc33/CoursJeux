#include "Walking.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"
#include "Timemanager.h"
#include "Entity.h"



Walking::Walking(Entity * e) : ActionEntity(e)
{
	bool right = InputManager::GetKeyState(Keys::RIGHT);
	bool left = InputManager::GetKeyState(Keys::LEFT);
	if (right)
		parent->imageReversed = false;
	else if (left)
		parent->imageReversed = true;
}


Walking::~Walking()
{

}

int Walking::update()
{
	bool right = InputManager::GetKeyState(Keys::RIGHT);
	bool left = InputManager::GetKeyState(Keys::LEFT);
	bool down = InputManager::GetKeyState(Keys::DOWN);
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
		return (int)PlayerAction::BASICATTACK;
	if (left == right)
		return (int)PlayerAction::STAND;
	if ((!parent->imageReversed  && left) || (parent->imageReversed  && right))
		return (int)PlayerAction::WALK;
	return -1;
}
