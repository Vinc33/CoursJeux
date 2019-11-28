#include "pingouin.h"
#include "Animation.h"
#include "Jumping.h"
#include "HeroActionsEnum.h"
#include "Walking.h"
#include "Standing.h"
#include "PingouinCrouch.h"
#include "PingouinAttack.h"

Pingouin::Pingouin() : Hero("Pingouin", 50, 30)
{
	acc = 1000;
	maxVelX = 500;
	drag = 1200;
	jumpingStrength = 700;
	airdrag = 400;
	gravity = 150;

	setPosition(50, 200);

	addAnimations();
	CurrentAction = new Standing(this);
}

Pingouin::~Pingouin()
{
}

void Pingouin::ChangeAction(int enumIndex)
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
		CurrentAction = new PingouinCrouch(this);
		break;
	case JUMP:
		animator.ChangeAnimation("Jump");
		delete CurrentAction;
		CurrentAction = new Jumping(this);
		break;
	case BASICATTACK:
		animator.ChangeAnimation("Attack");
		delete CurrentAction;
		CurrentAction = new PingouinAttack(this);
		break;
	}

}


void Pingouin::addAnimations()
{
		sf::Texture* texture = new Texture();
		texture->loadFromFile("Assets/SpriteSheetJeuxCombat/pingouin/pingouinRunRight-16.png");
		int nbRows = 1;
		int nbColums = 16;
		Spritesheet spritesheet = { texture, nbRows, nbColums };

		vector<Coord> indexes;
		vector<int> showTimes;

		indexes.push_back({ 0, 1 });
		showTimes.push_back(200);
		indexes.push_back({ 0, 2 });
		showTimes.push_back(200);
		indexes.push_back({ 0, 3 });
		showTimes.push_back(200);
		indexes.push_back({ 0, 4 });
		showTimes.push_back(200);
		indexes.push_back({ 0, 5 });
		showTimes.push_back(200);
		indexes.push_back({ 0, 6 });
		showTimes.push_back(200);
		indexes.push_back({ 0, 7 });
		showTimes.push_back(200);
		indexes.push_back({ 0, 8 });
		showTimes.push_back(200);
		indexes.push_back({ 0, 9 });
		showTimes.push_back(200);
		indexes.push_back({ 0, 10 });
		showTimes.push_back(200);
		indexes.push_back({ 0, 11 });
		showTimes.push_back(200);
		indexes.push_back({ 0, 12 });
		showTimes.push_back(200);
		indexes.push_back({ 0, 13 });
		showTimes.push_back(200);
		indexes.push_back({ 0, 14 });
		showTimes.push_back(200);
		indexes.push_back({ 0, 15 });
		showTimes.push_back(200);
		indexes.push_back({ 0, 16 });
		showTimes.push_back(200);

		animator.AddAnimation(new Animation(spritesheet, indexes, showTimes, false), "Run");

		texture->loadFromFile("Assets/SpriteSheetJeuxCombat/pingouin/pingouinBatAttackRight-15.png");
		nbRows = 1;
		nbColums = 15;
		spritesheet = { texture, nbRows, nbColums };


		indexes = vector<Coord>();
		showTimes = vector<int>();

		indexes.push_back({ 1, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 2, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 3, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 4, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 5, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 6, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 7, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 8, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 9, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 10, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 11, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 12, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 13, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 14, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 15, 0 });
		showTimes.push_back(200);

		animator.AddAnimation(new Animation(spritesheet, indexes, showTimes, false), "BatAttack");

		texture->loadFromFile("Assets/SpriteSheetJeuxCombat/pingouin/pingouinCrouchGunRight-8.png");
		nbRows = 1;
		nbColums = 8;
		spritesheet = { texture, nbRows, nbColums };

		indexes = vector<Coord>();
		showTimes = vector<int>();

		indexes.push_back({ 1, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 2, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 3, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 4, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 5, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 6, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 7, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 8, 0 });
		showTimes.push_back(200);

		animator.AddAnimation(new Animation(spritesheet, indexes, showTimes, false), "CrouchGun");

		texture->loadFromFile("Assets/SpriteSheetJeuxCombat/pingouin/pingouinCrouchIdleRight-14.png");
		nbRows = 1;
		nbColums = 14;
		spritesheet = { texture, nbRows, nbColums };

		indexes = vector<Coord>();
		showTimes = vector<int>();

		indexes.push_back({ 1, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 2, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 3, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 4, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 5, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 6, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 7, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 8, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 9, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 10, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 11, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 12, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 13, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 14, 0 });
		showTimes.push_back(200);

		animator.AddAnimation(new Animation(spritesheet, indexes, showTimes, false), "CrouchIdle");

		texture->loadFromFile("Assets/SpriteSheetJeuxCombat/pingouin/pingouinCrouchingRight-16.png");
		nbRows = 1;
		nbColums = 16;
		spritesheet = { texture, nbRows, nbColums };

		indexes = vector<Coord>();
		showTimes = vector<int>();

		indexes.push_back({ 1, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 2, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 3, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 4, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 5, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 6, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 7, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 8, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 9, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 10, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 11, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 12, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 13, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 14, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 15, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 16, 0 });
		showTimes.push_back(200);

		animator.AddAnimation(new Animation(spritesheet, indexes, showTimes), "Crouching");

		texture->loadFromFile("Assets/SpriteSheetJeuxCombat/pingouin/pingouinHurtRight-8.png");
		nbRows = 1;
		nbColums = 8;
		spritesheet = { texture, nbRows, nbColums };

		indexes = vector<Coord>();
		showTimes = vector<int>();

		indexes.push_back({ 1, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 2, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 3, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 4, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 5, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 6, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 7, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 8, 0 });
		showTimes.push_back(200);

		animator.AddAnimation(new Animation(spritesheet, indexes, showTimes, false), "Hurt");

		texture->loadFromFile("Assets/SpriteSheetJeuxCombat/pingouin/pingouinIdleRight-16.png");
		nbRows = 1;
		nbColums = 16;
		spritesheet = { texture, nbRows, nbColums };

		indexes = vector<Coord>();
		showTimes = vector<int>();

		indexes.push_back({ 1, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 2, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 3, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 4, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 5, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 6, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 7, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 8, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 9, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 10, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 11, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 12, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 13, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 14, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 15, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 16, 0 });
		showTimes.push_back(200);

		animator.AddAnimation(new Animation(spritesheet, indexes, showTimes), "Idle");

		texture->loadFromFile("Assets/SpriteSheetJeuxCombat/pingouin/pingouinJumpRight-14.png");
		nbRows = 1;
		nbColums = 14;
		spritesheet = { texture, nbRows, nbColums };

		indexes = vector<Coord>();
		showTimes = vector<int>();

		indexes.push_back({ 1, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 2, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 3, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 4, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 5, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 6, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 7, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 8, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 9, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 10, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 11, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 12, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 13, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 14, 0 });
		showTimes.push_back(200);

		animator.AddAnimation(new Animation(spritesheet, indexes, showTimes), "Jump");

		texture->loadFromFile("Assets/SpriteSheetJeuxCombat/pingouin/pingouinRunNGunRight-16.png");
		nbRows = 1;
		nbColums = 16;
		spritesheet = { texture, nbRows, nbColums };

		indexes = vector<Coord>();
		showTimes = vector<int>();

		indexes.push_back({ 1, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 2, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 3, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 4, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 5, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 6, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 7, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 8, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 9, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 10, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 11, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 12, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 13, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 14, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 15, 0 });
		showTimes.push_back(200);
		indexes.push_back({ 16, 0 });
		showTimes.push_back(200);

		animator.AddAnimation(new Animation(spritesheet, indexes, showTimes), "RunNGun");

}