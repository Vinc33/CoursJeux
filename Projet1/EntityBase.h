#pragma once
#pragma warning(disable: 4250)
#include <SFML\Graphics\Transformable.hpp>
#include <SFML\Graphics\drawable.hpp>
#include <SFML\Graphics.hpp>
using namespace sf;

class EntityBase : public Transformable
{
protected:
	struct COLLISIONEFFECT
	{
	public:
		int id;
		int variance;
	};

public:
	EntityBase();
	virtual ~EntityBase();


	virtual void update() = 0;

	virtual void draw(sf::RenderTarget& target);

	virtual void drawHitBox(sf::RenderTarget& target);

	virtual FloatRect* getHitBox();

	virtual FloatRect* getDrawLocation();

	virtual void onCollision(EntityBase* e);

	/// <returns>a pointer to the first element of an array (or nullptr)</returns>
	virtual COLLISIONEFFECT* getCollisionEffects();

	virtual std::string toString();
};

