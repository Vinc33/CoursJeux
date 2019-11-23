#include "Rogue.h"
#include "TimeManager.h"
#include "Animation.h"
#include "HeroActionsEnum.h"
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

Rogue::Rogue() : Hero("Rogue", 20, 40)
{

	acc = 1000;
	maxVelX = 500;
	drag = 1600;
	jumpingStrength = 700;
	airdrag = 400;
	gravity = 2000;
	//gravity = 1000;

	setPosition(50, 200);

	addAnimations();
	CurrentAction = new RogueStanding(this);

	downToolTimer = 0.0f;
	downToolCooldown = 0.75f;

	upToolTimer = 0.0f;
	upToolCooldown = 0.75f;

	frontToolTimer = 0.0f;
	frontToolCooldown = 0.75f;

	standToolTimer = 0.0f;
	standToolCooldown = 0.75f;

	equipedUp = AXE;
	equipedDown = CALTROPS;
	equipedFront = KNIFE;
	equipedStand = KNIFE;
}

Rogue::~Rogue()
{

}

void Rogue::Update()
{
	Entity::Update();
	downToolTimer -= TimeManager::DeltaTime;
	upToolTimer -= TimeManager::DeltaTime;
	frontToolTimer -= TimeManager::DeltaTime;
	standToolTimer -= TimeManager::DeltaTime;
}

void Rogue::ChangeAction(int enumIndex)
{
	switch ((PlayerAction)enumIndex)
	{
	case STAND:
		animator.ChangeAnimation("Stand");
		delete CurrentAction;
		CurrentAction = new RogueStanding(this);
		break;
	case WALK:
		animator.ChangeAnimation("Walk");
		delete CurrentAction;
		CurrentAction = new RogueWalk(this);
		break;
	case CROUNCH:
		animator.ChangeAnimation("Crounch");
		delete CurrentAction;
		CurrentAction = new RogueCrounch(this);
		break;
	case JUMP:
		animator.ChangeAnimation("Jump");
		delete CurrentAction;
		CurrentAction = new RogueJump(this);
		break;
	case FALL:
		animator.ChangeAnimation("Jump");
		delete CurrentAction;
		CurrentAction = new RogueJump(this, false, false);
		break;
	case FALLMAYROLL:
		animator.ChangeAnimation("Jump");
		delete CurrentAction;
		CurrentAction = new RogueJump(this, false);
		break;
	case BASICATTACK:
		animator.ChangeAnimation("Attack");
		delete CurrentAction;
		CurrentAction = new RogueAttack(this);
		break;
	case ROLL:
		animator.ChangeAnimation("Roll");
		delete CurrentAction;
		CurrentAction = new RogueRoll(this);
		break;
	case SOMERSAULT:
		animator.ChangeAnimation("Roll");
		delete CurrentAction;
		CurrentAction = new RogueSomersault(this);
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
	delete CurrentAction;
	animator.ChangeAnimation("Item");
	switch (rw)
	{
	case NONE:
		break;
	case KNIFE:
		CurrentAction = new RogueThrowKnife(this);
		break;
	case AXE:
		CurrentAction = new RogueThrowAxe(this);
		break;
	case CALTROPS:
		CurrentAction = new RogueThrowCaltrops(this);
		break;
	default:
		break;
	}
}

void Rogue::addAnimations()
{
	sf::Texture* texture = new Texture();
	texture->loadFromFile("Assets/SpriteSheet/Rogue.png");
	int nbRows = 5;
	int nbColums = 8;
	Spritesheet spritesheet = { texture, nbRows, nbColums };

	vector<Coord> indexes;
	vector<int> showTimes;

	indexes.push_back({ 0, 2 });
	showTimes.push_back(150);
	indexes.push_back({ 1, 2 });
	showTimes.push_back(150);
	indexes.push_back({ 2, 2 });
	showTimes.push_back(150);
	indexes.push_back({ 3, 2 });
	showTimes.push_back(150);
	indexes.push_back({ 4, 2 });
	showTimes.push_back(150);
	indexes.push_back({ 5, 2 });
	showTimes.push_back(150);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes), "Stand");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 0, 0 });
	showTimes.push_back(75);
	indexes.push_back({ 1, 0 });
	showTimes.push_back(50);
	indexes.push_back({ 2, 0 });
	showTimes.push_back(50);
	indexes.push_back({ 3, 0 });
	showTimes.push_back(75);
	indexes.push_back({ 4, 0 });
	showTimes.push_back(100);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes, false), "Attack");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 1, 0 });
	showTimes.push_back(100);
	indexes.push_back({ 2, 0 });
	showTimes.push_back(75);
	indexes.push_back({ 3, 0 });
	showTimes.push_back(75);
	indexes.push_back({ 4, 0 });
	showTimes.push_back(75);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes, false), "Item");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 5, 0 });
	showTimes.push_back(100);
	indexes.push_back({ 6, 0 });
	showTimes.push_back(100);
	indexes.push_back({ 7, 0 });
	showTimes.push_back(100);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes, false), "Knockback");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 0, 1 });
	showTimes.push_back(25);
	indexes.push_back({ 1, 1 });
	showTimes.push_back(200);
	indexes.push_back({ 2, 1 });
	showTimes.push_back(175);
	indexes.push_back({ 3, 1 });
	showTimes.push_back(150);
	indexes.push_back({ 4, 1 });
	showTimes.push_back(125);
	indexes.push_back({ 5, 1 });
	showTimes.push_back(100);
	indexes.push_back({ 6, 1 });
	showTimes.push_back(100);
	indexes.push_back({ 7, 1 });
	showTimes.push_back(100);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes, false), "Roll");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 6, 2 });
	showTimes.push_back(100);
	indexes.push_back({ 7, 2 });
	showTimes.push_back(100);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes), "Jump");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 6, 3 });
	showTimes.push_back(100);
	indexes.push_back({ 7, 3 });
	showTimes.push_back(100);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes, false), "Crounch");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 0, 3 });
	showTimes.push_back(100);
	indexes.push_back({ 1, 3 });
	showTimes.push_back(100);
	indexes.push_back({ 2, 3 });
	showTimes.push_back(100);
	indexes.push_back({ 3, 3 });
	showTimes.push_back(100);
	indexes.push_back({ 4, 3 });
	showTimes.push_back(100);
	indexes.push_back({ 5, 3 });
	showTimes.push_back(100);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes), "Walk");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 0, 4 });
	showTimes.push_back(100);
	indexes.push_back({ 1, 4 });
	showTimes.push_back(100);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes), "Fall");
}