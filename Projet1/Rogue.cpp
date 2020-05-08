#include "Rogue.h"
#include "TimeManager.h"
#include "Animation.h"

#include "RogueStanding.h"
#include "RogueWalk.h"
#include "RogueCrounch.h"
#include "RogueJump.h"
#include "RogueAttack.h"
#include "RogueRoll.h"
#include "RogueSomersault.h"

#include "RogueThrowKnife.h"
#include "RogueThrowAxe.h"
#include "RogueThrowCaltrops.h"
#include "RogueThrowSpear.h"
#include "RogueThrowSmallBomb.h"
#include "RogueThrowSawBlade.h"

#include "Manager\AssetManager.h"

Rogue::Rogue(short playerID) : Hero("Rogue", playerID, 20, 40)
{

	acc = 500;
	maxVelX = 250;
	drag = 800;
	jumpingStrength = 350;
	airdrag = 200;
	gravity = 1000;

	addAnimations();
	setPosition(50, 200);

	currentAction = new RogueStanding(this);
	delayedActionTimer = 0.0f;
	nextAction = PlayerAction::STAND;


	attackCooldown = 0.75f;
	itemCooldown = 0.2f;
	downToolCooldown = 0.75f;
	upToolCooldown = 0.75f;
	frontToolCooldown = 0.75f;
	standToolCooldown = 0.75f;

	equipedUp = AXE;
	equipedDown = SPEAR;
	equipedFront = KNIFE;
	equipedStand = CALTROPS;
}

Rogue::~Rogue()
{

}

void Rogue::update()
{
	Entity::update();
	downToolTimer -= TimeManager::DeltaTime;
	upToolTimer -= TimeManager::DeltaTime;
	frontToolTimer -= TimeManager::DeltaTime;
	standToolTimer -= TimeManager::DeltaTime;
	itemTimer -= TimeManager::DeltaTime;
	attackTimer -= TimeManager::DeltaTime;
	if (checkForDelayedAction)
	{
		delayedActionTimer -= TimeManager::DeltaTime;
		if (delayedActionTimer < 0)
		{
			checkForDelayedAction = false;
			changeAction(nextAction);
		}
	}
}

std::string Rogue::toString()
{
	return "Rogue";
}

void Rogue::changeAction(int enumIndex)
{
	switch ((PlayerAction)enumIndex)
	{
	case STAND:
		changeAnimation("Stand");
		delete currentAction;
		currentAction = new RogueStanding(this);
		break;
	case WALK:
		changeAnimation("Walk");
		delete currentAction;
		currentAction = new RogueWalk(this);
		break;
	case CROUNCH:
		changeAnimation("Crounch");
		delete currentAction;
		currentAction = new RogueCrounch(this);
		break;
	case JUMP:
		changeAnimation("Jump");
		delete currentAction;
		currentAction = new RogueJump(this);
		break;
	case FALL:
		changeAnimation("Jump");
		delete currentAction;
		currentAction = new RogueJump(this, false, false);
		break;
	case FALLMAYROLL:
		changeAnimation("Jump");
		delete currentAction;
		currentAction = new RogueJump(this, false);
		break;
	case BASICATTACK:
		if (attackTimer < 0)
		{
			attackTimer = attackCooldown;
			changeAnimation("Attack");
			delete currentAction;
			currentAction = new RogueAttack(this);
		}
		break;
	case ROLL:
		changeAnimation("Roll");
		delete currentAction;
		currentAction = new RogueRoll(this);
		break;
	case SOMERSAULT:
		changeAnimation("Roll");
		delete currentAction;
		currentAction = new RogueSomersault(this);
		break;
	case CHAINEDJUMP:
		changeAnimation("Walk");
		delete currentAction;
		currentAction = new RogueWalk(this);
		nextAction = PlayerAction::JUMP;
		delayedActionTimer = .12f;
		checkForDelayedAction = true;
		break;
	case ITEMDOWN:
		if (downToolTimer < 0)
		{
			downToolTimer = downToolCooldown;
			useWeapon(equipedDown);
		}
		break;
	case ITEMUP:
		if (upToolTimer < 0)
		{
			upToolTimer = upToolCooldown;
			useWeapon(equipedUp);
		}
		break;
	case ITEMFRONT:
		if (frontToolTimer < 0)
		{
			frontToolTimer = frontToolCooldown;
			useWeapon(equipedFront);
		}
		break;
	case ITEMSTAND:
		if (standToolTimer < 0)
		{
			standToolTimer = standToolCooldown;
			useWeapon(equipedStand);
		}
		break;
	}
}

