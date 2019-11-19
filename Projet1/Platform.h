#pragma once
#include <SFML\Graphics.hpp>
#include "Collider.h"
#include "Animator.h"
#include <SFML/Graphics.hpp>
class Platform
{
public:
	Platform(sf::Texture* texture,sf::Vector2f size,sf::Vector2f position);
	~Platform();

	void Draw(sf::RenderWindow& window);
	RectangleShape* GetCollider() 
	{ 
		return body; 
	}
	const Texture* GetTexture() { return body->getTexture(); }

	Animator animator;
private:
	sf::RectangleShape* body;
	Sprite currentSprite;
};

