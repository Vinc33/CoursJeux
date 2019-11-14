#include "RogueAttack.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"
#include "Entity.h"

RogueAttack::RogueAttack(Entity* e) : Action(e)
{
	timeRemaining = 0.35f;
	if (parent->velY > 0)
	{
		parent->gravityMult = 0.7f;
		parent->velY = 0;
	}

	if (parent->isFacingLeft)
		parent->accelerate(-.7f);
	else
		parent->accelerate(.7f);

}


RogueAttack::~RogueAttack()
{

}

int RogueAttack::Update()
{
	bool left = InputManager::GetKeyState(LEFT);
	bool right = InputManager::GetKeyState(RIGHT);


	if (right && !left)
		parent->accelerate(0.4f);
	else if (left && !right)
		parent->accelerate(-0.4f);

	timeRemaining -= TimeManager::DeltaTime;
	if (timeRemaining < 0)
	{
		parent->gravityMult = 1;
		if (parent->isAirborne)
			return (int)PlayerAction::FALLMAYROLL;
		bool down = InputManager::GetKeyState(DOWN);

		if (down)
			return (int)PlayerAction::CROUNCH;
		if ((left && !right) || (right && !left))
			return (int)PlayerAction::WALK;
		return (int)PlayerAction::STAND;
	}

	return -1;
}
