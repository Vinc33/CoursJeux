#include "RogueWalk.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"
#include "Timemanager.h"
#include "Entity.h"


RogueWalk::RogueWalk(Entity* e) : Action(e)
{
	bool right = InputManager::GetKeyState(Keys::RIGHT);
	bool left = InputManager::GetKeyState(Keys::LEFT);
	if (right)
		parent->isFacingLeft = false;
	else if (left)
		parent->isFacingLeft = true;
}


RogueWalk::~RogueWalk()
{
}

int RogueWalk::Update()
{
	bool right = InputManager::GetKeyState(Keys::RIGHT);
	bool left = InputManager::GetKeyState(Keys::LEFT);

	if (right && !left)
		parent->accelerate(1);
	else if (left && !right)
		parent->accelerate(-1);

	if (InputManager::GetKeyState(Keys::A))
	{
		if (InputManager::GetKeyState(Keys::UP))
			return (int)PlayerAction::SOMERSAULT;
		else
			return (int)PlayerAction::JUMP;
	}
	if (InputManager::GetKeyState(Keys::DOWN))
	{
		if(right != left)
			return (int)PlayerAction::ROLL;
		else
			return (int)PlayerAction::CROUNCH;

	}
	if (InputManager::GetKeyState(Keys::X))
		return (int)PlayerAction::BASICATTACK;
	if (left == right)
		return (int)PlayerAction::STAND;
	if ((!parent->isFacingLeft && left) || (parent->isFacingLeft && right))
		return (int)PlayerAction::WALK;
	return -1;
}
