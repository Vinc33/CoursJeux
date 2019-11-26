#include "HandBomb.h"
#include "InputManager.h"


HandBomb::HandBomb(float initialSpeed)
{
	addAnimations();

	maxVelX = 10000;
	velX = (float)initialSpeed;
	jumpingStrength = 300;
	airdrag = 100;
	gravity = 1250;

	jump();

	if (initialSpeed < 0)
		imageReversed = true;
}


HandBomb::~HandBomb()
{
}

void HandBomb::update()
{
	EntityPhysic::update();

	if (!InputManager::GetKeyState(B))
	{
		isAirborne = false;
		velY = 0;
		velX = 0;
		animator.ChangeAnimation("Explode");
	}
}

void HandBomb::addAnimations()
{
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("Assets/ToolAndMagic/SmallBomb.png");
	int nbRows = 4;
	int nbColums = 3;
	Spritesheet spritesheet = { texture, nbRows, nbColums };

	std::vector<Coord> indexes;
	std::vector<int> showTimes;

	indexes.push_back({ 0, 0 });
	showTimes.push_back(45);
	indexes.push_back({ 1, 0 });
	showTimes.push_back(45);
	indexes.push_back({ 2, 0 });
	showTimes.push_back(45);

	indexes.push_back({ 0, 1 });
	showTimes.push_back(45);
	indexes.push_back({ 1, 1 });
	showTimes.push_back(45);
	indexes.push_back({ 2, 1 });
	showTimes.push_back(45);

	indexes.push_back({ 0, 2 });
	showTimes.push_back(45);
	indexes.push_back({ 1, 2 });
	showTimes.push_back(45);
	indexes.push_back({ 2, 2 });
	showTimes.push_back(45);

	indexes.push_back({ 0, 3 });
	showTimes.push_back(45);
	indexes.push_back({ 1, 3 });
	showTimes.push_back(45);
	indexes.push_back({ 2, 3 });
	showTimes.push_back(45);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes), "Roll");

	//TODO ADD THIS
	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes), "Explode");
}
