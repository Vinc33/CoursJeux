#pragma once
#pragma warning(disable: 4250)
#include <SFML\Graphics\Transformable.hpp>
#include <SFML\Graphics\drawable.hpp>
#include <SFML\Graphics.hpp>
using namespace sf;

class EntityBase //: public Transformable
{
protected:
	enum EFFECT {DAMAGE, KNOCKBACK};
	struct COLLISIONEFFECT
	{
	public:
		EFFECT effect;
		int variance;
	};

public:
	EntityBase();
	virtual ~EntityBase();


	virtual void update() = 0;

	virtual void draw(RenderTarget& target);
	virtual void drawHitBox(RenderTarget& target);

	virtual FloatRect* getHitBox();

	virtual Transform getTransform() = 0;

	virtual Vector2f getOrigin() = 0;
	virtual void setOrigin(Vector2f origin) = 0;

	virtual Vector2f getPosition() = 0;
	virtual void setPosition(Vector2f origin) = 0;
	virtual void setPosition(float x, float y) = 0;
	virtual void move(float x, float y) = 0;

	virtual float getRotation() = 0;
	virtual void setRotation(float angle) = 0;
	virtual void rotate(float angle) = 0;

	virtual void onCollision(EntityBase* e);

	/// <returns>a pointer to the first element of an array (or nullptr)</returns>
	virtual COLLISIONEFFECT* getCollisionEffects();

	virtual std::string toString();
};

