#pragma once
#pragma warning(disable: 4250)
#include <SFML\Graphics\Transformable.hpp>
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include "Animation.h"
#include "Animator.h"


class EntityBase :
	public sf::Transformable
{
public:
	EntityBase();
	~EntityBase();

	virtual void Update() = 0;
	virtual void Draw(sf::RenderTarget& target) = 0;

protected: 
	sf::Transformable position;
};

