#include "HunterJump.h"
#include "Hero.h"
#include "HeroActionsEnum.h"
#include "InputManager.h"
#include "Settings.h"

HunterJump::HunterJump(Hero* e) : HeroAction(e)
{

	bool left = parent->getKeyState(KEYLEFT);
	bool right = parent->getKeyState(KEYRIGHT);
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

int HunterJump::update()
{
	bool left = parent->getKeyState(KEYLEFT);
	bool right = parent->getKeyState(KEYRIGHT);

	if (right && !left)
		parent->accelerate(0.7f);
	else if (left && !right)
		parent->accelerate(-0.7f);

	if (parent->velY < 50)
		return (int)PlayerAction::SECONDJUMP;
	return -1;
}