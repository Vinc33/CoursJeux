#include "Standing.h"
#include "HeroActionsEnum.h"
#include "Settings.h"
#include "Hero.h"

Standing::Standing(Hero* e) : HeroAction(e)
{

}


Standing::~Standing()
{

}

int Standing::update()
{
	if (parent->getKeyState(KEYJUMP))
		return (int)PlayerAction::JUMP;
	else if (parent->getKeyState(KEYDOWN))
		return (int)PlayerAction::CROUNCH;
	else if (parent->getKeyState(KEYATTACK))
	{
		if (parent->getKeyState(KEYUP))
			return (int)PlayerAction::NOJUMPROUNDHOUSE;
		return (int)PlayerAction::BASICATTACK;

	}

	bool right = parent->getKeyState(KEYRIGHT);
	bool left = parent->getKeyState(KEYLEFT);

	if (right && !left )
	{
		parent->accelerate(1);
		if (parent->velX >= 50)
			return (int)PlayerAction::WALK;
	}
	else if (left && !right)
	{
		parent->accelerate(-1);
		if (parent->velX <= -50)
			return (int)PlayerAction::WALK;
	}
	
	return -1;
}
