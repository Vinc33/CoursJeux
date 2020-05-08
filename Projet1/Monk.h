#pragma once
#include "Hero.h"

class Monk : public Hero
{
public:
	Monk(short playerID);
	~Monk();
	void changeAction(int enumPlaceholder) override;

	std::string toString();
private:
	void addAnimations();
	bool hasRoundhoused;
	bool hasPunched;
	bool hasDropkicked;
	int jumpRemaining;
	int maxNumberOfJumps;
};

