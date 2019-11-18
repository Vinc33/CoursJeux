#pragma once
class EntityBrain;

class Action
{
public:
	Action(EntityBrain* e);
	~Action();
	virtual int Update();
protected:
	EntityBrain* p;
};

