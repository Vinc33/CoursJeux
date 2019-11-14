#include "MonkHoldAttack.h"
#include "HeroActionsEnum.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Entity.h"



MonkHoldAttack::MonkHoldAttack(Entity* e) : Action(e)
{
	bool left = InputManager::GetKeyState(LEFT);
	bool right = InputManager::GetKeyState(RIGHT);
	if (left && !right)
		parent->isFacingLeft = true;
	else if (!left && right)
		parent->isFacingLeft = false;

	currentTime = 0.0f;
	parent->gravityMult = 0.3f;
	if (parent->velY > 200)
		parent->velY = 200;
}


MonkHoldAttack::~MonkHoldAttack()
{
}

int MonkHoldAttack::Update()
{
	if (!parent->isAirborne)
		parent->gravityMult = 1;
	else
	{
		if (parent->velY < 0)
		{
			parent->gravityMult = 1;
			currentTime = 0;
		}
		else
			parent->gravityMult = 0.4f + 0.8f * currentTime;
	}

	if (currentTime > 0.1f)
	{
		if (!InputManager::GetKeyState(X))
			return (int)PlayerAction::RELEASEATTACK;
	}
	if (currentTime < 1)
		currentTime += TimeManager::DeltaTime;
	
	return -1;
}
