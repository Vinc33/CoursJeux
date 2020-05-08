#include "MonkHoldAttack.h"
#include "HeroActionsEnum.h"
#include "TimeManager.h"
#include "Hero.h"
#include "MonkChargeParticle.h"


MonkHoldAttack::MonkHoldAttack(Hero* e) : HeroAction(e)
{
	currentTime = .0f;
	particleTimer = .0f;

	bool left = parent->getKeyState(KEYLEFT);
	bool right = parent->getKeyState(KEYRIGHT);
	if (left && !right)
		parent->imageReversed = true;
	else if (!left && right)
		parent->imageReversed = false;

	parent->gravityMult = .3f;
	if (parent->velY > 200)
		parent->velY = 200;
	
	spawnParticle();
}

MonkHoldAttack::~MonkHoldAttack()
{
}

int MonkHoldAttack::update()
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
		if (!parent->getKeyState(KEYATTACK))
		{
			parent->ResetEmitter();
			return (int)PlayerAction::RELEASEATTACK;
		}
	}
	if (currentTime < 1)
		currentTime += TimeManager::DeltaTime;

	//particles
	particleTimer += TimeManager::DeltaTime;
	if (particleTimer > .23f)
	{
		particleTimer -= .23f;
		spawnParticle();
	}
	
	return -1;
}

void MonkHoldAttack::spawnParticle()
{
	if (parent->imageReversed)
		parent->AddParticle(new MonkChargeParticle(parent, true, 22, 12));
	else
		parent->AddParticle(new MonkChargeParticle(parent, false, -22, 12));
}
