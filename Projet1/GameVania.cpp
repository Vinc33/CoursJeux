#include "GameVania.h"

//TESTS
#include "Hunter.h"
#include "Monk.h"
#include "Rogue.h"
#include "Platform.h"

namespace GameView
{
	GameVania::GameVania(int width, int height, string titleScreen) : Game(width, height, titleScreen)
	{
	}


	GameVania::~GameVania()
	{
	}
	void GameVania::init()
	{
		Game::init();

		//Test
		AddCollisionBetweenLayers(0, 1);
		AddCollisionBetweenLayers(0, 2);
		AddCollisionBetweenLayers(1, 2);

		Monk * monk = new Monk();
		camera->setTarget(monk);

		AddEntity(monk);
		AddEntity(new Rogue(), 0);
		//AddEntity(new Hunter());

		sf::Texture* texture = new sf::Texture();
		texture->loadFromFile("Assets/ToolAndMagic/ThrownAxe.png");
		AddEntity(new Platform(texture, Vector2f(200.0f, 300.0f)), 2);

		//End Test
	}
}
