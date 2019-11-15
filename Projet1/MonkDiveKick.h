#pragma once
#include "ActionEntity.h"
class MonkDiveKick :
	public ActionEntity
{
public:
	MonkDiveKick(Entity* e);
	~MonkDiveKick();

	int Update();
private:
	float countDown;
};

