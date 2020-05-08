#include "HeroAction.h"
#include "EntityStateMachine.h"


HeroAction::HeroAction(Hero* e) : Action((EntityStateMachine*)e)
{
	parent = e;
}


HeroAction::~HeroAction()
{

}
