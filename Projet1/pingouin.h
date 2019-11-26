#pragma once
#include "Hero.h"

class Pingouin : public Hero
{
public:
	Pingouin();
	~Pingouin();
	void ChangeAction(int enumIndex);
private:
	void addAnimations();
	Animator animatorFX;
	bool hasRoundhoused;
	bool hasPunched;
	bool hasDropkicked;
	bool hasDoubleJumped;
};