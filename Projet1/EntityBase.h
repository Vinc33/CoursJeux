#pragma once
#pragma warning(disable: 4250)
#include <SFML\Graphics\Transformable.hpp>
#include <SFML\Graphics\Drawable.hpp>

class EntityBase
{
public:
	EntityBase();
	~EntityBase();

	virtual void Update() = 0;
	virtual void Draw(sf::RenderTarget& target) = 0;

	sf::Transformable position;
};

