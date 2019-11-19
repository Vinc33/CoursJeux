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
#include "Collider.h"

Monk::Monk() : Hero("Monk", 50, 30)
{
	acc = 700;
	maxVelX = 200;
	drag = 600;
	jumpingStrength = 700;
	airdrag = 200;
	gravity = 100;

	setPosition(50, 200);

	AddAnimations();
	CurrentAction = new Standing(this);

	hasRoundhoused = false;
	hasPunched = false;
	hasDropkicked = false;
	hasDoubleJumped = false;
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
		animatorFX.ChangeAnimation("Stand");
		delete CurrentAction;
		CurrentAction = new Standing(this);
		break;
	case WALK:
		animator.ChangeAnimation("Walk");
		animatorFX.ChangeAnimation("Walk");
		delete CurrentAction;
		CurrentAction = new MonkWalking(this);
		break;
	case CROUNCH:
		animator.ChangeAnimation("Crounch");
		animatorFX.ChangeAnimation("Crounch");
		delete CurrentAction;
		CurrentAction = new MonkCrounching(this, 0.0f);
		break;
	case JUMP:
		hasRoundhoused = false;
		hasPunched = false;
		hasDropkicked = false;
		animator.ChangeAnimation("Jump");
		animatorFX.ChangeAnimation("Jump");
		delete CurrentAction;
		CurrentAction = new MonkJump(this, !hasRoundhoused, !hasPunched, !hasDropkicked, !hasDoubleJumped);
		break;
	case SECONDJUMP:
		animator.ChangeAnimation("Fall");
		animatorFX.ChangeAnimation("Fall");
		delete CurrentAction;
		CurrentAction = new MonkSecondJump(this, !hasRoundhoused, !hasPunched, !hasDropkicked);
		break;
	case FALL:
		animator.ChangeAnimation("Jump");
		animatorFX.ChangeAnimation("Jump");
		delete CurrentAction;
		CurrentAction = new MonkFall(this, !hasRoundhoused, !hasPunched, !hasDropkicked, !hasDoubleJumped);
		break;
	case FALLJUMPREADY:
		animator.ChangeAnimation("Jump");
		animatorFX.ChangeAnimation("Jump");
		delete CurrentAction;
		CurrentAction = new MonkFall(this, !hasRoundhoused, !hasPunched, !hasDropkicked, !hasDoubleJumped, true);
		break;
	case ROUNDHOUSE:
		hasRoundhoused = true;
		animator.ChangeAnimation("Roundhouse kick");
		animatorFX.ChangeAnimation("Roundhouse kick");
		delete CurrentAction;
		CurrentAction = new MonkRoundhouse(this, true, !hasPunched, !hasDropkicked);
		break;
	case NOJUMPROUNDHOUSE:
		animator.ChangeAnimation("Roundhouse kick");
		animatorFX.ChangeAnimation("Roundhouse kick");
		delete CurrentAction;
		CurrentAction = new MonkRoundhouse(this, false, !hasPunched, !hasDropkicked);
		break;
	case BASICATTACK:
		hasPunched = true;
		animator.ChangeAnimation("ChargePunch");
		animatorFX.ChangeAnimation("ChargePunch");
		delete CurrentAction;
		CurrentAction = new MonkHoldAttack(this);
		break;
	case RELEASEATTACK:
		animator.ChangeAnimation("Punch");
		animatorFX.ChangeAnimation("Punch");
		delete CurrentAction;
		CurrentAction = new MonkPunch(this);
		break;
	case CROUNCHATTACK:
		hasRoundhoused = false;
		hasPunched = false;
		hasDropkicked = false;
		animator.ChangeAnimation("Low kick");
		animatorFX.ChangeAnimation("Low kick");
		delete CurrentAction;
		CurrentAction = new MonkRisingKick(this);
		break;
	case DIVEKICK:
		hasDropkicked = true;
		animator.ChangeAnimation("Flying kick");
		animatorFX.ChangeAnimation("Flying kick");
		delete CurrentAction;
		CurrentAction = new MonkDiveKick(this);
		break;
	}
}

void Monk::Draw(sf::RenderTarget& target)
{
	animator.Update();
	animatorFX.Update();
	Sprite* s = animator.GetSprite(isFacingLeft);
	Sprite* sFX = animatorFX.GetSprite(isFacingLeft);
	target.draw(*s, position.getTransform());
	target.draw(*sFX, position.getTransform());
}

void Monk::AddAnimations()
{
	sf::Texture* texture = new Texture();
	texture->loadFromFile("Assets\\SpriteSheet\\Monk.png");
	int nbRows = 4;
	int nbColums = 10;
	Spritesheet spritesheet = { texture, nbRows, nbColums};

	sf::Texture* textureFX = new Texture();
	textureFX->loadFromFile("Assets\\SpriteSheet\\MonkFX_Fiery.png");
	Spritesheet spritesheetFX = { textureFX, nbRows, nbColums };
	
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
	animatorFX.AddAnimation(new Animation(spritesheetFX, indexes, showTimes), "Stand");

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
	animatorFX.AddAnimation(new Animation(spritesheetFX, indexes, showTimes, false), "Punch");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 4, 0 });
	showTimes.push_back(200);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes, false), "ChargePunch");
	animatorFX.AddAnimation(new Animation(spritesheetFX, indexes, showTimes, false), "ChargePunch");

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
	animatorFX.AddAnimation(new Animation(spritesheetFX, indexes, showTimes), "Walk");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 6, 1 });
	showTimes.push_back(150);
	indexes.push_back({ 7, 1 });
	showTimes.push_back(150);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes), "Jump");
	animatorFX.AddAnimation(new Animation(spritesheetFX, indexes, showTimes), "Jump");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 8, 1 });
	showTimes.push_back(100);
	indexes.push_back({ 9, 1 });
	showTimes.push_back(100);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes), "Fall");
	animatorFX.AddAnimation(new Animation(spritesheetFX, indexes, showTimes), "Fall");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 0, 2 });
	showTimes.push_back(100);
	indexes.push_back({ 1, 2 });
	showTimes.push_back(100);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes), "Flying kick");
	animatorFX.AddAnimation(new Animation(spritesheetFX, indexes, showTimes), "Flying kick");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 2, 2 });
	showTimes.push_back(175);
	indexes.push_back({ 3, 2 });
	showTimes.push_back(150);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes, false), "Crounch");
	animatorFX.AddAnimation(new Animation(spritesheetFX, indexes, showTimes, false), "Crounch");

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
	animatorFX.AddAnimation(new Animation(spritesheetFX, indexes, showTimes, false), "Low kick");

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
	animatorFX.AddAnimation(new Animation(spritesheetFX, indexes, showTimes, false), "Roundhouse kick");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 5, 3 });
	showTimes.push_back(150);
	indexes.push_back({ 6, 3 });
	showTimes.push_back(150);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes), "Knockback");
	animatorFX.AddAnimation(new Animation(spritesheetFX, indexes, showTimes), "Knockback");
}
