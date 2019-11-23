#include "Animator.h"
#include <fstream>
#include <iostream>

Animator::Animator()
{
	animations = std::map<std::string, Animation*>();
}

Animator::~Animator()
{
	std::map<std::string, Animation*>::iterator it;
	for (it = animations.begin(); it != animations.end(); it++)
		delete it->second;
}

void Animator::AddAnimation(Animation* a, std::string name)
{
	animations.insert(make_pair(name, a));
	if (size(animations) == 1)
		currentAnimation = animations[name];
}

void Animator::ChangeAnimation(std::string name)
{
	currentAnimation->Reset();
	currentAnimation = animations[name];
}

sf::Sprite* Animator::GetSprite(bool reverse)
{
	return currentAnimation->GetSprite(reverse);
}

void Animator::update()
{
	currentAnimation->update();
}

void Animator::JumpToFrame(unsigned int index)
{
	currentAnimation->JumpToFrame(index);
}
