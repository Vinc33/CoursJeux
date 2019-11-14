#include "RogueJump.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"
#include "Entity.h"


RogueJump::RogueJump(Entity* e, bool jump, bool canRoll) : Action(e)
{
	if (jump)
	{
		parent->isAirborne = true;
		parent->velY = 0;
		parent->jump();
	}
	parent->gravityMult = 1;
	this->canRoll = canRoll;
}


RogueJump::~RogueJump()
{

}

int RogueJump::Update()
{
	bool right = InputManager::GetKeyState(Keys::RIGHT);
	bool left = InputManager::GetKeyState(Keys::LEFT);
	bool down = InputManager::GetKeyState(Keys::DOWN);
	bool jump = InputManager::GetKeyState(Keys::A);

	if (!parent->isAirborne)
	{
		parent->gravityMult = 1;
		if (down)
			return (int)PlayerAction::CROUNCH;

		if (right || left)
			return (int)PlayerAction::WALK;
		return ((int)PlayerAction::STAND);
	}

	if (jump)
	{
		parent->gravityMult = 1;
	}
	else
		parent->gravityMult = 3;


	if (right && !left)
		parent->accelerate(0.5);
	else if (left && !right)
		parent->accelerate(-0.5);

	if (InputManager::GetKeyState(UP) && parent->velY < -(parent->jumpingStrength * 0.8))
		return(int)PlayerAction::SOMERSAULT;

	if (down && jump && canRoll)
	{
		return(int)PlayerAction::ROLL;
	}

	if (InputManager::GetKeyState(X))
	{
		parent->gravityMult = 1;
		return (int)PlayerAction::BASICATTACK;
	}

	return -1;
}
