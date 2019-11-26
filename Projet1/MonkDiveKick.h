#pragma once
#include "ActionEntity.h"
class MonkDiveKick :
	public ActionEntity
{
public:
	MonkDiveKick(Entity* e);
	~MonkDiveKick();

	int update();
private:
	float countDown;
};

