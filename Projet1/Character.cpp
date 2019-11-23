#include "Character.h"



Character::Character(string unitName, short baseDamage, short maxHP)
{
	this->unitName = unitName;
	this->baseDamage = baseDamage;
	this->maxHP = maxHP;
	this->currentHP = maxHP;
}


Character::~Character()
{
}

DamageInfo Character::getDamage()
{
	return { DamageType::PHYSICAL, baseDamage };
}


bool Character::ApplyDamage(short damage)
{
	currentHP -= damage;
	return currentHP > 0 ? true : false;
}
