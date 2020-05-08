#pragma once
#include "RogueItemUse.h"
class RogueThrowAxe :
	public RogueItemUse
{
public:
	RogueThrowAxe(Hero* e);
	~RogueThrowAxe();

	int update();
};

