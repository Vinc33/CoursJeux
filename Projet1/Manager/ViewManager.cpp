#include "ViewManager.h"



ViewManager::ViewManager(sf::Vector2f center,sf::Vector2f halfSize)
{
	this->halfSize = halfSize;
	this->center = center;
	myView=new View(center,halfSize);
	minimap = new View();
	shakeRight = true;
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
void ViewManager::ShakeView(int intensity, sf::Vector2f positionInitial)
{
	intensity = intensity * 2;
	if (shakeRight==true) 
	{
		myView->setCenter(positionInitial.x + intensity, positionInitial.y);
		shakeRight=false ;
	}
	else 
	{
		myView->setCenter(positionInitial.x - intensity, positionInitial.y);
		shakeRight=true;
	}
}

void ViewManager::ViewUpdate(sf::Vector2f mouvement)
{
	myView->setCenter(mouvement);
	myView->setViewport(sf::FloatRect(0, 0, 1, 1));
}

View* ViewManager::getView()
{
	return myView;
}
