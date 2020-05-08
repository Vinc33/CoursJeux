#pragma once
#include "RogueItemUse.h"
class RogueThrowKnife :
	public RogueItemUse
{
public:
	RogueThrowKnife(Hero* e);
	~RogueThrowKnife();

	int update();
};

