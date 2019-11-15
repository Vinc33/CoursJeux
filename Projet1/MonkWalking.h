#pragma once
#include "ActionEntity.h"
class MonkWalking :
	public ActionEntity
{
public:
	MonkWalking(Entity* e);
	~MonkWalking();
	int Update();
};

