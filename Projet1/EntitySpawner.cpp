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
	e->position.setPosition(position.getPosition().x + offsetX, position.getPosition().y + offsetY);
	GameView::Game::AddEntity(e);
}
