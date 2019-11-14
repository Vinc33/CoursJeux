#include "RogueSomersault.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"
#include "Timemanager.h"
#include "Entity.h"
#include <cmath>


RogueSomersault::RogueSomersault(Entity* e) : Action(e)
{
	bool right = InputManager::GetKeyState(Keys::RIGHT);
	bool left = InputManager::GetKeyState(Keys::LEFT);
	if (right)
		parent->isFacingLeft = false;
	else if (left)
		parent->isFacingLeft = true;

	timeRemaining = 1.0f;
	chainAttack = false;
	parent->velY = 0;
	if (parent->isAirborne)
		parent->jump(1.2f);
	else
		parent->jump(1.3f);
	parent->isAirborne = true;
}

RogueSomersault::~RogueSomersault()
{

}

int RogueSomersault::Update()
{
	timeRemaining -= TimeManager::DeltaTime;

	if (parent->velX > parent->maxVelX * 0.4f || -parent->velX > parent->maxVelX * 0.4f)
		parent->velX /= 1 + abs(parent->velX / 100) * TimeManager::DeltaTime;

	if (timeRemaining < 0.5f && InputManager::GetKeyState(X))
		chainAttack = true;

	if (timeRemaining > .5f)
	{
		bool left = InputManager::GetKeyState(LEFT);
		bool right = InputManager::GetKeyState(RIGHT);

		if (right && !left)
			parent->accelerate(0.5f * (1 - timeRemaining));
		else if (left && !right)
			parent->accelerate(-0.5f * (1 - timeRemaining));

		if (parent->isFacingLeft)
			parent->accelerate(-1.8f * (1 - timeRemaining));
		else
			parent->accelerate(1.8f * (1 - timeRemaining));
	}


	if (timeRemaining < 0.4f && chainAttack)
	{
		parent->gravityMult = 1;
		parent->isFacingLeft = !parent->isFacingLeft;
		bool right = InputManager::GetKeyState(Keys::RIGHT);
		bool left = InputManager::GetKeyState(Keys::LEFT);
		if (right)
			parent->isFacingLeft = false;
		else if (left)
			parent->isFacingLeft = true;
		return (int)PlayerAction::BASICATTACK;
	}

	if (!parent->isAirborne)
	{
		parent->isFacingLeft = !parent->isFacingLeft;
		if (InputManager::GetKeyState(DOWN))
			return (int)PlayerAction::CROUNCH;

		if (InputManager::GetKeyState(RIGHT) || InputManager::GetKeyState(LEFT))
			return (int)PlayerAction::WALK;
		return ((int)PlayerAction::STAND);
	}

	if (timeRemaining < 0)
	{
		return (int)PlayerAction::FALL;
	}
}
