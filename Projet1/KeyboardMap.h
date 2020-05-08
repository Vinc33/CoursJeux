#pragma once
#include <iostream>
#include "InputMap.h"
#include <SFML/Window/Keyboard.hpp>

class KeyboardMap :
	public InputMap
{
public:
	KeyboardMap();
	~KeyboardMap();

	bool getUp();
	bool getDown();
	bool getLeft();
	bool getRight();
	bool getAttack();
	bool getJump();
	bool getSkill1();
	bool getSkill2();

private:

	sf::Keyboard::Key keyUp;
	sf::Keyboard::Key keyDown;
	sf::Keyboard::Key keyLeft;
	sf::Keyboard::Key keyRight;

	sf::Keyboard::Key keyAttack;
	sf::Keyboard::Key keyJump;
	sf::Keyboard::Key keySkill1;
	sf::Keyboard::Key keySkill2;
};

