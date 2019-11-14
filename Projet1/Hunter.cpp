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

Hunter::Hunter() : Hero("Hunter", 50, 100)
{
	acc = 800;
	maxVelX = 350;
	drag = 1200;
	jumpingStrength = 600;
	airdrag = 400;
	gravity = 3000;

	setPosition(50, 200);

	AddAnimations();
	CurrentAction = new Standing(this);
}

Hunter::~Hunter()
{

}

void Hunter::ChangeAction(int enumIndex)
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
		CurrentAction = new Walking(this);
		break;
	case JUMP:
		animator.ChangeAnimation("JumpRise");
		delete CurrentAction;
		CurrentAction = new HunterJump(this);
		break;
	case SECONDJUMP:
		animator.ChangeAnimation("JumpMid");
		delete CurrentAction;
		CurrentAction = new HunterJumpMid(this);
		break;
	case FALL:
		animator.ChangeAnimation("Fall");
		delete CurrentAction;
		CurrentAction = new Falling(this);
		break;
	case CROUNCH:
		animator.ChangeAnimation("Crounch");
		delete CurrentAction;
		CurrentAction = new Crounching(this);
		break;
	case BASICATTACK:
		animator.ChangeAnimation("Shoot");
		delete CurrentAction;
		CurrentAction = new HunterShoot(this);
		break;
	}
}

void Hunter::AddAnimations()
{
	sf::Texture* texture = new Texture();
	texture->loadFromFile("Assets/SpriteSheet/Hunter.png");
	int nbRows = 2;
	int nbColums = 16;
	Spritesheet spritesheet = { texture, nbRows, nbColums };

	vector<Coord> indexes;
	vector<int> showTimes;

	indexes.push_back({ 15, 0 });
	showTimes.push_back(100);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes, false), "Stand");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 0, 1 });
	showTimes.push_back(25);
	indexes.push_back({ 1, 1 });
	showTimes.push_back(25);
	indexes.push_back({ 2, 1 });
	showTimes.push_back(25);
	indexes.push_back({ 3, 1 });
	showTimes.push_back(25);
	indexes.push_back({ 4, 1 });
	showTimes.push_back(25);
	indexes.push_back({ 5, 1 });
	showTimes.push_back(25);
	indexes.push_back({ 6, 1 });
	showTimes.push_back(25);
	indexes.push_back({ 7, 1 });
	showTimes.push_back(25);
	indexes.push_back({ 8, 1 });
	showTimes.push_back(25);
	indexes.push_back({ 9, 1 });
	showTimes.push_back(25);
	indexes.push_back({ 10, 1 });
	showTimes.push_back(25);
	indexes.push_back({ 11, 1 });
	showTimes.push_back(25);
	indexes.push_back({ 12, 1 });
	showTimes.push_back(25);
	indexes.push_back({ 13, 1 });
	showTimes.push_back(25);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes), "Walk");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 5, 0 });
	showTimes.push_back(150);
	indexes.push_back({ 6, 0 });
	showTimes.push_back(100);
	indexes.push_back({ 7, 0 });
	showTimes.push_back(100);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes, false), "Crounch");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 2, 0 });
	showTimes.push_back(100);
	indexes.push_back({ 3, 0 });
	showTimes.push_back(50);
	indexes.push_back({ 4, 0 });
	showTimes.push_back(100);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes, false), "CrounchShoot");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 12, 0 });
	showTimes.push_back(100);
	indexes.push_back({ 13, 0 });
	showTimes.push_back(50);
	indexes.push_back({ 14, 0 });
	showTimes.push_back(100);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes, false), "Shoot");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 10, 0 });
	showTimes.push_back(500);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes, false), "JumpRise");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 11, 0 });
	showTimes.push_back(500);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes, false), "JumpMid");

	indexes = vector<Coord>();
	showTimes = vector<int>();

	indexes.push_back({ 8, 0 });
	showTimes.push_back(150);
	indexes.push_back({ 9, 0 });
	showTimes.push_back(150);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes, false), "Fall");
}