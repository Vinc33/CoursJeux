#include "KeyboardMap.h"

KeyboardMap::KeyboardMap()
{

	keyUp = sf::Keyboard::Up;
	keyDown = sf::Keyboard::Down;
	keyLeft = sf::Keyboard::Left;
	keyRight = sf::Keyboard::Right;

	keyAttack = sf::Keyboard::X;
	keyJump = sf::Keyboard::Space;
	keySkill1 = sf::Keyboard::C;
	keySkill2 = sf::Keyboard::D;
}

KeyboardMap::~KeyboardMap()
{
}

bool KeyboardMap::getUp()
{
	return sf::Keyboard::isKeyPressed(keyUp);
}

bool KeyboardMap::getDown()
{
	return sf::Keyboard::isKeyPressed(keyDown);
}

bool KeyboardMap::getLeft()
{
	return sf::Keyboard::isKeyPressed(keyLeft);
}

bool KeyboardMap::getRight()
{
	return sf::Keyboard::isKeyPressed(keyRight);
}

bool KeyboardMap::getAttack()
{
	return sf::Keyboard::isKeyPressed(keyAttack);
}

bool KeyboardMap::getJump()
{
	return sf::Keyboard::isKeyPressed(keyJump);
}

bool KeyboardMap::getSkill1()
{
	return sf::Keyboard::isKeyPressed(keySkill1);
}

bool KeyboardMap::getSkill2()
{
	return sf::Keyboard::isKeyPressed(keySkill2);
}
