#include "ThrownAxe.h"
#include "Manager\AssetManager.h"


ThrownAxe::ThrownAxe(int initialSpeed)
{
	sf::Texture* texture = &AssetManager::getTexture("axe");
	int nbRows = 2;
	int nbColums = 8;
	Spritesheet spritesheet = { texture, nbRows, nbColums };

	std::vector<Coord> indexes;
	std::vector<int> showTimes;

	indexes.push_back({ 0, 0 });
	showTimes.push_back(31);
	indexes.push_back({ 1, 0 });
	showTimes.push_back(31);
	indexes.push_back({ 2, 0 });
	showTimes.push_back(31);
	indexes.push_back({ 3, 0 });
	showTimes.push_back(31);
	indexes.push_back({ 4, 0 });
	showTimes.push_back(31);
	indexes.push_back({ 5, 0 });
	showTimes.push_back(31);
	indexes.push_back({ 6, 0 });
	showTimes.push_back(31);
	indexes.push_back({ 7, 0 });
	showTimes.push_back(31);
	indexes.push_back({ 0, 1 });
	showTimes.push_back(31);
	indexes.push_back({ 1, 1 });
	showTimes.push_back(31);
	indexes.push_back({ 2, 1 });
	showTimes.push_back(31);
	indexes.push_back({ 3, 1 });
	showTimes.push_back(31);
	indexes.push_back({ 4, 1 });
	showTimes.push_back(31);
	indexes.push_back({ 5, 1 });
	showTimes.push_back(31);
	indexes.push_back({ 6, 1 });
	showTimes.push_back(31);
	indexes.push_back({ 7, 1 });
	showTimes.push_back(31);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes), "Roll");
	animator.JumpToFrame(14);

	maxVelX = 10000;
	velX = (float)initialSpeed;
	jumpingStrength = 700;
	airdrag = 400;
	gravity = 2000;

	jump();

	if (initialSpeed < 0)
		imageReversed = true;
}

ThrownAxe::~ThrownAxe()
{
}

void ThrownAxe::update()
{
	EntityPhysic::update();
	EntityCollision::update();
}
