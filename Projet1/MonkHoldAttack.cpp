#include "MonkHoldAttack.h"
#include "HeroActionsEnum.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Entity.h"
#include "MonkChargeParticle.h"


MonkHoldAttack::MonkHoldAttack(Entity* e) : ActionEntity(e)
{
	bool left = InputManager::GetKeyState(LEFT);
	bool right = InputManager::GetKeyState(RIGHT);
	if (left && !right)
		parent->isFacingLeft = true;
	else if (!left && right)
		parent->isFacingLeft = false;

	parent->gravityMult = .3f;
	if (parent->velY > 200)
		parent->velY = 200;

	if (parent->isFacingLeft)
		parent->AddParticle(new MonkChargeParticle(true, 128, 84));
	else
		parent->AddParticle(new MonkChargeParticle(false, 38, 84));
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
			parent->gravityMult = .4f + .8f * currentTime;
	}

	if (currentTime > .1f)
	{
		if (!InputManager::GetKeyState(X))
		{
			parent->ResetEmitter();
			return (int)PlayerAction::RELEASEATTACK;
		}
	}
	if (currentTime < 1)
		currentTime += TimeManager::DeltaTime;


	//particles
	particleTimer += TimeManager::DeltaTime;
	if (particleTimer > .2349f)
	{
		particleTimer -= .2349f;
		if (parent->isFacingLeft)
			parent->AddParticle(new MonkChargeParticle(true, 128, 84));
		else
			parent->AddParticle(new MonkChargeParticle(false, 38, 84));
	}
	
	return -1;
}
