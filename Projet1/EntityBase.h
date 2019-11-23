#pragma once
#pragma warning(disable: 4250)
#include <SFML\Graphics\Transformable.hpp>
#include <SFML\Graphics\drawable.hpp>

class EntityBase
{
public:
	EntityBase();
	virtual ~EntityBase();

	virtual void update() = 0;
	virtual void draw(sf::RenderTarget& target) = 0;

	sf::Transformable position;
};

