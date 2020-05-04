#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "./Manager/StateManager.h"
#include <vector>
#include <string>

struct Coord {
	int x;
	int y;
};

struct Spritesheet {
	sf::Texture* texture;
	int nbRows;
	int nbColums;
};

class Animation
{
public:
	Animation(Spritesheet ss);
	~Animation();

	bool reversed = false;

	void addFrame(Coord index, int showTime = 250);

	void update();
	void updateHitbox();
	void restart();
	void jumpToFrame(unsigned int index);

	void init(sf::Sprite* s);

private:
	int currentFrame;
	float currentTime;

	Spritesheet spritesheet;
	sf::Sprite* sprite;
	sf::IntRect uvRect;

	std::vector<Coord> indexes;
	std::vector<int> showTimes;

	int spriteWidth;
	int spriteHeight;
};

