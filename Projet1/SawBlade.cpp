#include "SawBlade.h"
#include "Manager\AssetManager.h"

SawBlade::SawBlade(int initialSpeed)
{
	sf::Texture* texture = &AssetManager::getTexture("sawblade");
	Spritesheet spritesheet = { texture, 1, 3 };
	Animation * anim = new Animation(spritesheet);
	anim->addFrame({ 0, 0 }, 32);
	anim->addFrame({ 1, 0 }, 32);
	anim->addFrame({ 2, 0 }, 32);
	addAnimation(anim, "Roll");

	maxVelX = 10000;
	velX = (float)initialSpeed;
	jumpingStrength = 700;
	airdrag = 400;
	gravity = 2000;

	jump();

	if (initialSpeed < 0)
		imageReversed = true;
}

SawBlade::~SawBlade()
{
}

void SawBlade::update()
{
	EntityAnimated::update();
	EntityPhysic::update();
}
