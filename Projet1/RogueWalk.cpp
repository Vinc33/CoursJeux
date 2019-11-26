#include "RogueWalk.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"
#include "Timemanager.h"
#include "Entity.h"


RogueWalk::RogueWalk(Entity* e) : ActionEntity(e)
{
	bool right = InputManager::GetKeyState(Keys::RIGHT);
	bool left = InputManager::GetKeyState(Keys::LEFT);
	if (right != left)
	{
		if (right)
			parent->imageReversed = false;
		else
			parent->imageReversed = true;
	}

	if (!InputManager::GetKeyState(Keys::A))
		jumpReady = true;
}


RogueWalk::~RogueWalk()
{
}

int RogueWalk::update()
{
	bool right = InputManager::GetKeyState(Keys::RIGHT);
	bool left = InputManager::GetKeyState(Keys::LEFT);

	if (right != left)
	{
		if (right)
			parent->accelerate(1);
		else
			parent->accelerate(-1);
	}

	if (InputManager::GetKeyState(Keys::B))
	{
		if (itemReady)
		{
			if (InputManager::GetKeyState(Keys::UP))
				return (int)PlayerAction::ITEMUP;
			if (InputManager::GetKeyState(Keys::DOWN))
				return (int)PlayerAction::ITEMDOWN;
			if (right != left)
				return (int)PlayerAction::ITEMFRONT;
			return (int)PlayerAction::ITEMSTAND;
		}
	}
	else
	{
		itemReady = true;
	}

	if (InputManager::GetKeyState(Keys::A))
	{
		if (jumpReady)
		{
			if (InputManager::GetKeyState(Keys::UP))
				return (int)PlayerAction::SOMERSAULT;
			else
				return (int)PlayerAction::JUMP;
		}
	}
	else
	{
		jumpReady = true;
	}

	if (InputManager::GetKeyState(Keys::X))
	{
		if (attackReady)
			return (int)PlayerAction::BASICATTACK;
	}
	else
	{
		attackReady = true;
	}

	if (InputManager::GetKeyState(Keys::DOWN))
	{
		if (right != left)
			return (int)PlayerAction::ROLL;
		return (int)PlayerAction::CROUNCH;
	}
	if (left == right)
		return (int)PlayerAction::STAND;
	if ((!parent->imageReversed && left) || (parent->imageReversed && right))
		return (int)PlayerAction::WALK;
	return -1;
}
