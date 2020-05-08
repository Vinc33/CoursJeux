#include "HunterJumpMid.h"
#include "Hero.h"
#include "HeroActionsEnum.h"
#include "InputManager.h"
#include "Settings.h"

HunterJumpMid::HunterJumpMid(Hero* e) : HeroAction(e)
{
}


HunterJumpMid::~HunterJumpMid()
{
}

int HunterJumpMid::update()
{
	bool left = parent->getKeyState(KEYLEFT);
	bool right = parent->getKeyState(KEYRIGHT);

	if (right && !left)
		parent->accelerate(0.5);
	else if (left && !right)
		parent->accelerate(-0.5);

	if (parent->velY > -200)
		return (int)PlayerAction::FALL;
	return -1;
}