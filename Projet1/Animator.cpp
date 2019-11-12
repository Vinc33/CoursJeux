#include "Animator.h"
#include <fstream>
#include <iostream>

Animator::Animator()
{
	animations = map<string, Animation*>();
}

Animator::~Animator()
{
	std::map<string, Animation*>::iterator it;
	for (it = animations.begin(); it != animations.end(); it++)
		delete it->second;
}

void Animator::AddAnimation(Animation* a, string name)
{
	animations.insert(make_pair(name, a));
	if (size(animations) == 1)
		currentAnimation = animations[name];
}

void Animator::ChangeAnimation(string name)
{
	currentAnimation->Reset();
	currentAnimation = animations[name];
}

Sprite* Animator::GetSprite(bool reverse)
{
	return currentAnimation->GetSprite(reverse);
}

void Animator::Update()
{
	currentAnimation->Update();
}
