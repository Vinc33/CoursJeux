#pragma once

class InputMap
{
public:
	virtual bool getUp() = 0;
	virtual bool getDown() = 0;
	virtual bool getLeft() = 0;
	virtual bool getRight() = 0;
	virtual bool getAttack() = 0;
	virtual bool getJump() = 0;
	virtual bool getSkill1() = 0;
	virtual bool getSkill2() = 0;
};