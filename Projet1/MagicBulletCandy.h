#pragma once
#include "Particle.h"


class MagicBulletCandy :
	public Particle
{
private:
	sf::Transformable* posToFollow;
	float lerp(float a, float b, float f);
	float offset;
	int degree;


public:
	MagicBulletCandy(float lifeTime,sf::Transformable* posToFollow, float tracking);
	~MagicBulletCandy();

	void Update();
};

