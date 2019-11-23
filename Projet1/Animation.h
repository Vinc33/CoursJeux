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
	Animation(Spritesheet ss, std::vector<Coord> indexes, std::vector<int> showTimes, bool loop = true);
	~Animation();
	void update();
	sf::Sprite* GetSprite(bool reverse = false);
	void Reset();

	void JumpToFrame(unsigned int index);

private:
	int currentFrame;
	float currentTime;

	sf::Sprite* currentSprite;
	sf::IntRect uvRect;

	Spritesheet spritesheet;
	std::vector<Coord> indexes;
	std::vector<int> showTimes;

	int spriteWidth;
	int spriteHeight;
};

