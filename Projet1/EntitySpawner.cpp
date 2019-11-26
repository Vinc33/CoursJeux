#include "EntitySpawner.h"
#include "Game.h"


EntitySpawner::EntitySpawner()
{
}


EntitySpawner::~EntitySpawner()
{
}


void EntitySpawner::Spawn(EntityBase* e, int offsetX, int offsetY)
{
	e->setPosition(getPosition().x + offsetX, getPosition().y + offsetY);
	GameView::Game::AddEntity(e);
}
