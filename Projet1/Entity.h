#pragma once
#include "EntityAnimated.h"
#include "EntityBrain.h"
#include "EntityPhysic.h"
#include "EntitySpawner.h"
#include "EntityCollision.h"
#include "EntityParticleEmitter.h"

class Entity :
	public EntityAnimated,
	public EntityBrain,
	public EntityPhysic,
	public EntitySpawner,
	public EntityParticleEmitter,
	public EntityCollision

{
public:
	Entity();
	~Entity();

	virtual void update();
	virtual void draw(sf::RenderTarget& target);
	

};

