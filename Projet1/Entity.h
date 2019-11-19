#pragma once
#include "EntityAnimated.h"
#include "EntityBrain.h"
#include "EntityPhysic.h"
#include "EntitySpawner.h"
#include "EntityParticleEmitter.h"
#include <SFML\Graphics\Transformable.hpp>
#include <SFML\Graphics\RenderTarget.hpp>

class Entity :
	public EntityAnimated,
	public EntityBrain,
	public EntityPhysic,
	public EntitySpawner,
	public EntityParticleEmitter
{
public:
	Entity();
	~Entity();

	void setPosition(const sf::Vector2f& pos);
	void setPosition(const int& x, const int& y);

	virtual void Update();
	virtual void Draw(sf::RenderTarget& target);

	void MoveOnHitBox();

protected:
	sf::RectangleShape* body;
};

