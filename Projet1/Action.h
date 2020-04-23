#pragma once
class EntityStateMachine;

class Action
{
public:
	Action(EntityStateMachine* e);
	~Action();
	virtual int update();
protected:
	EntityStateMachine* stateMachine;
};

