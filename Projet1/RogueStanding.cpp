#include "RogueStanding.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"
#include "Entity.h"
#include "Settings.h"



RogueStanding::RogueStanding(Entity* e) : ActionEntity(e)
{
	if (!InputManager::GetKeyState(Keys::A))
		jumpReady = true;
}


RogueStanding::~RogueStanding()
{
}

int RogueStanding::update()
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
		if (InputManager::GetKeyState(Keys::UP))
			return (int)PlayerAction::ITEMUP;
		if (InputManager::GetKeyState(Keys::DOWN))
			return (int)PlayerAction::ITEMDOWN;
		if (right != left)
			return (int)PlayerAction::ITEMFRONT;
		return (int)PlayerAction::ITEMSTAND;
	}

	if (InputManager::GetKeyState(Keys::X))
		return (int)PlayerAction::BASICATTACK;

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

	if (right != left)
	{
		if (right)
		{
			if (parent->velX >= 50)
				return (int)PlayerAction::WALK;
		}
		else
		{
			if (parent->velX <= -50)
				return (int)PlayerAction::WALK;
		}
	}

	if (InputManager::GetKeyState(Keys::DOWN))
		return (int)PlayerAction::CROUNCH;

	return -1;
}