#include "TimeManager.h"

float TimeManager::DeltaTime = 0;

TimeManager::TimeManager()
{

}


TimeManager::~TimeManager()
{
}

void TimeManager::update() 
{
	DeltaTime = (restart()).asSeconds();
}
