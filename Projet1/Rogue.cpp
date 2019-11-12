#include "Rogue.h"
#include "Animation.h"
#include "HeroActionsEnum.h"
#include "Standing.h"
#include "Walking.h"
#include "Crounching.h"
#include "Jumping.h"
#include "RogueAttack.h"

Rogue::Rogue() : Hero("Rogue", 20, 40)
{

	acc = 1000;
	maxVelX = 400;
	drag = 1200;
	jumpingStrength = 700;
	airdrag = 400;
	gravity = 150;

	setPosition(50, 200);

	addAnimations();
	CurrentAction = new Standing(this);
}

Rogue::~Rogue()
{

}

void Rogue::ChangeAction(int enumIndex)
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
	case CROUNCH:
		animator.ChangeAnimation("Crounch");
		delete CurrentAction;
		CurrentAction = new Crounching(this);
		break;
	case JUMP:
		animator.ChangeAnimation("Jump");
		delete CurrentAction;
		CurrentAction = new Jumping(this);
		break;
	case BASICATTACK:
		animator.ChangeAnimation("Attack");
		delete CurrentAction;
		CurrentAction = new RogueAttack(this);
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
	showTimes.push_back(200);
	indexes.push_back({ 1, 2 });
	showTimes.push_back(200);
	indexes.push_back({ 2, 2 });
	showTimes.push_back(200);
	indexes.push_back({ 3, 2 });
	showTimes.push_back(200);
	indexes.push_back({ 4, 2 });
	showTimes.push_back(200);
	indexes.push_back({ 5, 2 });
	showTimes.push_back(200);

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
	showTimes.push_back(100);
	indexes.push_back({ 1, 1 });
	showTimes.push_back(100);
	indexes.push_back({ 2, 1 });
	showTimes.push_back(100);
	indexes.push_back({ 3, 1 });
	showTimes.push_back(100);
	indexes.push_back({ 4, 1 });
	showTimes.push_back(100);
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