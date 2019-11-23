#include "HunterJumpMid.h"
#include "Entity.h"
#include "HeroActionsEnum.h"
#include "InputManager.h"
#include "Settings.h"

HunterJumpMid::HunterJumpMid(Entity* e) : ActionEntity(e)
{
}


HunterJumpMid::~HunterJumpMid()
{
}

int HunterJumpMid::update()
{
	bool left = InputManager::GetKeyState(LEFT);
	bool right = InputManager::GetKeyState(RIGHT);

	if (right && !left)
		parent->accelerate(0.5);
	else if (left && !right)
		parent->accelerate(-0.5);

	if (parent->velY > -200)
		return (int)PlayerAction::FALL;
	return -1;
}