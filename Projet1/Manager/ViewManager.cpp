#include "ViewManager.h"
#include "../TimeManager.h"
#include "../Entity.h"



ViewManager::ViewManager(sf::Vector2f size)
{
	myView = new View({0,0}, { size.x, size.y });
	minimap = new View();
	//shakeRight = true;
	myView->setViewport(sf::FloatRect(0, 0, 1, 1));
}


ViewManager::~ViewManager()
{
}


void ViewManager::ZoomView(float zoomRaport)
{
	myView->zoom(zoomRaport);
}


void ViewManager::RotateView(float angle)
{
	myView->rotate(angle);
}


void ViewManager::setTarget(EntityBase * e)
{
	target = e;

	//sf::Vector2f center = { target->getPosition().x + target->getHitBox()->width / 2, target->getPosition().y + target->getHitBox()->height / 2 };
}


void ViewManager::ShakeView(int intensity, sf::Vector2f positionInitial)
{
	intensity = intensity * 2;
	if (shakeRight == true)
	{
		myView->setCenter(positionInitial.x + intensity, positionInitial.y);
		shakeRight = false;
	}
	else
	{
		myView->setCenter(positionInitial.x - intensity, positionInitial.y);
		shakeRight = true;
	}
}


void ViewManager::update()
{
	float smoothMotionWeight = .3f;
	if (target)
	{
		float x = lerp(myView->getCenter().x, target->getPosition().x, 1 - pow(1 - smoothMotionWeight, 1 - TimeManager::DeltaTime));
		float y = lerp(myView->getCenter().y, target->getPosition().y, 1 - pow(1 - smoothMotionWeight, 1 - TimeManager::DeltaTime));
		myView->setCenter(x, y);
	}
}


View* ViewManager::getView()
{
	return myView;
}


float ViewManager::lerp(float v0, float v1, float t)
{
	return (1 - t) * v0 + t * v1;
}