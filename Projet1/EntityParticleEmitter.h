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

	virtual void Update();
	virtual void Draw(sf::RenderTarget& target);

	void AddParticle(Particle* p);
	void ResetEmitter();
protected:
	bool particlesMoveWithParent;
	std::vector<Particle*> particles;
};

