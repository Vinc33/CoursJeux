#pragma once
#pragma once
#include <SFML\Graphics\Transformable.hpp>
#include <SFML\Graphics\drawable.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics.hpp>
#include <time.h>
#include "../EntityBase.h"



class ViewManager
{
public:
	ViewManager(sf::Vector2f size);
	~ViewManager();

	void update();
	View* getView();
	void ShakeView(int intensity, sf::Vector2f positionInitial);
	void ZoomView(float zoomRaport);
	void RotateView(float angle);
	void setTarget(EntityBase* e);
private:
	View* myView;
	View* minimap;
	bool shakeRight;
	EntityBase* target;

	float lerp(float v0, float v1, float t);

};