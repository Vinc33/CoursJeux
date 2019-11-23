#pragma once
#include <SFML\System\Clock.hpp>
#include <SFML\System\Time.hpp>

class TimeManager : public sf::Clock
{
public:
	TimeManager();
	~TimeManager();
	void update();
	static float DeltaTime;
};
