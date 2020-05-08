#include "InputManager.h"
#include "JoystickMap.h"
#include "KeyboardMap.h"
#include <SFML/Window/Joystick.hpp>

vector<InputMap*> InputManager::players = vector<InputMap*>();

InputManager::InputManager()
{

}

InputManager::~InputManager()
{
	for (InputMap* map : players)
		delete map;
}

void InputManager::init()
{
	players.push_back(new KeyboardMap());
}

void InputManager::update()
{
	sf::Joystick::update();
}

bool InputManager::getKeyState(int playerID, INPUT key)
{
	switch (key)
	{
	case KEYUP:
		return players[playerID]->getUp();
		break;
	case KEYDOWN:
		return players[playerID]->getDown();
		break;
	case KEYLEFT:
		return players[playerID]->getLeft();
		break;
	case KEYRIGHT:
		return players[playerID]->getRight();
		break;
	case KEYATTACK:
		return players[playerID]->getAttack();
		break;
	case KEYJUMP:
		return players[playerID]->getJump();
		break;
	case KEYSKILL1:
		return players[playerID]->getSkill1();
		break;
	case KEYSKILL2:
		return players[playerID]->getSkill2();
		break;
	default:
		break;
	}
}