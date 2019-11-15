#include "Knockback.h"
#include "HeroActionsEnum.h"
#include "TimeManager.h"
#include "Settings.h"
#include "Entity.h"


Knockback::Knockback(int initialForceX, int initialForceY, Entity* e) : ActionEntity(e)
{
	parent->velX += initialForceX;
	parent->velY += initialForceY;
}


Knockback::~Knockback()
{

}

int Knockback::Update()
{
	if (!(parent->isAirborne))
		return (int)PlayerAction::STAND;

	if (parent->velX < 20 && parent->velX > -20)
		return (int)PlayerAction::STAND;


	return -1;
}
