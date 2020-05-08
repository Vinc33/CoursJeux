#include "MonkWalking.h"
#include "HeroActionsEnum.h"
#include "Hero.h"


MonkWalking::MonkWalking(Hero* e) : HeroAction(e)
{
	bool right = parent->getKeyState(KEYRIGHT);
	bool left = parent->getKeyState(KEYLEFT);
	if (right)
		parent->imageReversed = false;
	else if (left)
		parent->imageReversed = true;
}

MonkWalking::~MonkWalking()
{
}

int MonkWalking::update()
{
	bool right = parent->getKeyState(KEYRIGHT);
	bool left = parent->getKeyState(KEYLEFT);
	bool down = parent->getKeyState(KEYDOWN);
	bool up = parent->getKeyState(KEYUP);
	bool jump = parent->getKeyState(KEYJUMP);
	bool attack = parent->getKeyState(KEYATTACK);

	if (right && !left)
		parent->accelerate(1);
	else if (left && !right)
		parent->accelerate(-1);

	if (jump)
		return (int)PlayerAction::JUMP;
	if (down)
		return (int)PlayerAction::CROUNCH;
	if (attack)
	{
		if (up)
			return (int)PlayerAction::NOJUMPROUNDHOUSE;
		return (int)PlayerAction::BASICATTACK;
	}
	if (left == right || (parent->velX > 0 && left) || (parent->velX < 0 && right))
		return (int)PlayerAction::STAND;
	return -1;
}