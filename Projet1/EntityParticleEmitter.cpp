#include "EntityParticleEmitter.h"
#include <SFML\Graphics\RenderTarget.hpp>
#include "TimeManager.h"

EntityParticleEmitter::EntityParticleEmitter()
{
	particles = std::vector<Particle*>();
	particlesMoveWithParent = true;
}


EntityParticleEmitter::~EntityParticleEmitter()
{
	std::vector<Particle*>::iterator it;
	for (it = particles.begin(); it != particles.end(); it++)
		delete *it;
}

void EntityParticleEmitter::Update()
{
	std::vector<Particle*>::iterator it;
	for (it = particles.begin(); it != particles.end(); )
	{
		(*it)->lifeTime -= TimeManager::DeltaTime;
		if ((*it)->lifeTime < .0f)
		{
			delete *it;
			it = particles.erase(it);
		}
		else
		{
			(*it)->Update();
			if (particlesMoveWithParent)
				(*it)->MoveOrigin(position.getPosition().x, position.getPosition().y);
			it++;
		}
	}
}

void EntityParticleEmitter::Draw(sf::RenderTarget& target)
{
	std::vector<Particle*>::iterator it;
	for (it = particles.begin(); it != particles.end(); it++)
		(*it)->Draw(target);
}

void EntityParticleEmitter::AddParticle(Particle* p)
{
	particles.push_back(p);
}

void EntityParticleEmitter::ResetEmitter()
{
	std::vector<Particle*>::iterator it;
	for (it = particles.begin(); it != particles.end(); )
	{
		delete *it;
		it = particles.erase(it);
	}
}
