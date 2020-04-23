#pragma once
#include <SFML\Graphics.hpp>
#include "EntityInanimate.h"

class Platform :
	public EntityInanimate
{
public:
	Platform(sf::Texture* texture, sf::Vector2f position);
	~Platform();

	void update(){}

	virtual void draw(sf::RenderTarget& target);

	virtual std::string toString();

private:
};

