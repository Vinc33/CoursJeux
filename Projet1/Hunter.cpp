#include "Hunter.h"
#include "Animation.h"
#include "HeroActionsEnum.h"
#include "Standing.h"
#include "Walking.h"
#include "HunterJump.h"
#include "HunterJumpMid.h"
#include "Falling.h"
#include "Crounching.h"
#include "HunterShoot.h"
#include "Manager\AssetManager.h"

Hunter::Hunter() : Hero("Hunter", 50, 100)
{
	acc = 800;
	maxVelX = 350;
	drag = 1200;
	jumpingStrength = 600;
	airdrag = 400;
	gravity = 3000;

	setPosition(50, 200);

	addAnimations();
	currentAction = new Standing(this);
}

Hunter::~Hunter()
{

}

void Hunter::changeAction(int enumIndex)
{
	switch ((PlayerAction)enumIndex)
	{
	case STAND:
		changeAnimation("Stand");
		delete currentAction;
		currentAction = new Standing(this);
		break;
	case WALK:
		changeAnimation("Walk");
		delete currentAction;
		currentAction = new Walking(this);
		break;
	case JUMP:
		changeAnimation("JumpRise");
		delete currentAction;
		currentAction = new HunterJump(this);
		break;
	case SECONDJUMP:
		changeAnimation("JumpMid");
		delete currentAction;
		currentAction = new HunterJumpMid(this);
		break;
	case FALL:
		changeAnimation("Fall");
		delete currentAction;
		currentAction = new Falling(this);
		break;
	case CROUNCH:
		changeAnimation("Crounch");
		delete currentAction;
		currentAction = new Crounching(this);
		break;
	case BASICATTACK:
		changeAnimation("Shoot");
		delete currentAction;
		currentAction = new HunterShoot(this);
		break;
	}
}

void Hunter::addAnimations()
{
	sf::Texture* texture = &AssetManager::getTexture("hunter.png");
	Spritesheet spritesheet = { texture, 2, 16 };

	Animation * anim = new Animation(spritesheet);
	anim->addFrame({ 15, 0 }, -1);
	addAnimation(anim, "Stand");

	anim = new Animation(spritesheet);
	anim->addFrame({ 0, 1 }, 25);
	anim->addFrame({ 1, 1 }, 25);
	anim->addFrame({ 2, 1 }, 25);
	anim->addFrame({ 3, 1 }, 25);
	anim->addFrame({ 4, 1 }, 25);
	anim->addFrame({ 5, 1 }, 25);
	anim->addFrame({ 6, 1 }, 25);
	anim->addFrame({ 7, 1 }, 25);
	anim->addFrame({ 8, 1 }, 25);
	anim->addFrame({ 9, 1 }, 25);
	anim->addFrame({ 10, 1 }, 25);
	anim->addFrame({ 11, 1 }, 25);
	anim->addFrame({ 12, 1 }, 25);
	anim->addFrame({ 13, 1 }, 25);
	addAnimation(anim, "Walk");

	anim = new Animation(spritesheet);
	anim->addFrame({ 5, 0 }, 150);
	anim->addFrame({ 6, 0 }, 100);
	anim->addFrame({ 7, 0 }, -1);
	addAnimation(anim, "Crounch");

	anim = new Animation(spritesheet);
	anim->addFrame({ 2, 0 }, 100);
	anim->addFrame({ 3, 0 }, 50);
	anim->addFrame({ 4, 0 }, 100);
	addAnimation(anim, "CrounchShoot");

	anim = new Animation(spritesheet);
	anim->addFrame({ 12, 0 }, 100);
	anim->addFrame({ 13, 0 }, 50);
	anim->addFrame({ 14, 0 }, 100);
	addAnimation(anim, "Shoot");

	anim = new Animation(spritesheet);
	anim->addFrame({ 10, 0 }, -1);
	addAnimation(anim, "JumpRise");

	anim = new Animation(spritesheet);
	anim->addFrame({ 11, 0 }, -1);
	addAnimation(anim, "JumpMid");

	anim = new Animation(spritesheet);
	anim->addFrame({ 8, 0 }, 150);
	anim->addFrame({ 9, 0 }, 150);
	addAnimation(anim, "Fall");
}