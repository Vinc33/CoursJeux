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
		AddCollisionBetweenLayers(1, 2);

		Monk * monk = new Monk(0);
		AddEntity(monk, 1);
		//Rogue * rogue = new Rogue(0);
		//AddEntity(rogue, 2);
		//AddEntity(new Hunter());

		camera->setTarget(monk);
		camera->getView()->zoom(0.5f);


		/*sf::Texture* texture = new sf::Texture();
		texture->loadFromFile("Assets/ToolAndMagic/ThrownAxe.png");*/
		//AddEntity(new Platform(texture, Vector2f(200.0f, 300.0f)), 2);

		//End Test
	}
}
