#pragma once
#include "EntityAnimated.h"
#include "EntityPhysic.h"
#include "Hero.h"

class HandBomb :
	public EntityAnimated,
	public EntityPhysic
{
public:
	HandBomb(Hero * parent, float initialSpeed);
	~HandBomb();

	void update();
private:
	void addAnimations();

	Hero * parent;
};

