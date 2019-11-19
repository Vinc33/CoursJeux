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

Monk::Monk() : Hero("Monk", 50, 30)
{
	acc = 700;
	maxVelX = 200;
	drag = 600;
	jumpingStrength = 700;
	airdrag = 200;
	gravity = 1500;

	setPosition(50, 200);

	AddAnimations();
	CurrentAction = new Standing(this);

	hasRoundhoused = false;
	hasPunched = false;
	hasDropkicked = false;
	maxNumberOfJumps = 4;
	jumpRemaining = maxNumberOfJumps;

	particlesMoveWithParent = true;

	srand((unsigned)time(NULL));
}

Monk::~Monk()
{
}

void Monk::ChangeAction(int enumIndex)
{
	switch ((PlayerAction)enumIndex)
	{
	case STAND:
		animator.ChangeAnimation("Stand");
		delete CurrentAction;
		CurrentAction = new Standing(this);
		break;
	case WALK:
		animator.ChangeAnimation("Walk");
		delete CurrentAction;
		CurrentAction = new MonkWalking(this);
		break;
	case CROUNCH:
		animator.ChangeAnimation("Crounch");
		delete CurrentAction;
		CurrentAction = new MonkCrounching(this, 0.0f);
		break;
	case JUMP:
		hasRoundhoused = false;
		hasPunched = false;
		hasDropkicked = false;
		animator.ChangeAnimation("Jump");
		delete CurrentAction;
		jump();
		jumpRemaining = maxNumberOfJumps - 1;
		CurrentAction = new MonkJump(this, !hasRoundhoused, !hasPunched, !hasDropkicked, jumpRemaining > 0);
		break;
	case SECONDJUMP:
		animator.ChangeAnimation("Fall");
		delete CurrentAction;
		jumpRemaining--;
		velY = 0;
		jump(0.9f);
		CurrentAction = new MonkFall(this, !hasRoundhoused, !hasPunched, !hasDropkicked, false);
		break;
	case FALL:
		if (jumpRemaining > 0)
			animator.ChangeAnimation("Jump");
		else
			animator.ChangeAnimation("Fall");
		delete CurrentAction;
		CurrentAction = new MonkFall(this, !hasRoundhoused, !hasPunched, !hasDropkicked, jumpRemaining > 0);
		break;
	case ROUNDHOUSE:
		hasRoundhoused = true;
		animator.ChangeAnimation("Roundhouse kick");
		delete CurrentAction;
		CurrentAction = new MonkRoundhouse(this, true, !hasPunched, !hasDropkicked, jumpRemaining > 0);
		break;
	case NOJUMPROUNDHOUSE:
		animator.ChangeAnimation("Roundhouse kick");
		delete CurrentAction;
		CurrentAction = new MonkRoundhouse(this, false, !hasPunched, !hasDropkicked, jumpRemaining > 0);
		break;
	case BASICATTACK:
		hasPunched = true;
		animator.ChangeAnimation("ChargePunch");
		delete CurrentAction;
		CurrentAction = new MonkHoldAttack(this);
		break;
	case RELEASEATTACK:
		animator.ChangeAnimation("Punch");
		delete CurrentAction;
		CurrentAction = new MonkPunch(this, jumpRemaining > 0);
		break;
	case CROUNCHATTACK:
		hasRoundhoused = false;
		hasPunched = false;
		hasDropkicked = false;
		animator.ChangeAnimation("Low kick");
		delete CurrentAction;
		CurrentAction = new MonkRisingKick(this);
		break;
	case DIVEKICK:
		hasDropkicked = true;
		animator.ChangeAnimation("Flying kick");
		delete CurrentAction;
		CurrentAction = new MonkDiveKick(this);
		break;
	}
}

void Monk::AddAnimations()
{
	sf::Texture* texture = new Texture();
	texture->loadFromFile("Assets\\SpriteSheet\\Monk.png");
	int nbRows = 4;
	int nbColums = 10;
	Spritesheet spritesheet = { texture, nbRows, nbColums};

	vector<Coord> indexes;
	vector<int> showTimes;

	indexes.push_back({ 0, 0 });
	showTimes.push_back(100);
	indexes.push_back({ 1, 0 });
	showTimes.push_back(150);
	indexes.push_back({ 2, 0 });
	showTimes.push_back(150);
	indexes.push_back({ 3, 0 });
	showTimes.push_back(100);
	indexes.push_back({ 2, 0 });
	showTimes.push_back(150);
	indexes.push_back({ 1, 0 });
	showTimes.push_back(150);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes), "Stand");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 5, 0 });
	showTimes.push_back(100);
	indexes.push_back({ 6, 0 });
	showTimes.push_back(100);
	indexes.push_back({ 7, 0 });
	showTimes.push_back(75);
	indexes.push_back({ 8, 0 });
	showTimes.push_back(50);
	indexes.push_back({ 9, 0 });
	showTimes.push_back(50);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes, false), "Punch");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 4, 0 });
	showTimes.push_back(200);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes, false), "ChargePunch");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 0, 1 });
	showTimes.push_back(100);
	indexes.push_back({ 1, 1 });
	showTimes.push_back(100);
	indexes.push_back({ 2, 1 });
	showTimes.push_back(150);
	indexes.push_back({ 3, 1 });
	showTimes.push_back(100);
	indexes.push_back({ 4, 1 });
	showTimes.push_back(100);
	indexes.push_back({ 5, 1 });
	showTimes.push_back(150);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes), "Walk");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 6, 1 });
	showTimes.push_back(150);
	indexes.push_back({ 7, 1 });
	showTimes.push_back(150);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes), "Jump");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 8, 1 });
	showTimes.push_back(100);
	indexes.push_back({ 9, 1 });
	showTimes.push_back(100);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes), "Fall");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 0, 2 });
	showTimes.push_back(100);
	indexes.push_back({ 1, 2 });
	showTimes.push_back(100);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes), "Flying kick");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 2, 2 });
	showTimes.push_back(175);
	indexes.push_back({ 3, 2 });
	showTimes.push_back(150);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes, false), "Crounch");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 4, 2 });
	showTimes.push_back(50);
	indexes.push_back({ 5, 2 });
	showTimes.push_back(75);
	indexes.push_back({ 6, 2 });
	showTimes.push_back(75);
	indexes.push_back({ 7, 2 });
	showTimes.push_back(50);
	indexes.push_back({ 8, 2 });
	showTimes.push_back(25);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes, false), "Low kick");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 0, 3 });
	showTimes.push_back(50);
	indexes.push_back({ 1, 3 });
	showTimes.push_back(75);
	indexes.push_back({ 2, 3 });
	showTimes.push_back(75);
	indexes.push_back({ 3, 3 });
	showTimes.push_back(100);
	indexes.push_back({ 4, 3 });
	showTimes.push_back(150);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes, false), "Roundhouse kick");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 5, 3 });
	showTimes.push_back(150);
	indexes.push_back({ 6, 3 });
	showTimes.push_back(150);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes), "Knockback");
}
