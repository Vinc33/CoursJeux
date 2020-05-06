#include "Monk.h"
#include "Animation.h"
#include "HeroActionsEnum.h"
#include "Standing.h"
#include "MonkWalking.h"
#include "MonkCrounching.h"
#include "MonkJump.h"
#include "MonkFall.h"
#include "Knockback.h"
#include "MonkHoldAttack.h"
#include "MonkPunch.h"
#include "MonkRoundhouse.h"
#include "MonkRisingKick.h"
#include "MonkSecondJump.h"
#include "MonkDiveKick.h"
#include "Manager\AssetManager.h"

Monk::Monk() : Hero("Monk", 50, 30)
{
	acc = 350;
	maxVelX = 100;
	drag = 300;
	jumpingStrength = 350;
	airdrag = 100;
	gravity = 750;

	addAnimations();
	setPosition(50, 200);

	currentAction = new Standing(this);

	hasRoundhoused = false;
	hasPunched = false;
	hasDropkicked = false;
	maxNumberOfJumps = 4;
	jumpRemaining = maxNumberOfJumps;

	particlesMoveWithParent = false;

	srand((unsigned)time(NULL));
}

Monk::~Monk()
{
}

void Monk::changeAction(int enumIndex)
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
		currentAction = new MonkWalking(this);
		break;
	case CROUNCH:
		changeAnimation("Crounch");
		delete currentAction;
		currentAction = new MonkCrounching(this, 0.0f);
		break;
	case JUMP:
		hasRoundhoused = false;
		hasPunched = false;
		hasDropkicked = false;
		changeAnimation("Jump");
		delete currentAction;
		jump();
		jumpRemaining = maxNumberOfJumps - 1;
		currentAction = new MonkJump(this, !hasRoundhoused, !hasPunched, !hasDropkicked, jumpRemaining > 0);
		break;
	case SECONDJUMP:
		changeAnimation("Fall");
		delete currentAction;
		jumpRemaining--;
		velY = 0;
		jump(0.9f);
		currentAction = new MonkFall(this, !hasRoundhoused, !hasPunched, !hasDropkicked, false);
		break;
	case FALL:
		if (jumpRemaining > 0)
			changeAnimation("Jump");
		else
			changeAnimation("Fall");
		delete currentAction;
		currentAction = new MonkFall(this, !hasRoundhoused, !hasPunched, !hasDropkicked, jumpRemaining > 0);
		break;
	case ROUNDHOUSE:
		hasRoundhoused = true;
		changeAnimation("Roundhouse kick");
		delete currentAction;
		currentAction = new MonkRoundhouse(this, true, !hasPunched, !hasDropkicked, jumpRemaining > 0);
		break;
	case NOJUMPROUNDHOUSE:
		changeAnimation("Roundhouse kick");
		delete currentAction;
		currentAction = new MonkRoundhouse(this, false, !hasPunched, !hasDropkicked, jumpRemaining > 0);
		break;
	case BASICATTACK:
		hasPunched = true;
		changeAnimation("ChargePunch");
		delete currentAction;
		currentAction = new MonkHoldAttack(this);
		break;
	case RELEASEATTACK:
		changeAnimation("Punch");
		delete currentAction;
		currentAction = new MonkPunch(this, jumpRemaining > 0);
		break;
	case CROUNCHATTACK:
		hasRoundhoused = false;
		hasPunched = false;
		hasDropkicked = false;
		changeAnimation("Low kick");
		delete currentAction;
		currentAction = new MonkRisingKick(this);
		break;
	case DIVEKICK:
		hasDropkicked = true;
		changeAnimation("Flying kick");
		delete currentAction;
		currentAction = new MonkDiveKick(this);
		break;
	}
}

std::string Monk::toString()
{
	return "Monk";
}

void Monk::addAnimations()
{
	sf::Texture* texture = &AssetManager::getTexture("monk");
	Spritesheet spritesheet = { texture, 4, 10 };

	Animation * anim = new Animation(spritesheet);
	anim->addFrame({ 0, 0 }, 100);
	anim->addFrame({ 1, 0 }, 150);
	anim->addFrame({ 2, 0 }, 150);
	anim->addFrame({ 3, 0 }, 100);
	anim->addFrame({ 2, 0 }, 150);
	anim->addFrame({ 1, 0 }, 150);
	addAnimation(anim, "Stand");

	anim = new Animation(spritesheet);
	anim->addFrame({ 5, 0 }, 100);
	anim->addFrame({ 6, 0 }, 100);
	anim->addFrame({ 7, 0 }, 75);
	anim->addFrame({ 8, 0 }, 50);
	anim->addFrame({ 9, 0 }, 50);
	addAnimation(anim, "Punch");

	anim = new Animation(spritesheet);
	anim->addFrame({ 4, 0 }, 200);
	addAnimation(anim, "ChargePunch");

	anim = new Animation(spritesheet);
	anim->addFrame({ 0, 1 }, 100);
	anim->addFrame({ 1, 1 }, 100);
	anim->addFrame({ 2, 1 }, 100);
	anim->addFrame({ 3, 1 }, 100);
	anim->addFrame({ 4, 1 }, 100);
	anim->addFrame({ 5, 1 }, 150);
	addAnimation(anim, "Walk");

	anim = new Animation(spritesheet);
	anim->addFrame({ 6, 1 }, 150);
	anim->addFrame({ 7, 1 }, 150);
	addAnimation(anim, "Jump");

	anim = new Animation(spritesheet);
	anim->addFrame({ 8, 1 }, 100);
	anim->addFrame({ 9, 1 }, 100);
	addAnimation(anim, "Fall");

	anim = new Animation(spritesheet);
	anim->addFrame({ 0, 2 }, 100);
	anim->addFrame({ 1, 2 }, 100);
	addAnimation(anim, "Flying kick");

	anim = new Animation(spritesheet);
	anim->addFrame({ 2, 2 }, 175);
	anim->addFrame({ 3, 2 }, -1);
	addAnimation(anim, "Crounch");

	anim = new Animation(spritesheet);
	anim->addFrame({ 4, 2 }, 50);
	anim->addFrame({ 5, 2 }, 75);
	anim->addFrame({ 6, 2 }, 75);
	anim->addFrame({ 7, 2 }, 50);
	anim->addFrame({ 8, 2 }, 25);
	addAnimation(anim, "Low kick");

	anim = new Animation(spritesheet);
	anim->addFrame({ 0, 3 }, 50);
	anim->addFrame({ 1, 3 }, 75);
	anim->addFrame({ 2, 3 }, 75);
	anim->addFrame({ 3, 3 }, 100);
	anim->addFrame({ 4, 3 }, 150);
	addAnimation(anim, "Roundhouse kick");

	anim = new Animation(spritesheet);
	anim->addFrame({ 5, 3 }, 150);
	anim->addFrame({ 6, 3 }, 150);
	addAnimation(anim, "Knockback");
}
