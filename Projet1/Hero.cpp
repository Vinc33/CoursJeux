#include "Hero.h"
#include "InputManager.h"


Hero::Hero(string unitName, short playerID, short baseDamage, short maxHP) : Character (unitName, baseDamage, maxHP)
{
	this->playerID = playerID;
}


Hero::~Hero()
{

}

bool Hero::getKeyState(INPUT key)
{
	return InputManager::getKeyState(playerID, key);
}
