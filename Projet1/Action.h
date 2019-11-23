#pragma once
class EntityBrain;

class Action
{
public:
	Action(EntityBrain* e);
	~Action();
	virtual int update();
protected:
	EntityBrain* p;
};

