#pragma once
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
	Animator animator;

	void SetPosition(const sf::Vector2f& pos);
	void SetPosition(const int& x, const int& y);
	void accelerate(float x);
	void jump(float power = 1);

	virtual void ChangeAction(int enumIndex);
	void Update();
	virtual void Draw(sf::RenderTarget& target);
	RectangleShape* GetCollider() { return body; }

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

	const Texture* GetTexture() { return body->getTexture(); }

protected:
	sf::RectangleShape* body;

	
	sf::Transformable position;
	Action* CurrentAction;
};

