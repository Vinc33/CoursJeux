#pragma once
#include "Hero.h"
#include "Animator.h"

class Monk : public Hero
{
public:
	Monk();
	~Monk();
	void ChangeAction(int enumPlaceholder) override;
private:
	Animator animatorFX;
	void AddAnimations();
	bool hasRoundhoused;
	bool hasPunched;
	bool hasDropkicked;
	int jumpRemaining;
	int maxNumberOfJumps;
};

