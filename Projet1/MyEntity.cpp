#include "MyEntity.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML\Window\Keyboard.hpp>

<<<<<<< HEAD
MyEntity::MyEntity()
{
	/*myTexture=texture;
=======
MyEntity::MyEntity(sf::Texture* texture,Vector2f size, sf::Vector2u imageCount, float switchTime, float speed) : animation(texture,imageCount,switchTime)
{
	body = new RectangleShape();
	body->setOrigin(Vector2f(0.0f,0.0f));
	body->setSize(size);
	body->setTexture(texture);
	body->setPosition(0.0f, 0.0f);
	myTexture=texture;
>>>>>>> e39a63a7813f267956b6dd0c8b2571982ac21769
	mySprite.setTexture(*myTexture);
	mySprite.setScale(.2f, .2f);
	uvReckt.left = (int)(texture->getSize().x / float(imageCount.x));
<<<<<<< HEAD
	uvReckt.height = (int)(texture->getSize().y / float(imageCount.y));*/
=======
	uvReckt.height = (int)(texture->getSize().y / float(imageCount.y));
	hitbox = new Collider(body);
>>>>>>> e39a63a7813f267956b6dd0c8b2571982ac21769
}


MyEntity::~MyEntity()
{
}

void MyEntity::setPosition(const sf::Vector2f& pos)
{
	myTransform.setPosition(pos.x, pos.y);
	body->setPosition(pos);
}
void MyEntity::setPosition(const int& x, const int& y)
{
<<<<<<< HEAD
	//myTransform.setPosition(x, y);
=======
	myTransform.setPosition(x, y);
	body->setPosition(Vector2f(x, y));
>>>>>>> e39a63a7813f267956b6dd0c8b2571982ac21769
}


void MyEntity::draw(sf::RenderTarget& target)
{
	//target.draw(mySprite, myTransform.getTransform());
}

/*void MyEntity::updateInput(float fps)
{

	sf::Vector2f movements = { 0.0f,0.0f };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		movements = { -speed * fps,0.0f };
		row = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		movements = { speed*fps, 0.0f };
		row = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		movements = { 0.0f,speed*fps };
		row = 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		movements = { 0.0f,-speed * fps };
		row = 4;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) 
	{
		row = 0;
	}

		lastPos = GetPosition();
		animation.Update(row, fps);
		mySprite.setTextureRect(animation.uvReckt);
		setPosition(myTransform.getPosition() + movements);	
}

void MyEntity::moveOnHitBox()
{
	setPosition(body->getPosition());
}

void MyEntity::updateInput(float fps, bool is2D) {

	sf::Vector2f movements = { 0.0f,0.0f };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		movements = { -speed * fps,0.0f };
		animation.Update(1, fps);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		movements = { speed*fps, 0.0f };
		animation.Update(0, fps);
	}
	mySprite.setTextureRect(animation.uvReckt);
<<<<<<< HEAD
	myTransform.setPosition(myTransform.getPosition() + movements);
}*/
=======
	setPosition(myTransform.getPosition() + movements);
}
>>>>>>> e39a63a7813f267956b6dd0c8b2571982ac21769
