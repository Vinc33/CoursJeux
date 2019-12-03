#include "Collider.h"



Collider::Collider(RectangleShape* _body)
{
	body = _body;
}


Collider::~Collider()
{
}


 bool Collider::checkCollision(RectangleShape* other,float push) {
	sf::Vector2f otherPosition = other->getPosition();
	sf::Vector2f otherHalfSize = GetHalfSize(other);
	sf::Vector2f thisPosition = body->getPosition();
	sf::Vector2f thisHalfSize = GetHalfSize(body);

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX <= 0.0f&&intersectY <= 0.0f) {
		push = std::min(std::max(push, 0.0f), 1.0f);

		if (intersectX > intersectY) {
			if (deltaX > 0.0f) {
				other->move(-intersectX * push, 0.0f);
				
			}
			else {
				other->move(intersectX * push, 0.0f);
			}
		}
		else {
			if (deltaY > 0.0f) {
				other->move( 0.0f,-intersectY * push);
			}
			else {
				other->move( 0.0f,intersectY * push);
			}
		
		}
		return true;
	}
	return false;
}

 bool Collider::checkCollision(RectangleShape * other, float push, EntityBase * e)
 {
	 sf::Vector2f otherPosition = other->getPosition();
	 sf::Vector2f otherHalfSize = GetHalfSize(other);
	 sf::Vector2f thisPosition = body->getPosition();
	 sf::Vector2f thisHalfSize = GetHalfSize(body);

	 float deltaX = otherPosition.x - thisPosition.x;
	 float deltaY = otherPosition.y - thisPosition.y;
	 float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	 float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	 if (intersectX <= 0.0f&&intersectY <= 0.0f) {
		 push = std::min(std::max(push, 0.0f), 1.0f);

		 if (intersectX > intersectY) {
			 if (deltaX > 0.0f) {
				 other->move(-intersectX * push, 0.0f);
				 e->move(-intersectX * push, 0.0f);
			 }
			 else {
				 other->move(intersectX * push, 0.0f);
				 e->move(intersectX * push, 0.0f);
			 }
		 }
		 else {
			 if (deltaY > 0.0f) {
				 other->move(0.0f, -intersectY * push);
				 e->move(0.0f, -intersectY * push);
				 
			 }
			 else {
				 other->move(0.0f, intersectY * push);
				 e->move(0.0f, intersectY * push);
				 (dynamic_cast<EntityPhysic*>(e))->isAirborne = false;
				 (dynamic_cast<EntityPhysic*>(e))->gravityMult = 1;
			 }

		 }
		 return true ;                   
     }      
	 (dynamic_cast<EntityPhysic*>(e))->isAirborne = true;
	 return false;
 }
