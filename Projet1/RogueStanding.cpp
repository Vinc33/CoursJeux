#include "RogueStanding.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"
#include "Entity.h"
#include "Settings.h"



RogueStanding::RogueStanding(Entity* e): ActionEntity(e)
{
}


RogueStanding::~RogueStanding()
{
}

int RogueStanding::Update()
{
	bool right = InputManager::GetKeyState(Keys::RIGHT);
	bool left = InputManager::GetKeyState(Keys::LEFT);
	bool down = InputManager::GetKeyState(Keys::DOWN);
	bool up = InputManager::GetKeyState(Keys::UP);
	bool jump = InputManager::GetKeyState(Keys::A);
	bool attack = InputManager::GetKeyState(Keys::X);

	if (jump)
	{
		if (up)
			return (int)PlayerAction::SOMERSAULT;
		else
			return (int)PlayerAction::JUMP;
	}
	if (down)
		return (int)PlayerAction::CROUNCH;
	if (attack)
		return (int)PlayerAction::BASICATTACK;

	if (right && !left)
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