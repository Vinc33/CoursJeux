#pragma once
#include "EntityInanimate.h"
#include "EntityParticleEmitter.h"

class MagicBullet :

	public EntityInanimate,
	public EntityParticleEmitter
	
{
public:
	MagicBullet();
	~MagicBullet();
	void Update();
	void Draw(sf::RenderTarget& target);

private:
	float timer;
	float degree;

};

