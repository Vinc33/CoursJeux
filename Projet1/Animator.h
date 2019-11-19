#pragma once
#include "Animation.h"
#include <iostream>
#include <SFML\Graphics\Sprite.hpp>
#include <string>

class Animator
{
public:
	Animator();
	~Animator();

	void AddAnimation(Animation* a, std::string name);
	void ChangeAnimation(std::string name);
	sf::Sprite* GetSprite(bool reverse = false);
	void Update();
	void JumpToFrame(unsigned int index);
private:
	Animation* currentAnimation;
	std::map<std::string, Animation*> animations;

};

