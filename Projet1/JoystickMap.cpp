#include "JoystickMap.h"
#include <SFML/Window/Joystick.hpp>

JoystickMap::JoystickMap(int controllerIndex)
{
	this->controllerIndex = controllerIndex;

	buttonJump = 0;
	buttonAttack = 2;
	buttonSkill1 = 1;
	buttonSkill2 = 3;
}

JoystickMap::~JoystickMap()
{
}

bool JoystickMap::getUp()
{
	if (sf::Joystick::getAxisPosition(controllerIndex, sf::Joystick::PovY) > 50 ||
		sf::Joystick::getAxisPosition(controllerIndex, sf::Joystick::Y) > 25)
		return true;
	else
		return false;
}

bool JoystickMap::getDown()
{
	if (sf::Joystick::getAxisPosition(controllerIndex, sf::Joystick::PovY) < -50 ||
		sf::Joystick::getAxisPosition(controllerIndex, sf::Joystick::Y) < -25)
		return true;
	else
		return false;
}

bool JoystickMap::getLeft()
{
	if (sf::Joystick::getAxisPosition(controllerIndex, sf::Joystick::PovX) < -50 ||
		sf::Joystick::getAxisPosition(controllerIndex, sf::Joystick::X) < -25)
		return true;
	else
		return false;
}

bool JoystickMap::getRight()
{
	if (sf::Joystick::getAxisPosition(controllerIndex, sf::Joystick::PovX) > 50 || 
		sf::Joystick::getAxisPosition(controllerIndex, sf::Joystick::X) > 25)
		return true;
	else
		return false;
}

bool JoystickMap::getAttack()
{
	return sf::Joystick::isButtonPressed(controllerIndex, buttonAttack);
}

bool JoystickMap::getJump()
{
	return sf::Joystick::isButtonPressed(controllerIndex, buttonJump);
}

bool JoystickMap::getSkill1()
{
	return sf::Joystick::isButtonPressed(controllerIndex, buttonSkill1);
}

bool JoystickMap::getSkill2()
{
	return sf::Joystick::isButtonPressed(controllerIndex, buttonSkill2);
}
