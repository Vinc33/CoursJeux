#include "RogueItemUse.h"
#include "Entity.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"


RogueItemUse::RogueItemUse(Entity* e, float timer) : ActionEntity(e)
{
	this->timer = timer;
}


RogueItemUse::~RogueItemUse()
{
}

int RogueItemUse::Update()
{
	timer -= TimeManager::DeltaTime;
	if (timer < 0)
	{
		if (parent->isAirborne)
			return (int)PlayerAction::FALL;

		if (InputManager::GetKeyState(DOWN))
			return (int)PlayerAction::CROUNCH;

		if (InputManager::GetKeyState(RIGHT) != InputManager::GetKeyState(LEFT))
			return (int)PlayerAction::WALK;

		return ((int)PlayerAction::STAND);
	}
	return -1;
}
