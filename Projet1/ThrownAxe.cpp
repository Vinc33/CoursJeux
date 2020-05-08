#include "ThrownAxe.h"
#include "Manager\AssetManager.h"


ThrownAxe::ThrownAxe(int initialSpeed)
{
	sf::Texture* texture = &AssetManager::getTexture("axe");
	Spritesheet spritesheet = { texture, 2, 8 };
	Animation * anim = new Animation(spritesheet);
	anim->addFrame({ 0, 0 }, 31);
	anim->addFrame({ 1, 0 }, 31);
	anim->addFrame({ 2, 0 }, 31);
	anim->addFrame({ 3, 0 }, 31);
	anim->addFrame({ 4, 0 }, 31);
	anim->addFrame({ 5, 0 }, 31);
	anim->addFrame({ 6, 0 }, 31);
	anim->addFrame({ 7, 0 }, 31);
	anim->addFrame({ 0, 1 }, 31);
	anim->addFrame({ 1, 1 }, 31);
	anim->addFrame({ 2, 1 }, 31);
	anim->addFrame({ 3, 1 }, 31);
	anim->addFrame({ 4, 1 }, 31);
	anim->addFrame({ 5, 1 }, 31);
	anim->addFrame({ 6, 1 }, 31);
	anim->addFrame({ 7, 1 }, 31);
	addAnimation(anim, "Roll");

	jumpToFrame(14);

	maxVelX = 10000;
	velX = (float)initialSpeed;
	jumpingStrength = 600;
	airdrag = 150;
	gravity = 2000;

	jump();

	if (initialSpeed < 0)
		imageReversed = true;
}

ThrownAxe::~ThrownAxe()
{
}

void ThrownAxe::update()
{
	EntityAnimated::update();
	EntityPhysic::update();
}
