#pragma once
#include <iostream>
#include "InputMap.h"

class JoystickMap :
	public InputMap
{
public:
	JoystickMap(int controllerIndex);
	~JoystickMap();

	bool getUp();
	bool getDown();
	bool getLeft();
	bool getRight();
	bool getAttack();
	bool getJump();
	bool getSkill1();
	bool getSkill2();

private:
	int controllerIndex;

	int buttonAttack;
	int buttonJump;
	int buttonSkill1;
	int buttonSkill2;
};

