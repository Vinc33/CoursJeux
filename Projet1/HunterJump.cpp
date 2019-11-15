#include "HunterJump.h"
#include "Entity.h"
#include "HeroActionsEnum.h"
#include "InputManager.h"
#include "Settings.h"

HunterJump::HunterJump(Entity* e) : ActionEntity(e)
{

	bool left = InputManager::GetKeyState(LEFT);
	bool right = InputManager::GetKeyState(RIGHT);
	if (left != right)
	{
		if (left)
			parent->velX = (float)-parent->maxVelX;
		else
			parent->velX = (float)parent->maxVelX;
	}
	parent->jump();

}

HunterJump::~HunterJump()
{
}

int HunterJump::Update()
{
	bool left = InputManager::GetKeyState(LEFT);
	bool right = InputManager::GetKeyState(RIGHT);

	if (right && !left)
		parent->accelerate(0.7f);
	else if (left && !right)
		parent->accelerate(-0.7f);

	if (parent->velY < 50)
		return (int)PlayerAction::SECONDJUMP;
	return -1;
}