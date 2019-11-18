/*#pragma once
#include <SFML\Graphics\Transformable.hpp>
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include "Animation.h"
#include "Animator.h"
class Action;

class Entity :
	public sf::Transformable
{
public:
	Entity();
	~Entity();

	void setPosition(const sf::Vector2f& pos);
	void setPosition(const int& x, const int& y);
	void accelerate(float x);
	void jump(float power = 1);

	virtual void ChangeAction(int enumIndex);
	void Update();
	virtual void Draw(sf::RenderTarget& target);

	void MoveOnHitBox();

	bool isFacingLeft;
	bool isAirborne;
	int gravity;
	float gravityMult;
	int maxVelX;
	//int maxFallSpeed;
	float velX;
	float velY;
	int acc;
	int jumpingStrength;
	int drag;
	int airdrag;
	//int airacc;

protected:
	sf::RectangleShape* body;

	Animator animator;
	sf::Transformable position;
	Action* CurrentAction;
};

*/