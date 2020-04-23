#pragma once
#include "EntityAnimated.h"
#include "EntityStateMachine.h"
#include "EntityPhysic.h"
#include "EntitySpawner.h"
#include "EntityParticleEmitter.h"

class Entity :
	public EntityAnimated,
	public EntityStateMachine,
	public EntityPhysic,
	public EntitySpawner,
	public EntityParticleEmitter
{
public:
	Entity();
	~Entity();

	virtual void update();
	virtual void draw(sf::RenderTarget& target);

};

