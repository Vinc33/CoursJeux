#pragma once
#include "Particle.h"
class MonkChargeParticle :
	public Particle
{
public:
	MonkChargeParticle(bool reversed = false, float originX = 0, float originY = 0);
	~MonkChargeParticle();

	void update();
private:
	bool rotatingLeft;
	bool isCounterClockwise;
};

