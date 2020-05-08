#include "MonkDiveKick.h"
#include "InputManager.h"
#include "HeroActionsEnum.h"
#include "TimeManager.h"
#include "Hero.h"
#include "Settings.h"


MonkDiveKick::MonkDiveKick(Hero* e) : HeroAction(e)
{
	parent->gravityMult = 1;
	bool right = parent->getKeyState(KEYRIGHT);
	bool left = parent->getKeyState(KEYLEFT);
	if (right)
		parent->imageReversed = false;
	else if (left)
		parent->imageReversed = true;
	parent->isAirborne = true;
	countDown = 0.350f;
	parent->velY += 50;
	if (parent->velY > 0)
		parent->velY *= 2;
}


MonkDiveKick::~MonkDiveKick()
{
}

int MonkDiveKick::update()
{

	//if (countDown = )
	if (parent->imageReversed)
		parent->velX = (-650.0f * countDown - parent->maxVelX * 1.8f);
	else
		parent->velX = (650.0f * countDown + parent->maxVelX * 1.8f);

	countDown -= TimeManager::DeltaTime;

	bool right = parent->getKeyState(KEYRIGHT);
	bool left = parent->getKeyState(KEYLEFT);
	bool down = parent->getKeyState(KEYDOWN);

	if (!parent->isAirborne)
	{
		if (parent->velX > parent->maxVelX * 2.8f)
			parent->velX = parent->maxVelX * 2.8f;
		else if (parent->velX < -parent->maxVelX * 2.8f)
			parent->velX = -parent->maxVelX * 2.8f;

		if (down)
			return (int)PlayerAction::CROUNCH;

		if (right || left)
			return (int)PlayerAction::WALK;
		return ((int)PlayerAction::STAND);
	}

	if (countDown < 0)
	{
		if (!parent->getKeyState(KEYATTACK) || abs(parent->velX) <= 1.4 * parent->maxVelX)
		{
			if (parent->isAirborne)
				return (int)PlayerAction::FALL;

			if (down)
				return (int)PlayerAction::CROUNCH;
			if (right || left)
				return (int)PlayerAction::WALK;
			return ((int)PlayerAction::STAND);
		}
	}
	return -1;
}
