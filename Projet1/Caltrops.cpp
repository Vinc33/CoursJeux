#include "Caltrops.h"
#include "Manager\AssetManager.h"



Caltrops::Caltrops(float initialSpeed)
{

	sf::Texture* texture = &AssetManager::getTexture("caltrops");
	Spritesheet spritesheet = { texture, 4, 3 };
	Animation * anim = new Animation(spritesheet);
	anim->addFrame({ 0, 0 }, 31);
	anim->addFrame({ 1, 0 }, 31);
	anim->addFrame({ 2, 0 }, 31);
	anim->addFrame({ 0, 1 }, 31);
	anim->addFrame({ 1, 1 }, 31);
	anim->addFrame({ 2, 1 }, 31);
	anim->addFrame({ 0, 2 }, 31);
	anim->addFrame({ 1, 2 }, 31);
	anim->addFrame({ 2, 2 }, 31);
	anim->addFrame({ 0, 3 }, 31);
	anim->addFrame({ 1, 3 }, 31);
	anim->addFrame({ 2, 3 }, 31);
	addAnimation(anim, "Roll");
	jumpToFrame(rand() % 12);


	texture = &AssetManager::getTexture("caltrops_deployed");
	spritesheet = { texture, 3, 3 };
	anim = new Animation(spritesheet);
	anim->addFrame({ 0, 0 }, -1);
	anim->addFrame({ 1, 0 }, -1);
	anim->addFrame({ 2, 0 }, -1);
	anim->addFrame({ 0, 1 }, -1);
	anim->addFrame({ 1, 1 }, -1);
	anim->addFrame({ 2, 1 }, -1);
	anim->addFrame({ 0, 2 }, -1);
	anim->addFrame({ 1, 2 }, -1);
	anim->addFrame({ 2, 2 }, -1);
	addAnimation(anim, "Land");


	maxVelX = 10000;
	velX = (float)initialSpeed;
	jumpingStrength = 50;
	airdrag = 200;
	gravity = 1500;
	drag = 2500;
	jump();
}


Caltrops::~Caltrops()
{
}

void Caltrops::update()
{
	EntityAnimated::update();
	EntityPhysic::update();

	//temporary ground
	if (velY > 0 && getPosition().y > 440)
	{
		isAirborne = false;
		setPosition(getPosition().x, 440);
		velY = 0;
		changeAnimation("Land");
		jumpToFrame(rand() % 9);
	}
	//end temporary ground
}
