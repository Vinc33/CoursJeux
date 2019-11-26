#pragma once
#include "Hero.h"
#include "Animator.h"

class Monk : public Hero
{
public:
	Monk();
	~Monk();
	void changeAction(int enumPlaceholder) override;
private:
	Animator animatorFX;
	void addAnimations();
	bool hasRoundhoused;
	bool hasPunched;
	bool hasDropkicked;
	int jumpRemaining;
	int maxNumberOfJumps;
};

