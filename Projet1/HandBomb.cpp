#include "HandBomb.h"
#include "InputManager.h"
#include "Manager\AssetManager.h"


HandBomb::HandBomb(Hero * parent, float initialSpeed)
{
	this->parent = parent;

	addAnimations();

	maxVelX = 10000;
	velX = (float)initialSpeed;
	jumpingStrength = 300;
	airdrag = 100;
	gravity = 1250;

	jump();

	if (initialSpeed < 0)
		imageReversed = true;
}


HandBomb::~HandBomb()
{
}

void HandBomb::update()
{
	EntityAnimated::update();
	EntityPhysic::update();

	if (!parent->getKeyState(KEYSKILL1))
	{
		isAirborne = false;
		velY = 0;
		velX = 0;
		changeAnimation("Explode");
	}
}

void HandBomb::addAnimations()
{

	sf::Texture* texture = &AssetManager::getTexture("handbomb");
	Spritesheet spritesheet = { texture, 4, 3 };
	Animation * anim = new Animation(spritesheet);
	anim->addFrame({ 0, 0 }, 45);
	anim->addFrame({ 1, 0 }, 45);
	anim->addFrame({ 2, 0 }, 45);
	anim->addFrame({ 0, 1 }, 45);
	anim->addFrame({ 1, 1 }, 45);
	anim->addFrame({ 2, 1 }, 45);
	anim->addFrame({ 0, 2 }, 45);
	anim->addFrame({ 1, 2 }, 45);
	anim->addFrame({ 2, 2 }, 45);
	anim->addFrame({ 0, 3 }, 45);
	anim->addFrame({ 1, 3 }, 45);
	anim->addFrame({ 2, 3 }, 45);
	addAnimation(anim, "Roll");


	//TODO ADD THIS
	addAnimation(anim, "Explode");
}
