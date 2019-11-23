#pragma once
#include <vector>
#include "EntityBase.h"
#include "Particle.h"
class EntityParticleEmitter :
	public virtual EntityBase
{
public:
	EntityParticleEmitter();
	~EntityParticleEmitter();

	virtual void update();
	virtual void draw(sf::RenderTarget& target);

	void AddParticle(Particle* p);
	void ResetEmitter();
protected:
	bool particlesMoveWithParent;
	std::vector<Particle*> particles;
};

