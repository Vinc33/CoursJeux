#pragma once
#pragma once
#include <SFML\Graphics\Transformable.hpp>
#include <SFML\Graphics\drawable.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics.hpp>
#include "../Collider.h"
#include <time.h>

class ViewManager
{
private:
	sf::Vector2f center;
	sf::Vector2f halfSize;
	View* myView;
	View* minimap;
	bool shakeRight;

public:
	ViewManager(sf::Vector2f center, sf::Vector2f hlafSize);
	~ViewManager();

	void Viewupdate(sf::Vector2f position);
	View* getView();
	void ShakeView(int intensity,sf::Vector2f positionInitial);
	void ZoomView(float zoomRaport);
	void RotateView(float angle);
};

