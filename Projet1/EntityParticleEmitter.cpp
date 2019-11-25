#include "EntityParticleEmitter.h"
#include <SFML\Graphics\RenderTarget.hpp>
#include "TimeManager.h"

EntityParticleEmitter::EntityParticleEmitter()
{
	particles = std::vector<Particle*>();
	particlesMoveWithParent = false;
}


EntityParticleEmitter::~EntityParticleEmitter()
{
	std::vector<Particle*>::iterator it;
	for (it = particles.begin(); it != particles.end(); it++)
		delete *it;
}

void EntityParticleEmitter::update()
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
			(*it)->update();
			if (particlesMoveWithParent)
				(*it)->MoveOrigin(getPosition().x, getPosition().y);
			it++;
		}
	}
}

void EntityParticleEmitter::draw(sf::RenderTarget& target)
{
	std::vector<Particle*>::iterator it;
	for (it = particles.begin(); it != particles.end(); it++)
		(*it)->draw(target);
}

void EntityParticleEmitter::AddParticle(Particle* p)
{ 
	p->setOrigin(this->getPosition().x, this->getPosition().y);
	p->move(this->getPosition().x, this->getPosition().y);
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