void Rogue::useWeapon(RogueWeapon rw)
{
	if (itemTimer < 0)
	{
		itemTimer = itemCooldown;
		attackTimer = attackCooldown / 2;
		delete currentAction;
		changeAnimation("Item");
		switch (rw)
		{
		case NONE:
			break;
		case KNIFE:
			currentAction = new RogueThrowKnife(this);
			break;
		case AXE:
			currentAction = new RogueThrowAxe(this);
			break;
		case CALTROPS:
			currentAction = new RogueThrowCaltrops(this);
			break;
		case SPEAR:
			currentAction = new RogueThrowSpear(this);
			break;
		case HANDBOMB:
			currentAction = new RogueThrowSmallBomb(this);
			break;
		case SAWBLADE:
			currentAction = new RogueThrowSawBlade(this);
			break;
		default:
			break;
		}
	}
}

void Rogue::addAnimations()
{
	sf::Texture* texture = &AssetManager::getTexture("rogue");
	Spritesheet spritesheet = { texture, 5, 8 };

	Animation * anim = new Animation(spritesheet);
	anim->addFrame({ 0, 2 }, 150);
	anim->addFrame({ 1, 2 }, 150);
	anim->addFrame({ 2, 2 }, 150);
	anim->addFrame({ 3, 2 }, 150);
	anim->addFrame({ 4, 2 }, 150);
	anim->addFrame({ 5, 2 }, 150);
	addAnimation(anim, "Stand");

	anim = new Animation(spritesheet);
	anim->addFrame({ 0, 0 }, 75);
	anim->addFrame({ 1, 0 }, 50);
	anim->addFrame({ 2, 0 }, 50);
	anim->addFrame({ 3, 0 }, 75);
	anim->addFrame({ 4, 0 }, 100);
	addAnimation(anim, "Attack");

	anim = new Animation(spritesheet);
	anim->addFrame({ 1, 0 }, 100);
	anim->addFrame({ 2, 0 }, 75);
	anim->addFrame({ 3, 0 }, 75);
	anim->addFrame({ 4, 0 }, 75);
	addAnimation(anim, "Item");

	anim = new Animation(spritesheet);
	anim->addFrame({ 5, 0 }, 100);
	anim->addFrame({ 6, 0 }, 100);
	anim->addFrame({ 7, 0 }, 100);
	addAnimation(anim, "Knockback");

	anim = new Animation(spritesheet);
	anim->addFrame({ 0, 1 }, 25);
	anim->addFrame({ 1, 1 }, 200);
	anim->addFrame({ 2, 1 }, 175);
	anim->addFrame({ 3, 1 }, 150);
	anim->addFrame({ 4, 1 }, 125);
	anim->addFrame({ 5, 1 }, 100);
	anim->addFrame({ 6, 1 }, 100);
	anim->addFrame({ 7, 1 }, 100);
	addAnimation(anim, "Roll");

	anim = new Animation(spritesheet);
	anim->addFrame({ 6, 2 }, 100);
	anim->addFrame({ 7, 2 }, 100);
	addAnimation(anim, "Jump");

	anim = new Animation(spritesheet);
	anim->addFrame({ 6, 3 }, 100);
	anim->addFrame({ 7, 3 }, -1);
	addAnimation(anim, "Crounch");

	anim = new Animation(spritesheet);
	anim->addFrame({ 0, 3 }, 100);
	anim->addFrame({ 1, 3 }, 100);
	anim->addFrame({ 2, 3 }, 100);
	anim->addFrame({ 3, 3 }, 100);
	anim->addFrame({ 4, 3 }, 100);
	anim->addFrame({ 5, 3 }, 100);
	addAnimation(anim, "Walk");

	anim = new Animation(spritesheet);
	anim->addFrame({ 0, 4 }, 100);
	anim->addFrame({ 1, 4 }, 100);
	addAnimation(anim, "Fall");
}