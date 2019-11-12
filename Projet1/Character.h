#pragma once
#include <string>
#include <vector>
#include "Entity.h"
using namespace std;

enum DamageType { PHYSICAL, FIRE, COLD, THUNDER, POISON };
enum ExtraEffect {STUN, DOT};

struct DamageInfo 
{
public:
	DamageType Type;
	short Amount;
	short KnockBack = 10;
	vector<ExtraEffect> Effects = { };
	vector<short> Magnitudes = { };
};

class Character :
	public Entity
{
public:
	Character(string unitName, short baseDamage, short maxHP);
	~Character();
	
	///<summary>Return true if the character is still alive</summary>
	bool ApplyDamage(short damage);
	virtual DamageInfo GetDamage();

	virtual void ChangeAction(int enumIndex) = 0;

protected:
	string UnitName;
	short CurrentHP;
	short MaxHP;
	short BaseDamage;
};

