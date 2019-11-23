#include "Caltrops.h"



Caltrops::Caltrops(float initialSpeed)
{
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("Assets/ToolAndMagic/Caltrops.png");
	Spritesheet spritesheet = { texture, 4, 3 };

	std::vector<Coord> indexes;
	std::vector<int> showTimes;

	indexes.push_back({ 0, 0 });
	showTimes.push_back(31);
	indexes.push_back({ 1, 0 });
	showTimes.push_back(31);
	indexes.push_back({ 2, 0 });
	showTimes.push_back(31);

	indexes.push_back({ 0, 1 });
	showTimes.push_back(31);
	indexes.push_back({ 1, 1 });
	showTimes.push_back(31);
	indexes.push_back({ 2, 1 });
	showTimes.push_back(31);

	indexes.push_back({ 0, 2 });
	showTimes.push_back(31);
	indexes.push_back({ 1, 2 });
	showTimes.push_back(31);
	indexes.push_back({ 2, 2 });
	showTimes.push_back(31);

	indexes.push_back({ 0, 3 });
	showTimes.push_back(31);
	indexes.push_back({ 1, 3 });
	showTimes.push_back(31);
	indexes.push_back({ 2, 3 });
	showTimes.push_back(31);

	animator.AddAnimation(new Animation(spritesheet, indexes, showTimes), "Roll");
	animator.JumpToFrame(rand() % 12);

	sf::Texture* texture2 = new sf::Texture();
	texture2->loadFromFile("Assets/ToolAndMagic/Caltrops_Deployed.png");
	Spritesheet spritesheet2 = { texture2, 3, 3 };


	indexes = std::vector<Coord>();
	showTimes = std::vector<int>();

	indexes.push_back({ 0, 0 });
	showTimes.push_back(-1);
	indexes.push_back({ 1, 0 });
	showTimes.push_back(-1);
	indexes.push_back({ 2, 0 });
	showTimes.push_back(-1);
	indexes.push_back({ 0, 1 });
	showTimes.push_back(-1);
	indexes.push_back({ 1, 1 });
	showTimes.push_back(-1);
	indexes.push_back({ 2, 1 });
	showTimes.push_back(-1);
	indexes.push_back({ 0, 2 });
	showTimes.push_back(-1);
	indexes.push_back({ 1, 2 });
	showTimes.push_back(-1);
	indexes.push_back({ 2, 2 });
	showTimes.push_back(-1);

	animator.AddAnimation(new Animation(spritesheet2, indexes, showTimes), "Land");


	maxVelX = 10000;
	velX = (float)initialSpeed;
	jumpingStrength = 50;
	airdrag = 200;
	gravity = 1500;
	drag = 2500;
	jump();
}


Caltrops::~Caltrops()
{
}

void Caltrops::update()
{
	EntityPhysic::update();
	//temporary ground
	if (velY > 0 && position.getPosition().y > 440)
	{
		isAirborne = false;
		position.setPosition(position.getPosition().x, 440);
		velY = 0;
		animator.ChangeAnimation("Land");
		animator.JumpToFrame(rand() % 9);
	}
	//end temporary ground
}
