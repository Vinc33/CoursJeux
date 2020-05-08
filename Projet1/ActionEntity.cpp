#include "HeroAction.h"
#include "EntityStateMachine.h"


HeroAction::HeroAction(Entity* e) : Action((EntityStateMachine*)e)
{
	parent = e;
}


HeroAction::~HeroAction()
{

}
